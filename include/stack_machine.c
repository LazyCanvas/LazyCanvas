#include "structure/objects.h"
#include "instance.h"
#include "attribution.h"

enum code_operations {
  INSTANCE, ATTRIBUTION, ACTION, HALT
};

struct instruction {
  enum code_operations operation;
  char *var_name;
  char *attribution_field;
  char *str_value;
  double number_value;
};

struct loop_instruction {
  // boolean condition to loop
  int active;
  char *var_name;
  int init;
  int halt_condition;
};

// Limited code
struct instruction code[999];

// position of stack code
int top = 0;

// instruction register
struct instruction ir;

struct loop_instruction loop;

// program counter
int pc = 0;

void execute_block() {
  int keep_run = 1;

  while(keep_run) {
    ir = code[pc++];
    switch (ir.operation) {
      case INSTANCE:
        instance_object(ir.var_name, ir.attribution_field);
        break;
      case ATTRIBUTION:
        if(ir.attribution_field == NULL) {
          if(ir.str_value == NULL) {
            put_new_number(ir.var_name, VAR_NUMBER, ir.number_value);
          } else {
            put_new_text(ir.var_name, VAR_TEXT, ir.str_value);
          }
        } else {
          if(ir.str_value == NULL) {
            include_number_on_object_attribute(ir.var_name,
              ir.attribution_field, ir.number_value);
          } else {
            include_text_on_object_attribute(ir.var_name,
              ir.attribution_field, ir.str_value);
          }
        }
        break;
      case ACTION:
        ObjectNode *finded = search_element(ir.var_name);
        if(finded == NULL) {
          printf("Variable %s not found\n", ir.var_name);
        } else {
          draw(finded);
        }
        break;
      case HALT:
        printf("End of block\n");
        keep_run = 0;
        break;
      default:
        printf("FATAL ERROR on execute_block\n");
        keep_run = 0;
        break;
    }
  }
  // clean program counter
  pc=0;
}

void init_for(char *var_name, int init, int halt_condition) {
  loop.active = 1;
  strcpy(loop.var_name, var_name);
  loop.init = init;
  loop.halt_condition = halt_condition;
}

int loop_is_active() {
  return loop.active;
}

void run_loop() {
  ObjectNode *finded = search_element(loop.var_name);
  double loop_var = (double) finded.structure;
  for(int x = loop_var; x < loop.halt_condition; x++) {
    execute_block();
  }
}

void push_instruction(code_operations operation, char *var_name,
  char *attribution_field, char *str_value, double number_value) {
    struct instruction actual_ir;
    actual_ir.code_operations = operation;
    strcpy(actual_ir.var_name, var_name);
    strcpy(actual_ir.attribution_field, attribution_field);
    strcpy(actual_ir.str_value, str_value);
    actual_ir.number_value = number_value;
    code[top] = actual_ir;
    top++;
}
