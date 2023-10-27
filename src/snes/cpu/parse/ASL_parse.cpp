#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction ASL_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: ASL - mode = 'dir'
	*/
		case 0x06: {
			instr.opcode = 0x06;
			instr.mnemonic = "ASL";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = ASL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ASL - mode = 'acc'
	*/
		case 0x0A: {
			instr.opcode = 0x0A;
			instr.mnemonic = "ASL";
			instr.length = 1;
			instr.mode = accumulator;
			instr.callback = ASL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ASL - mode = 'abs'
	*/
		case 0x0E: {
			instr.opcode = 0x0E;
			instr.mnemonic = "ASL";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = ASL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ASL - mode = 'dir,X'
	*/
		case 0x16: {
			instr.opcode = 0x16;
			instr.mnemonic = "ASL";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = ASL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ASL - mode = 'abs,X'
	*/
		case 0x1E: {
			instr.opcode = 0x1E;
			instr.mnemonic = "ASL";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.callback = ASL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}