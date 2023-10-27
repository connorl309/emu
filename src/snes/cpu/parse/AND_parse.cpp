#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction AND_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: AND - mode = '(dir,X)'
	*/
		case 0x21: {
			instr.opcode = 0x21;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'stk,S'
	*/
		case 0x23: {
			instr.opcode = 0x23;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = stack_s;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'dir'
	*/
		case 0x25: {
			instr.opcode = 0x25;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = '[dir]'
	*/
		case 0x27: {
			instr.opcode = 0x27;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'imm'
	*/
		case 0x29: {
			instr.opcode = 0x29;
			instr.mnemonic = "AND";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'abs'
	*/
		case 0x2D: {
			instr.opcode = 0x2D;
			instr.mnemonic = "AND";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'long'
	*/
		case 0x2F: {
			instr.opcode = 0x2F;
			instr.mnemonic = "AND";
			instr.length = 4;
			instr.mode = long_;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = '(dir),Y'
	*/
		case 0x31: {
			instr.opcode = 0x31;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = '(dir)'
	*/
		case 0x32: {
			instr.opcode = 0x32;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = '(stk,S),Y'
	*/
		case 0x33: {
			instr.opcode = 0x33;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'dir,X'
	*/
		case 0x35: {
			instr.opcode = 0x35;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = '[dir],Y'
	*/
		case 0x37: {
			instr.opcode = 0x37;
			instr.mnemonic = "AND";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'abs,Y'
	*/
		case 0x39: {
			instr.opcode = 0x39;
			instr.mnemonic = "AND";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'abs,X'
	*/
		case 0x3D: {
			instr.opcode = 0x3D;
			instr.mnemonic = "AND";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: AND - mode = 'long,X'
	*/
		case 0x3F: {
			instr.opcode = 0x3F;
			instr.mnemonic = "AND";
			instr.length = 4;
			instr.mode = long_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}