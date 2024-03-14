#include "types.h"
#include "riscv.h"
#include "defs.h"

int read_count = 0;

uint64 sys_getreadcount(void) {
  return read_count;
}
