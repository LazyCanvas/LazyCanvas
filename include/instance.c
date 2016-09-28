#ifndef INSTANCE_H

#define INSTANCE_H

#include "object_types.h"
#include "structure/objects.h"
#include "attribute_name.h"

/**
 * This function identifies which object type is passed pushing
 * it for object stack with your value
 */
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

void include_text_on_object_attribute(char* variable_name, char* attribute, char* text) {
  ObjectNode *node = search_element(variable_name);

  if(node == NULL) {
    printf(">>  ERROR: Attempt to access non-existing entitie %s", variable_name);
  } else {
    switch(node->object_type) {
      case CIRCLE:
        attribution_on_circle((Circle) node, attribute, text, variable_name);
      break;
      case ELIPSE:
        attribution_on_elipse((Elipse) node, attribute, text, variable_name);
      break;
      case RECTANGLE:
        attribution_on_rectange((Rectangle) node, attribute, text, variable_name);
      break;
      case LINE:
        attribution_on_line((Line) node, attribute, text, variable_name);
      break;
      case ARC:
        attribution_on_arc((Arc) node, attribute, text, variable_name);
      break;
      case VAR_TEXT:
        print_no_attribute(variable_name, attribute);
      break;
      case VAR_NUMBE:
        print_no_attribute(variable_name, attribute);
      break;
    }
  }
}

void attribution_on_circle(Circle *circle, char *attribute, char *text, char *variable_name) {
  if(strcmp(attribute, RADIUS)) {
    printf("alterando o raio");
  } else if(strcmp(attribute, BACKGROUND)) {
    printf("alterando o background");
  } else if(attribute, X) {
    printf("alterando o x");
  } else if(attribute, Y) {
    printf("alterando o y");
  } else if(strcmp(attribute, LINE_WIDTH)){
    printf("alterando o lineWidth");
  } else {
    print_no_attribute(variable_name, attribute):
  }
}

void attribution_on_elipse(Elipse *elipse, char *attribute, char *text, char *variable_name) {
  // TODO
}

void attribution_on_rectange(Rectangle *rectangle, char *attribute, char *text, char *variable_name) {
  if(strcmp(attribute, X1)) {
    printf("alterando o x1");
  } else if(strcmp(attribute, X2)) {
    printf("alterando o x2");
  } else if(strcmp(attribute, X3)) {
    printf("alterando o x3");
  } else if(strcmp(attribute, X4)) {
    printf("alterando o x4");
  } else if(strcmp(attribute, Y1)) {
    printf("alterando o y1");
  } else if(strcmp(attribute, Y2)) {
    printf("alterando o y2");
  } else if(strcmp(attribute, Y3)) {
    printf("alterando o y3");
  } else if(strcmp(attribute, Y4)) {
    printf("alterando o y4");
  } else if(strcmp(attribute, BACKGROUND)) {
    printf("alterando o background");
  } else if(strcmp(attribute, LINE_WIDTH)){
    printf("alterando o lineWidth");
  } else {
    print_no_attribute(variable_name, attribute):
  }
}

void attribution_on_line(Line* line, char *attribute, char *text, char *variable_name) {
  if(strcmp(attribute, X1)) {
    printf("alterando o x1");
  } else if(strcmp(attribute, X2)) {
    printf("alterando o x2");
  } else if(strcmp(attribute, Y1)) {
    printf("alterando o y1");
  } else if(strcmp(attribute, Y2)) {
    printf("alterando o y2");
  } else if(strcmp(attribute, BACKGROUND)) {
    printf("alterando o background");
  } else if(strcmp(attribute, LINE_WIDTH)){
    printf("alterando o lineWidth");
  } else {
    print_no_attribute(variable_name, attribute):
  }
}

void attribution_on_arc(Arc *arc, char *attribute, char *text, char *variable_name) {
  if(strcmp(attribute, CENTER_X)) {
    printf("alterando o center x");
  } else if(strcmp(attribute, CENTER_Y)) {
    printf("alterando o x2");
  } else if(strcmp(attribute, START_ANGLE)) {
    printf("alterando o start angle");
  } else if(strcmp(attribute, FINAL_ANGLE)) {
    printf("alterando o final angle");
  } else {
    print_no_attribute(variable_name, attribute):
  }
}

void print_no_attribute(char *variable_name, char *attribue) {
  printf(">> Error variable %s has no attribute %s", variable_name, attribute);
}

#endif
