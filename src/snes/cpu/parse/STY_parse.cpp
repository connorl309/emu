#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction STY_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: STY - mode = 'dir'
	*/
		case 0x84: {
			instr.opcode = 0x84;
			instr.mnemonic = "STY";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = STY_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STY - mode = 'abs'
	*/
		case 0x8C: {
			instr.opcode = 0x8C;
			instr.mnemonic = "STY";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = STY_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STY - mode = 'dir,X'
	*/
		case 0x94: {
			instr.opcode = 0x94;
			instr.mnemonic = "STY";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = STY_execute;
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