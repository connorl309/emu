#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction BCS_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: BCS - mode = 'rel8'
	*/
		case 0xB0: {
			instr.opcode = 0xB0;
			instr.mnemonic = "BCS";
			instr.length = 2;
			instr.mode = rel8;
			instr.callback = BCS_execute;
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