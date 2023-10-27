#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction BVC_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: BVC - mode = 'rel8'
	*/
		case 0x50: {
			instr.opcode = 0x50;
			instr.mnemonic = "BVC";
			instr.length = 2;
			instr.mode = rel8;
			instr.callback = BVC_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}