#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction RTI_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: RTI - mode = 'imp'
	*/
		case 0x40: {
			instr.opcode = 0x40;
			instr.mnemonic = "RTI";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(n_flag, "*"), // RTI instruction sets N flag to * flag value
				std::pair(v_flag, "*"), // RTI instruction sets V flag to * flag value
				std::pair(m_flag, "*"), // RTI instruction sets M flag to * flag value
				std::pair(x_flag, "*"), // RTI instruction sets X flag to * flag value
				std::pair(d_flag, "*"), // RTI instruction sets D flag to * flag value
				std::pair(i_flag, "*"), // RTI instruction sets I flag to * flag value
				std::pair(z_flag, "*"), // RTI instruction sets Z flag to * flag value
				std::pair(c_flag, "*"), // RTI instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}