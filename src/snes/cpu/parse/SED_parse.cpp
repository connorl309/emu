#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction SED_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: SED - mode = 'imp'
	*/
		case 0xF8: {
			instr.opcode = 0xF8;
			instr.mnemonic = "SED";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = SED_execute;
			instr.flags_set = {
				std::pair(d_flag, "1"), // SED instruction sets D flag to 1 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}