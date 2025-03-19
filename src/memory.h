#ifndef INCLUDE_SRC_MEMORY_H_
#define INCLUDE_SRC_MEMORY_H_

#include "cpu.h"
#include "types.h"

extern u8 mem_read(CPU *cpu, u16 segment, u16 offset);
extern int mem_write(CPU *cpu, u16 segment, u16 offset, u8 data);
extern void list_memory(CPU *cpu, int segment, int range, int per_line);

#endif // INCLUDE_SRC_MEMORY_H_
