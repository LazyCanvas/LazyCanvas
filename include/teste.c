#include "figure/instances.h"

int main() {
  int *a;

  insert_object_node("circle", "1", a);
  insert_object_node("square", "1", a);
  insert_object_node("purple", "1", a);
  insert_object_node("red", "1-1", a);
  insert_object_node("rectangle", "1-1", a);
  insert_object_node("triangle", "1-1-1", a);
  insert_object_node("arc", "1-1-1", a);

  print_object_queue(queue->head);

  remove_all_from_scope("1-1-1");

  printf("\n\n");
  print_object_queue(queue->head);
  return 0;
}
