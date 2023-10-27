#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction TYA_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: TYA - mode = 'imp'
	*/
		case 0x98: {
			instr.opcode = 0x98;
			instr.mnemonic = "TYA";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = TYA_execute;
			instr.flags_set = {
				std::pair(n_flag, "m"), // TYA instruction sets N flag to M flag value
				std::pair(z_flag, "m"), // TYA instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}