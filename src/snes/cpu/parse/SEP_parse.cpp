#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction SEP_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: SEP - mode = 'imm'
	*/
		case 0xE2: {
			instr.opcode = 0xE2;
			instr.mnemonic = "SEP";
			instr.length = 2;
			instr.mode = immediate;
			instr.callback = SEP_execute;
			instr.flags_set = {
				std::pair(n_flag, "*"), // SEP instruction sets N flag to * flag value
				std::pair(v_flag, "*"), // SEP instruction sets V flag to * flag value
				std::pair(m_flag, "*"), // SEP instruction sets M flag to * flag value
				std::pair(x_flag, "*"), // SEP instruction sets X flag to * flag value
				std::pair(d_flag, "*"), // SEP instruction sets D flag to * flag value
				std::pair(i_flag, "*"), // SEP instruction sets I flag to * flag value
				std::pair(z_flag, "*"), // SEP instruction sets Z flag to * flag value
				std::pair(c_flag, "*"), // SEP instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}