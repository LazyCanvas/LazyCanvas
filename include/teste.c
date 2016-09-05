#include "figure/instances.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  init_scopes();
  instance_line(0.0, 0.0, 10.0, 10.0, 1, "red", "circle");
  init_scopes();

  instance_line(0.0, 0.0, 10.0, 10.0, 1, "green", "square");
  print_line(search_element("circle")->structure);
  print_line(search_element("square")->structure);

  return 0;
}
