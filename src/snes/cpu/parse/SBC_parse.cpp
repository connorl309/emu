#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction SBC_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: SBC - mode = '(dir,X)'
	*/
		case 0xE1: {
			instr.opcode = 0xE1;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'stk,S'
	*/
		case 0xE3: {
			instr.opcode = 0xE3;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = stack_s;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'dir'
	*/
		case 0xE5: {
			instr.opcode = 0xE5;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = '[dir]'
	*/
		case 0xE7: {
			instr.opcode = 0xE7;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'imm'
	*/
		case 0xE9: {
			instr.opcode = 0xE9;
			instr.mnemonic = "SBC";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'abs'
	*/
		case 0xED: {
			instr.opcode = 0xED;
			instr.mnemonic = "SBC";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'long'
	*/
		case 0xEF: {
			instr.opcode = 0xEF;
			instr.mnemonic = "SBC";
			instr.length = 4;
			instr.mode = long_;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = '(dir),Y'
	*/
		case 0xF1: {
			instr.opcode = 0xF1;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = '(dir)'
	*/
		case 0xF2: {
			instr.opcode = 0xF2;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = '(stk,S),Y'
	*/
		case 0xF3: {
			instr.opcode = 0xF3;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'dir,X'
	*/
		case 0xF5: {
			instr.opcode = 0xF5;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = '[dir],Y'
	*/
		case 0xF7: {
			instr.opcode = 0xF7;
			instr.mnemonic = "SBC";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'abs,Y'
	*/
		case 0xF9: {
			instr.opcode = 0xF9;
			instr.mnemonic = "SBC";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'abs,X'
	*/
		case 0xFD: {
			instr.opcode = 0xFD;
			instr.mnemonic = "SBC";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: SBC - mode = 'long,X'
	*/
		case 0xFF: {
			instr.opcode = 0xFF;
			instr.mnemonic = "SBC";
			instr.length = 4;
			instr.mode = long_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}