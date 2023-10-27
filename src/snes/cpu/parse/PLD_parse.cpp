#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction PLD_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: PLD - mode = 'imp'
	*/
		case 0x2B: {
			instr.opcode = 0x2B;
			instr.mnemonic = "PLD";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = PLD_execute;
			instr.flags_set = {
				std::pair(n_flag, "*"), // PLD instruction sets N flag to * flag value
				std::pair(z_flag, "*"), // PLD instruction sets Z flag to * flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}