#include "stack_machine.h"
#include "if.h"

struct instruction {
  CodeOperations operation;
  char *var_name;
  char *attribution_field;
  char *str_value;
  double number_value;
};

struct loop_instruction {
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

// program counter
int pc = 0;

BlockType block_type = DEFAULT;

struct loop_instruction loop;

void execute_block() {
  int keep_run = 1;
  while(keep_run) {
    ir = code[pc];
    printf("Operation[%d] will executed is %d\n", pc, ir.operation);
    switch (ir.operation) {
      case INSTANCE:
        printf("Instantiate %s like %s\n", ir.var_name, ir.attribution_field);
        instance_object(ir.var_name, ir.attribution_field);
        printf("Success instance_object\n");
        break;
      case ATTRIBUTION:
        // variable attribution
        if(ir.attribution_field == NULL) {
          if(ir.str_value == NULL) {
            put_new_number(ir.var_name, VAR_NUMBER, ir.number_value);
          } else {
            put_new_text(ir.var_name, VAR_TEXT, ir.str_value);
          }
        } else {
          // object property attribution
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
        draw(search_element(ir.var_name));
        break;
      case HALT:
        keep_run = 0;
        break;
      default:
        printf("FATAL ERROR on execute_block\n");
        keep_run = 0;
        break;
    }
    pc++;
  }
  // clean program counter
  pc=0;
}

void init_if(int valueCompared) {
  block_type = IFELSE;
  if_should_print = valueCompared;
}

void init_for(char *var_name, int init, int halt_condition) {
  block_type = LOOP;
  int var_name_size = strlen(var_name);
  loop.var_name = (char*) malloc(sizeof(char)*var_name_size);
  strcpy(loop.var_name, var_name);
  loop.init = init;
  loop.halt_condition = halt_condition;
  printf("Var name: %s\n", loop.var_name);
  printf("Loop init value %d\n", loop.init);
  printf("Halt condition %d\n", loop.halt_condition);
}

void run_loop() {
  ObjectNode *finded = search_element(loop.var_name);
  double *loop_var = (double *) finded->structure;
  double var_value = *loop_var;

  int x = 0;

  for(x = (int) var_value; x < loop.halt_condition; x++) {
    execute_block();

    free(finded->structure);

    // update loop var
    put_new_number(finded->name, VAR_NUMBER, x);
  }
  block_type = DEFAULT;
  top = 0;
}

void run_ifelse() {
  
}

void push_instruction(CodeOperations operation, char *var_name,
  char *attribution_field, char *str_value, double number_value) {

    struct instruction actual_ir;
    actual_ir.operation = operation;

    printf("Operation type: %d\n", operation);

    if(var_name != NULL) {
      actual_ir.var_name = strdup(var_name);
    } else {
      actual_ir.var_name = NULL;
    }

    if(attribution_field != NULL) {
      actual_ir.attribution_field = strdup(attribution_field);
    } else {
      actual_ir.attribution_field = NULL;
    }

    if(str_value != NULL) {
      actual_ir.str_value = strdup(str_value);
    } else {
      actual_ir.str_value = NULL;
    }

    actual_ir.number_value = number_value;
    code[top] = actual_ir;
    top++;
}
