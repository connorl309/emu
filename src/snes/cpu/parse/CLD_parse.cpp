#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction CLD_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: CLD - mode = 'imp'
	*/
		case 0xD8: {
			instr.opcode = 0xD8;
			instr.mnemonic = "CLD";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = CLD_execute;
			instr.flags_set = {
				std::pair(d_flag, "0"), // CLD instruction sets D flag to 0 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}