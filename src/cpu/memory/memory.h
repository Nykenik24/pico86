#ifndef INCLUDE_MEMORY_MEMORY_H_
#define INCLUDE_MEMORY_MEMORY_H_

#include "cpu/cpu.h"
#include "definitions/types.h"

extern byte mem_read(CPU *cpu, u32 segment, u16 offset);
extern void mem_write(CPU *cpu, u32 segment, u16 offset, byte data);

#endif // INCLUDE_MEMORY_MEMORY_H_
