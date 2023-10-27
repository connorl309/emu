#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction DEX_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: DEX - mode = 'imp'
	*/
		case 0xCA: {
			instr.opcode = 0xCA;
			instr.mnemonic = "DEX";
			instr.length = 1;
			instr.mode = implied;
			instr.callback = DEX_execute;
			instr.flags_set = {
				std::pair(n_flag, "x"), // DEX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // DEX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}