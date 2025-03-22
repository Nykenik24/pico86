#ifndef INCLUDE_DEFINITIONS_INSTRUCTIONS_H_
#define INCLUDE_DEFINITIONS_INSTRUCTIONS_H_

#include "definitions/types.h"

typedef enum {
  ADD = 0x0,
  SUB,
  MUL,
  DIV,
  AND = 0x20,
  OR,
  XOR,
  NOT,
  JMP = 0x40,
  JZ,
  JNZ,
  CALL,
  RET,
  MOV = 0x60,
  PUSH,
  POP,
  SHL = 0x80,
  SHR,
  ROL,
  ROR,
  HLT = 0xFF
} opcode;

typedef struct {
  opcode opcode;
  byte operands[];
} instruction;

#endif // INCLUDE_DEFINITIONS_INSTRUCTIONS_H_
