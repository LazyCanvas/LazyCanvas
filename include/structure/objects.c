#include "objects.h"

/**
 *
 */
ObjectStack *object_stack = NULL;

long long current_scope_id = 0;

int push(char *name, int scope_id, void *structure, StructureType structure_type) {
  int pushed = 0;
  if(object_stack != NULL){
    ObjectNode *node = search_element(name);

    if(node != NULL){
      remove_node(name);
    }
  }

  ObjectNode *new_node = create_object_node(name, scope_id, structure,
    structure_type);

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
      int already_used_in_scope = (node->scope_id <= current_scope_id);

      if(already_used_in_scope) {
        pushed = 0;
      } else {
        new_node->next = object_stack->head;
        object_stack->head = new_node;
        pushed = 1;
      }
    }
  }

  return pushed;
}

ObjectNode* create_object_node(char *name, int scope_id, void *structure,
  StructureType structure_type) {
  ObjectNode *node = (ObjectNode*) malloc(sizeof(ObjectNode));

  node->next = NULL;
  node->name = name;
  node->scope_id = scope_id;
  node->structure = structure;
  node->object_type = structure_type;

  return node;
}

ObjectNode* pop(void) {
  ObjectNode *node = object_stack->head;
  object_stack->head = node->next;

  free(node);

  return object_stack->head;
}

int remove_all_from_scope(int scope_id) {
  // if some variable are removed, this should be set to 1
  int remove_success = 0;
  // if this scope is not the current, something is wrong
  int equals_scope = (object_stack->head->scope_id == scope_id);

  while(object_stack->head != NULL && equals_scope) {
    pop();
    remove_success = 1;
  }

  return remove_success;
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

void clean_stack() {
  while (object_stack->head != NULL) {
    ObjectNode *node = object_stack->head;
    object_stack->head = node->next;

    free(node);
  }
}
int remove_node(char* name){
  ObjectNode *node = object_stack->head;
  ObjectNode *previous = object_stack->head;

  if(node !=NULL){
    while(node != NULL){
      if(strcmp(node->name,name)==0){
        if(node == object_stack->head){
          object_stack->head = previous->next;
        }else{
          previous->next = node->next;
        }
        free(node->structure);
        free(node);
        return 1;
      }else{
        previous = node;
        node = node->next;
      }
    }
  }

  return 0;
}
