#include "objects.h"

int push(char *name, int scope_id, void *structure) {
  ObjectNode *new_node = create_object_node(name, scope_id, structure);

  if(object_stack == NULL) {
    object_stack = (object_stack*) malloc(sizeof(object_stack));
    object_stack->head = new_node;
  } else {
    ObjectNode *node = search_element(name);

    if(node == NULL) {
      new_node->next = object_stack->head;
      object_stack->head = new_node;
    } else {
      printf("previous declarition of %s was found\n", name);
      exit(EXIT_FAILURE);
    }

  }

  return 1;
}

ObjectNode* create_object_node(char *name, int scope_id, void *structure) {
  ObjectNode *node = (ObjectNode*) malloc(sizeof(ObjectNode));

  node->next = NULL;
  node->name = name;
  node->scope_id = scope_id;
  node->structure = structure;

  return node;
}

ObjectNode* pop(void) {
  ObjectNode *node = object_stack->head;
  object_stack->head = node->next;

  free(node);

  return object_stack->head;
}

int remove_all_from_scope(int scope_id) {
  while(object_stack->head != NULL && (object_stack->head->scope_id == scope_id)) {
    pop();
  }

  return 1;
}

int print_object_stack(ObjectNode *node) {
  if(node == NULL) {
    return 1;
  } else {
    printf("%s - %s\n", node->name, node->scope_id);
    return print_object_stack(node->next);
  }
}

ObjectNode* search_element(char* name) {
  return search_element_with_same_name(object_stack->head, name);
}

ObjectNode* search_element_with_same_name(ObjectNode *node, char* name) {
  if(node == NULL) {
    return NULL;
  } else {
    if(strcmp(node->name, name) == 0) {
      return node;
    } else {
      return search_element_with_same_name(node->next, name);
    }
  }
}
