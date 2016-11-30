#include "if.h"

// conditional
int if_should_print;

typedef enum conditional_operator {
  EQUALS_TO = 0, GREATTER_EQUALS_THEN = 1, SMALLER_EQUALS_THEN = 2,
  DIFFERENT_THEN = 3, SMALLER_THEN = 4, BIGGER_THEN = 5
} ConditionalOperator;

ConditionalOperator conditionalOp;
