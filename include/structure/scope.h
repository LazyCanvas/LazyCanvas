#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
  struct node *next;
  struct node *previous;
  char *id;
} Node;

typedef struct stack {
  Node *head;
} Stack;

Stack *stack;

int create_scope(void);
Node* create_scope_node(char*);

int remove_scope(void);

Node* search_scope(char*);

void print_scope(Node*);

char* calculate_id(char*);

char*get_last_scope_id(void);

int create_scope(void) {
  char *id;
  if(stack == NULL) {
    stack = (Stack*) malloc(sizeof(Stack));
    id = "1";
    stack->head = create_scope_node(id);
  } else {
    char *id_last = stack->head->id;
    char *new_id = calculate_id(id_last);
    Node *node = create_scope_node(new_id);
    node->next = stack->head;
    stack->head = node;
  }

  return 0;
}

char* get_last_scope_id(void) {
  return stack->head->id;
}

Node* create_scope_node(char *id) {
  Node *node = (Node*) malloc(sizeof(Node));

  node->next = NULL;
  node->previous = NULL;
  node->id = id;

  return node;
}


int remove_scope(void) {
  Node *last = stack->head;
  if(last != NULL) {
    stack->head = last->next;
    free(last);
  } else {
    exit(4);
  }
  return 1;
}

void print_scope(Node *node) {
  if(node == NULL) {
    return;
  } else {
    printf("%s\n", node->id);
    print_scope(node->next);
  }
}

char* calculate_id(char* id_previous) {
  char *add_id = "-1";
  char *new_id = (char*) malloc(strlen(id_previous) + strlen(add_id) + 1);
  strcpy(new_id, id_previous);
  strcat(new_id, add_id);
  return new_id;
}
