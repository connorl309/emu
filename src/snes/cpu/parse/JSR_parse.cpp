#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction JSR_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: JSR - mode = 'abs'
	*/
		case 0x20: {
			instr.opcode = 0x20;
			instr.mnemonic = "JSR";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = JSR_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: JSR - mode = '(abs,X)'
	*/
		case 0xFC: {
			instr.opcode = 0xFC;
			instr.mnemonic = "JSR";
			instr.length = 3;
			instr.mode = absolute_x_paren;
			instr.callback = JSR_execute;
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