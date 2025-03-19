#ifndef INCLUDE_CPU_CPU_H_
#define INCLUDE_CPU_CPU_H_

// 64KB
#include <stdint.h>
#define CPU_MAX_MEM 0xFFFF

#include "flags.h"
#include "registers.h"
#include "types.h"

typedef struct {
  // main registers
  /*u8 AL, AH;*/
  /*u8 BL, BH;*/
  /*u8 CL, CH;*/
  /*u8 DL, DH;*/
  register16 AX, BX, CX, DX;

  // index registers
  u16 SI;
  u16 DI;

  // stack registers
  u16 BP;
  u16 SP;

  // instruction pointer (program counter)
  u16 IP;

  // flags
  flags flags;

  // memory

  // main memory storage
  u8 mem[CPU_MAX_MEM];

  // segment registers
  u16 CS;
  u16 DS;
  u16 ES;
  u16 SS;

  // interrupt handling
  u8 interrupts_enabled;
} CPU;

extern CPU *new_cpu(u16 memory_size);
extern int run_program(CPU *cpu);
extern void list_registers(CPU *cpu);
extern void list_segment_adresses(CPU *cpu);

#endif // INCLUDE_CPU_CPU_H_
