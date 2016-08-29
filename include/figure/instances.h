#include "../structure/tree.h"
#include "drawable.h"
#include "print.h"

/*********************************************************
* Funções de instanciação                                *
*********************************************************/
/*
* param: double position_x
* param: double position_y
* param: double second_position_x
* param: double second_position_y
* param: double line_width
* param: char *background
* param: char *name
*/
void instance_line(double, double, double, double, double, char*, char*);


Drawable* instance_drawable(char*, double, double, double);
/*********************************************************
* Implementação das funções                              *
*********************************************************/
void instance_line(double position_x, double position_y, double second_position_x, double second_position_y, double line_width, char *background, char *name) {

  Drawable *drawable = instance_drawable(background, position_x, position_y, line_width);
  Line* line = (Line*) malloc(sizeof(Line));
  line->drawable = drawable;
  line->second_position_x = second_position_x;
  line->second_position_y = second_position_y;

  insert(line, name);
}

Drawable* instance_drawable(char* background, double position_x, double position_y, double line_width) {
  Drawable *drawable = (Drawable*) malloc(sizeof(Drawable));
  drawable->background = background;
  drawable->position_x = position_x;
  drawable->position_y = position_y;
  drawable->line_width = line_width;

  return drawable;
}
