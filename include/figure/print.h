void print_line(Line*);

void print_line(Line *line) {
  printf("ctx.beginPath()\n");
  printf("ctx.moveTo(%lf, %lf);\n", line->drawable->position_x, line->drawable->position_y);
  printf("ctx.lineTo(%lf, %lf);\n", line->second_position_x, line->second_position_y);
  printf("ctx.strokeStyle=\"%s\";\n", line->drawable->background);
  printf("ctx.stroke();\n");
}
