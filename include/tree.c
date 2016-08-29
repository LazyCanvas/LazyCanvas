#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**************************************************************
* Enums                                                       *
**************************************************************/
typedef enum {
  red,
  black
}color;
typedef enum {
  CASE_ONE,
  CASE_TWO,
  CASE_THREE,
  CASE_FOUR,
  CASE_FIVE
}fix_case;

/**************************************************************
* structs                                                     *
**************************************************************/
typedef struct tree {
  struct node *root;
}Tree;

typedef struct node {
  color color_of_node;
  char *name;
  struct node *parent;
  struct node *left_child;
  struct node *right_child;
  void *structure;
}Node;

/**************************************************************
* global variables                                            *
**************************************************************/
Tree *tree;
Node *sentinel;

/**************************************************************
* functions signature                                         *
**************************************************************/
/**************************************************************
* insert funcitons                                            *
**************************************************************/
void insert(void*, char*);
Node* search_and_add(Node*, Node*);

/**************************************************************
* exibition funcitons                                         *
**************************************************************/
void print_tree(Node*);

/**************************************************************
* fix node functions                                          *
**************************************************************/
void verify_node(Node*);
fix_case wich_case(Node*);
void fix_node_case1(Node*);
void fix_node_case3(Node*);
void fix_node_case4(Node*);
void fix_node_case5(Node*);

/**************************************************************
* Create functions                                            *
**************************************************************/
void create_sentinel();
void start();
Node* create_node(void*, char*);

/**************************************************************
* Util functions                                              *
**************************************************************/
Node* uncle(Node*);
Node* grand_father(Node*);
void change_color(Node*);

int main() {
  start();
  int *a = (int*)malloc(sizeof(int));
  char name[] = "Pedro";
  char name2[] = "Marcos";
  char name3[] = "Ana";
  char name4[] = "Eduardo";
  char name5[] = "Brasil";
  char name6[] = "Giovana";

  insert(a, name);
  insert(a, name2);
  insert(a, name3);
  insert(a, name4);
  insert(a, name5);
  insert(a, name6);


  print_tree(tree->root);

  return 0;
}

/**************************************************************
* insert funcitons                                            *
**************************************************************/
void insert(void *structure, char *name) {
  Node *temp_node = create_node(structure, name);

  if(tree->root == sentinel) {
    temp_node->color_of_node = black;
    tree->root = temp_node;
  } else {
    temp_node = search_and_add(tree->root, temp_node);
    verify_node(temp_node);
  }
}

Node* search_and_add(Node* current, Node* node_to_add) {
  // go left
  if(strcmp(current->name, node_to_add->name) >= 0) {
    if(current->left_child == sentinel) {
      node_to_add->parent = current;
      current->left_child = node_to_add;
      return current->left_child;
    } else {
      return search_and_add(current->left_child, node_to_add);
    }
  }
  // goes right
  else {
    if(current->right_child == sentinel) {
      node_to_add->parent = current;
      current->right_child = node_to_add;
      return current->right_child;
    } else {
      return search_and_add(current->right_child, node_to_add);
    }
  }
}

/**************************************************************
* exibition funcitons                                         *
**************************************************************/
void print_tree(Node* node) {
  if(node == sentinel) {
    return;
  }
  print_tree(node->left_child);
  print_tree(node->right_child);
  printf("%s - %d left: %s, right: %s, parent: %s\n",node->name, node->color_of_node ,node->left_child->name, node->right_child->name, node->parent != NULL ? node->parent->name : "root");
}

/**************************************************************
* fix node functions                                          *
**************************************************************/
void verify_node(Node* node) {
  fix_case case_to_check = wich_case(node);
  switch (case_to_check) {
    case CASE_ONE:
      fix_node_case1(node);
      break;
    case CASE_TWO:
      // nothing to do because tree is valid.
      break;
    case CASE_THREE:
      fix_node_case3(node);
      break;
    case CASE_FOUR:
      fix_node_case4(node);
      break;
    case CASE_FIVE:
      fix_node_case5(node);
      break;
    default:
      printf("ERRO ON TYPE OF CASES");
      exit(400);
      break;
  }
}

fix_case wich_case(Node* node) {
  if (node->parent == NULL) {
    return CASE_ONE;
  } else {
    // parent is black.
    if(node->parent->color_of_node == black) {
      return CASE_TWO;
    }
    // parent is red.
    else {
      Node *uncle_node = uncle(node);
      Node *father = node->parent;
      Node *grand_father_node = grand_father(node);
      // uncle is red.
      if(uncle_node->color_of_node == red) {
        return CASE_THREE;
      }
      // uncle is black.
      else {
        // node is the oposite child from the father
        if((father->right_child == node && father == grand_father_node->left_child) || (father->left_child == node && father == grand_father_node->right_child)) {
          return CASE_FOUR;
        }
        // node is the same side of the father
        else {
          return CASE_FIVE;
        }
      }
    }
  }
}

void fix_node_case1(Node* node) {
  if (node->color_of_node == red) {
    node->color_of_node = black;
	} else {
	   // nothing to do.
	}
}

void fix_node_case3(Node* node) {
  Node *father = node->parent;
	Node *uncle_node = uncle(node);
	Node *grand_father_node = grand_father(node);

  father->color_of_node = black;
  uncle_node->color_of_node = black;
  grand_father_node->color_of_node = red;

	verify_node(grand_father_node);
}

void fix_node_case4(Node* node) {
  Node *father = node->parent;
  Node *grand_father_node = grand_father(node);

  if (grand_father_node->left_child == father) {
    grand_father_node->left_child = node;
  } else {
  	grand_father_node->right_child = node;
  }

  node->parent = grand_father_node;

  if (father->right_child == node) {
    father->right_child = node->left_child;
    node->left_child = father;
  } else {
    father->left_child = node->right_child;
    node->right_child = father;
  }

  father->parent = node;
  verify_node(node);
}

void fix_node_case5(Node* node) {

  Node *father = node->parent;
  Node *grand_father_node = grand_father(node);

  father->color_of_node = black;
  grand_father_node->color_of_node = red;

  if(node == father->left_child) {
    grand_father_node->left_child = father->right_child;
    grand_father_node->left_child->parent = grand_father_node;
    father->right_child = grand_father_node;
    if(grand_father_node->parent != NULL) {
      grand_father_node->parent->left_child = father;
    }
  } else {
    grand_father_node->right_child = father->left_child;
    grand_father_node->right_child->parent = grand_father_node;
    father->left_child = grand_father_node;
    if(grand_father_node->parent != NULL) {
      grand_father_node->parent->right_child = father;
    }
  }
  father->parent = grand_father_node->parent;
  grand_father_node->parent = father;

  if(grand_father_node == tree->root) {
    tree->root = father;
  }
}

/**************************************************************
* Create functions                                            *
**************************************************************/
void start() {
  tree = (Tree*) malloc(sizeof(Tree));
  create_sentinel();
  tree->root = sentinel;
}


void create_sentinel() {
  sentinel = (Node*) malloc(sizeof(Node));

  sentinel->left_child = sentinel;
  sentinel->right_child = sentinel;
  sentinel->color_of_node = black;
  sentinel->name = "sentinel";
  sentinel->structure = NULL;
}

Node* create_node(void *structure, char *name) {
  Node *temp_node = (Node*) malloc(sizeof(Node));

  temp_node->structure = structure;
  temp_node->left_child = sentinel;
  temp_node->right_child = sentinel;
  temp_node->name = name;
  temp_node->color_of_node = red;

  return temp_node;
}

/**************************************************************
* Util functions                                              *
**************************************************************/
Node* grand_father(Node* current_node) {
  if(current_node != NULL && current_node->parent != NULL) {
    return current_node->parent->parent;
  } else {
    return NULL;
  }
}

Node* uncle(Node* current_node) {
  Node *grand_father_node = grand_father(current_node);

  if(grand_father_node == NULL) {
    return NULL;
  } else {
    if(current_node->parent == grand_father_node->left_child) {
      return grand_father_node->right_child;
    } else if(current_node->parent == grand_father_node->right_child) {
      return grand_father_node->left_child;
    }
  }
}

void change_color(Node* node) {
  if(node->color_of_node == red) {
    node->color_of_node = black;
  } else {
    node->color_of_node = red;
  }
}

int is_same_direction_of_uncle(Node* node) {
  Node *father = node->parent;
  Node *grand_father_node = grand_father(node);

  if (father->left_child == node && grand_father_node->right_child == father) {
  	return 1;
  } else {
  	if (father->right_child == node && grand_father_node->left_child == father) {
  		return 1;
  	} else {
  		return 0;
  	}
  }
}
