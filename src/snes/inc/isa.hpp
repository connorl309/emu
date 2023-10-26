#ifndef SNES_ISA_HPP
#define SNES_ISA_HPP

#include "snes_common.hpp"
#include "snes_memory.hpp"
#include <bitset>

// http://www.6502.org/tutorials/65c816opcodes.html
namespace snes_cpu {

/**
 * Note: the 65c816 is little endian
*/

/**
 * CPU mode
 * emulation modes are 8bA and 8bI
*/
typedef enum {
    binary_emu,
    binary_native_8bA_8bI,
    binary_native_8bA_16bI,
    binary_native_16bA_8bI,
    binary_native_16bA_16bI,
    decimal_emu,
    decimal_native_8bA_8bI,
    decimal_native_8bA_16bI,
    decimal_native_16bA_8bI,
    decimal_native_16bA_16bI,
    _NUM_CPU_MODES
} cpu_mode;

typedef enum {
    /*
        N flag set when result is negative (MSB depending on data width)
    */
    n_flag,
    /*
        V flag set when overflow detected
    */
    v_flag,
    /*
        When M = 1, accumulator and memory width is 16 bits.
        When M = 0, accumulator and memory width is 8 bits.
    */
    m_flag,
    /*
        In native mode (X flag):
        - X = 0: index register is 16 bits
        - X = 1: index register is 8 bits.
                * The high bytes of the X and Y registers are forced 0.

        In emulation mode (B flag):
        - distinguishes between IRQ (hardware) from BRK (software) interrupts.
    */
    x_b_flag,
    /*
        When D = 0:
        - ADC/SBC instructions perform binary arithmatic
        When D = 1:
        - ADC/SBC instructions perform BCD arithmatic
    */
    d_flag,
    /*
        When I = 0:
        - interrupts are enabled
        When I = 1:
        - interrupts are disabled
    */
    i_flag,
    /*
        Z flag set when result is zero
    */
    z_flag,
    /*
        C flag is set when there is a carry detected
    */
    c_flag,
    /*
        E = 0 if running in native mode
        E = 1 if running in emulation mode. This forces M flag = X flag = 1, and high byte of stack pointer to 0x01.
    */
    e_flag,
    PSR_FLAGS
} _flags;
/**
 * List of registers supported by the 65c816
*/
typedef struct {
    uint16_t accumulator; // has a low/hi byte
    uint8_t data_bank_reg;
    uint16_t direct_reg; // has a low/hi byte
    uint8_t program_bank_reg;
    uint16_t program_counter;
    std::bitset<9> psr; // contains 9 flags + E flag which technically isnt in the PSR but whatever
    uint16_t sp;
    uint16_t x_index_reg; // has a low/hi byte
    uint16_t y_index_reg; // has a low/hi byte
} cpu_registers;

/**
 * Addressing modes supported by the 65c816
*/
typedef enum {

} addressing_modes;

typedef struct {
    uint8_t opcode;
    uint8_t length;
    uint8_t cycles;

} instruction;

/**
 * 
 * 5.1.3 NOTATION
 * 
Page boundary wrapping only occurs in emulation mode, and only for "old" instructions and addressing modes, 
i.e. instructions and addressing modes that are available on the 65C02. Page boundary wrapping only occurs in the following situations:
A. When the DL register is $00 (and in emulation mode -- both conditions must be met), the direct page wraps at a page boundary
B. In emulation mode, the stack wraps at the page 1 boundary
*/


}

#endif