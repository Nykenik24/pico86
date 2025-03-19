#include "memory.h"
#include <stddef.h>
#include <stdio.h>

u8 mem_read(CPU *cpu, u16 segment, u16 offset) {
  u32 physical_adress = (segment << 4) + offset;
  if (physical_adress < CPU_MAX_MEM) {
    return cpu->mem[physical_adress];
  }
  return 0;
}

int mem_write(CPU *cpu, u16 segment, u16 offset, u8 data) {
  u32 physical_adress = (segment << 4) + offset;
  if (physical_adress < CPU_MAX_MEM) {
    cpu->mem[physical_adress] = data;
    return 0;
  }
  return 1;
}

void list_memory(CPU *cpu, int segment, int range, int per_line) {
  uint32_t base_address = segment * 16;
  uint32_t end_address = base_address + range;

  for (uint32_t i = base_address; i < end_address; i++) {
    if ((i - base_address) % per_line == 0)
      printf("\n0x%04X: ", i);

    if (cpu->mem[i] == 0) {
      printf("\x1b[31m%02X\x1b[0m ", cpu->mem[i]);
    } else {
      printf("\x1b[32m%02X\x1b[0m ", cpu->mem[i]);
    }
  }
  printf("\n");
}
