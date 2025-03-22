#include "cpu.h"
#include "memory/memory.h"
#include "util/debug.h"
#include "util/logger.h"
#include <stdlib.h>
#include <string.h>

CPU *new_cpu() {
  CPU *cpu = (CPU *)malloc(sizeof(CPU));
  if (!cpu) {
    return NULL;
  }

  memset(cpu, 0, sizeof(CPU));
  memset(cpu->memory, 0, MAX_MEMORY);

  cpu->CS.base_address = 0x0000;
  cpu->DS.base_address = SEGMENT_SIZE;
  cpu->ES.base_address = SEGMENT_SIZE * 2;
  cpu->SS.base_address = SEGMENT_SIZE * 3;

  cpu->SP = (u16)MAX_MEMORY - 1;
  cpu->IP = 0;
  return cpu;
}

byte fetch_operand(CPU *cpu) {
  byte operand = (mem_read(cpu, cpu->CS.base_address, cpu->IP++) << 8) |
                 mem_read(cpu, cpu->CS.base_address, cpu->IP++);
  dump_u8(operand, "Fetched operand");
  return operand;
}

instruction fetch(CPU *cpu) {
  byte first_byte = mem_read(cpu, cpu->CS.base_address, cpu->IP++);
  dump_u8(first_byte, "First byte");

  byte opcode = (first_byte >> 2) & 0x3F;
  byte operand_count = first_byte & 0x03;

  u16 operand1 = 0, operand2 = 0;

  dump_u8(operand_count, "Operand count");
  panic_if_error(
      assert(operand_count > 3, "Error when fetching: operand count too big"));

  if (operand_count == 0x01) {
    operand1 = fetch_operand(cpu);
  } else if (operand_count == 0x02) {
    operand1 = fetch_operand(cpu);
    operand2 = fetch_operand(cpu);
  }

  instruction instruction;
  instruction.opcode = opcode;
  dump_u8(opcode, "Opcode");
  instruction.operands[0] = operand1;
  dump_u16(operand1, "Operand 1");
  instruction.operands[1] = operand2;
  dump_u16(operand2, "Operand 2");

  return instruction;
}

byte encode(byte opcode, byte operand_count) {
  return (opcode << 2) | operand_count;
}
