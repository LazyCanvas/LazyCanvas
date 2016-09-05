#include "test.h"
// includes to test
#include "../include/structure/scope.c"

void test_unitialized_scopes(void) {
  assert_null(scope_stack);
}

void test_initialized_scopes(void) {
  init_scopes();

  assert_not_null(scope_stack);
}

void test_value_after_initialize(void) {
  init_scopes();

  assert_eq("1", scope_stack->head->scope_id);
}

void test_create_new_node(void) {

}

int main(void) {
  // test_unitialized_scopes();
  // test_initialized_scopes();
  // test_value_after_initialize();

  return 0;
}
