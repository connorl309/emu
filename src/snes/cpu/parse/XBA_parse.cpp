#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction XBA_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: XBA - mode = 'imp'
	*/
		case 0xEB: {
			instr.opcode = 0xEB;
			instr.mnemonic = "XBA";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(n_flag, "*"), // XBA instruction sets N flag to * flag value
				std::pair(z_flag, "*"), // XBA instruction sets Z flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}