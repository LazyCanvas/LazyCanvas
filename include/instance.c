#include "object_types.h"

void instance_object(char *variable_name, char *type_name) {
  void * structure;

  if(strcmp(type_name, CIRCLE_NAME) == 0) {
     structure = (Circle*) malloc(sizeof(Circle));
  }

  if(strcmp(type_name, ELIPSE_NAME) == 0) {
     structure = (Elipse*) malloc(sizeof(Elipse));
  }

  if(strcmp(type_name, RECTANGLE_NAME) == 0) {
     structure = (Rectangle*) malloc(sizeof(Rectangle));
  }

  if(strcmp(type_name, LINE_NAME) == 0) {
     structure = (Line*) malloc(sizeof(Line));
  }

  if(strcmp(type_name, ARC_NAME) == 0) {
     structure = (Arc*) malloc(sizeof(Arc));
  }

  push(variable_name, current_scope_id, structure);

  printf(">> #%s<%s>\n", variable_name, type_name);
}
