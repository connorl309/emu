#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction EOR_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: EOR - mode = '(dir,X)'
	*/
		case 0x41: {
			instr.opcode = 0x41;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'stk,S'
	*/
		case 0x43: {
			instr.opcode = 0x43;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = stack_s;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'dir'
	*/
		case 0x45: {
			instr.opcode = 0x45;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = '[dir]'
	*/
		case 0x47: {
			instr.opcode = 0x47;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'imm'
	*/
		case 0x49: {
			instr.opcode = 0x49;
			instr.mnemonic = "EOR";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'abs'
	*/
		case 0x4D: {
			instr.opcode = 0x4D;
			instr.mnemonic = "EOR";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'long'
	*/
		case 0x4F: {
			instr.opcode = 0x4F;
			instr.mnemonic = "EOR";
			instr.length = 4;
			instr.mode = long_;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = '(dir),Y'
	*/
		case 0x51: {
			instr.opcode = 0x51;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = '(dir)'
	*/
		case 0x52: {
			instr.opcode = 0x52;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = '(stk,S),Y'
	*/
		case 0x53: {
			instr.opcode = 0x53;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'dir,X'
	*/
		case 0x55: {
			instr.opcode = 0x55;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = '[dir],Y'
	*/
		case 0x57: {
			instr.opcode = 0x57;
			instr.mnemonic = "EOR";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'abs,Y'
	*/
		case 0x59: {
			instr.opcode = 0x59;
			instr.mnemonic = "EOR";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'abs,X'
	*/
		case 0x5D: {
			instr.opcode = 0x5D;
			instr.mnemonic = "EOR";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: EOR - mode = 'long,X'
	*/
		case 0x5F: {
			instr.opcode = 0x5F;
			instr.mnemonic = "EOR";
			instr.length = 4;
			instr.mode = long_x;
			instr.callback = EOR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}