#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction STX_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: STX - mode = 'dir'
	*/
		case 0x86: {
			instr.opcode = 0x86;
			instr.mnemonic = "STX";
			instr.length = 2;
			instr.mode = direct;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STX - mode = 'abs'
	*/
		case 0x8E: {
			instr.opcode = 0x8E;
			instr.mnemonic = "STX";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: STX - mode = 'dir,Y'
	*/
		case 0x96: {
			instr.opcode = 0x96;
			instr.mnemonic = "STX";
			instr.length = 2;
			instr.mode = direct_y;
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