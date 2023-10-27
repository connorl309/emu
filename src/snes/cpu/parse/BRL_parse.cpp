#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction BRL_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: BRL - mode = 'rel16'
	*/
		case 0x82: {
			instr.opcode = 0x82;
			instr.mnemonic = "BRL";
			instr.length = 3;
			instr.mode = rel16;
			instr.callback = BRL_execute;
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