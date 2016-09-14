#include "../include/figure/drawable.h"
#include "../include/figure/print.h"
#include "../include/structure/objects.c"
#include "../include/figure/instances.h"

int main() {

  instance_circle(100, 100, 10, 2, "#fff", "circle");
  drawCircle(search_element("circle")->structure);
  instance_circle(150, 100, 10, 2, "#fff", "circle2");
  drawCircle(search_element("circle2")->structure);
  instance_line(100, 100, 150, 100, 3, "green", "line");
  drawLine(search_element("line")->structure);

  //
  // Line *line = (Line*) malloc(sizeof(Line));
  // line->second_position_x = 100;
  // line->second_position_y = 200;
  // drawLine(line);
  //
  // Rectangle *rectangle = (Rectangle*) malloc(sizeof(Rectangle));
  // rectangle->width = 50;
  // rectangle->heigth = 30;
  // drawRectangle(rectangle);
  //
  // Elipse *elipse = (Elipse*) malloc(sizeof(Elipse));
  // elipse->focus1 = 60;
  // elipse->focus2 = 70;
  // elipse->distance = 20;
  // drawElipse(elipse);
  //
  //
  // Arc *arc = (Arc*) malloc(sizeof(Arc));
  // arc->radius = 60;
  // arc->start_angle = 70;
  // arc->final_angle = 20;
  // arc->center_x = 10;
  // arc->center_y = 20;
  // drawArc(arc);

}
