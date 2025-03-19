#include "cpu.h"
#include "instructions.h"
#include "logger.h"
#include "memory.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  CPU *cpu = new_cpu((uint16_t)0xFFFF);
  mem_write(cpu, cpu->CS, 21, ADD);
  info("Memory:");
  list_memory(cpu, cpu->CS, 16 * 16, 16);
  info("Registers:\n");
  list_registers(cpu);
  info("Segment adresses:\n");
  list_segment_adresses(cpu);

  printf("\n");

  if (run_program(cpu) == 0) {
    ok("Program didn't have any errors");
  } else {
    error("Program ended with errors");
  };
  free(cpu);
  return EXIT_SUCCESS;
}
