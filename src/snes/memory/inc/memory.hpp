#ifndef SNES_MEM_HPP
#define SNES_MEM_HPP

#include <stdint.h>
#include <stdlib.h>
#include <bitset>
#include <memory>

namespace snes_memory
{

    class MemoryManager
    {
        private:
            std::unique_ptr<uint8_t[]> raw_memory;
            uint32_t memory_size;
        
        public:
            MemoryManager(uint32_t size);
            ~MemoryManager() { delete[] raw_memory.release(); raw_memory.reset(); }
            uint8_t read_byte(uint32_t address);
            uint16_t read_word(uint32_t address);
            void write_byte(uint32_t address, uint8_t val);
            void write_word(uint32_t address, uint16_t val);
    };

};

#endif