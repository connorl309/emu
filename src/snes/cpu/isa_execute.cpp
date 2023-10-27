#include "../inc/isa.hpp"
#include "../inc/isa_impl.hpp"

typedef uint8_t u8;

namespace snes_cpu {

	// Helper function to translate addresses
	// Note: my "direct" mode also means the zero page.
	// "rr" = DBR
	// TODO: implement boundary wrapping for page/bank
	const static std::vector<uint32_t> translate_addr(const instruction& instr, cpu_registers& regfile, uint8_t* memory_buffer) {
		std::vector<uint32_t> final_addr;

		switch (instr.mode)
		{
			case absolute: { 
				if (instr.mnemonic == "JMP")
					final_addr.push_back((regfile.program_bank_reg << 16) + (instr.data[1] << 8) + instr.data[0]);
				else
					final_addr.push_back((regfile.data_bank_reg << 16) + (instr.data[1] << 8) + instr.data[0]);
				break; 
			}
			case absolute_y: { 
				uint8_t ll = instr.data[0];
				uint8_t hh = instr.data[1];
				uint16_t off = (hh << 8) + ll;
				final_addr.push_back((regfile.data_bank_reg << 16) + off + regfile.y_index_reg);
				break; 
			}
			case absolute_x: { 
				uint8_t ll = instr.data[0];
				uint8_t hh = instr.data[1];
				uint16_t off = (hh << 8) + ll;
				final_addr.push_back((regfile.data_bank_reg << 16) + off + regfile.x_index_reg);
				break; 
			}
			case absolute_paren: { // 16 bit ptr, only used by jmp
				uint8_t ll = instr.data[0];
				uint8_t hh = instr.data[1];
				uint16_t off = (hh << 8) + ll;
				uint8_t lo, hi;
				lo = memory_buffer[off];
				hi = memory_buffer[off + 1];
				final_addr.push_back((regfile.program_bank_reg << 16) + (hi << 8) + lo);
				break; 
			}
			case absolute_bracket: { // 24 bit ptr, only used by jmp
				uint8_t ll = instr.data[0];
				uint8_t hh = instr.data[1];
				uint16_t off = (hh << 8) + ll;
				uint8_t lo, mid, hi;
				lo = memory_buffer[off];
				mid = memory_buffer[off + 1];
				hi = memory_buffer[off + 2];
				final_addr.push_back((hi << 16) + (mid << 8) + lo);
				break; 
			} 
			case absolute_x_paren: { 
				uint16_t offset = (instr.data[1] << 8) + instr.data[0] + regfile.x_index_reg;
				uint16_t ptr = ((uint16_t*)memory_buffer)[(regfile.program_bank_reg << 16) + offset];
				uint16_t real_addr = ((uint16_t*)memory_buffer)[ptr];
				final_addr.push_back((regfile.program_bank_reg << 16) + real_addr);
				break; 
			} 
			case accumulator: { // special
				final_addr.push_back(-1);
				break; 
			}
			case direct: { 
				uint8_t ll = instr.data[0];
				uint16_t data;
				if (regfile.psr[e_flag] && (regfile.direct_reg & 0xFF) == 0)
					data = (regfile.direct_reg & 0xFF00) + ll;
				else
					data = regfile.direct_reg + ll;
				final_addr.push_back(data);
				break; 
			}
			case direct_x: { 
				uint8_t ll = instr.data[0];
				uint16_t data;
				if (regfile.psr[e_flag] && (regfile.direct_reg & 0xFF) == 0)
					data = (regfile.direct_reg & 0xFF00) + ll + regfile.x_index_reg;
				else
					data = regfile.direct_reg + ll + regfile.x_index_reg;
				final_addr.push_back(data);
				break; 
			} 			
			case direct_y: { 
				uint8_t ll = instr.data[0];
				uint16_t data;
				if (regfile.psr[e_flag] && (regfile.direct_reg & 0xFF) == 0)
					data = (regfile.direct_reg & 0xFF00) + ll + regfile.y_index_reg;
				else
					data = regfile.direct_reg + ll + regfile.y_index_reg;
				final_addr.push_back(data);
				break; 
			} 			
			case direct_paren: { // 16 bit ptr, no offset
				uint16_t ptr_addr;
				uint8_t ll = instr.data[0];
				if (regfile.psr[e_flag] && (regfile.direct_reg & 0xFF) == 0)
					ptr_addr = (regfile.direct_reg & 0xFF00) + ll;
				else
					ptr_addr = regfile.direct_reg + ll;
				uint16_t ptr = ((uint16_t*)memory_buffer)[ptr_addr];
				uint32_t data_addr = (regfile.data_bank_reg << 16) + ptr;
				final_addr.push_back(data_addr);
				break; 
			} 
			case direct_bracket: { // 24 bit ptr, no index reg offset
				uint8_t ll = instr.data[0];
				uint8_t lo, mid, hi;
				lo = memory_buffer[(uint8_t)regfile.direct_reg + ll];
				mid = memory_buffer[(uint8_t)regfile.direct_reg + ll + 1];
				hi = memory_buffer[(uint8_t)regfile.direct_reg + ll + 2];
				uint16_t data_addr = ((uint16_t*)memory_buffer)[(hi << 16) + (mid << 8) + lo];
				final_addr.push_back(data_addr);
				break; 
			} 
			case direct_x_paren: { // 16 bit ptr
				uint8_t ll = instr.data[0];
				uint16_t ptr_addr;
				if (regfile.psr[e_flag] && ((regfile.direct_reg & 0xFF) == 0))
					ptr_addr = (regfile.direct_reg & 0xFF00) + ll;
				else
					ptr_addr = regfile.direct_reg + ll;
				uint16_t mem_addr = ((uint16_t*)memory_buffer)[ptr_addr];
				final_addr.push_back((regfile.data_bank_reg << 16) + mem_addr + regfile.x_index_reg);
				break; 
			}
			case direct_paren_y: { // 16 bit ptr; same as above, but with Y instead of X
				uint8_t ll = instr.data[0];
				uint16_t ptr_addr;
				if (regfile.psr[e_flag] && ((regfile.direct_reg & 0xFF) == 0))
					ptr_addr = (regfile.direct_reg & 0xFF00) + ll;
				else
					ptr_addr = regfile.direct_reg + ll;
				uint16_t mem_addr = ((uint16_t*)memory_buffer)[ptr_addr];
				final_addr.push_back((regfile.data_bank_reg << 16) + mem_addr + regfile.y_index_reg);
				break; 
			}
			case direct_bracket_y: { // 24 bit ptr
				uint8_t ll = instr.data[0];
				uint8_t lo, mid, hi;
				lo = memory_buffer[(uint8_t)regfile.direct_reg + ll];
				mid = memory_buffer[(uint8_t)regfile.direct_reg + ll + 1];
				hi = memory_buffer[(uint8_t)regfile.direct_reg + ll + 2];
				uint16_t data_addr = ((uint16_t*)memory_buffer)[(hi << 16) + (mid << 8) + lo + regfile.y_index_reg];
				final_addr.push_back(data_addr);
				break; 
			}
			case immediate: { // TODO: determine if 8/16bit. maybe do in instruction itself?
				for (uint8_t byte : instr.data)
					final_addr.push_back(byte);
				break; 
			}
			case implied: {  // special
				final_addr.push_back(-1);
				break; 
			}
			case long_: { 
				uint32_t provided_addr = (instr.data[2] << 16) + (instr.data[1] << 8) + instr.data[0];
				final_addr.push_back(provided_addr);
				break; 
			}
			case long_x: { 
				uint32_t base_addr_provided = (instr.data[2] << 16) + (instr.data[1] << 8) + instr.data[0];
				final_addr.push_back(base_addr_provided + regfile.x_index_reg);
				break; 
			}
			case rel8: { 
				uint32_t offset = regfile.program_counter + 2 + (int8_t)(instr.data[0]);
				final_addr.push_back((regfile.program_bank_reg << 16) + (offset & 0xFFFF));
				break; 
			} 
			case rel16: { 
				uint32_t offset = regfile.program_counter + 3 + (int16_t)((instr.data[1] << 8) + instr.data[0]);
				final_addr.push_back((regfile.program_bank_reg << 16) + (offset & 0xFFFF));
				break; 
			}
			case src_dest: { 
				// special
				break; 
			}
			case stack_s: { 
				final_addr.push_back(regfile.sp + (uint8_t)instr.data[0]);
				break; 
			}
			case stack_s_paren_y: { 
				uint16_t ptr_addr = regfile.sp + (uint8_t)(instr.data[0] & 0xFF);
				uint16_t ptr = ((uint16_t*)memory_buffer)[ptr_addr];
				final_addr.push_back((ptr + regfile.y_index_reg) + (regfile.data_bank_reg << 16));
				break; 
			}
			default: break;
		}

		return final_addr;
	}
	/*
	ADC adds to the accumulator
	When M flag = 0, 16 bit operation
	When M flag = 1, 8 bit operation
	When D flag = 0, binary math
	When D flag = 1, BCD math
	*/
	void ADC_execute(const instruction& toExec, cpu_registers& regfile) {
	
	}

	void SBC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void CMP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void CPX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void CPY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void DEC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void DEX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void DEY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void INC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void INX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void INY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void AND_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void EOR_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void ORA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BIT_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TRB_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TSB_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void ASL_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void LSR_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void ROL_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void ROR_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BCC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BCS_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BEQ_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BMI_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BNE_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BPL_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BRA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BVC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BVS_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BRL_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void JMP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void JSL_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void JSR_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void RTL_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void RTS_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void BRK_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void COP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void RTI_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void CLC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void CLD_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void CLI_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void CLV_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void SEC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void SED_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void SEI_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void REP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void SEP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void LDA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void LDX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void LDY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void STA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void STX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void STY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void STZ_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void MVN_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void MVP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void NOP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void WDM_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PEA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PEI_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PER_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PHA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PHX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PHY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PLA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PLX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PLY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PHB_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PHD_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PHK_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PHP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PLB_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PLD_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void PLP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void STP_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void WAI_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TAX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TAY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TSX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TXA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TXS_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TXY_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TYA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TYX_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TCD_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TCS_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TDC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void TSC_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void XBA_execute(const instruction& toExec, cpu_registers& regfile) {

	}

	void XCE_execute(const instruction& toExec, cpu_registers& regfile) {

	}

}