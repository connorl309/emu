#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction ADC_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: ADC - mode = '(dir,X)'
	*/
		case 0x61: {
			instr.opcode = 0x61;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = direct_x_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'stk,S'
	*/
		case 0x63: {
			instr.opcode = 0x63;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = stack_s;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'dir'
	*/
		case 0x65: {
			instr.opcode = 0x65;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = '[dir]'
	*/
		case 0x67: {
			instr.opcode = 0x67;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = direct_bracket;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'imm'
	*/
		case 0x69: {
			instr.opcode = 0x69;
			instr.mnemonic = "ADC";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'abs'
	*/
		case 0x6D: {
			instr.opcode = 0x6D;
			instr.mnemonic = "ADC";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'long'
	*/
		case 0x6F: {
			instr.opcode = 0x6F;
			instr.mnemonic = "ADC";
			instr.length = 4;
			instr.mode = long_;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = '(dir),Y'
	*/
		case 0x71: {
			instr.opcode = 0x71;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = direct_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = '(dir)'
	*/
		case 0x72: {
			instr.opcode = 0x72;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = direct_paren;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = '(stk,S),Y'
	*/
		case 0x73: {
			instr.opcode = 0x73;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = stack_s_paren_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'dir,X'
	*/
		case 0x75: {
			instr.opcode = 0x75;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = '[dir],Y'
	*/
		case 0x77: {
			instr.opcode = 0x77;
			instr.mnemonic = "ADC";
			instr.length = 2;
			instr.mode = direct_bracket_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'abs,Y'
	*/
		case 0x79: {
			instr.opcode = 0x79;
			instr.mnemonic = "ADC";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'abs,X'
	*/
		case 0x7D: {
			instr.opcode = 0x7D;
			instr.mnemonic = "ADC";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ADC - mode = 'long,X'
	*/
		case 0x7F: {
			instr.opcode = 0x7F;
			instr.mnemonic = "ADC";
			instr.length = 4;
			instr.mode = long_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}