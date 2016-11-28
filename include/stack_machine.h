#ifndef STACK_MACHINE
#define STACK_MACHINE

#include "structure/objects.h"
#include "instance.h"
#include "attribution.h"

typedef enum code_operations {
  INSTANCE = 0, ATTRIBUTION = 1, ACTION = 2, HALT = 3
} CodeOperations;

// position of stack code
extern int top;

// instruction register
extern struct instruction ir;

extern struct loop_instruction loop;

// program counter
extern int pc;

extern int block_type;

#endif
