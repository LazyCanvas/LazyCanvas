#include "../include/figure/drawable.h"
#include "../include/figure/print.h"
#include "../include/structure/objects.c"

int main() {
  Circle *circle = (Circle*) malloc(sizeof(Circle));
  circle->radius = 20;
  drawCircle(circle);
}
