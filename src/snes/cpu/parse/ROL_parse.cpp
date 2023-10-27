#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction ROL_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: ROL - mode = 'dir'
	*/
		case 0x26: {
			instr.opcode = 0x26;
			instr.mnemonic = "ROL";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = ROL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROL - mode = 'acc'
	*/
		case 0x2A: {
			instr.opcode = 0x2A;
			instr.mnemonic = "ROL";
			instr.length = 1;
			instr.mode = accumulator;
			instr.callback = ROL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROL - mode = 'abs'
	*/
		case 0x2E: {
			instr.opcode = 0x2E;
			instr.mnemonic = "ROL";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = ROL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROL - mode = 'dir,X'
	*/
		case 0x36: {
			instr.opcode = 0x36;
			instr.mnemonic = "ROL";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = ROL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: ROL - mode = 'abs,X'
	*/
		case 0x3E: {
			instr.opcode = 0x3E;
			instr.mnemonic = "ROL";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.callback = ROL_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
				std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}