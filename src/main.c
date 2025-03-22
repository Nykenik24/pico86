#include "cpu/cpu.h"
#include "cpu/definitions/instructions.h"
#include "cpu/memory/memory.h"
#include "util/logger.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  CPU *cpu = new_cpu();

  byte first_byte = encode(0b0111000, 0b10);
  byte operand1 = 0b1010;
  byte operand2 = 0b0101;

  mem_write(cpu, cpu->CS.base_address, 1, first_byte);
  mem_write(cpu, cpu->CS.base_address, 2, operand1);
  mem_write(cpu, cpu->CS.base_address, 3, operand1);
  mem_write(cpu, cpu->CS.base_address, 4, operand2);
  mem_write(cpu, cpu->CS.base_address, 5, operand2);

  cpu->IP++;
  instruction last_instruction = fetch(cpu);
  return EXIT_SUCCESS;
}
