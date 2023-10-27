#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction STZ_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: STZ - mode = 'dir'
	*/
		case 0x64: {
			instr.opcode = 0x64;
			instr.mnemonic = "STZ";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = STZ_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STZ - mode = 'dir,X'
	*/
		case 0x74: {
			instr.opcode = 0x74;
			instr.mnemonic = "STZ";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = STZ_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STZ - mode = 'abs'
	*/
		case 0x9C: {
			instr.opcode = 0x9C;
			instr.mnemonic = "STZ";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = STZ_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STZ - mode = 'abs,X'
	*/
		case 0x9E: {
			instr.opcode = 0x9E;
			instr.mnemonic = "STZ";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.callback = STZ_execute;
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