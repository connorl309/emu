#ifndef SNES_COMMON_HPP
#define SNES_COMMON_HPP

#include <stdint.h>
#include <bit>
#include <chrono>
#include <math.h>
#include <stdlib.h>

namespace snes_common {

/**
 * Memory definitions
 * https://en.wikibooks.org/wiki/Super_NES_Programming/SNES_memory_map
*/
#define SNES_ROM_BITMASK 0x001A0BCD

/**
 * Memory struct
 * will make memory on the heap because megabytes is a lot of space
 * double ptr in the form of [banks][offset]
*/
typedef struct
{
    uint8_t** memory_map;
} LoROM, HiROM;

/**
 * Hardware registers
 * start at 0x2100
 * https://en.wikibooks.org/wiki/Super_NES_Programming/SNES_Hardware_Registers
*/

}


#endif