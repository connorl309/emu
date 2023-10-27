#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction REP_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: REP - mode = 'imm'
	*/
		case 0xC2: {
			instr.opcode = 0xC2;
			instr.mnemonic = "REP";
			instr.length = 2;
			instr.mode = immediate;
			instr.callback = REP_execute;
			instr.flags_set = {
				std::pair(n_flag, "*"), // REP instruction sets N flag to * flag value
				std::pair(v_flag, "*"), // REP instruction sets V flag to * flag value
				std::pair(m_flag, "*"), // REP instruction sets M flag to * flag value
				std::pair(x_flag, "*"), // REP instruction sets X flag to * flag value
				std::pair(d_flag, "*"), // REP instruction sets D flag to * flag value
				std::pair(i_flag, "*"), // REP instruction sets I flag to * flag value
				std::pair(z_flag, "*"), // REP instruction sets Z flag to * flag value
				std::pair(c_flag, "*"), // REP instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}