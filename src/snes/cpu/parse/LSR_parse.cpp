#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction LSR_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: LSR - mode = 'dir'
	*/
		case 0x46: {
			instr.opcode = 0x46;
			instr.mnemonic = "LSR";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
				std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LSR - mode = 'acc'
	*/
		case 0x4A: {
			instr.opcode = 0x4A;
			instr.mnemonic = "LSR";
			instr.length = 1;
			instr.mode = accumulator;
			instr.flags_set = {
				std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
				std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LSR - mode = 'abs'
	*/
		case 0x4E: {
			instr.opcode = 0x4E;
			instr.mnemonic = "LSR";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
				std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LSR - mode = 'dir,X'
	*/
		case 0x56: {
			instr.opcode = 0x56;
			instr.mnemonic = "LSR";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
				std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LSR - mode = 'abs,X'
	*/
		case 0x5E: {
			instr.opcode = 0x5E;
			instr.mnemonic = "LSR";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
				std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
				std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}