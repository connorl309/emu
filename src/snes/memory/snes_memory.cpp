#include "inc/memory.hpp"

namespace snes_memory
{

/**
 * create memory manager
*/
MemoryManager::MemoryManager(uint32_t size) {
    raw_memory = std::make_unique<uint8_t[]>(size);
    memory_size = size;
}

/**
 * read a byte
*/
uint8_t MemoryManager::read_byte(uint32_t addr) {
    return raw_memory.get()[addr];
}
/**
 * read a word
*/
uint16_t MemoryManager::read_word(uint32_t addr) {
    uint8_t low = raw_memory.get()[addr];
    uint8_t hi = raw_memory.get()[addr + 1];
    return (hi << 8) + low;
}
/**
 * write a byte
*/
void MemoryManager::write_byte(uint32_t addr, uint8_t val) {
    raw_memory.get()[addr] = val;
}
/**
 * write a word
*/
void MemoryManager::write_word(uint32_t addr, uint16_t val) {
    raw_memory.get()[addr] = val & 0xFF;
    raw_memory.get()[addr + 1] = (val >> 8) & 0xFF;
}

}