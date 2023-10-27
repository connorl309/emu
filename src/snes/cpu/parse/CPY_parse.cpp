#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction CPY_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: CPY - mode = 'imm'
	*/
		case 0xC0: {
			instr.opcode = 0xC0;
			instr.mnemonic = "CPY";
			instr.length = 3 - m_flag_val;
			instr.mode = immediate;
			instr.callback = CPY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // CPY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // CPY instruction sets Z flag to X flag value
				std::pair(c_flag, "x"), // CPY instruction sets C flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CPY - mode = 'dir'
	*/
		case 0xC4: {
			instr.opcode = 0xC4;
			instr.mnemonic = "CPY";
			instr.length = 2;
			instr.mode = direct;
			instr.callback = CPY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // CPY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // CPY instruction sets Z flag to X flag value
				std::pair(c_flag, "x"), // CPY instruction sets C flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: CPY - mode = 'abs'
	*/
		case 0xCC: {
			instr.opcode = 0xCC;
			instr.mnemonic = "CPY";
			instr.length = 3;
			instr.mode = absolute;
			instr.callback = CPY_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // CPY instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // CPY instruction sets Z flag to X flag value
				std::pair(c_flag, "x"), // CPY instruction sets C flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}