#include "scope.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global scope have value one like id
#define FIRST_LEVEL_ID "1"

int init_scopes(void) {

  if(scope_stack == NULL) {
    scope_stack = (Stack*) malloc(sizeof(Stack));
    scope_stack->head = create_scope_node(FIRST_LEVEL_ID);
  } else {
    char *id_last = scope_stack->head->scope_id;
    char *new_id = calculate_id(id_last);
    Scope *node = create_scope_node(new_id);
    node->next = scope_stack->head;
    scope_stack->head = node;
  }

  return 0;
}

Scope* create_scope_node(char *id) {
  Scope *node = (Scope*) malloc(sizeof(Scope));

  node->next = NULL;
  node->scope_id = id;

  return node;
}

int pop(void) {
  Scope *last = scope_stack->head;
  // TODO define boolean
  int removed = -1;

  if(last != NULL) {
    scope_stack->head = last->next;
    free(last);
    removed = 1;
  } else {
    exit(EXIT_FAILURE);
  }

  return removed;
}

char* calculate_id(char *last_scope_id) {
  char *id_token = "-";

  int new_id_lenght = strlen(last_scope_id) + strlen(id_token) + 1;
  char *new_id = (char*) malloc(new_id_lenght);

  strcpy(new_id, last_scope_id);
  strcat(new_id, id_token);

  return new_id;
}

void print_scopes(Scope *node) {
  if(node == NULL) {
    return;
  } else {
    printf("%s\n", node->scope_id);
    print_scopes(node->next);
  }
}

char* get_last_scope_id(void) {
  if(scope_stack == NULL || scope_stack->head == NULL) {
    // TODO Log
    printf("Scope head cannot be null\n");
    exit(EXIT_FAILURE);
  } else {
    return scope_stack->head->scope_id;
  }
}
