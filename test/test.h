#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAIL -1

void success(void) {
  printf("SUCCESS!\n");
}

void fail(void) {
  printf("FAIL\n");
}

int errors_count = 0;

int assert_eq(void *expec, void *result) {
  int status = -1;

  if(expec == result) {
    success();
    status = SUCCESS;
  } else {
    fail();
    errors_count++;
  }

  return status;  
}

int assert_eq_int(int expec, int result) {
  int status = -1;

  if(expec == result) {
    success();
    status = SUCCESS;
  } else {
    fail();
    errors_count++;
  }

  return status;
}

int assert_null(void *expec) {
  int status = FAIL;

  if(expec == NULL) {
    success();
    status = SUCCESS;
  } else {
    fail();
    errors_count++;
  }

  return status;
}

int assert_not_null(void *expec) {
  int status = FAIL;

  // if status is success this assert fails
  if(expec != NULL) {
    status = SUCCESS;
    success();
  } else {
    status = FAIL;
    errors_count++;
    fail();
  }

  return status;
}

#endif
