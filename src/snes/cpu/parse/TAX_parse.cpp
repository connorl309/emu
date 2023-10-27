#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction TAX_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: TAX - mode = 'imp'
	*/
		case 0xAA: {
			instr.opcode = 0xAA;
			instr.mnemonic = "TAX";
			instr.length = 1;
			instr.mode = implied;
			instr.flags_set = {
				std::pair(n_flag, "x"), // TAX instruction sets N flag to X flag value
				std::pair(z_flag, "x"), // TAX instruction sets Z flag to X flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}