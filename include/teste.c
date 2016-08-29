#include "figure/instances.h"

int main() {
  start();
  instance_line(0, 0, 10, 10, 1, "#fff", "circle1");
  Node *node = search(tree->root, "circle1");
  Line *line = (Line*) node->structure;
  print_line(line);
}
