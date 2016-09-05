/**
 * This file describe type and functions about stack used to
 * work with scopes. Each scope created is stored with one id
 * that follows the pattern <father_id><self_id>. That is useful
 * to manage variable scope by example.
 */
#ifndef SCOPE_STACK_H

#define SCOPE_STACK_H

// The stack have many scopes identified by your id.
typedef struct scope {
  struct scope *next;
  char *scope_id;
} Scope;

// Each new scope has added like head of stack
typedef struct stack {
  struct scope *head;
} Stack;

// All operations are used through this pointer
Stack *scope_stack;

//Below are describe some functions of stack structure.

int init_scopes(void);

Scope* create_scope_node(char *id);

int pop(void);

char* calculate_id(char *last_scope_id);

void print_scopes(Scope*);

char* get_last_scope_id(void);

#endif
