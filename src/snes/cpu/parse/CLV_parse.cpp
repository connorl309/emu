#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction CLV_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: CLV - mode = 'imp'
	*/
		case 0xB8: {
			instr.opcode = 0xB8;
			instr.mnemonic = "CLV";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = CLV_execute;
			instr.flags_set = {
				std::pair(v_flag, "0"), // CLV instruction sets V flag to 0 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}