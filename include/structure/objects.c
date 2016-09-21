#include "objects.h"

int push(char *name, int scope_id, void *structure) {
  int pushed = -1;

  ObjectNode *new_node = create_object_node(name, scope_id, structure);

  if(object_stack == NULL) {
    object_stack = (ObjectStack*) malloc(sizeof(ObjectStack));
    object_stack->head = new_node;
    pushed = 1;
  } else {
    ObjectNode *node = search_element(name);

    if(node == NULL) {
      new_node->next = object_stack->head;
      object_stack->head = new_node;
      pushed = 1;
    } else {
      // An same scope can not have same variable names
      int already_used_in_scope = (node->scope_id == current_scope_id);

      if(already_used_in_scope) {
        printf("Previous declarition of %s was found\n", name);
        pushed = -1;
      } else {
        new_node->next = object_stack->head;
        object_stack->head = new_node;
        pushed = 1;
      }
    }
  }

  return pushed;
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
    printf("Name: %s | scope_id: %lld\n", node->name, node->scope_id);
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
    // function return 0 when string are equals
    int name_found = (strcmp(node->name, name) == 0);

    if(name_found) {
      return node;
    } else {
      return search_element_with_same_name(node->next, name);
    }
  }
}