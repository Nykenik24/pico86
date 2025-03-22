#ifndef INCLUDE_UTIL_DEBUG_H_
#define INCLUDE_UTIL_DEBUG_H_

#include "definitions/types.h"

// assert
extern bool assert(bool condition, string message);
extern bool assert_equal(int first, int second, string message);
extern bool assert_nequal(int first, int second, string message);
extern bool assert_sequal(string first, string second, string message);
extern bool assert_snequal(string first, string second, string message);

// misc.
extern void panic_if_error(bool error);

#endif // INCLUDE_UTIL_DEBUG_H_
