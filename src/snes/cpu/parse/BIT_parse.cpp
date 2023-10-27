#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction BIT_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: BIT - mode = 'dir'
	*/
		case 0x24: {
			instr.opcode = 0x24;
			instr.mnemonic = "BIT";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: BIT - mode = 'abs'
	*/
		case 0x2C: {
			instr.opcode = 0x2C;
			instr.mnemonic = "BIT";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: BIT - mode = 'dir,X'
	*/
		case 0x34: {
			instr.opcode = 0x34;
			instr.mnemonic = "BIT";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: BIT - mode = 'abs,X'
	*/
		case 0x3C: {
			instr.opcode = 0x3C;
			instr.mnemonic = "BIT";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
				std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
				std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: BIT - mode = 'imm'
	*/
		case 0x89: {
			instr.opcode = 0x89;
			instr.mnemonic = "BIT";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.flags_set = {
				std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}