#include "cpu.h"
#include "instructions.h"
#include "logger.h"
#include "memory.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CPU *new_cpu(u16 memory_size) {
  CPU *cpu = (CPU *)malloc(sizeof(CPU));
  if (!cpu) {
    return NULL;
  }

  memset(cpu, 0, sizeof(CPU));
  memset(cpu->mem, 0, memory_size);

  cpu->SP = memory_size - 1;
  cpu->IP = 0;

  cpu->CS = 0;
  cpu->DS = (u16)65536 + 1;
  cpu->ES = (u16)65536 * 2 + 1;
  cpu->SS = (u16)65536 * 3 + 1;
  return cpu;
}

int run_program(CPU *cpu) {
  while (1) {
    u8 opcode = mem_read(cpu, cpu->CS, cpu->IP++);
    info("Fetched OPCODE: 0x%02X", opcode);
    info("IP: %i", cpu->IP);

    switch (opcode) {
    case ADD:
      cpu->AX.L += cpu->BX.L;
    case HLT:
      return 0;
    default:
      error("Unknown OPCODE 0x%02X at CS with IP 0x%02X", opcode, cpu->IP);
      return 1;
    }
  }
}

void list_registers(CPU *cpu) {
  printf("AX: 0x%02X, 0x%02X\n", cpu->AX.L, cpu->AX.H);
  printf("BX: 0x%02X, 0x%02X\n", cpu->BX.L, cpu->BX.H);
  printf("CX: 0x%02X, 0x%02X\n", cpu->CX.L, cpu->CX.H);
  printf("DX: 0x%02X, 0x%02X\n", cpu->DX.L, cpu->DX.H);
}

void list_segment_adresses(CPU *cpu) {
  printf("CS: %" PRIu16 "\n", cpu->CS);
  printf("DS: %" PRIu16 "\n", cpu->DS);
  printf("ES: %" PRIu16 "\n", cpu->ES);
  printf("SS: %" PRIu16 "\n", cpu->SS);
}
