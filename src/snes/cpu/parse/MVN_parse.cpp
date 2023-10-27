#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction MVN_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: MVN - mode = 'src,dest'
	*/
		case 0x54: {
			instr.opcode = 0x54;
			instr.mnemonic = "MVN";
			instr.length = 3;
			instr.mode = src_dest;
			instr.callback = MVN_execute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}