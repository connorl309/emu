#ifndef _65C816_HPP
#define _65C816_HPP

#include <stdint.h>
#include <stdlib.h>
#include <memory>
#include "isa.hpp"
#include "../../memory/inc/memory.hpp"

// Need to adjust this eventually
// Once I've got a ROM class set up
// CPU mode determined by the ROM I think
namespace snes_cpu
{
    class SNES_65C816_CPU
    {
        private:
            cpu_registers register_file;
            cpu_mode cpumode;
            snes_memory::MemoryManager mem_mgr;
        public:
            SNES_65C816_CPU();
            ~SNES_65C816_CPU();
    };
}


#endif