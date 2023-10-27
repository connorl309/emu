#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction CPX_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: CPX - mode = 'imm'
	*/
		case 0xE0: {
			instr.opcode = 0xE0;
			instr.mnemonic = "CPX";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.callback = CPX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // CPX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // CPX instruction sets Z flag to X flag value
				std::pair(c_flag, "x"), // CPX instruction sets C flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CPX - mode = 'dir'
	*/
		case 0xE4: {
			instr.opcode = 0xE4;
			instr.mnemonic = "CPX";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = CPX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // CPX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // CPX instruction sets Z flag to X flag value
				std::pair(c_flag, "x"), // CPX instruction sets C flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CPX - mode = 'abs'
	*/
		case 0xEC: {
			instr.opcode = 0xEC;
			instr.mnemonic = "CPX";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = CPX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // CPX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // CPX instruction sets Z flag to X flag value
				std::pair(c_flag, "x"), // CPX instruction sets C flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}