#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction XCE_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: XCE - mode = 'imp'
	*/
		case 0xFB: {
			instr.opcode = 0xFB;
			instr.mnemonic = "XCE";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(c_flag, "*"), // XCE instruction sets C flag to * flag value
				std::pair(e_flag, "*"), // XCE instruction sets E flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}