#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction LDX_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: LDX - mode = 'imm'
	*/
		case 0xA2: {
			instr.opcode = 0xA2;
			instr.mnemonic = "LDX";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.callback = LDX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDX - mode = 'dir'
	*/
		case 0xA6: {
			instr.opcode = 0xA6;
			instr.mnemonic = "LDX";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = LDX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDX - mode = 'abs'
	*/
		case 0xAE: {
			instr.opcode = 0xAE;
			instr.mnemonic = "LDX";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = LDX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDX - mode = 'dir,Y'
	*/
		case 0xB6: {
			instr.opcode = 0xB6;
			instr.mnemonic = "LDX";
			instr.length = 2;
			instr.mode = direct_y;
			instr.callback = LDX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: LDX - mode = 'abs,Y'
	*/
		case 0xBE: {
			instr.opcode = 0xBE;
			instr.mnemonic = "LDX";
			instr.length = 3;
			instr.mode = absolute_y;
			instr.callback = LDX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}