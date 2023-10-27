#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction PHP_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: PHP - mode = 'imp'
	*/
		case 0x08: {
			instr.opcode = 0x08;
			instr.mnemonic = "PHP";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = PHP_execute;
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