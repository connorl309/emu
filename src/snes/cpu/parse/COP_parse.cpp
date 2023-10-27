#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction COP_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: COP - mode = 'imm'
	*/
		case 0x02: {
			instr.opcode = 0x02;
			instr.mnemonic = "COP";
			instr.length = 2;
			instr.mode = immediate;
			instr.flags_set = {
				std::pair(d_flag, "0"), // COP instruction sets D flag to 0 flag value
				std::pair(i_flag, "1"), // COP instruction sets I flag to 1 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}