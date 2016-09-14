#include "../include/figure/drawable.h"
#include "../include/figure/print.h"
#include "../include/structure/objects.c"

int main() {
  Circle *circle = (Circle*) malloc(sizeof(Circle));
  circle->radius = 20;
  drawCircle(circle);

  Line *line = (Line*) malloc(sizeof(Line));
  line->second_position_x = 100;
  line->second_position_y = 200;
  drawLine(line);

  Rectangle *rectangle = (Rectangle*) malloc(sizeof(Rectangle));
  rectangle->width = 50;
  rectangle->heigth = 30;
  drawRectangle(rectangle);

  Elipse *elipse = (Elipse*) malloc(sizeof(Elipse));
  elipse->focus1 = 60;
  elipse->focus2 = 70;
  elipse->distance = 20;
  drawElipse(elipse);


  Arc *arc = (Arc*) malloc(sizeof(Arc));
  arc->radius = 60;
  arc->start_angle = 70;
  arc->final_angle = 20;
  arc->center_x = 10;
  arc->center_y = 20;
  drawArc(arc);

}
