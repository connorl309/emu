#ifndef SNES_COMMON_HPP
#define SNES_COMMON_HPP

#include <stdint.h>
#include <bit>
#include <chrono>
#include <math.h>
#include <stdlib.h>

/**
 * Memory definitions
 * https://en.wikibooks.org/wiki/Super_NES_Programming/SNES_memory_map
*/
#define _SNES_MAX_MEM_SIZE (1 << 24)
#define _SNES_BANK_SIZE (1 << 16)
#define _SNES_BANK_COUNT 256
#define _SNES_PAGE_SIZE 256
#define _SNES_PAGE_COUNT_MAX (1 << 16)
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

#endif