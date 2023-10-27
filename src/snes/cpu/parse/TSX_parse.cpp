#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction TSX_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: TSX - mode = 'imp'
	*/
		case 0xBA: {
			instr.opcode = 0xBA;
			instr.mnemonic = "TSX";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(n_flag, "x"), // TSX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // TSX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}