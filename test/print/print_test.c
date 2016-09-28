#include "../../include/figure/drawable.h"
#include "../../include/structure/objects.c"
#include "../../include/figure/instances.h"
#include "../../include/figure/print.h"

int main() {

  Drawable *drawable = instance_drawable("bckg", 0, 0, 1);
  Line* line = (Line*) malloc(sizeof(Line));
  line->drawable = drawable;
  line->second_position_x = 10;
  line->second_position_y = 20;

  push("a", current_scope_id, line);

  ObjectNode *node = search_element("a");
  node->object_type = LINE;

  draw(node);

  return 0;
  //
  // Rectangle *rectangle = (Rectangle*) malloc(sizeof(Rectangle));
  // rectangle->width = 50;
  // rectangle->heigth = 30;
  // draw(rectangle);
  //
  // Elipse *elipse = (Elipse*) malloc(sizeof(Elipse));
  // elipse->focus1 = 60;
  // elipse->focus2 = 70;
  // elipse->distance = 20;
  // draw(elipse);
  //
  // Arc *arc = (Arc*) malloc(sizeof(Arc));
  // arc->radius = 60;
  // arc->start_angle = 70;
  // arc->final_angle = 20;
  // arc->center_x = 10;
  // arc->center_y = 20;
  // draw(arc);

}
