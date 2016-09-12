#include "test.h"
// includes to test
#include "../include/structure/objects.c"
#include "../include/figure/drawable.h"

// should be SUCCESS
void test_init_scope(void) {
  char *name = "variableTest";
  // into new scope
  int scope_id = current_scope_id + 1;
  // empty variable
  Elipse *elipse = (Elipse*) malloc(sizeof(ObjectNode));

  int result = push(name, scope_id, elipse);

  printf("Head of stack are %s\n", object_stack->head->name);

  assert_eq_int(1, result);
}

// should be SUCCESS
void test_scope_active_with_another_name(void) {
  test_init_scope();

  char *name = "anotherTest";
  // same scope of init_scope
  int scope_id = current_scope_id;
  // empty variable
  Elipse *elipse = (Elipse*) malloc(sizeof(ObjectNode));

  int result = push(name, scope_id, elipse);

  assert_eq_int(1, result);
}

// should be SUCCESS
void test_scope_active_with_same_variable_name(void) {
  test_init_scope();

  // same name! Cause error
  char *name = "variableTest";
  // same scope of init_scope
  current_scope_id++;
  int scope_id = current_scope_id;

  // empty variable
  Elipse *elipse = (Elipse*) malloc(sizeof(ObjectNode));

  int result = push(name, scope_id, elipse);

  assert_eq_int(-1, result);
}

void test_scope_active_with_other_variable_name(void) {
  // call this to simulate a first object setted
  test_init_scope();

  // Other name! Should pass
  char *name = "variableOther";
  // same scope of init_scope
  current_scope_id++;
  int scope_id = current_scope_id;

  // empty variable
  Elipse *elipse = (Elipse*) malloc(sizeof(ObjectNode));

  int result = push(name, scope_id, elipse);

  assert_eq_int(1, result);

  print_object_stack(object_stack->head);
}

int main(void) {
  /* Bellow tests are to push function */

  // test_init_scope();
  // test_scope_active_with_another_name();
  // test_scope_active_with_same_variable_name();
  // test_scope_active_with_other_variable_name();

  
  return 0;
}
