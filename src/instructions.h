#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_H_

enum opcode {
  // arithmetic
  ADD = 0x01,
  SUB = 0x02,
  MUL = 0x03,
  IMUL = 0x04,
  DIV = 0x05,
  IDIV = 0x06,
  INC = 0x07,
  DEC = 0x08,
  NEG = 0x09,
  CMP = 0x10,
  // logical
  AND = 0x11,
  OR = 0x12,
  XOR = 0x13,
  NOT = 0x14,
  SHL = 0x15,
  SHR = 0x16,
  SAR = 0x17,
  ROL = 0x18,
  ROR = 0x19,
  // flow
  JMP = 0x20,
  JZ = 0x21,
  JNZ = 0x22,
  JC = 0x23,
  JNC = 0x24,
  JO = 0x25,
  JNO = 0x26,
  // misc
  HLT = 0xFF, // halt (stop)
};

#endif // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_H_
