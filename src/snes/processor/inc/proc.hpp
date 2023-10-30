#ifndef _65C816_INC_HPP
#define _65C816_INC_HPP

#include <stdint.h>
#include <bitset>
#include <memory>
#include <assert.h>

#define MAX_MEM_SIZE ( 1 << 24 )

namespace WDC65816 {

// status flags
/**
 * M flag = 0: 16b accumulator
 * M flag = 1: 8b accumulator
 * 
 * X flag = 0: 16b X/Y regs
 * X flag = 1: 8b X/Y regs
 * 
 */
typedef enum {
    n, v, m, x, d, i, z, c, e, NUM_FLAGS
} flags;

// regfile struct
typedef struct {
    int16_t accumulator;
    uint16_t x, y;
    uint16_t d;
    uint16_t s;
    uint8_t dbr;
    uint8_t pbr; uint16_t pc;
} regfile_t;

class WDC65C816 {

private:
    regfile_t regfile;
    std::bitset<NUM_FLAGS> sr;
    std::unique_ptr<uint8_t[]> memory;
    inline uint32_t convert() { return (regfile.pbr << 16) + regfile.pc; }
public:
    WDC65C816() { 
        memory = std::make_unique<uint8_t[]>(MAX_MEM_SIZE);
    }
    ~WDC65C816() { delete[] memory.release(); memory.reset(); }
    inline const regfile_t& regs() { return regfile; }
    inline const uint8_t readByte(uint32_t addr) { return memory[addr]; }
    inline const uint16_t readWord(uint32_t addr) { return (memory[addr + 1] << 8) + memory[addr]; }
    inline void writeByte(uint32_t addr, uint8_t val) { memory[addr] = val; }
    inline uint8_t getFlag(flags f) { return sr[f]; }
    inline void setFlag(flags f, uint8_t val) { assert(val <= 1); sr[f] = val; }
    // Reads a byte AND increments PC
    uint8_t fetchByte() { uint8_t ret = readByte(convert()); regfile.pc++; return ret; }
    // Read a word AND increment PC
    uint16_t fetchWord() { uint16_t ret = readWord(convert()); regfile.pc += 2; return ret; }
};

}

#endif