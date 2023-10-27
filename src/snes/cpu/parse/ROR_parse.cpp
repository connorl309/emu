#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction ROR_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: ROR - mode = 'dir'
	*/
		case 0x66: {
			instr.opcode = 0x66;
			instr.mnemonic = "ROR";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = ROR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROR - mode = 'acc'
	*/
		case 0x6A: {
			instr.opcode = 0x6A;
			instr.mnemonic = "ROR";
			instr.length = 1;
			instr.mode = accumulator;
			instr.callback = ROR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROR - mode = 'abs'
	*/
		case 0x6E: {
			instr.opcode = 0x6E;
			instr.mnemonic = "ROR";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = ROR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROR - mode = 'dir,X'
	*/
		case 0x76: {
			instr.opcode = 0x76;
			instr.mnemonic = "ROR";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = ROR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROR - mode = 'abs,X'
	*/
		case 0x7E: {
			instr.opcode = 0x7E;
			instr.mnemonic = "ROR";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.callback = ROR_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}