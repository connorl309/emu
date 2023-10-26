#include "../inc/isa.hpp"

namespace snes_cpu {
    /**
     * Parse an instruction from a starting memory address
     * This is a beefy function.
    */
    instruction parseInstruction(uint8_t* memory_address, const cpu_registers& regfile) {
        snes_cpu::instruction instr;
        const uint8_t m_val = regfile.psr[m_flag];

        switch( *memory_address )
        {
            /*
                Instruction: ADC - mode = '(dir,X)'
            */
            case 0x61: {
                instr.opcode = 0x61;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'stk,S'
            */
            case 0x63: {
                instr.opcode = 0x63;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'dir'
            */
            case 0x65: {
                instr.opcode = 0x65;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = '[dir]'
            */
            case 0x67: {
                instr.opcode = 0x67;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'imm'
            */
            case 0x69: {
                instr.opcode = 0x69;
                instr.mnemonic = "ADC";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'abs'
            */
            case 0x6D: {
                instr.opcode = 0x6D;
                instr.mnemonic = "ADC";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'long'
            */
            case 0x6F: {
                instr.opcode = 0x6F;
                instr.mnemonic = "ADC";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = '(dir),Y'
            */
            case 0x71: {
                instr.opcode = 0x71;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = '(dir)'
            */
            case 0x72: {
                instr.opcode = 0x72;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = '(stk,S),Y'
            */
            case 0x73: {
                instr.opcode = 0x73;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'dir,X'
            */
            case 0x75: {
                instr.opcode = 0x75;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = '[dir],Y'
            */
            case 0x77: {
                instr.opcode = 0x77;
                instr.mnemonic = "ADC";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'abs,Y'
            */
            case 0x79: {
                instr.opcode = 0x79;
                instr.mnemonic = "ADC";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'abs,X'
            */
            case 0x7D: {
                instr.opcode = 0x7D;
                instr.mnemonic = "ADC";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ADC - mode = 'long,X'
            */
            case 0x7F: {
                instr.opcode = 0x7F;
                instr.mnemonic = "ADC";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ADC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // ADC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // ADC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ADC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = '(dir,X)'
            */
            case 0xE1: {
                instr.opcode = 0xE1;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'stk,S'
            */
            case 0xE3: {
                instr.opcode = 0xE3;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'dir'
            */
            case 0xE5: {
                instr.opcode = 0xE5;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = '[dir]'
            */
            case 0xE7: {
                instr.opcode = 0xE7;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'imm'
            */
            case 0xE9: {
                instr.opcode = 0xE9;
                instr.mnemonic = "SBC";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'abs'
            */
            case 0xED: {
                instr.opcode = 0xED;
                instr.mnemonic = "SBC";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'long'
            */
            case 0xEF: {
                instr.opcode = 0xEF;
                instr.mnemonic = "SBC";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = '(dir),Y'
            */
            case 0xF1: {
                instr.opcode = 0xF1;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = '(dir)'
            */
            case 0xF2: {
                instr.opcode = 0xF2;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = '(stk,S),Y'
            */
            case 0xF3: {
                instr.opcode = 0xF3;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'dir,X'
            */
            case 0xF5: {
                instr.opcode = 0xF5;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = '[dir],Y'
            */
            case 0xF7: {
                instr.opcode = 0xF7;
                instr.mnemonic = "SBC";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'abs,Y'
            */
            case 0xF9: {
                instr.opcode = 0xF9;
                instr.mnemonic = "SBC";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'abs,X'
            */
            case 0xFD: {
                instr.opcode = 0xFD;
                instr.mnemonic = "SBC";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SBC - mode = 'long,X'
            */
            case 0xFF: {
                instr.opcode = 0xFF;
                instr.mnemonic = "SBC";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // SBC instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // SBC instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // SBC instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // SBC instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = '(dir,X)'
            */
            case 0xC1: {
                instr.opcode = 0xC1;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'stk,S'
            */
            case 0xC3: {
                instr.opcode = 0xC3;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'dir'
            */
            case 0xC5: {
                instr.opcode = 0xC5;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = '[dir]'
            */
            case 0xC7: {
                instr.opcode = 0xC7;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'imm'
            */
            case 0xC9: {
                instr.opcode = 0xC9;
                instr.mnemonic = "CMP";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'abs'
            */
            case 0xCD: {
                instr.opcode = 0xCD;
                instr.mnemonic = "CMP";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'long'
            */
            case 0xCF: {
                instr.opcode = 0xCF;
                instr.mnemonic = "CMP";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = '(dir),Y'
            */
            case 0xD1: {
                instr.opcode = 0xD1;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = '(dir)'
            */
            case 0xD2: {
                instr.opcode = 0xD2;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = '(stk,S),Y'
            */
            case 0xD3: {
                instr.opcode = 0xD3;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'dir,X'
            */
            case 0xD5: {
                instr.opcode = 0xD5;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = '[dir],Y'
            */
            case 0xD7: {
                instr.opcode = 0xD7;
                instr.mnemonic = "CMP";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'abs,Y'
            */
            case 0xD9: {
                instr.opcode = 0xD9;
                instr.mnemonic = "CMP";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'abs,X'
            */
            case 0xDD: {
                instr.opcode = 0xDD;
                instr.mnemonic = "CMP";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CMP - mode = 'long,X'
            */
            case 0xDF: {
                instr.opcode = 0xDF;
                instr.mnemonic = "CMP";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // CMP instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // CMP instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // CMP instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CPX - mode = 'imm'
            */
            case 0xE0: {
                instr.opcode = 0xE0;
                instr.mnemonic = "CPX";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // CPX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // CPX instruction sets Z flag to X flag value
                    std::pair(c_flag, "x"), // CPX instruction sets C flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CPX - mode = 'dir'
            */
            case 0xE4: {
                instr.opcode = 0xE4;
                instr.mnemonic = "CPX";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // CPX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // CPX instruction sets Z flag to X flag value
                    std::pair(c_flag, "x"), // CPX instruction sets C flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CPX - mode = 'abs'
            */
            case 0xEC: {
                instr.opcode = 0xEC;
                instr.mnemonic = "CPX";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // CPX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // CPX instruction sets Z flag to X flag value
                    std::pair(c_flag, "x"), // CPX instruction sets C flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CPY - mode = 'imm'
            */
            case 0xC0: {
                instr.opcode = 0xC0;
                instr.mnemonic = "CPY";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // CPY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // CPY instruction sets Z flag to X flag value
                    std::pair(c_flag, "x"), // CPY instruction sets C flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CPY - mode = 'dir'
            */
            case 0xC4: {
                instr.opcode = 0xC4;
                instr.mnemonic = "CPY";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // CPY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // CPY instruction sets Z flag to X flag value
                    std::pair(c_flag, "x"), // CPY instruction sets C flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CPY - mode = 'abs'
            */
            case 0xCC: {
                instr.opcode = 0xCC;
                instr.mnemonic = "CPY";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // CPY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // CPY instruction sets Z flag to X flag value
                    std::pair(c_flag, "x"), // CPY instruction sets C flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: DEC - mode = 'acc'
            */
            case 0x3A: {
                instr.opcode = 0x3A;
                instr.mnemonic = "DEC";
                instr.length = 1 - m_val;
                instr.mode = accumulator;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: DEC - mode = 'dir'
            */
            case 0xC6: {
                instr.opcode = 0xC6;
                instr.mnemonic = "DEC";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: DEC - mode = 'abs'
            */
            case 0xCE: {
                instr.opcode = 0xCE;
                instr.mnemonic = "DEC";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: DEC - mode = 'dir,X'
            */
            case 0xD6: {
                instr.opcode = 0xD6;
                instr.mnemonic = "DEC";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: DEC - mode = 'abs,X'
            */
            case 0xDE: {
                instr.opcode = 0xDE;
                instr.mnemonic = "DEC";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // DEC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // DEC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: DEX - mode = 'imp'
            */
            case 0xCA: {
                instr.opcode = 0xCA;
                instr.mnemonic = "DEX";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // DEX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // DEX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: DEY - mode = 'imp'
            */
            case 0x88: {
                instr.opcode = 0x88;
                instr.mnemonic = "DEY";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // DEY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // DEY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: INC - mode = 'acc'
            */
            case 0x1A: {
                instr.opcode = 0x1A;
                instr.mnemonic = "INC";
                instr.length = 1 - m_val;
                instr.mode = accumulator;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: INC - mode = 'dir'
            */
            case 0xE6: {
                instr.opcode = 0xE6;
                instr.mnemonic = "INC";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: INC - mode = 'abs'
            */
            case 0xEE: {
                instr.opcode = 0xEE;
                instr.mnemonic = "INC";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: INC - mode = 'dir,X'
            */
            case 0xF6: {
                instr.opcode = 0xF6;
                instr.mnemonic = "INC";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: INC - mode = 'abs,X'
            */
            case 0xFE: {
                instr.opcode = 0xFE;
                instr.mnemonic = "INC";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // INC instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // INC instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: INX - mode = 'imp'
            */
            case 0xE8: {
                instr.opcode = 0xE8;
                instr.mnemonic = "INX";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // INX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // INX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: INY - mode = 'imp'
            */
            case 0xC8: {
                instr.opcode = 0xC8;
                instr.mnemonic = "INY";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // INY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // INY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = '(dir,X)'
            */
            case 0x21: {
                instr.opcode = 0x21;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'stk,S'
            */
            case 0x23: {
                instr.opcode = 0x23;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'dir'
            */
            case 0x25: {
                instr.opcode = 0x25;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = '[dir]'
            */
            case 0x27: {
                instr.opcode = 0x27;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'imm'
            */
            case 0x29: {
                instr.opcode = 0x29;
                instr.mnemonic = "AND";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'abs'
            */
            case 0x2D: {
                instr.opcode = 0x2D;
                instr.mnemonic = "AND";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'long'
            */
            case 0x2F: {
                instr.opcode = 0x2F;
                instr.mnemonic = "AND";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = '(dir),Y'
            */
            case 0x31: {
                instr.opcode = 0x31;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = '(dir)'
            */
            case 0x32: {
                instr.opcode = 0x32;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = '(stk,S),Y'
            */
            case 0x33: {
                instr.opcode = 0x33;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'dir,X'
            */
            case 0x35: {
                instr.opcode = 0x35;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = '[dir],Y'
            */
            case 0x37: {
                instr.opcode = 0x37;
                instr.mnemonic = "AND";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'abs,Y'
            */
            case 0x39: {
                instr.opcode = 0x39;
                instr.mnemonic = "AND";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'abs,X'
            */
            case 0x3D: {
                instr.opcode = 0x3D;
                instr.mnemonic = "AND";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: AND - mode = 'long,X'
            */
            case 0x3F: {
                instr.opcode = 0x3F;
                instr.mnemonic = "AND";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // AND instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // AND instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = '(dir,X)'
            */
            case 0x41: {
                instr.opcode = 0x41;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'stk,S'
            */
            case 0x43: {
                instr.opcode = 0x43;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'dir'
            */
            case 0x45: {
                instr.opcode = 0x45;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = '[dir]'
            */
            case 0x47: {
                instr.opcode = 0x47;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'imm'
            */
            case 0x49: {
                instr.opcode = 0x49;
                instr.mnemonic = "EOR";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'abs'
            */
            case 0x4D: {
                instr.opcode = 0x4D;
                instr.mnemonic = "EOR";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'long'
            */
            case 0x4F: {
                instr.opcode = 0x4F;
                instr.mnemonic = "EOR";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = '(dir),Y'
            */
            case 0x51: {
                instr.opcode = 0x51;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = '(dir)'
            */
            case 0x52: {
                instr.opcode = 0x52;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = '(stk,S),Y'
            */
            case 0x53: {
                instr.opcode = 0x53;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'dir,X'
            */
            case 0x55: {
                instr.opcode = 0x55;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = '[dir],Y'
            */
            case 0x57: {
                instr.opcode = 0x57;
                instr.mnemonic = "EOR";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'abs,Y'
            */
            case 0x59: {
                instr.opcode = 0x59;
                instr.mnemonic = "EOR";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'abs,X'
            */
            case 0x5D: {
                instr.opcode = 0x5D;
                instr.mnemonic = "EOR";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: EOR - mode = 'long,X'
            */
            case 0x5F: {
                instr.opcode = 0x5F;
                instr.mnemonic = "EOR";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // EOR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // EOR instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = '(dir,X)'
            */
            case 0x01: {
                instr.opcode = 0x01;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'stk,S'
            */
            case 0x03: {
                instr.opcode = 0x03;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'dir'
            */
            case 0x05: {
                instr.opcode = 0x05;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = '[dir]'
            */
            case 0x07: {
                instr.opcode = 0x07;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'imm'
            */
            case 0x09: {
                instr.opcode = 0x09;
                instr.mnemonic = "ORA";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'abs'
            */
            case 0x0D: {
                instr.opcode = 0x0D;
                instr.mnemonic = "ORA";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'long'
            */
            case 0x0F: {
                instr.opcode = 0x0F;
                instr.mnemonic = "ORA";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = '(dir),Y'
            */
            case 0x11: {
                instr.opcode = 0x11;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = '(dir)'
            */
            case 0x12: {
                instr.opcode = 0x12;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = '(stk,S),Y'
            */
            case 0x13: {
                instr.opcode = 0x13;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'dir,X'
            */
            case 0x15: {
                instr.opcode = 0x15;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = '[dir],Y'
            */
            case 0x17: {
                instr.opcode = 0x17;
                instr.mnemonic = "ORA";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'abs,Y'
            */
            case 0x19: {
                instr.opcode = 0x19;
                instr.mnemonic = "ORA";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'abs,X'
            */
            case 0x1D: {
                instr.opcode = 0x1D;
                instr.mnemonic = "ORA";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ORA - mode = 'long,X'
            */
            case 0x1F: {
                instr.opcode = 0x1F;
                instr.mnemonic = "ORA";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ORA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ORA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BIT - mode = 'dir'
            */
            case 0x24: {
                instr.opcode = 0x24;
                instr.mnemonic = "BIT";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BIT - mode = 'abs'
            */
            case 0x2C: {
                instr.opcode = 0x2C;
                instr.mnemonic = "BIT";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BIT - mode = 'dir,X'
            */
            case 0x34: {
                instr.opcode = 0x34;
                instr.mnemonic = "BIT";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BIT - mode = 'abs,X'
            */
            case 0x3C: {
                instr.opcode = 0x3C;
                instr.mnemonic = "BIT";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // BIT instruction sets N flag to M flag value
                    std::pair(v_flag, "m"), // BIT instruction sets V flag to M flag value
                    std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BIT - mode = 'imm'
            */
            case 0x89: {
                instr.opcode = 0x89;
                instr.mnemonic = "BIT";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(z_flag, "m"), // BIT instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TRB - mode = 'dir'
            */
            case 0x14: {
                instr.opcode = 0x14;
                instr.mnemonic = "TRB";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(z_flag, "m"), // TRB instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TRB - mode = 'abs'
            */
            case 0x1C: {
                instr.opcode = 0x1C;
                instr.mnemonic = "TRB";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(z_flag, "m"), // TRB instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TSB - mode = 'dir'
            */
            case 0x04: {
                instr.opcode = 0x04;
                instr.mnemonic = "TSB";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(z_flag, "m"), // TSB instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TSB - mode = 'abs'
            */
            case 0x0C: {
                instr.opcode = 0x0C;
                instr.mnemonic = "TSB";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(z_flag, "m"), // TSB instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ASL - mode = 'dir'
            */
            case 0x06: {
                instr.opcode = 0x06;
                instr.mnemonic = "ASL";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ASL - mode = 'acc'
            */
            case 0x0A: {
                instr.opcode = 0x0A;
                instr.mnemonic = "ASL";
                instr.length = 1 - m_val;
                instr.mode = accumulator;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ASL - mode = 'abs'
            */
            case 0x0E: {
                instr.opcode = 0x0E;
                instr.mnemonic = "ASL";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ASL - mode = 'dir,X'
            */
            case 0x16: {
                instr.opcode = 0x16;
                instr.mnemonic = "ASL";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ASL - mode = 'abs,X'
            */
            case 0x1E: {
                instr.opcode = 0x1E;
                instr.mnemonic = "ASL";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ASL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ASL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ASL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LSR - mode = 'dir'
            */
            case 0x46: {
                instr.opcode = 0x46;
                instr.mnemonic = "LSR";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
                    std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LSR - mode = 'acc'
            */
            case 0x4A: {
                instr.opcode = 0x4A;
                instr.mnemonic = "LSR";
                instr.length = 1 - m_val;
                instr.mode = accumulator;
                instr.flags_set = {
                    std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
                    std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LSR - mode = 'abs'
            */
            case 0x4E: {
                instr.opcode = 0x4E;
                instr.mnemonic = "LSR";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
                    std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LSR - mode = 'dir,X'
            */
            case 0x56: {
                instr.opcode = 0x56;
                instr.mnemonic = "LSR";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
                    std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LSR - mode = 'abs,X'
            */
            case 0x5E: {
                instr.opcode = 0x5E;
                instr.mnemonic = "LSR";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "0"), // LSR instruction sets N flag to 0 flag value
                    std::pair(z_flag, "m"), // LSR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // LSR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROL - mode = 'dir'
            */
            case 0x26: {
                instr.opcode = 0x26;
                instr.mnemonic = "ROL";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROL - mode = 'acc'
            */
            case 0x2A: {
                instr.opcode = 0x2A;
                instr.mnemonic = "ROL";
                instr.length = 1 - m_val;
                instr.mode = accumulator;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROL - mode = 'abs'
            */
            case 0x2E: {
                instr.opcode = 0x2E;
                instr.mnemonic = "ROL";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROL - mode = 'dir,X'
            */
            case 0x36: {
                instr.opcode = 0x36;
                instr.mnemonic = "ROL";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROL - mode = 'abs,X'
            */
            case 0x3E: {
                instr.opcode = 0x3E;
                instr.mnemonic = "ROL";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROL instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROL instruction sets Z flag to M flag value
                    std::pair(c_flag, "m"), // ROL instruction sets C flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROR - mode = 'dir'
            */
            case 0x66: {
                instr.opcode = 0x66;
                instr.mnemonic = "ROR";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROR - mode = 'acc'
            */
            case 0x6A: {
                instr.opcode = 0x6A;
                instr.mnemonic = "ROR";
                instr.length = 1 - m_val;
                instr.mode = accumulator;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROR - mode = 'abs'
            */
            case 0x6E: {
                instr.opcode = 0x6E;
                instr.mnemonic = "ROR";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROR - mode = 'dir,X'
            */
            case 0x76: {
                instr.opcode = 0x76;
                instr.mnemonic = "ROR";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: ROR - mode = 'abs,X'
            */
            case 0x7E: {
                instr.opcode = 0x7E;
                instr.mnemonic = "ROR";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // ROR instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // ROR instruction sets Z flag to M flag value
                    std::pair(c_flag, "*"), // ROR instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BCC - mode = 'rel8'
            */
            case 0x90: {
                instr.opcode = 0x90;
                instr.mnemonic = "BCC";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BCS - mode = 'rel8'
            */
            case 0xB0: {
                instr.opcode = 0xB0;
                instr.mnemonic = "BCS";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BEQ - mode = 'rel8'
            */
            case 0xF0: {
                instr.opcode = 0xF0;
                instr.mnemonic = "BEQ";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BMI - mode = 'rel8'
            */
            case 0x30: {
                instr.opcode = 0x30;
                instr.mnemonic = "BMI";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BNE - mode = 'rel8'
            */
            case 0xD0: {
                instr.opcode = 0xD0;
                instr.mnemonic = "BNE";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BPL - mode = 'rel8'
            */
            case 0x10: {
                instr.opcode = 0x10;
                instr.mnemonic = "BPL";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BRA - mode = 'rel8'
            */
            case 0x80: {
                instr.opcode = 0x80;
                instr.mnemonic = "BRA";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BVC - mode = 'rel8'
            */
            case 0x50: {
                instr.opcode = 0x50;
                instr.mnemonic = "BVC";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BVS - mode = 'rel8'
            */
            case 0x70: {
                instr.opcode = 0x70;
                instr.mnemonic = "BVS";
                instr.length = 2 - m_val;
                instr.mode = rel8;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BRL - mode = 'rel16'
            */
            case 0x82: {
                instr.opcode = 0x82;
                instr.mnemonic = "BRL";
                instr.length = 3 - m_val;
                instr.mode = rel16;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JMP - mode = 'abs'
            */
            case 0x4C: {
                instr.opcode = 0x4C;
                instr.mnemonic = "JMP";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JMP - mode = 'long'
            */
            case 0x5C: {
                instr.opcode = 0x5C;
                instr.mnemonic = "JMP";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JMP - mode = '(abs)'
            */
            case 0x6C: {
                instr.opcode = 0x6C;
                instr.mnemonic = "JMP";
                instr.length = 3 - m_val;
                instr.mode = absolute_paren;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JMP - mode = '(abs,X)'
            */
            case 0x7C: {
                instr.opcode = 0x7C;
                instr.mnemonic = "JMP";
                instr.length = 3 - m_val;
                instr.mode = absolute_x_paren;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JMP - mode = '[abs]'
            */
            case 0xDC: {
                instr.opcode = 0xDC;
                instr.mnemonic = "JMP";
                instr.length = 3 - m_val;
                instr.mode = absolute_bracket;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JSL - mode = 'long'
            */
            case 0x22: {
                instr.opcode = 0x22;
                instr.mnemonic = "JSL";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JSR - mode = 'abs'
            */
            case 0x20: {
                instr.opcode = 0x20;
                instr.mnemonic = "JSR";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: JSR - mode = '(abs,X)'
            */
            case 0xFC: {
                instr.opcode = 0xFC;
                instr.mnemonic = "JSR";
                instr.length = 3 - m_val;
                instr.mode = absolute_x_paren;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: RTL - mode = 'imp'
            */
            case 0x6B: {
                instr.opcode = 0x6B;
                instr.mnemonic = "RTL";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: RTS - mode = 'imp'
            */
            case 0x60: {
                instr.opcode = 0x60;
                instr.mnemonic = "RTS";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: BRK - mode = 'imp'
            */
            case 0x00: {
                instr.opcode = 0x00;
                instr.mnemonic = "BRK";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(d_flag, "0"), // BRK instruction sets D flag to 0 flag value
                    std::pair(i_flag, "1"), // BRK instruction sets I flag to 1 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: COP - mode = 'imm'
            */
            case 0x02: {
                instr.opcode = 0x02;
                instr.mnemonic = "COP";
                instr.length = 2 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(d_flag, "0"), // COP instruction sets D flag to 0 flag value
                    std::pair(i_flag, "1"), // COP instruction sets I flag to 1 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: RTI - mode = 'imp'
            */
            case 0x40: {
                instr.opcode = 0x40;
                instr.mnemonic = "RTI";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // RTI instruction sets N flag to * flag value
                    std::pair(v_flag, "*"), // RTI instruction sets V flag to * flag value
                    std::pair(m_flag, "*"), // RTI instruction sets M flag to * flag value
                    std::pair(x_flag, "*"), // RTI instruction sets X flag to * flag value
                    std::pair(d_flag, "*"), // RTI instruction sets D flag to * flag value
                    std::pair(i_flag, "*"), // RTI instruction sets I flag to * flag value
                    std::pair(z_flag, "*"), // RTI instruction sets Z flag to * flag value
                    std::pair(c_flag, "*"), // RTI instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CLC - mode = 'imp'
            */
            case 0x18: {
                instr.opcode = 0x18;
                instr.mnemonic = "CLC";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(c_flag, "0"), // CLC instruction sets C flag to 0 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CLD - mode = 'imp'
            */
            case 0xD8: {
                instr.opcode = 0xD8;
                instr.mnemonic = "CLD";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(d_flag, "0"), // CLD instruction sets D flag to 0 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CLI - mode = 'imp'
            */
            case 0x58: {
                instr.opcode = 0x58;
                instr.mnemonic = "CLI";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(i_flag, "0"), // CLI instruction sets I flag to 0 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: CLV - mode = 'imp'
            */
            case 0xB8: {
                instr.opcode = 0xB8;
                instr.mnemonic = "CLV";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(v_flag, "0"), // CLV instruction sets V flag to 0 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SEC - mode = 'imp'
            */
            case 0x38: {
                instr.opcode = 0x38;
                instr.mnemonic = "SEC";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(c_flag, "1"), // SEC instruction sets C flag to 1 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SED - mode = 'imp'
            */
            case 0xF8: {
                instr.opcode = 0xF8;
                instr.mnemonic = "SED";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(d_flag, "1"), // SED instruction sets D flag to 1 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SEI - mode = 'imp'
            */
            case 0x78: {
                instr.opcode = 0x78;
                instr.mnemonic = "SEI";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(i_flag, "1"), // SEI instruction sets I flag to 1 flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: REP - mode = 'imm'
            */
            case 0xC2: {
                instr.opcode = 0xC2;
                instr.mnemonic = "REP";
                instr.length = 2 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // REP instruction sets N flag to * flag value
                    std::pair(v_flag, "*"), // REP instruction sets V flag to * flag value
                    std::pair(m_flag, "*"), // REP instruction sets M flag to * flag value
                    std::pair(x_flag, "*"), // REP instruction sets X flag to * flag value
                    std::pair(d_flag, "*"), // REP instruction sets D flag to * flag value
                    std::pair(i_flag, "*"), // REP instruction sets I flag to * flag value
                    std::pair(z_flag, "*"), // REP instruction sets Z flag to * flag value
                    std::pair(c_flag, "*"), // REP instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: SEP - mode = 'imm'
            */
            case 0xE2: {
                instr.opcode = 0xE2;
                instr.mnemonic = "SEP";
                instr.length = 2 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // SEP instruction sets N flag to * flag value
                    std::pair(v_flag, "*"), // SEP instruction sets V flag to * flag value
                    std::pair(m_flag, "*"), // SEP instruction sets M flag to * flag value
                    std::pair(x_flag, "*"), // SEP instruction sets X flag to * flag value
                    std::pair(d_flag, "*"), // SEP instruction sets D flag to * flag value
                    std::pair(i_flag, "*"), // SEP instruction sets I flag to * flag value
                    std::pair(z_flag, "*"), // SEP instruction sets Z flag to * flag value
                    std::pair(c_flag, "*"), // SEP instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = '(dir,X)'
            */
            case 0xA1: {
                instr.opcode = 0xA1;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'stk,S'
            */
            case 0xA3: {
                instr.opcode = 0xA3;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'dir'
            */
            case 0xA5: {
                instr.opcode = 0xA5;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = '[dir]'
            */
            case 0xA7: {
                instr.opcode = 0xA7;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'imm'
            */
            case 0xA9: {
                instr.opcode = 0xA9;
                instr.mnemonic = "LDA";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'abs'
            */
            case 0xAD: {
                instr.opcode = 0xAD;
                instr.mnemonic = "LDA";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'long'
            */
            case 0xAF: {
                instr.opcode = 0xAF;
                instr.mnemonic = "LDA";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = '(dir),Y'
            */
            case 0xB1: {
                instr.opcode = 0xB1;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = '(dir)'
            */
            case 0xB2: {
                instr.opcode = 0xB2;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = '(stk,S),Y'
            */
            case 0xB3: {
                instr.opcode = 0xB3;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'dir,X'
            */
            case 0xB5: {
                instr.opcode = 0xB5;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = '[dir],Y'
            */
            case 0xB7: {
                instr.opcode = 0xB7;
                instr.mnemonic = "LDA";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'abs,Y'
            */
            case 0xB9: {
                instr.opcode = 0xB9;
                instr.mnemonic = "LDA";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'abs,X'
            */
            case 0xBD: {
                instr.opcode = 0xBD;
                instr.mnemonic = "LDA";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDA - mode = 'long,X'
            */
            case 0xBF: {
                instr.opcode = 0xBF;
                instr.mnemonic = "LDA";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // LDA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // LDA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDX - mode = 'imm'
            */
            case 0xA2: {
                instr.opcode = 0xA2;
                instr.mnemonic = "LDX";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDX - mode = 'dir'
            */
            case 0xA6: {
                instr.opcode = 0xA6;
                instr.mnemonic = "LDX";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDX - mode = 'abs'
            */
            case 0xAE: {
                instr.opcode = 0xAE;
                instr.mnemonic = "LDX";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDX - mode = 'dir,Y'
            */
            case 0xB6: {
                instr.opcode = 0xB6;
                instr.mnemonic = "LDX";
                instr.length = 2 - m_val;
                instr.mode = direct_y;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDX - mode = 'abs,Y'
            */
            case 0xBE: {
                instr.opcode = 0xBE;
                instr.mnemonic = "LDX";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDY - mode = 'imm'
            */
            case 0xA0: {
                instr.opcode = 0xA0;
                instr.mnemonic = "LDY";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDY - mode = 'dir'
            */
            case 0xA4: {
                instr.opcode = 0xA4;
                instr.mnemonic = "LDY";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDY - mode = 'abs'
            */
            case 0xAC: {
                instr.opcode = 0xAC;
                instr.mnemonic = "LDY";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDY - mode = 'dir,X'
            */
            case 0xB4: {
                instr.opcode = 0xB4;
                instr.mnemonic = "LDY";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: LDY - mode = 'abs,X'
            */
            case 0xBC: {
                instr.opcode = 0xBC;
                instr.mnemonic = "LDY";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // LDY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // LDY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = '(dir,X)'
            */
            case 0x81: {
                instr.opcode = 0x81;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = direct_x_paren;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'stk,S'
            */
            case 0x83: {
                instr.opcode = 0x83;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = stack_s;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'dir'
            */
            case 0x85: {
                instr.opcode = 0x85;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = '[dir]'
            */
            case 0x87: {
                instr.opcode = 0x87;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'abs'
            */
            case 0x8D: {
                instr.opcode = 0x8D;
                instr.mnemonic = "STA";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'long'
            */
            case 0x8F: {
                instr.opcode = 0x8F;
                instr.mnemonic = "STA";
                instr.length = 4 - m_val;
                instr.mode = long_;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = '(dir),Y'
            */
            case 0x91: {
                instr.opcode = 0x91;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = direct_paren_y;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = '(dir)'
            */
            case 0x92: {
                instr.opcode = 0x92;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = direct_paren;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = '(stk,S),Y'
            */
            case 0x93: {
                instr.opcode = 0x93;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = stack_s_paren_y;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'dir,X'
            */
            case 0x95: {
                instr.opcode = 0x95;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = '[dir],Y'
            */
            case 0x97: {
                instr.opcode = 0x97;
                instr.mnemonic = "STA";
                instr.length = 2 - m_val;
                instr.mode = direct_bracket_y;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'abs,Y'
            */
            case 0x99: {
                instr.opcode = 0x99;
                instr.mnemonic = "STA";
                instr.length = 3 - m_val;
                instr.mode = absolute_y;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'abs,X'
            */
            case 0x9D: {
                instr.opcode = 0x9D;
                instr.mnemonic = "STA";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STA - mode = 'long,X'
            */
            case 0x9F: {
                instr.opcode = 0x9F;
                instr.mnemonic = "STA";
                instr.length = 4 - m_val;
                instr.mode = long_x;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STX - mode = 'dir'
            */
            case 0x86: {
                instr.opcode = 0x86;
                instr.mnemonic = "STX";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STX - mode = 'abs'
            */
            case 0x8E: {
                instr.opcode = 0x8E;
                instr.mnemonic = "STX";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STX - mode = 'dir,Y'
            */
            case 0x96: {
                instr.opcode = 0x96;
                instr.mnemonic = "STX";
                instr.length = 2 - m_val;
                instr.mode = direct_y;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STY - mode = 'dir'
            */
            case 0x84: {
                instr.opcode = 0x84;
                instr.mnemonic = "STY";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STY - mode = 'abs'
            */
            case 0x8C: {
                instr.opcode = 0x8C;
                instr.mnemonic = "STY";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STY - mode = 'dir,X'
            */
            case 0x94: {
                instr.opcode = 0x94;
                instr.mnemonic = "STY";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STZ - mode = 'dir'
            */
            case 0x64: {
                instr.opcode = 0x64;
                instr.mnemonic = "STZ";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STZ - mode = 'dir,X'
            */
            case 0x74: {
                instr.opcode = 0x74;
                instr.mnemonic = "STZ";
                instr.length = 2 - m_val;
                instr.mode = direct_x;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STZ - mode = 'abs'
            */
            case 0x9C: {
                instr.opcode = 0x9C;
                instr.mnemonic = "STZ";
                instr.length = 3 - m_val;
                instr.mode = absolute;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STZ - mode = 'abs,X'
            */
            case 0x9E: {
                instr.opcode = 0x9E;
                instr.mnemonic = "STZ";
                instr.length = 3 - m_val;
                instr.mode = absolute_x;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: MVN - mode = 'src,dest'
            */
            case 0x54: {
                instr.opcode = 0x54;
                instr.mnemonic = "MVN";
                instr.length = 3 - m_val;
                instr.mode = src_dest;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: MVP - mode = 'src,dest'
            */
            case 0x44: {
                instr.opcode = 0x44;
                instr.mnemonic = "MVP";
                instr.length = 3 - m_val;
                instr.mode = src_dest;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: NOP - mode = 'imp'
            */
            case 0xEA: {
                instr.opcode = 0xEA;
                instr.mnemonic = "NOP";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: WDM - mode = 'imm'
            */
            case 0x42: {
                instr.opcode = 0x42;
                instr.mnemonic = "WDM";
                instr.length = 2 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PEA - mode = 'imm'
            */
            case 0xF4: {
                instr.opcode = 0xF4;
                instr.mnemonic = "PEA";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PEI - mode = 'dir'
            */
            case 0xD4: {
                instr.opcode = 0xD4;
                instr.mnemonic = "PEI";
                instr.length = 2 - m_val;
                instr.mode = direct;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PER - mode = 'imm'
            */
            case 0x62: {
                instr.opcode = 0x62;
                instr.mnemonic = "PER";
                instr.length = 3 - m_val;
                instr.mode = immediate;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PHA - mode = 'imp'
            */
            case 0x48: {
                instr.opcode = 0x48;
                instr.mnemonic = "PHA";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PHX - mode = 'imp'
            */
            case 0xDA: {
                instr.opcode = 0xDA;
                instr.mnemonic = "PHX";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PHY - mode = 'imp'
            */
            case 0x5A: {
                instr.opcode = 0x5A;
                instr.mnemonic = "PHY";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PLA - mode = 'imp'
            */
            case 0x68: {
                instr.opcode = 0x68;
                instr.mnemonic = "PLA";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // PLA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // PLA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PLX - mode = 'imp'
            */
            case 0xFA: {
                instr.opcode = 0xFA;
                instr.mnemonic = "PLX";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // PLX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // PLX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PLY - mode = 'imp'
            */
            case 0x7A: {
                instr.opcode = 0x7A;
                instr.mnemonic = "PLY";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // PLY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // PLY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PHB - mode = 'imp'
            */
            case 0x8B: {
                instr.opcode = 0x8B;
                instr.mnemonic = "PHB";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PHD - mode = 'imp'
            */
            case 0x0B: {
                instr.opcode = 0x0B;
                instr.mnemonic = "PHD";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PHK - mode = 'imp'
            */
            case 0x4B: {
                instr.opcode = 0x4B;
                instr.mnemonic = "PHK";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PHP - mode = 'imp'
            */
            case 0x08: {
                instr.opcode = 0x08;
                instr.mnemonic = "PHP";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PLB - mode = 'imp'
            */
            case 0xAB: {
                instr.opcode = 0xAB;
                instr.mnemonic = "PLB";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // PLB instruction sets N flag to * flag value
                    std::pair(z_flag, "*"), // PLB instruction sets Z flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PLD - mode = 'imp'
            */
            case 0x2B: {
                instr.opcode = 0x2B;
                instr.mnemonic = "PLD";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // PLD instruction sets N flag to * flag value
                    std::pair(z_flag, "*"), // PLD instruction sets Z flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: PLP - mode = 'imp'
            */
            case 0x28: {
                instr.opcode = 0x28;
                instr.mnemonic = "PLP";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // PLP instruction sets N flag to * flag value
                    std::pair(v_flag, "*"), // PLP instruction sets V flag to * flag value
                    std::pair(m_flag, "*"), // PLP instruction sets M flag to * flag value
                    std::pair(x_flag, "*"), // PLP instruction sets X flag to * flag value
                    std::pair(d_flag, "*"), // PLP instruction sets D flag to * flag value
                    std::pair(i_flag, "*"), // PLP instruction sets I flag to * flag value
                    std::pair(z_flag, "*"), // PLP instruction sets Z flag to * flag value
                    std::pair(c_flag, "*"), // PLP instruction sets C flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: STP - mode = 'imp'
            */
            case 0xDB: {
                instr.opcode = 0xDB;
                instr.mnemonic = "STP";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: WAI - mode = 'imp'
            */
            case 0xCB: {
                instr.opcode = 0xCB;
                instr.mnemonic = "WAI";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TAX - mode = 'imp'
            */
            case 0xAA: {
                instr.opcode = 0xAA;
                instr.mnemonic = "TAX";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // TAX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // TAX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TAY - mode = 'imp'
            */
            case 0xA8: {
                instr.opcode = 0xA8;
                instr.mnemonic = "TAY";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // TAY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // TAY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TSX - mode = 'imp'
            */
            case 0xBA: {
                instr.opcode = 0xBA;
                instr.mnemonic = "TSX";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // TSX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // TSX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TXA - mode = 'imp'
            */
            case 0x8A: {
                instr.opcode = 0x8A;
                instr.mnemonic = "TXA";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // TXA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // TXA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TXS - mode = 'imp'
            */
            case 0x9A: {
                instr.opcode = 0x9A;
                instr.mnemonic = "TXS";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TXY - mode = 'imp'
            */
            case 0x9B: {
                instr.opcode = 0x9B;
                instr.mnemonic = "TXY";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // TXY instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // TXY instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TYA - mode = 'imp'
            */
            case 0x98: {
                instr.opcode = 0x98;
                instr.mnemonic = "TYA";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "m"), // TYA instruction sets N flag to M flag value
                    std::pair(z_flag, "m"), // TYA instruction sets Z flag to M flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TYX - mode = 'imp'
            */
            case 0xBB: {
                instr.opcode = 0xBB;
                instr.mnemonic = "TYX";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "x"), // TYX instruction sets N flag to X flag value
                    std::pair(z_flag, "x"), // TYX instruction sets Z flag to X flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TCD - mode = 'imp'
            */
            case 0x5B: {
                instr.opcode = 0x5B;
                instr.mnemonic = "TCD";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // TCD instruction sets N flag to * flag value
                    std::pair(z_flag, "*"), // TCD instruction sets Z flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TCS - mode = 'imp'
            */
            case 0x1B: {
                instr.opcode = 0x1B;
                instr.mnemonic = "TCS";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TDC - mode = 'imp'
            */
            case 0x7B: {
                instr.opcode = 0x7B;
                instr.mnemonic = "TDC";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // TDC instruction sets N flag to * flag value
                    std::pair(z_flag, "*"), // TDC instruction sets Z flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: TSC - mode = 'imp'
            */
            case 0x3B: {
                instr.opcode = 0x3B;
                instr.mnemonic = "TSC";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // TSC instruction sets N flag to * flag value
                    std::pair(z_flag, "*"), // TSC instruction sets Z flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: XBA - mode = 'imp'
            */
            case 0xEB: {
                instr.opcode = 0xEB;
                instr.mnemonic = "XBA";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(n_flag, "*"), // XBA instruction sets N flag to * flag value
                    std::pair(z_flag, "*"), // XBA instruction sets Z flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }
            /*
                Instruction: XCE - mode = 'imp'
            */
            case 0xFB: {
                instr.opcode = 0xFB;
                instr.mnemonic = "XCE";
                instr.length = 1 - m_val;
                instr.mode = implied;
                instr.flags_set = {
                    std::pair(c_flag, "*"), // XCE instruction sets C flag to * flag value
                    std::pair(e_flag, "*"), // XCE instruction sets E flag to * flag value
                };
                for (uint8_t i = 0; i < instr.length - m_val; i++) {
                    instr.data.push_back(*(memory_address + i + 1));
                }
            }

        }

        return instr;
    }
}
