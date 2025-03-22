#ifndef INCLUDE_CPU_CPU_H_
#define INCLUDE_CPU_CPU_H_

#include "cpu/definitions/instructions.h"
#include "cpu/definitions/registers.h"
#include "definitions/types.h"

#define MAX_MEMORY (u32)0x100000
#define SEGMENT_SIZE 0x10000

typedef struct {
  byte memory[MAX_MEMORY];

  // main registers
  register16 AX, BX, CX, DX;
  // segment registers
  segment_register CS, DS, ES, SS;
  // index registers
  u16 SI, DI, BP, SP;

  u16 IP; // instruction pointer,
          // equivalent to program counter

  // flags
  status_register status;
} CPU;

extern CPU *new_cpu();
extern byte encode(byte opcode, byte operand_count);
extern instruction fetch(CPU *cpu);
extern byte fetch_operand(CPU *cpu);
extern void add_instruction(CPU *cpu, byte first_byte, byte operand1,
                            byte operand2);

#endif // INCLUDE_CPU_CPU_H_
