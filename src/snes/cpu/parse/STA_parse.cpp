#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction STA_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: STA - mode = '(dir,X)'
	*/
		case 0x81: {
			instr.opcode = 0x81;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'stk,S'
	*/
		case 0x83: {
			instr.opcode = 0x83;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = stack_s;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'dir'
	*/
		case 0x85: {
			instr.opcode = 0x85;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = '[dir]'
	*/
		case 0x87: {
			instr.opcode = 0x87;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'abs'
	*/
		case 0x8D: {
			instr.opcode = 0x8D;
			instr.mnemonic = "STA";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'long'
	*/
		case 0x8F: {
			instr.opcode = 0x8F;
			instr.mnemonic = "STA";
			instr.length = 4;
			instr.mode = long_;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = '(dir),Y'
	*/
		case 0x91: {
			instr.opcode = 0x91;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = '(dir)'
	*/
		case 0x92: {
			instr.opcode = 0x92;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = '(stk,S),Y'
	*/
		case 0x93: {
			instr.opcode = 0x93;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'dir,X'
	*/
		case 0x95: {
			instr.opcode = 0x95;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = '[dir],Y'
	*/
		case 0x97: {
			instr.opcode = 0x97;
			instr.mnemonic = "STA";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'abs,Y'
	*/
		case 0x99: {
			instr.opcode = 0x99;
			instr.mnemonic = "STA";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'abs,X'
	*/
		case 0x9D: {
			instr.opcode = 0x9D;
			instr.mnemonic = "STA";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STA - mode = 'long,X'
	*/
		case 0x9F: {
			instr.opcode = 0x9F;
			instr.mnemonic = "STA";
			instr.length = 4;
			instr.mode = long_x;
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