#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction ORA_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: ORA - mode = '(dir,X)'
	*/
		case 0x01: {
			instr.opcode = 0x01;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'stk,S'
	*/
		case 0x03: {
			instr.opcode = 0x03;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = stack_s;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'dir'
	*/
		case 0x05: {
			instr.opcode = 0x05;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = '[dir]'
	*/
		case 0x07: {
			instr.opcode = 0x07;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'imm'
	*/
		case 0x09: {
			instr.opcode = 0x09;
			instr.mnemonic = "ORA";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'abs'
	*/
		case 0x0D: {
			instr.opcode = 0x0D;
			instr.mnemonic = "ORA";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'long'
	*/
		case 0x0F: {
			instr.opcode = 0x0F;
			instr.mnemonic = "ORA";
			instr.length = 4;
			instr.mode = long_;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = '(dir),Y'
	*/
		case 0x11: {
			instr.opcode = 0x11;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = '(dir)'
	*/
		case 0x12: {
			instr.opcode = 0x12;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = '(stk,S),Y'
	*/
		case 0x13: {
			instr.opcode = 0x13;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'dir,X'
	*/
		case 0x15: {
			instr.opcode = 0x15;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = '[dir],Y'
	*/
		case 0x17: {
			instr.opcode = 0x17;
			instr.mnemonic = "ORA";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'abs,Y'
	*/
		case 0x19: {
			instr.opcode = 0x19;
			instr.mnemonic = "ORA";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'abs,X'
	*/
		case 0x1D: {
			instr.opcode = 0x1D;
			instr.mnemonic = "ORA";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ORA - mode = 'long,X'
	*/
		case 0x1F: {
			instr.opcode = 0x1F;
			instr.mnemonic = "ORA";
			instr.length = 4;
			instr.mode = long_x;
			instr.callback = ORA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}