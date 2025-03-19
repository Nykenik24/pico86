#include "logger.h"
#include <stdarg.h>
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void info(const char *format, ...) {
  va_list args;
  printf(ANSI_COLOR_CYAN);
  printf("[INFO]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void ok(const char *format, ...) {
  va_list args;
  printf(ANSI_COLOR_GREEN);
  printf("[OK]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void error(const char *format, ...) {
  va_list args;
  printf(ANSI_COLOR_RED);
  printf("[ERROR]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void warn(const char *format, ...) {
  va_list args;
  printf(ANSI_COLOR_YELLOW);
  printf("[WARN]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void trace(const char *format, ...) {
  va_list args;
  printf(ANSI_COLOR_MAGENTA);
  printf("[TRACE]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}

void note(const char *format, ...) {
  va_list args;
  printf(ANSI_COLOR_BLUE);
  printf("[NOTE]: ");
  printf(ANSI_COLOR_RESET);
  printf(format, args);
  printf("\n");
}
