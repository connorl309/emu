#ifndef ISA_IMPL_HPP
#define ISA_IMPL_HPP
#include "isa.hpp"

namespace snes_cpu {

	// Parse and execute a ADC instruction from starting memory address
	instruction ADC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void ADC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a SBC instruction from starting memory address
	instruction SBC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void SBC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a CMP instruction from starting memory address
	instruction CMP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void CMP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a CPX instruction from starting memory address
	instruction CPX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void CPX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a CPY instruction from starting memory address
	instruction CPY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void CPY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a DEC instruction from starting memory address
	instruction DEC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void DEC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a DEX instruction from starting memory address
	instruction DEX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void DEX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a DEY instruction from starting memory address
	instruction DEY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void DEY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a INC instruction from starting memory address
	instruction INC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void INC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a INX instruction from starting memory address
	instruction INX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void INX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a INY instruction from starting memory address
	instruction INY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void INY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a AND instruction from starting memory address
	instruction AND_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void AND_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a EOR instruction from starting memory address
	instruction EOR_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void EOR_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a ORA instruction from starting memory address
	instruction ORA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void ORA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BIT instruction from starting memory address
	instruction BIT_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BIT_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TRB instruction from starting memory address
	instruction TRB_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TRB_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TSB instruction from starting memory address
	instruction TSB_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TSB_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a ASL instruction from starting memory address
	instruction ASL_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void ASL_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a LSR instruction from starting memory address
	instruction LSR_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void LSR_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a ROL instruction from starting memory address
	instruction ROL_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void ROL_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a ROR instruction from starting memory address
	instruction ROR_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void ROR_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BCC instruction from starting memory address
	instruction BCC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BCC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BCS instruction from starting memory address
	instruction BCS_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BCS_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BEQ instruction from starting memory address
	instruction BEQ_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BEQ_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BMI instruction from starting memory address
	instruction BMI_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BMI_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BNE instruction from starting memory address
	instruction BNE_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BNE_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BPL instruction from starting memory address
	instruction BPL_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BPL_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BRA instruction from starting memory address
	instruction BRA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BRA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BVC instruction from starting memory address
	instruction BVC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BVC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BVS instruction from starting memory address
	instruction BVS_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BVS_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BRL instruction from starting memory address
	instruction BRL_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BRL_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a JMP instruction from starting memory address
	instruction JMP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void JMP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a JSL instruction from starting memory address
	instruction JSL_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void JSL_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a JSR instruction from starting memory address
	instruction JSR_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void JSR_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a RTL instruction from starting memory address
	instruction RTL_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void RTL_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a RTS instruction from starting memory address
	instruction RTS_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void RTS_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a BRK instruction from starting memory address
	instruction BRK_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void BRK_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a COP instruction from starting memory address
	instruction COP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void COP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a RTI instruction from starting memory address
	instruction RTI_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void RTI_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a CLC instruction from starting memory address
	instruction CLC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void CLC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a CLD instruction from starting memory address
	instruction CLD_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void CLD_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a CLI instruction from starting memory address
	instruction CLI_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void CLI_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a CLV instruction from starting memory address
	instruction CLV_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void CLV_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a SEC instruction from starting memory address
	instruction SEC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void SEC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a SED instruction from starting memory address
	instruction SED_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void SED_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a SEI instruction from starting memory address
	instruction SEI_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void SEI_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a REP instruction from starting memory address
	instruction REP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void REP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a SEP instruction from starting memory address
	instruction SEP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void SEP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a LDA instruction from starting memory address
	instruction LDA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void LDA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a LDX instruction from starting memory address
	instruction LDX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void LDX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a LDY instruction from starting memory address
	instruction LDY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void LDY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a STA instruction from starting memory address
	instruction STA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void STA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a STX instruction from starting memory address
	instruction STX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void STX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a STY instruction from starting memory address
	instruction STY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void STY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a STZ instruction from starting memory address
	instruction STZ_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void STZ_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a MVN instruction from starting memory address
	instruction MVN_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void MVN_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a MVP instruction from starting memory address
	instruction MVP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void MVP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a NOP instruction from starting memory address
	instruction NOP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void NOP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a WDM instruction from starting memory address
	instruction WDM_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void WDM_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PEA instruction from starting memory address
	instruction PEA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PEA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PEI instruction from starting memory address
	instruction PEI_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PEI_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PER instruction from starting memory address
	instruction PER_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PER_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PHA instruction from starting memory address
	instruction PHA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PHA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PHX instruction from starting memory address
	instruction PHX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PHX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PHY instruction from starting memory address
	instruction PHY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PHY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PLA instruction from starting memory address
	instruction PLA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PLA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PLX instruction from starting memory address
	instruction PLX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PLX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PLY instruction from starting memory address
	instruction PLY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PLY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PHB instruction from starting memory address
	instruction PHB_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PHB_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PHD instruction from starting memory address
	instruction PHD_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PHD_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PHK instruction from starting memory address
	instruction PHK_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PHK_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PHP instruction from starting memory address
	instruction PHP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PHP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PLB instruction from starting memory address
	instruction PLB_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PLB_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PLD instruction from starting memory address
	instruction PLD_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PLD_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a PLP instruction from starting memory address
	instruction PLP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void PLP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a STP instruction from starting memory address
	instruction STP_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void STP_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a WAI instruction from starting memory address
	instruction WAI_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void WAI_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TAX instruction from starting memory address
	instruction TAX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TAX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TAY instruction from starting memory address
	instruction TAY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TAY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TSX instruction from starting memory address
	instruction TSX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TSX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TXA instruction from starting memory address
	instruction TXA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TXA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TXS instruction from starting memory address
	instruction TXS_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TXS_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TXY instruction from starting memory address
	instruction TXY_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TXY_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TYA instruction from starting memory address
	instruction TYA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TYA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TYX instruction from starting memory address
	instruction TYX_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TYX_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TCD instruction from starting memory address
	instruction TCD_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TCD_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TCS instruction from starting memory address
	instruction TCS_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TCS_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TDC instruction from starting memory address
	instruction TDC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TDC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a TSC instruction from starting memory address
	instruction TSC_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void TSC_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a XBA instruction from starting memory address
	instruction XBA_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void XBA_execute(const instruction& toExec, cpu_registers& regfile);

	// Parse and execute a XCE instruction from starting memory address
	instruction XCE_parse_instr(uint8_t* mem_addr, uint8_t m_flag_val);
	void XCE_execute(const instruction& toExec, cpu_registers& regfile);

}
#endif