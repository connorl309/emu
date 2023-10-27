#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction LDY_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: LDY - mode = 'imm'
	*/
		case 0xA0: {
			instr.opcode = 0xA0;
			instr.mnemonic = "LDY";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.callback = LDY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDY - mode = 'dir'
	*/
		case 0xA4: {
			instr.opcode = 0xA4;
			instr.mnemonic = "LDY";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = LDY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDY - mode = 'abs'
	*/
		case 0xAC: {
			instr.opcode = 0xAC;
			instr.mnemonic = "LDY";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = LDY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDY - mode = 'dir,X'
	*/
		case 0xB4: {
			instr.opcode = 0xB4;
			instr.mnemonic = "LDY";
			instr.length = 2;
			instr.mode = direct_x;
			instr.callback = LDY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDY - mode = 'abs,X'
	*/
		case 0xBC: {
			instr.opcode = 0xBC;
			instr.mnemonic = "LDY";
			instr.length = 3;
			instr.mode = absolute_x;
			instr.callback = LDY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}