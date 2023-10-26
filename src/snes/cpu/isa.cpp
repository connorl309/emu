#include "../inc/isa.hpp"

namespace snes_cpu {
    /**
     * Parse an instruction from a starting memory address
     * This is a beefy function.
    */
    instruction parseInstruction(uint8_t* memory_address, const cpu_registers& regfile) {
        snes_cpu::instruction instr;

        switch( *memory_address )
        {
            // ADC
            case 0x61: {
                instr.length = 2;
                instr.mnemonic = "ADC";
                instr.mode = direct_x_paren;
                instr.data.push_back(*(memory_address + 1));
                
            }
        }

        return instr;
    }
}
