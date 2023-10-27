#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction DEC_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: DEC - mode = 'acc'
	*/
		case 0x3A: {
			instr.opcode = 0x3A;
			instr.mnemonic = "DEC";
			instr.length = 1;
			instr.mode = accumulator;
			instr.flags_set = {
				std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: DEC - mode = 'dir'
	*/
		case 0xC6: {
			instr.opcode = 0xC6;
			instr.mnemonic = "DEC";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: DEC - mode = 'abs'
	*/
		case 0xCE: {
			instr.opcode = 0xCE;
			instr.mnemonic = "DEC";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: DEC - mode = 'dir,X'
	*/
		case 0xD6: {
			instr.opcode = 0xD6;
			instr.mnemonic = "DEC";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: DEC - mode = 'abs,X'
	*/
		case 0xDE: {
			instr.opcode = 0xDE;
			instr.mnemonic = "DEC";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}