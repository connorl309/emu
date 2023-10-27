#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction TRB_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: TRB - mode = 'dir'
	*/
		case 0x14: {
			instr.opcode = 0x14;
			instr.mnemonic = "TRB";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
				std::pair(z_flag, "m"), // TRB instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: TRB - mode = 'abs'
	*/
		case 0x1C: {
			instr.opcode = 0x1C;
			instr.mnemonic = "TRB";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
				std::pair(z_flag, "m"), // TRB instruction sets Z flag to M flag value
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	}
	return instr;
	}
}