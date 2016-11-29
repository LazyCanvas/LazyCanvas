#ifndef STACK_MACHINE
#define STACK_MACHINE

#include "structure/objects.h"
#include "instance.h"
#include "attribution.h"

typedef enum code_operations {
  INSTANCE = 0, ATTRIBUTION = 1, ACTION = 2, HALT = 3
} CodeOperations;

typedef enum block_type {
  DEFAULT = 0, LOOP = 1, DEF = 2, IFELSE = 3
} BlockType;

// position of stack code
extern int top;

// instruction register
extern struct instruction ir;

extern struct loop_instruction loop;

// program counter
extern int pc;

extern BlockType block_type;

#endif
