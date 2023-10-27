#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction SEI_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: SEI - mode = 'imp'
	*/
		case 0x78: {
			instr.opcode = 0x78;
			instr.mnemonic = "SEI";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = SEI_execute;
			instr.flags_set = {
				std::pair(i_flag, "1"), // SEI instruction sets I flag to 1 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}