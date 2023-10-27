#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction TCD_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: TCD - mode = 'imp'
	*/
		case 0x5B: {
			instr.opcode = 0x5B;
			instr.mnemonic = "TCD";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = TCD_execute;
			instr.flags_set = {
				std::pair(n_flag, "*"), // TCD instruction sets N flag to * flag value
				std::pair(z_flag, "*"), // TCD instruction sets Z flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}