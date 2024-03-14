#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "spinlock.h"

struct spinlock read_count_lock;
int read_count = 0;

uint64 sys_getreadcount(void) {
  return read_count;
}
