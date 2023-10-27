#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction SEC_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: SEC - mode = 'imp'
	*/
		case 0x38: {
			instr.opcode = 0x38;
			instr.mnemonic = "SEC";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(c_flag, "1"), // SEC instruction sets C flag to 1 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}