#ifndef INSTANCE_H

#define INSTANCE_H value

#include "object_types.h"

void instance_object(char *variable_name, char *type_name) {
  void * structure;
  StructureType object_type;

  if(strcmp(type_name, CIRCLE_NAME) == 0) {
     structure = (Circle*) malloc(sizeof(Circle));
     object_type = CIRCLE;
  }

  if(strcmp(type_name, ELIPSE_NAME) == 0) {
     structure = (Elipse*) malloc(sizeof(Elipse));
     object_type = ELIPSE;
  }

  if(strcmp(type_name, RECTANGLE_NAME) == 0) {
     structure = (Rectangle*) malloc(sizeof(Rectangle));
     object_type = RECTANGLE;
  }

  if(strcmp(type_name, LINE_NAME) == 0) {
     structure = (Line*) malloc(sizeof(Line));
     object_type = LINE;
  }

  if(strcmp(type_name, ARC_NAME) == 0) {
     structure = (Arc*) malloc(sizeof(Arc));
     object_type = ARC;
  }

  int pushed = push(variable_name, current_scope_id, structure, object_type);

  if(pushed) {
    printf(">> #%s<%s>\n", variable_name, type_name);
  } else {
    printf(">> Variable '%s' already used\n", variable_name);
  }

}

#endif
