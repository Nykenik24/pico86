#include "debug.h"
#include "util/logger.h"
#include <stdlib.h>
#include <string.h>

bool assert(bool condition, string message) {
  if (condition != false) {
    error(message);
    return true;
  } else {
    return false;
  }
}

bool assert_equal(int first, int second, string message) {
  if (first != second) {
    error(message);
    return true;
  } else {
    return false;
  }
}

bool assert_nequal(int first, int second, string message) {
  if (first == second) {
    error(message);
    return true;
  } else {
    return false;
  }
}

bool assert_sequal(string first, string second, string message) {
  if (strcmp(first, second) == true) {
    error(message);
    return true;
  } else {
    return false;
  }
}

bool assert_snequal(string first, string second, string message) {
  if (strcmp(first, second) == false) {
    error(message);
    return true;
  } else {
    return false;
  }
}

void panic_if_error(bool error) {
  if (error == true) {
    exit(1);
  }
}
