#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction INC_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: INC - mode = 'acc'
	*/
		case 0x1A: {
			instr.opcode = 0x1A;
			instr.mnemonic = "INC";
			instr.length = 1;
			instr.mode = accumulator;
			instr.flags_set = {
				std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: INC - mode = 'dir'
	*/
		case 0xE6: {
			instr.opcode = 0xE6;
			instr.mnemonic = "INC";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: INC - mode = 'abs'
	*/
		case 0xEE: {
			instr.opcode = 0xEE;
			instr.mnemonic = "INC";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: INC - mode = 'dir,X'
	*/
		case 0xF6: {
			instr.opcode = 0xF6;
			instr.mnemonic = "INC";
			instr.length = 2;
			instr.mode = direct_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: INC - mode = 'abs,X'
	*/
		case 0xFE: {
			instr.opcode = 0xFE;
			instr.mnemonic = "INC";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.flags_set = {
				std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}