#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction LDA_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: LDA - mode = '(dir,X)'
	*/
		case 0xA1: {
			instr.opcode = 0xA1;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'stk,S'
	*/
		case 0xA3: {
			instr.opcode = 0xA3;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = stack_s;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'dir'
	*/
		case 0xA5: {
			instr.opcode = 0xA5;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = '[dir]'
	*/
		case 0xA7: {
			instr.opcode = 0xA7;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'imm'
	*/
		case 0xA9: {
			instr.opcode = 0xA9;
			instr.mnemonic = "LDA";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'abs'
	*/
		case 0xAD: {
			instr.opcode = 0xAD;
			instr.mnemonic = "LDA";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'long'
	*/
		case 0xAF: {
			instr.opcode = 0xAF;
			instr.mnemonic = "LDA";
			instr.length = 4;
			instr.mode = long_;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = '(dir),Y'
	*/
		case 0xB1: {
			instr.opcode = 0xB1;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = '(dir)'
	*/
		case 0xB2: {
			instr.opcode = 0xB2;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = '(stk,S),Y'
	*/
		case 0xB3: {
			instr.opcode = 0xB3;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'dir,X'
	*/
		case 0xB5: {
			instr.opcode = 0xB5;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = '[dir],Y'
	*/
		case 0xB7: {
			instr.opcode = 0xB7;
			instr.mnemonic = "LDA";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'abs,Y'
	*/
		case 0xB9: {
			instr.opcode = 0xB9;
			instr.mnemonic = "LDA";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'abs,X'
	*/
		case 0xBD: {
			instr.opcode = 0xBD;
			instr.mnemonic = "LDA";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDA - mode = 'long,X'
	*/
		case 0xBF: {
			instr.opcode = 0xBF;
			instr.mnemonic = "LDA";
			instr.length = 4;
			instr.mode = long_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}