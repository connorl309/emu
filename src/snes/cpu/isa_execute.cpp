#include "../inc/isa.hpp"
#include "../inc/isa_impl.hpp"

namespace snes_cpu {

	/*
	ADC adds to the accumulator
	When M flag = 0, 16 bit operation
	When M flag = 1, 8 bit operation
	When D flag = 0, binary math
	When D flag = 1, BCD math
	*/
	void ADC_execute(const instruction& toExec, cpu_registers& regfile) {
		switch (toExec.mode)
		{
			case direct_x_paren: {
				break;
			}
			case stack_s: {
				break;
			}
			case direct: {
				break;
			}
			case direct_bracket: {
				break;
			}
			case immediate: {
				break;
			}
			case absolute: {
				break;
			}
		}
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