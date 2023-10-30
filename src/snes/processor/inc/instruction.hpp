#ifndef _65C816_INSTR_HPP
#define _65C816_INSTR_HPP

#include "proc.hpp"
#include <functional>
#include <map>
#include <stdint.h>
#include <string>

namespace WDC65816
{

// https://wiki.superfamicom.org/65816-reference
// http://apple2.guidero.us/doku.php/mg_notes/65816_notes/addressing_modes
typedef enum
{
  Implied,
  Immediate,
  Relative8,
  Relative16,
  RelativeLong,
  Direct,
  DirectXIndexed,
  DirectYIndexed,
  DirectIndirect,
  DirectIndexedIndirect,
  DirectIndirectIndexed,
  DirectIndirectLong,
  DirectIndirectIndexedLong,
  JmpAbsolute,
  Absolute,
  AbsoluteXIndexed,
  AbsoluteYIndexed,
  AbsoluteLong,
  AbsoluteIndexedLong,
  StackRelative,
  StackRelativeIndirectIndexed,
  AbsoluteIndirect,
  AbsoluteIndirectLong,
  AbsoluteIndexedIndirect,
  Accumulator,
  BlockMove
} addressing_mode;

// These PerformXYZ will return an address to be used in instruction execution
uint32_t PerformImplied (WDC65C816& cpu);
uint32_t PerformImmediate (WDC65C816& cpu);
uint32_t PerformRelative8 (WDC65C816& cpu);
uint32_t PerformRelative16 (WDC65C816& cpu);
uint32_t PerformDirect (WDC65C816& cpu);
uint32_t PerformDirectXIndexed (WDC65C816& cpu);
uint32_t PerformDirectYIndexed (WDC65C816& cpu);
uint32_t PerformDirectIndirect (WDC65C816& cpu);
uint32_t PerformDirectIndexedIndirect (WDC65C816& cpu);
uint32_t PerformDirectIndirectIndexed (WDC65C816& cpu);
uint32_t PerformDirectIndirectLong (WDC65C816& cpu);
uint32_t PerformDirectIndirectIndexedLong (WDC65C816& cpu);
uint32_t PerformJmpAbsolute (WDC65C816& cpu);
uint32_t PerformAbsolute (WDC65C816& cpu);
uint32_t PerformAbsoluteXIndexed (WDC65C816& cpu);
uint32_t PerformAbsoluteYIndexed (WDC65C816& cpu);
uint32_t PerformAbsoluteLong (WDC65C816& cpu);
uint32_t PerformAbsoluteIndexedLong (WDC65C816& cpu);
uint32_t PerformStackRelative (WDC65C816& cpu);
uint32_t PerformStackRelativeIndirectIndexed (WDC65C816& cpu);
uint32_t PerformAbsoluteIndirect (WDC65C816& cpu);
uint32_t PerformAbsoluteIndirectLong (WDC65C816& cpu);
uint32_t PerformAbsoluteIndexedIndirect (WDC65C816& cpu);
uint32_t PerformAccumulator (WDC65C816& cpu);
uint32_t PerformBlockMove (WDC65C816& cpu);

static const std::map<addressing_mode, std::function<uint32_t (WDC65C816 &)> > mode_map = { 
        { Implied, PerformImplied },
        { Immediate, PerformImmediate },
        { Relative8, PerformRelative8 },
        { Relative16, PerformRelative16 },
        { Direct, PerformDirect },
        { DirectXIndexed, PerformDirectXIndexed },
        { DirectYIndexed, PerformDirectYIndexed },
        { DirectIndirect, PerformDirectIndirect },
        { DirectIndexedIndirect, PerformDirectIndexedIndirect },
        { DirectIndirectIndexed, PerformDirectIndirectIndexed },
        { DirectIndirectLong, PerformDirectIndirectLong },
        { DirectIndirectIndexedLong, PerformDirectIndirectIndexedLong },
        { JmpAbsolute, PerformJmpAbsolute },
        { Absolute, PerformAbsolute },
        { AbsoluteXIndexed, PerformAbsoluteXIndexed },
        { AbsoluteYIndexed, PerformAbsoluteYIndexed },
        { AbsoluteLong, PerformAbsoluteLong },
        { AbsoluteIndexedLong, PerformAbsoluteIndexedLong },
        { StackRelative, PerformStackRelative },
        { StackRelativeIndirectIndexed, PerformStackRelativeIndirectIndexed },
        { AbsoluteIndirect, PerformAbsoluteIndirect },
        { AbsoluteIndirectLong, PerformAbsoluteIndirectLong },
        { AbsoluteIndexedIndirect, PerformAbsoluteIndexedIndirect },
        { Accumulator, PerformAccumulator },
        { BlockMove, PerformBlockMove } 
};

}

#endif