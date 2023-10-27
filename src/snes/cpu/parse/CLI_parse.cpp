#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction CLI_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: CLI - mode = 'imp'
	*/
		case 0x58: {
			instr.opcode = 0x58;
			instr.mnemonic = "CLI";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = CLI_execute;
			instr.flags_set = {
				std::pair(i_flag, "0"), // CLI instruction sets I flag to 0 flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}