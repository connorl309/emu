#ifndef ISA_IMPL_HPP
#define ISA_IMPL_HPP

#include "isa.hpp"

/**
 * Everything relating to the 65c816 CPU
 * Instructions, addressing modes, regfiles, execution, etc
*/
namespace snes_cpu
{

// Execute an ADC instruction from current register states
void ADC_execute(cpu_registers& regfile);
// Execute an SBC instruction from current register states
void SBC_execute(cpu_registers& regfile);
// Execute an CMP instruction from current register states
void CMP_execute(cpu_registers& regfile);
// Execute an CPX instruction from current register states
void CPX_execute(cpu_registers& regfile);
// Execute an CPY instruction from current register states
void CPY_execute(cpu_registers& regfile);
// Execute an DEC instruction from current register states
void DEC_execute(cpu_registers& regfile);
// Execute an DEX instruction from current register states
void DEX_execute(cpu_registers& regfile);
// Execute an DEY instruction from current register states
void DEY_execute(cpu_registers& regfile);
// Execute an INC instruction from current register states
void INC_execute(cpu_registers& regfile);
// Execute an INX instruction from current register states
void INX_execute(cpu_registers& regfile);
// Execute an INY instruction from current register states
void INY_execute(cpu_registers& regfile);
// Execute an AND instruction from current register states
void AND_execute(cpu_registers& regfile);
// Execute an EOR instruction from current register states
void EOR_execute(cpu_registers& regfile);
// Execute an ORA instruction from current register states
void ORA_execute(cpu_registers& regfile);
// Execute an BIT instruction from current register states
void BIT_execute(cpu_registers& regfile);
// Execute an TRB instruction from current register states
void TRB_execute(cpu_registers& regfile);
// Execute an TSB instruction from current register states
void TSB_execute(cpu_registers& regfile);
// Execute an ASL instruction from current register states
void ASL_execute(cpu_registers& regfile);
// Execute an LSR instruction from current register states
void LSR_execute(cpu_registers& regfile);
// Execute an ROL instruction from current register states
void ROL_execute(cpu_registers& regfile);
// Execute an ROR instruction from current register states
void ROR_execute(cpu_registers& regfile);
// Execute an BCC instruction from current register states
void BCC_execute(cpu_registers& regfile);
// Execute an BCS instruction from current register states
void BCS_execute(cpu_registers& regfile);
// Execute an BEQ instruction from current register states
void BEQ_execute(cpu_registers& regfile);
// Execute an BMI instruction from current register states
void BMI_execute(cpu_registers& regfile);
// Execute an BNE instruction from current register states
void BNE_execute(cpu_registers& regfile);
// Execute an BPL instruction from current register states
void BPL_execute(cpu_registers& regfile);
// Execute an BRA instruction from current register states
void BRA_execute(cpu_registers& regfile);
// Execute an BVC instruction from current register states
void BVC_execute(cpu_registers& regfile);
// Execute an BVS instruction from current register states
void BVS_execute(cpu_registers& regfile);
// Execute an BRL instruction from current register states
void BRL_execute(cpu_registers& regfile);
// Execute an JMP instruction from current register states
void JMP_execute(cpu_registers& regfile);
// Execute an JSL instruction from current register states
void JSL_execute(cpu_registers& regfile);
// Execute an JSR instruction from current register states
void JSR_execute(cpu_registers& regfile);
// Execute an RTL instruction from current register states
void RTL_execute(cpu_registers& regfile);
// Execute an RTS instruction from current register states
void RTS_execute(cpu_registers& regfile);
// Execute an BRK instruction from current register states
void BRK_execute(cpu_registers& regfile);
// Execute an COP instruction from current register states
void COP_execute(cpu_registers& regfile);
// Execute an RTI instruction from current register states
void RTI_execute(cpu_registers& regfile);
// Execute an CLC instruction from current register states
void CLC_execute(cpu_registers& regfile);
// Execute an CLD instruction from current register states
void CLD_execute(cpu_registers& regfile);
// Execute an CLI instruction from current register states
void CLI_execute(cpu_registers& regfile);
// Execute an CLV instruction from current register states
void CLV_execute(cpu_registers& regfile);
// Execute an SEC instruction from current register states
void SEC_execute(cpu_registers& regfile);
// Execute an SED instruction from current register states
void SED_execute(cpu_registers& regfile);
// Execute an SEI instruction from current register states
void SEI_execute(cpu_registers& regfile);
// Execute an REP instruction from current register states
void REP_execute(cpu_registers& regfile);
// Execute an SEP instruction from current register states
void SEP_execute(cpu_registers& regfile);
// Execute an LDA instruction from current register states
void LDA_execute(cpu_registers& regfile);
// Execute an LDX instruction from current register states
void LDX_execute(cpu_registers& regfile);
// Execute an LDY instruction from current register states
void LDY_execute(cpu_registers& regfile);
// Execute an STA instruction from current register states
void STA_execute(cpu_registers& regfile);
// Execute an STX instruction from current register states
void STX_execute(cpu_registers& regfile);
// Execute an STY instruction from current register states
void STY_execute(cpu_registers& regfile);
// Execute an STZ instruction from current register states
void STZ_execute(cpu_registers& regfile);
// Execute an MVN instruction from current register states
void MVN_execute(cpu_registers& regfile);
// Execute an MVP instruction from current register states
void MVP_execute(cpu_registers& regfile);
// Execute an NOP instruction from current register states
void NOP_execute(cpu_registers& regfile);
// Execute an WDM instruction from current register states
void WDM_execute(cpu_registers& regfile);
// Execute an PEA instruction from current register states
void PEA_execute(cpu_registers& regfile);
// Execute an PEI instruction from current register states
void PEI_execute(cpu_registers& regfile);
// Execute an PER instruction from current register states
void PER_execute(cpu_registers& regfile);
// Execute an PHA instruction from current register states
void PHA_execute(cpu_registers& regfile);
// Execute an PHX instruction from current register states
void PHX_execute(cpu_registers& regfile);
// Execute an PHY instruction from current register states
void PHY_execute(cpu_registers& regfile);
// Execute an PLA instruction from current register states
void PLA_execute(cpu_registers& regfile);
// Execute an PLX instruction from current register states
void PLX_execute(cpu_registers& regfile);
// Execute an PLY instruction from current register states
void PLY_execute(cpu_registers& regfile);
// Execute an PHB instruction from current register states
void PHB_execute(cpu_registers& regfile);
// Execute an PHD instruction from current register states
void PHD_execute(cpu_registers& regfile);
// Execute an PHK instruction from current register states
void PHK_execute(cpu_registers& regfile);
// Execute an PHP instruction from current register states
void PHP_execute(cpu_registers& regfile);
// Execute an PLB instruction from current register states
void PLB_execute(cpu_registers& regfile);
// Execute an PLD instruction from current register states
void PLD_execute(cpu_registers& regfile);
// Execute an PLP instruction from current register states
void PLP_execute(cpu_registers& regfile);
// Execute an STP instruction from current register states
void STP_execute(cpu_registers& regfile);
// Execute an WAI instruction from current register states
void WAI_execute(cpu_registers& regfile);
// Execute an TAX instruction from current register states
void TAX_execute(cpu_registers& regfile);
// Execute an TAY instruction from current register states
void TAY_execute(cpu_registers& regfile);
// Execute an TSX instruction from current register states
void TSX_execute(cpu_registers& regfile);
// Execute an TXA instruction from current register states
void TXA_execute(cpu_registers& regfile);
// Execute an TXS instruction from current register states
void TXS_execute(cpu_registers& regfile);
// Execute an TXY instruction from current register states
void TXY_execute(cpu_registers& regfile);
// Execute an TYA instruction from current register states
void TYA_execute(cpu_registers& regfile);
// Execute an TYX instruction from current register states
void TYX_execute(cpu_registers& regfile);
// Execute an TCD instruction from current register states
void TCD_execute(cpu_registers& regfile);
// Execute an TCS instruction from current register states
void TCS_execute(cpu_registers& regfile);
// Execute an TDC instruction from current register states
void TDC_execute(cpu_registers& regfile);
// Execute an TSC instruction from current register states
void TSC_execute(cpu_registers& regfile);
// Execute an XBA instruction from current register states
void XBA_execute(cpu_registers& regfile);
// Execute an XCE instruction from current register states
void XCE_execute(cpu_registers& regfile);

}

#endif