#ifndef INCLUDE_LOGGER_LOGGER_H_
#define INCLUDE_LOGGER_LOGGER_H_

#define format_string const char *

enum color {
  BLACK = 30,
  RED = 31,
  GREEN = 32,
  YELLOW = 33,
  BLUE = 34,
  MAGENTA = 35,
  CYAN = 36,
  WHITE = 37,
  CLEAR = 0,
};

extern void info(format_string format, ...);
extern void ok(format_string format, ...);
extern void error(format_string format, ...);
extern void warn(format_string format, ...);
extern void trace(format_string format, ...);
extern void note(format_string format, ...);

#endif // INCLUDE_LOGGER_LOGGER_H_
