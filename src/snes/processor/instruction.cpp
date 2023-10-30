#include "inc/instruction.hpp"
#include "inc/proc.hpp"

#define IS_M(x) if ((x).getFlag(m))
#define IS_X(z) if ((z).getFlag(x))

namespace WDC65816
{

uint32_t PerformImplied (WDC65C816& cpu) {
    return -1; // No return value
}

uint32_t PerformImmediate (WDC65C816& cpu) {
    IS_M(cpu) {
        uint8_t val = cpu.fetchByte();
        return val;
    } else {
        uint8_t lo = cpu.fetchByte();
        uint8_t hi = cpu.fetchByte();
        return (hi << 8) + lo;
    }
}

uint32_t PerformRelative8 (WDC65C816& cpu) {
    uint16_t wrap = cpu.regs().pc + (int8_t)cpu.readByte(cpu.regs().pc);
    return (cpu.regs().pbr << 16) + wrap;
}
uint32_t PerformRelative16 (WDC65C816& cpu) {
    uint16_t wrap = cpu.regs().pc + (int16_t)cpu.readWord(cpu.regs().pc);
    return (cpu.regs().pbr << 16) + wrap;
}

uint32_t PerformDirect (WDC65C816& cpu) {
    uint16_t wrap = cpu.regs().d + cpu.fetchByte();
    return wrap;
}

uint32_t PerformDirectXIndexed (WDC65C816& cpu) {
    IS_X(cpu)
        return cpu.regs().d + cpu.fetchByte() + (cpu.regs().x & 0xFF);
    else
        return cpu.regs().d + cpu.fetchByte() + cpu.regs().x;
}

uint32_t PerformDirectYIndexed (WDC65C816& cpu) {
    IS_X(cpu)
        return cpu.regs().d + cpu.fetchByte() + (cpu.regs().y & 0xFF);
    else
        return cpu.regs().d + cpu.fetchByte() + cpu.regs().y;
}

uint32_t PerformDirectIndirect (WDC65C816& cpu) { // (direct)

}

uint32_t PerformDirectIndexedIndirect (WDC65C816& cpu) { // (direct, x)

}

uint32_t PerformDirectIndirectIndexed (WDC65C816& cpu) { // (direct), y

}

uint32_t PerformDirectIndirectLong (WDC65C816& cpu) { // [direct]

}

uint32_t PerformDirectIndirectIndexedLong (WDC65C816& cpu) { // [direct], y

}

// edge case for jmp/jsr
uint32_t PerformJmpAbsolute (WDC65C816& cpu) {
    uint16_t offset = cpu.fetchWord();
    return (cpu.regs().pbr << 16) + offset;
}
uint32_t PerformAbsolute (WDC65C816& cpu) {
    uint16_t offset = cpu.fetchWord();
    return (cpu.regs().dbr << 16) + offset;
}

uint32_t PerformAbsoluteXIndexed (WDC65C816& cpu) {
    uint16_t offset = cpu.fetchWord();
    IS_X(cpu)
        return (cpu.regs().dbr << 16) + (offset + (cpu.regs().x&0xFF));
    else
        return (cpu.regs().dbr << 16) + offset + cpu.regs().x;
}

uint32_t PerformAbsoluteYIndexed (WDC65C816& cpu) {
    uint16_t offset = cpu.fetchWord();
    IS_X(cpu)
        return (cpu.regs().dbr << 16) + (offset + (cpu.regs().y&0xFF));
    else
        return (cpu.regs().dbr << 16) + offset + cpu.regs().y;
}

uint32_t PerformAbsoluteLong (WDC65C816& cpu) {
    uint8_t low = cpu.fetchByte();
    uint8_t mid = cpu.fetchByte();
    uint8_t hi = cpu.fetchByte();

    return (hi << 16) + (mid << 8) + low;
}

uint32_t PerformAbsoluteIndexedLong (WDC65C816& cpu) {
    uint8_t low = cpu.fetchByte();
    uint8_t mid = cpu.fetchByte();
    uint8_t hi = cpu.fetchByte();

    IS_X(cpu)
        return (hi << 16) + (mid << 8) + low + (cpu.regs().x & 0xFF);
    else
        return (hi << 16) + (mid << 8) + low + cpu.regs().x;
}

// edge case * handle me
uint32_t PerformStack (WDC65C816& cpu) {

}
uint32_t PerformStackRelative (WDC65C816& cpu) {

}

uint32_t PerformStackRelativeIndirectIndexed (WDC65C816& cpu) {

}

uint32_t PerformAbsoluteIndirect (WDC65C816& cpu) {

}

uint32_t PerformAbsoluteIndirectLong (WDC65C816& cpu) {

}

uint32_t PerformAbsoluteIndexedIndirect (WDC65C816& cpu) {

}

uint32_t PerformAccumulator (WDC65C816& cpu) {

}

uint32_t PerformBlockMove (WDC65C816& cpu) {

}

}