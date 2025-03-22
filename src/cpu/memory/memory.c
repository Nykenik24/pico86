#include "memory.h"
#include "cpu/cpu.h"
#include "util/debug.h"
#include "util/logger.h"

byte mem_read(CPU *cpu, u32 segment_address, u16 offset) {
  u32 physical_address = (segment_address << 4) + offset;
  if (physical_address < MAX_MEMORY) {
    return cpu->memory[physical_address];
  }
  return 0;
}

void mem_write(CPU *cpu, u32 segment_address, u16 offset, byte data) {
  u32 physical_address = (segment_address << 4) + offset;
  panic_if_error(assert(physical_address > MAX_MEMORY,
                        "Error when writing: physical address too long"));
  cpu->memory[physical_address] = data;
}
