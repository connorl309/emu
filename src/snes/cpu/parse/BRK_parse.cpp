#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction BRK_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: BRK - mode = 'imp'
	*/
		case 0x00: {
			instr.opcode = 0x00;
			instr.mnemonic = "BRK";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(d_flag, "0"), // BRK instruction sets D flag to 0 flag value
				std::pair(i_flag, "1"), // BRK instruction sets I flag to 1 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}