#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction TSB_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: TSB - mode = 'dir'
	*/
		case 0x04: {
			instr.opcode = 0x04;
			instr.mnemonic = "TSB";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(z_flag, "m"), // TSB instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: TSB - mode = 'abs'
	*/
		case 0x0C: {
			instr.opcode = 0x0C;
			instr.mnemonic = "TSB";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(z_flag, "m"), // TSB instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}