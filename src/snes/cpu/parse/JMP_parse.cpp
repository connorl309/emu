#include "../../inc/isa.hpp"
#include "../../inc/isa_impl.hpp"
namespace snes_cpu {

instruction JMP_parse_instr(uint8_t* memory_address, uint8_t m_flag_val) {
	snes_cpu::instruction instr;

	switch ( *memory_address ) {

	/*
	Instruction: JMP - mode = 'abs'
	*/
		case 0x4C: {
			instr.opcode = 0x4C;
			instr.mnemonic = "JMP";
			instr.length = 3;
			instr.mode = absolute;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: JMP - mode = 'long'
	*/
		case 0x5C: {
			instr.opcode = 0x5C;
			instr.mnemonic = "JMP";
			instr.length = 4;
			instr.mode = long_;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: JMP - mode = '(abs)'
	*/
		case 0x6C: {
			instr.opcode = 0x6C;
			instr.mnemonic = "JMP";
			instr.length = 3;
			instr.mode = absolute_paren;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: JMP - mode = '(abs,X)'
	*/
		case 0x7C: {
			instr.opcode = 0x7C;
			instr.mnemonic = "JMP";
			instr.length = 3;
			instr.mode = absolute_x_paren;
			instr.flags_set = {
			};
			for (uint8_t i = 1; i < instr.length; i++) {
				instr.data.push_back(*(memory_address + i));
			}
		}
	/*
	Instruction: JMP - mode = '[abs]'
	*/
		case 0xDC: {
			instr.opcode = 0xDC;
			instr.mnemonic = "JMP";
			instr.length = 3;
			instr.mode = absolute_bracket;
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