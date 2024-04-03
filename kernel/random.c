#include "random.h"

#define POLY_MASK_32 0xB4BCD35C
#define POLY_MASK_31 0x7A5BC2E3

typedef unsigned int uint;

uint lfsr32 = 0xABCDE;
uint lfsr31 = 0x23456789;

int shift_lfsr(uint *lfsr, uint polynomial_mask) {
  int feedback = *lfsr & 1;
  *lfsr >>= 1;
  if (feedback == 1) {
    *lfsr ^= polynomial_mask;
  }
  return *lfsr;
}

int get_random() {
  shift_lfsr(&lfsr32, POLY_MASK_32);
  return (shift_lfsr(&lfsr32, POLY_MASK_32) ^ shift_lfsr(&lfsr31, POLY_MASK_31)) & 0xffff;
}

int get_random_int(int max_int) {
  return get_random() % max_int;
}

