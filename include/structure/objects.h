#ifndef OBJECT_STACK_H

#define OBJECT_STACK_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum structure_type {
  CIRCLE = 1,
  ELIPSE = 2,
  RECTANGLE = 3,
  LINE = 4,
  ARC = 5,
  VAR_TEXT = 6,
  VAR_NUMBER = 7
} StructureType;

/*
 * Each object should be represents by this Node. To store objects Drawable was
 * created a stack, declared bellow, that will keep objects to use in any time.
 */
typedef struct node {
  struct node *next;
  char *name;
  long long scope_id;
  void *structure;
  StructureType object_type;
} ObjectNode;

/*
 * When compiler is active, only one stack must be alive!
 */
typedef struct stack {
  ObjectNode *head;
} ObjectStack;

/**
 *
 */
extern ObjectStack *object_stack;

extern long long current_scope_id;

/*
 * Insert a new object into stack
 */
int push(char* name, int scope_id, void* structure,
  StructureType structure_type);

/*
 * Create node! Used by push function
 */
ObjectNode* create_object_node(char* name, int scope_id, void* structure,
  StructureType structure_type);

/*
 * Remove last element from stack
 */
ObjectNode* pop(void);

/*
 * Remove all elements in stack that have id like scope_id
 */
int remove_all_from_scope(int scope_id);

/*
 * Prints object stack from node
 */
int print_object_stack(ObjectNode* node);

/*
 * Search objects by name into stack
 */
ObjectNode* search_element(char* name);

/*
 * @deprecated
 */
ObjectNode* search_element_with_same_name(ObjectNode*, char*);

/*
 * Clean all stack
 */
void clean_stack(void);

#endif
