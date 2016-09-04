typedef struct object_node {
  struct object_node *next;
  struct object_node *previous;
  char *name;
  char *scope_id;
  void *structure;
} ObjectNode;

typedef struct queue {
  ObjectNode *head;
} Queue;

Queue *queue;

int insert_object_node(char*, char*, void*);
ObjectNode* create_object_node(char*, char*, void*);
int print_object_queue(ObjectNode*);

ObjectNode* search_element_with_same_name(ObjectNode*, char*);

int insert_object_node(char *name, char *scope_id, void *structure) {
  ObjectNode *new_node = create_object_node(name, scope_id, structure);

  if(queue == NULL) {
    queue = (Queue*) malloc(sizeof(Queue));
    queue->head = new_node;
  } else {
    ObjectNode *node = search_element_with_same_name(queue->head, name);
    if(node == NULL) {
      new_node->next = queue->head;
      queue->head = new_node;
    } else {
      printf("previous declarition of %s was found\n", name);
      exit(300);
    }
  }

  return 1;
}

int remove_all_from_scope(char *scope_id) {

  while(queue->head != NULL && strcmp(queue->head->scope_id, scope_id) == 0) {
    pop();
  }

  return 1;
}

int pop(void) {
  ObjectNode *node = queue->head;
  queue->head = node->next;

  free(node);
  return 1;
}

int print_object_queue(ObjectNode *node) {
  if(node == NULL) {
    return 1;
  } else {
    printf("%s - %s\n", node->name, node->scope_id);
    return print_object_queue(node->next);
  }
}

ObjectNode* search_element(char* name) {
  return search_element_with_same_name(queue->head, name);
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

ObjectNode* create_object_node(char *name, char *scope_id, void *structure) {
  ObjectNode *node = (ObjectNode*) malloc(sizeof(ObjectNode));

  node->next = NULL;
  node->previous = NULL;
  node->name = name;
  node->scope_id = scope_id;
  node->structure = structure;

  return node;
}
