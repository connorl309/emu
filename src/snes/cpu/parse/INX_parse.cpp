#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction INX_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: INX - mode = 'imp'
	*/
		case 0xE8: {
			instr.opcode = 0xE8;
			instr.mnemonic = "INX";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = INX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // INX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // INX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}