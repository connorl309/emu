#ifndef _65C816_INC_HPP
#define _65C816_INC_HPP

#include <stdint.h>
#include <bitset>

namespace WDC65816 {

// status flags
enum {
    n, v, m, x, d, i, z, c, e, NUM_FLAGS
} flags;

// regfile struct
struct {
    int16_t accumulator;
    uint16_t x, y;
    uint16_t d;
    uint16_t s;
    uint8_t dbr;
    uint8_t pbr; uint16_t pc;
    std::bitset<NUM_FLAGS> psr;
} registers;

}

#endif