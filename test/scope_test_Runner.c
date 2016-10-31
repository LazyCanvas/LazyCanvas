/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include <unity.h>
#include <setjmp.h>
#include <stdio.h>
#include "../include/figure/drawable.h"
#include "../include/variable.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_scope_active_with_same_variable_name(void);
extern void test_scope_active_with_other_variable_name(void);
extern void test_init_scope_with_success(void);
extern void test_pop_scope(void);
extern void test_search_element(void);
extern void test_search_inexistent_element(void);
extern void test_remove_all_from_scope(void);
extern void test_remove_all_from_inexistent_scope(void);
extern void test_clean_stack(void);


/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("scope_test.c");
  RUN_TEST(test_scope_active_with_same_variable_name, 28);
  RUN_TEST(test_scope_active_with_other_variable_name, 45);
  RUN_TEST(test_init_scope_with_success, 57);
  RUN_TEST(test_pop_scope, 69);
  RUN_TEST(test_search_element, 77);
  RUN_TEST(test_search_inexistent_element, 82);
  RUN_TEST(test_remove_all_from_scope, 87);
  RUN_TEST(test_remove_all_from_inexistent_scope, 98);
  RUN_TEST(test_clean_stack, 104);

  return (UnityEnd());
}
