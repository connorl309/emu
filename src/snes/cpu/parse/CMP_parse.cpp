#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction CMP_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: CMP - mode = '(dir,X)'
	*/
		case 0xC1: {
			instr.opcode = 0xC1;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'stk,S'
	*/
		case 0xC3: {
			instr.opcode = 0xC3;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = stack_s;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'dir'
	*/
		case 0xC5: {
			instr.opcode = 0xC5;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = '[dir]'
	*/
		case 0xC7: {
			instr.opcode = 0xC7;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'imm'
	*/
		case 0xC9: {
			instr.opcode = 0xC9;
			instr.mnemonic = "CMP";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'abs'
	*/
		case 0xCD: {
			instr.opcode = 0xCD;
			instr.mnemonic = "CMP";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'long'
	*/
		case 0xCF: {
			instr.opcode = 0xCF;
			instr.mnemonic = "CMP";
			instr.length = 4;
			instr.mode = long_;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = '(dir),Y'
	*/
		case 0xD1: {
			instr.opcode = 0xD1;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = '(dir)'
	*/
		case 0xD2: {
			instr.opcode = 0xD2;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = '(stk,S),Y'
	*/
		case 0xD3: {
			instr.opcode = 0xD3;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'dir,X'
	*/
		case 0xD5: {
			instr.opcode = 0xD5;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = '[dir],Y'
	*/
		case 0xD7: {
			instr.opcode = 0xD7;
			instr.mnemonic = "CMP";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'abs,Y'
	*/
		case 0xD9: {
			instr.opcode = 0xD9;
			instr.mnemonic = "CMP";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'abs,X'
	*/
		case 0xDD: {
			instr.opcode = 0xDD;
			instr.mnemonic = "CMP";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CMP - mode = 'long,X'
	*/
		case 0xDF: {
			instr.opcode = 0xDF;
			instr.mnemonic = "CMP";
			instr.length = 4;
			instr.mode = long_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}