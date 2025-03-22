#include "logger.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void info(string format, ...) {
  va_list args;
  printf(ANSI_COLOR_CYAN);
  printf("[INFO]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void ok(string format, ...) {
  va_list args;
  printf(ANSI_COLOR_GREEN);
  printf("[OK]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void error(string format, ...) {
  va_list args;
  printf(ANSI_COLOR_RED);
  printf("[ERROR]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void warn(string format, ...) {
  va_list args;
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void trace(string format, ...) {
  va_list args;
  printf(ANSI_COLOR_MAGENTA);
  printf("[TRACE]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void note(string format, ...) {
  va_list args;
  printf(ANSI_COLOR_BLUE);
  printf("[NOTE]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void dump_u8(byte number, string name) {
  printf(ANSI_COLOR_YELLOW);
  printf("[UINT8] %s: ", name);
  printf(ANSI_COLOR_RESET);
  printf("%" PRIu8 "\n", number);
}

void dump_u16(u16 number, string name) {
  printf(ANSI_COLOR_YELLOW);
  printf("[UINT16] %s: ", name);
  printf(ANSI_COLOR_RESET);
  printf("%" PRIu16 "\n", number);
}

void dump_u32(u32 number, string name) {
  printf(ANSI_COLOR_YELLOW);
  printf("[UINT32] %s: ", name);
  printf(ANSI_COLOR_RESET);
  printf("%" PRIu32 "\n", number);
}

void dump_hex(int hex, string name) {
  printf(ANSI_COLOR_YELLOW);
  printf("[HEX] %s: ", name);
  printf(ANSI_COLOR_RESET);
  printf(HEX_FORMAT "\n", hex);
}

#define foreach(item, array, length)                                           \
  for (size_t _i = 0, _len = (length); _i < _len && ((item) = (array)[_i], 1); \
       _i++)

void dump_array(int array[], int range) {
  int item;
  foreach (item, array, range) {
    printf("%d", item);
  };
}

void dump_hex_array(int array[], int range) {
  int item;
  foreach (item, array, range) {
    printf(HEX_FORMAT, item);
  }
}

void dump_u8_array(byte *array, int range) {
  byte item;
  foreach (item, array, range) {
    printf("%" PRIu8, item);
  }
}

void dump_u16_array(u16 *array, int range) {
  u16 item;
  foreach (item, array, range) {
    printf("%" PRIu16, item);
  }
}

void dump_u32_array(u32 *array, int range) {
  u32 item;
  foreach (item, array, range) {
    printf("%" PRIu32, item);
  }
}
