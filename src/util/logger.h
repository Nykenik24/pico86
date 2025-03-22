#ifndef INCLUDE_UTIL_LOGGER_H_
#define INCLUDE_UTIL_LOGGER_H_

#include "definitions/types.h"
#define HEX_FORMAT "0x%02X"
#define HEX_FORMAT_LONG "0x%4X"

extern void info(string format, ...);
extern void ok(string format, ...);
extern void error(string format, ...);
extern void warn(string format, ...);
extern void trace(string format, ...);
extern void note(string format, ...);

#include <inttypes.h>

// dump

// number
extern void dump_u8(byte number, string name);
extern void dump_u16(u16 number, string name);
extern void dump_u32(u32 number, string name);
extern void dump_hex(int hex, string name);
// array
extern void dump_array(int array[], int range);
extern void dump_hex_array(int array[], int range);
extern void dump_u8_array(byte *array, int range);
extern void dump_u16_array(u16 *array, int range);
extern void dump_u32_array(u32 *array, int range);

#endif // INCLUDE_UTIL_LOGGER_H_
