#include "inc/isa.hpp"
#include "inc/isa_impl.hpp"
#include <map>

namespace snes_cpu {

// opcode -> instruction parse function map.
static const std::map<uint8_t, std::function<instruction(uint8_t*, uint8_t)>> parse_map = {
	{0x61,ADC_parse_instr}, 	{0x63,ADC_parse_instr}, 	{0x65,ADC_parse_instr}, 	{0x67,ADC_parse_instr}, 	{0x69,ADC_parse_instr}, 	{0x6D,ADC_parse_instr}, 	{0x6F,ADC_parse_instr}, 	{0x71,ADC_parse_instr}, 
	{0x72,ADC_parse_instr}, 	{0x73,ADC_parse_instr}, 	{0x75,ADC_parse_instr}, 	{0x77,ADC_parse_instr}, 	{0x79,ADC_parse_instr}, 	{0x7D,ADC_parse_instr}, 	{0x7F,ADC_parse_instr}, 	{0xE1,SBC_parse_instr}, 
	{0xE3,SBC_parse_instr}, 	{0xE5,SBC_parse_instr}, 	{0xE7,SBC_parse_instr}, 	{0xE9,SBC_parse_instr}, 	{0xED,SBC_parse_instr}, 	{0xEF,SBC_parse_instr}, 	{0xF1,SBC_parse_instr}, 	{0xF2,SBC_parse_instr}, 
	{0xF3,SBC_parse_instr}, 	{0xF5,SBC_parse_instr}, 	{0xF7,SBC_parse_instr}, 	{0xF9,SBC_parse_instr}, 	{0xFD,SBC_parse_instr}, 	{0xFF,SBC_parse_instr}, 	{0xC1,CMP_parse_instr}, 	{0xC3,CMP_parse_instr}, 
	{0xC5,CMP_parse_instr}, 	{0xC7,CMP_parse_instr}, 	{0xC9,CMP_parse_instr}, 	{0xCD,CMP_parse_instr}, 	{0xCF,CMP_parse_instr}, 	{0xD1,CMP_parse_instr}, 	{0xD2,CMP_parse_instr}, 	{0xD3,CMP_parse_instr}, 
	{0xD5,CMP_parse_instr}, 	{0xD7,CMP_parse_instr}, 	{0xD9,CMP_parse_instr}, 	{0xDD,CMP_parse_instr}, 	{0xDF,CMP_parse_instr}, 	{0xE0,CPX_parse_instr}, 	{0xE4,CPX_parse_instr}, 	{0xEC,CPX_parse_instr}, 
	{0xC0,CPY_parse_instr}, 	{0xC4,CPY_parse_instr}, 	{0xCC,CPY_parse_instr}, 	{0x3A,DEC_parse_instr}, 	{0xC6,DEC_parse_instr}, 	{0xCE,DEC_parse_instr}, 	{0xD6,DEC_parse_instr}, 	{0xDE,DEC_parse_instr}, 
	{0xCA,DEX_parse_instr}, 	{0x88,DEY_parse_instr}, 	{0x1A,INC_parse_instr}, 	{0xE6,INC_parse_instr}, 	{0xEE,INC_parse_instr}, 	{0xF6,INC_parse_instr}, 	{0xFE,INC_parse_instr}, 	{0xE8,INX_parse_instr}, 
	{0xC8,INY_parse_instr}, 	{0x21,AND_parse_instr}, 	{0x23,AND_parse_instr}, 	{0x25,AND_parse_instr}, 	{0x27,AND_parse_instr}, 	{0x29,AND_parse_instr}, 	{0x2D,AND_parse_instr}, 	{0x2F,AND_parse_instr}, 
	{0x31,AND_parse_instr}, 	{0x32,AND_parse_instr}, 	{0x33,AND_parse_instr}, 	{0x35,AND_parse_instr}, 	{0x37,AND_parse_instr}, 	{0x39,AND_parse_instr}, 	{0x3D,AND_parse_instr}, 	{0x3F,AND_parse_instr}, 
	{0x41,EOR_parse_instr}, 	{0x43,EOR_parse_instr}, 	{0x45,EOR_parse_instr}, 	{0x47,EOR_parse_instr}, 	{0x49,EOR_parse_instr}, 	{0x4D,EOR_parse_instr}, 	{0x4F,EOR_parse_instr}, 	{0x51,EOR_parse_instr}, 
	{0x52,EOR_parse_instr}, 	{0x53,EOR_parse_instr}, 	{0x55,EOR_parse_instr}, 	{0x57,EOR_parse_instr}, 	{0x59,EOR_parse_instr}, 	{0x5D,EOR_parse_instr}, 	{0x5F,EOR_parse_instr}, 	{0x01,ORA_parse_instr}, 
	{0x03,ORA_parse_instr}, 	{0x05,ORA_parse_instr}, 	{0x07,ORA_parse_instr}, 	{0x09,ORA_parse_instr}, 	{0x0D,ORA_parse_instr}, 	{0x0F,ORA_parse_instr}, 	{0x11,ORA_parse_instr}, 	{0x12,ORA_parse_instr}, 
	{0x13,ORA_parse_instr}, 	{0x15,ORA_parse_instr}, 	{0x17,ORA_parse_instr}, 	{0x19,ORA_parse_instr}, 	{0x1D,ORA_parse_instr}, 	{0x1F,ORA_parse_instr}, 	{0x24,BIT_parse_instr}, 	{0x2C,BIT_parse_instr}, 
	{0x34,BIT_parse_instr}, 	{0x3C,BIT_parse_instr}, 	{0x89,BIT_parse_instr}, 	{0x14,TRB_parse_instr}, 	{0x1C,TRB_parse_instr}, 	{0x04,TSB_parse_instr}, 	{0x0C,TSB_parse_instr}, 	{0x06,ASL_parse_instr}, 
	{0x0A,ASL_parse_instr}, 	{0x0E,ASL_parse_instr}, 	{0x16,ASL_parse_instr}, 	{0x1E,ASL_parse_instr}, 	{0x46,LSR_parse_instr}, 	{0x4A,LSR_parse_instr}, 	{0x4E,LSR_parse_instr}, 	{0x56,LSR_parse_instr}, 
	{0x5E,LSR_parse_instr}, 	{0x26,ROL_parse_instr}, 	{0x2A,ROL_parse_instr}, 	{0x2E,ROL_parse_instr}, 	{0x36,ROL_parse_instr}, 	{0x3E,ROL_parse_instr}, 	{0x66,ROR_parse_instr}, 	{0x6A,ROR_parse_instr}, 
	{0x6E,ROR_parse_instr}, 	{0x76,ROR_parse_instr}, 	{0x7E,ROR_parse_instr}, 	{0x90,BCC_parse_instr}, 	{0xB0,BCS_parse_instr}, 	{0xF0,BEQ_parse_instr}, 	{0x30,BMI_parse_instr}, 	{0xD0,BNE_parse_instr}, 
	{0x10,BPL_parse_instr}, 	{0x80,BRA_parse_instr}, 	{0x50,BVC_parse_instr}, 	{0x70,BVS_parse_instr}, 	{0x82,BRL_parse_instr}, 	{0x4C,JMP_parse_instr}, 	{0x5C,JMP_parse_instr}, 	{0x6C,JMP_parse_instr}, 
	{0x7C,JMP_parse_instr}, 	{0xDC,JMP_parse_instr}, 	{0x22,JSL_parse_instr}, 	{0x20,JSR_parse_instr}, 	{0xFC,JSR_parse_instr}, 	{0x6B,RTL_parse_instr}, 	{0x60,RTS_parse_instr}, 	{0x00,BRK_parse_instr}, 
	{0x02,COP_parse_instr}, 	{0x40,RTI_parse_instr}, 	{0x18,CLC_parse_instr}, 	{0xD8,CLD_parse_instr}, 	{0x58,CLI_parse_instr}, 	{0xB8,CLV_parse_instr}, 	{0x38,SEC_parse_instr}, 	{0xF8,SED_parse_instr}, 
	{0x78,SEI_parse_instr}, 	{0xC2,REP_parse_instr}, 	{0xE2,SEP_parse_instr}, 	{0xA1,LDA_parse_instr}, 	{0xA3,LDA_parse_instr}, 	{0xA5,LDA_parse_instr}, 	{0xA7,LDA_parse_instr}, 	{0xA9,LDA_parse_instr}, 
	{0xAD,LDA_parse_instr}, 	{0xAF,LDA_parse_instr}, 	{0xB1,LDA_parse_instr}, 	{0xB2,LDA_parse_instr}, 	{0xB3,LDA_parse_instr}, 	{0xB5,LDA_parse_instr}, 	{0xB7,LDA_parse_instr}, 	{0xB9,LDA_parse_instr}, 
	{0xBD,LDA_parse_instr}, 	{0xBF,LDA_parse_instr}, 	{0xA2,LDX_parse_instr}, 	{0xA6,LDX_parse_instr}, 	{0xAE,LDX_parse_instr}, 	{0xB6,LDX_parse_instr}, 	{0xBE,LDX_parse_instr}, 	{0xA0,LDY_parse_instr}, 
	{0xA4,LDY_parse_instr}, 	{0xAC,LDY_parse_instr}, 	{0xB4,LDY_parse_instr}, 	{0xBC,LDY_parse_instr}, 	{0x81,STA_parse_instr}, 	{0x83,STA_parse_instr}, 	{0x85,STA_parse_instr}, 	{0x87,STA_parse_instr}, 
	{0x8D,STA_parse_instr}, 	{0x8F,STA_parse_instr}, 	{0x91,STA_parse_instr}, 	{0x92,STA_parse_instr}, 	{0x93,STA_parse_instr}, 	{0x95,STA_parse_instr}, 	{0x97,STA_parse_instr}, 	{0x99,STA_parse_instr}, 
	{0x9D,STA_parse_instr}, 	{0x9F,STA_parse_instr}, 	{0x86,STX_parse_instr}, 	{0x8E,STX_parse_instr}, 	{0x96,STX_parse_instr}, 	{0x84,STY_parse_instr}, 	{0x8C,STY_parse_instr}, 	{0x94,STY_parse_instr}, 
	{0x64,STZ_parse_instr}, 	{0x74,STZ_parse_instr}, 	{0x9C,STZ_parse_instr}, 	{0x9E,STZ_parse_instr}, 	{0x54,MVN_parse_instr}, 	{0x44,MVP_parse_instr}, 	{0xEA,NOP_parse_instr}, 	{0x42,WDM_parse_instr}, 
	{0xF4,PEA_parse_instr}, 	{0xD4,PEI_parse_instr}, 	{0x62,PER_parse_instr}, 	{0x48,PHA_parse_instr}, 	{0xDA,PHX_parse_instr}, 	{0x5A,PHY_parse_instr}, 	{0x68,PLA_parse_instr}, 	{0xFA,PLX_parse_instr}, 
	{0x7A,PLY_parse_instr}, 	{0x8B,PHB_parse_instr}, 	{0x0B,PHD_parse_instr}, 	{0x4B,PHK_parse_instr}, 	{0x08,PHP_parse_instr}, 	{0xAB,PLB_parse_instr}, 	{0x2B,PLD_parse_instr}, 	{0x28,PLP_parse_instr}, 
	{0xDB,STP_parse_instr}, 	{0xCB,WAI_parse_instr}, 	{0xAA,TAX_parse_instr}, 	{0xA8,TAY_parse_instr}, 	{0xBA,TSX_parse_instr}, 	{0x8A,TXA_parse_instr}, 	{0x9A,TXS_parse_instr}, 	{0x9B,TXY_parse_instr}, 
	{0x98,TYA_parse_instr}, 	{0xBB,TYX_parse_instr}, 	{0x5B,TCD_parse_instr}, 	{0x1B,TCS_parse_instr}, 	{0x7B,TDC_parse_instr}, 	{0x3B,TSC_parse_instr}, 	{0xEB,XBA_parse_instr}, 	{0xFB,XCE_parse_instr}, 
};

// mnemonic -> execution function map
static const std::map<std::string, std::function<void(const instruction&, cpu_registers&)>> exec_map = {
	{"ADC", ADC_execute}, 	{"SBC", SBC_execute}, 	{"CMP", CMP_execute}, 	{"CPX", CPX_execute}, 	{"CPY", CPY_execute}, 	{"DEC", DEC_execute}, 
	{"DEX", DEX_execute}, 	{"DEY", DEY_execute}, 	{"INC", INC_execute}, 	{"INX", INX_execute}, 	{"INY", INY_execute}, 	{"AND", AND_execute}, 
	{"EOR", EOR_execute}, 	{"ORA", ORA_execute}, 	{"BIT", BIT_execute}, 	{"TRB", TRB_execute}, 	{"TSB", TSB_execute}, 	{"ASL", ASL_execute}, 
	{"LSR", LSR_execute}, 	{"ROL", ROL_execute}, 	{"ROR", ROR_execute}, 	{"BCC", BCC_execute}, 	{"BCS", BCS_execute}, 	{"BEQ", BEQ_execute}, 
	{"BMI", BMI_execute}, 	{"BNE", BNE_execute}, 	{"BPL", BPL_execute}, 	{"BRA", BRA_execute}, 	{"BVC", BVC_execute}, 	{"BVS", BVS_execute}, 
	{"BRL", BRL_execute}, 	{"JMP", JMP_execute}, 	{"JSL", JSL_execute}, 	{"JSR", JSR_execute}, 	{"RTL", RTL_execute}, 	{"RTS", RTS_execute}, 
	{"BRK", BRK_execute}, 	{"COP", COP_execute}, 	{"RTI", RTI_execute}, 	{"CLC", CLC_execute}, 	{"CLD", CLD_execute}, 	{"CLI", CLI_execute}, 
	{"CLV", CLV_execute}, 	{"SEC", SEC_execute}, 	{"SED", SED_execute}, 	{"SEI", SEI_execute}, 	{"REP", REP_execute}, 	{"SEP", SEP_execute}, 
	{"LDA", LDA_execute}, 	{"LDX", LDX_execute}, 	{"LDY", LDY_execute}, 	{"STA", STA_execute}, 	{"STX", STX_execute}, 	{"STY", STY_execute}, 
	{"STZ", STZ_execute}, 	{"MVN", MVN_execute}, 	{"MVP", MVP_execute}, 	{"NOP", NOP_execute}, 	{"WDM", WDM_execute}, 	{"PEA", PEA_execute}, 
	{"PEI", PEI_execute}, 	{"PER", PER_execute}, 	{"PHA", PHA_execute}, 	{"PHX", PHX_execute}, 	{"PHY", PHY_execute}, 	{"PLA", PLA_execute}, 
	{"PLX", PLX_execute}, 	{"PLY", PLY_execute}, 	{"PHB", PHB_execute}, 	{"PHD", PHD_execute}, 	{"PHK", PHK_execute}, 	{"PHP", PHP_execute}, 
	{"PLB", PLB_execute}, 	{"PLD", PLD_execute}, 	{"PLP", PLP_execute}, 	{"STP", STP_execute}, 	{"WAI", WAI_execute}, 	{"TAX", TAX_execute}, 
	{"TAY", TAY_execute}, 	{"TSX", TSX_execute}, 	{"TXA", TXA_execute}, 	{"TXS", TXS_execute}, 	{"TXY", TXY_execute}, 	{"TYA", TYA_execute}, 
	{"TYX", TYX_execute}, 	{"TCD", TCD_execute}, 	{"TCS", TCS_execute}, 	{"TDC", TDC_execute}, 	{"TSC", TSC_execute}, 	{"XBA", XBA_execute}, 
	{"XCE", XCE_execute}, 
};

// Parse an instruction
instruction parseInstruction(uint8_t* memory_address, uint8_t m_flag_val) {
	instruction instr;
	std::function<instruction(uint8_t*, uint8_t)> parseCall = parse_map.at(*memory_address);
	instr = parseCall(memory_address, m_flag_val);
	return instr;
}

// Execute an instruction
void executeInstruction(const instruction& toExec, cpu_registers& regfile) {
	std::function<void(const instruction&, cpu_registers&)> execCall = exec_map.at(toExec.mnemonic);
	execCall(toExec, regfile);
}

}