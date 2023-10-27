#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction CLC_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: CLC - mode = 'imp'
	*/
		case 0x18: {
			instr.opcode = 0x18;
			instr.mnemonic = "CLC";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(c_flag, "0"), // CLC instruction sets C flag to 0 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}