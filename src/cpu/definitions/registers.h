#ifndef INCLUDE_DEFINITIONS_REGISTERS_H_
#define INCLUDE_DEFINITIONS_REGISTERS_H_

#include "definitions/types.h"
#include <stdint.h>

typedef struct {
  byte L : 8;
  byte H : 8;
} register16;

typedef struct {
  u32 base_address;
} segment_register;

typedef struct {
  bool OF : 1;
  bool DF : 1;
  bool IF : 1;
  bool TF : 1;
  bool SF : 1;
  bool ZF : 1;
  bool AF : 1;
  bool PF : 1;
  bool CF : 1;
  int _bit_rest : 7;
} status_register;

#endif // INCLUDE_DEFINITIONS_REGISTERS_H_
