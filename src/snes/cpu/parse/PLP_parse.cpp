#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction PLP_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: PLP - mode = 'imp'
	*/
		case 0x28: {
			instr.opcode = 0x28;
			instr.mnemonic = "PLP";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(n_flag, "*"), // PLP instruction sets N flag to * flag value
				std::pair(v_flag, "*"), // PLP instruction sets V flag to * flag value
				std::pair(m_flag, "*"), // PLP instruction sets M flag to * flag value
				std::pair(x_flag, "*"), // PLP instruction sets X flag to * flag value
				std::pair(d_flag, "*"), // PLP instruction sets D flag to * flag value
				std::pair(i_flag, "*"), // PLP instruction sets I flag to * flag value
				std::pair(z_flag, "*"), // PLP instruction sets Z flag to * flag value
				std::pair(c_flag, "*"), // PLP instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}