#include "unity.h"
#include "../include/structure/objects.c"
#include "../include/figure/drawable.h"
#include "../include/variable.h"

// used to push fast a object
void push_variable_text(char *var_name, long long scope_id, char *value) {
  Text *txt = (Text*) malloc(sizeof(Text));
  txt->value = value;

  push(var_name, scope_id, txt, VAR_TEXT);
}

void setUp(void) {
  // same name! Should cause error
  char *variable_name = "testXPTO";

  Text *structure = (Text*) malloc(sizeof(Text));
  structure->value = "testValue";

  push(variable_name, current_scope_id, structure, VAR_TEXT);
}

void tearDown(void) {
  clean_stack();
}

void test_scope_active_with_same_variable_name(void) {
  // same name! Should cause error
  char *variable_name = "variableTest";

  Text *structure = (Text*) malloc(sizeof(Text));
  structure->value = "testValue";
  int result = push(variable_name, current_scope_id, structure, VAR_TEXT);
  TEST_ASSERT_TRUE(result);

  Text *structure2 = (Text*) malloc(sizeof(Text));
  structure2->value = "testValue";
  // should return -1
  result = push(variable_name, current_scope_id, structure2, VAR_TEXT);

  TEST_ASSERT_FALSE(result);
}

void test_scope_active_with_other_variable_name(void) {
  // setUp already put a default object into stack
  char *other_name = "variableTest";

  Text *structure2 = (Text*) malloc(sizeof(Text));
  structure2->value = "testValue";

  int result = push(other_name, current_scope_id, structure2, VAR_TEXT);

  TEST_ASSERT(result);
}

void test_init_scope_with_success(void) {
  char *name = "variableTest";
  // into new scope
  int scope_id = current_scope_id + 1;
  // empty variable
  Elipse *elipse = (Elipse*) malloc(sizeof(ObjectNode));

  int result = push(name, scope_id, elipse, ELIPSE);

  TEST_ASSERT(result);
}

void test_pop_scope(void) {
  TEST_ASSERT_NOT_NULL(object_stack->head);
  // removes unique node added by setUp
  pop();
  // wait a null on head of stack
  TEST_ASSERT_NULL(object_stack->head);
}

void test_search_element(void) {
  // pushed in setUp
  TEST_ASSERT_NOT_NULL(search_element("testXPTO"));
}

void test_search_inexistent_element(void) {
  // Variable 'never' not exists into stack
  TEST_ASSERT_NULL(search_element("never"));
}

void test_remove_all_from_scope(void) {
  // Push a variable to stack
  push_variable_text("xpto", 7, "unit test");
  // if variable name is searched a Node are returned
  TEST_ASSERT_NOT_NULL(search_element("xpto"));

  // Remove all scopes
  TEST_ASSERT_EQUAL(1, remove_all_from_scope(7));
  TEST_ASSERT_NULL(search_element("xpto"));
}

void test_remove_all_from_inexistent_scope(void) {
  long inexistent_scope = 123456;
  // Remove all scopes
  TEST_ASSERT_EQUAL(0, remove_all_from_scope(inexistent_scope));
}

void test_clean_stack(void) {
  // Push a variable to stack, now have 2 variables
  push_variable_text("xpto", 7, "unit test");
  clean_stack();
  TEST_ASSERT_NULL(object_stack->head);
}
