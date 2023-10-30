#ifndef _65C816_INSTR_HPP
#define _65C816_INSTR_HPP

#include <stdint.h>
#include <string>

namespace WDC65816 {

// https://wiki.superfamicom.org/65816-reference
// http://apple2.guidero.us/doku.php/mg_notes/65816_notes/addressing_modes
enum {
    Implied,
    Immediate,
    Relative, RelativeLong,
    Direct, DirectXIndexed, DirectYIndexed,
    DirectIndirect, 
    DirectIndexedIndirect, DirectIndirectIndexed,
    DirectIndirectLong, DirectIndirectIndexedLong,
    Absolute, AbsoluteXIndexed, AbsoluteYIndexed,
    AbsoluteLong,
    AbsoluteIndexedLong,
    StackRelative,
    StackRelativeIndirectIndexed,
    AbsoluteIndirect, AbsoluteIndirectLong,
    AbsoluteIndexedIndirect,
    Accumulator,
    BlockMove
} addressing_mode;

}

#endif