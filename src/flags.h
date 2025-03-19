#ifndef INCLUDE_FLAGS_FLAGS_H_
#define INCLUDE_FLAGS_FLAGS_H_

#include "types.h"

typedef struct {
  u8 CF : 1;        // carry flag
  u8 PF : 1;        // parity flag
  u8 AF : 1;        // auxiliary carry flag
  u8 ZF : 1;        // zero flag
  u8 SF : 1;        // sign flag
  u8 TF : 1;        // trap flag (single-step)
  u8 IF : 1;        // interrupt flag
  u8 DF : 1;        // direction flag
  u8 OF : 1;        // overflow flag
  u8 _reserved : 7; // unused bits
} flags;

#endif // INCLUDE_FLAGS_FLAGS_H_
