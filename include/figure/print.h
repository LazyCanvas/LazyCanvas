/**
 * This file describes final functions of Canvas.
 * Basically, we have a parser that gets objects like Circles and Rectangles
 * and generates code in javascript to draw in HTML canvas.
 * Each function draw_* should be called only when is need draw the wanted figure.
 */
#ifndef PRINT_H

#define PRINT_H

#include <stdio.h>
#include <stdlib.h>

// how context object is called in js file
const char * CONTEXT = "ctx";

const char * JS_TEMPLATE = "../template/canvas.js";

int draw(Drawable *drawable);
int begin_path(void);
int stroke(void);
int fill(void);

int draw_rectangle(Rectangle *rectangle);
int draw_circle(Circle *circle);
int draw_elipse(Elipse *elipse);
int draw_line(Line *line);
int draw_arc(Arc *arc);

int clean_canvas(void);

// All methods should use this pointer
FILE * fp;

int draw(Drawable *drawable) {
  // only to append into model
  fp = fopen (JS_TEMPLATE, "a");

  if(drawable->background != NULL) {
    fprintf(fp, "%s.fillStyle = %s\n", CONTEXT, drawable->background);
  }

  fprintf(fp, "%s.lineWidth = %f\n", CONTEXT, drawable->line_width);

  fclose(fp);

  return 1;
}

int begin_path() {
  return fprintf(fp, "%s.begin_path();\n", CONTEXT);
}

int stroke() {
  return fprintf(fp, "%s.stroke();\n", CONTEXT);
}

int fill() {
  return fprintf(fp, "%s.fill()\n", CONTEXT);
}

int draw_circle(Circle *circle) {
  fp = fopen (JS_TEMPLATE, "a");

  begin_path();
  fprintf(fp, "%s.arc(100, 100, %f, 0, 2 * Math.PI);", CONTEXT, circle->radius);
  draw(circle->drawable);
  stroke();
  fill();

  fclose(fp);
  return 1;
}

int draw_line(Line *line) {
  fp = fopen (JS_TEMPLATE, "a");

  begin_path();
  fprintf(fp, "%s.moveTo(%f,%f)\n", CONTEXT, line->drawable->position_x,
    line->drawable->position_y);
  fprintf(fp, "%s.lineTo(%f,%f);\n", CONTEXT, line->second_position_x,
    line->second_position_y );
  stroke();
  fill();

  fclose(fp);
  return 1;
}

int draw_rectangle(Rectangle *rectangle) {
  fp = fopen (JS_TEMPLATE, "a");

  begin_path();
  fprintf(fp, "%s.rect(0,0,%f,%f);\n", CONTEXT, rectangle->width,
  rectangle->heigth );
  stroke();
  fill();

  fclose(fp);
  return 1;
}

// This command in canvas not exist
int draw_elipse(Elipse *elipse) {
  fp = fopen (JS_TEMPLATE, "a");

  begin_path();
  fprintf(fp, "%s.ellipse(0,0,%f,%f,0,0,2 * Math.PI,false);\n", CONTEXT,
  elipse->focus1, elipse->focus2);
  stroke();

  fclose(fp);
  return 1;
}

int draw_arc(Arc *arc) {
  fp = fopen (JS_TEMPLATE, "a");

  begin_path();
  fprintf(fp, "%s.arc(%f,%f,%f,%f * Math.PI , %f * Math.PI);\n", CONTEXT,
    arc->center_x, arc->center_y, arc->radius, arc->start_angle, arc->final_angle);
  stroke();

  fclose(fp);
  return 1;
}

int clean_canvas() {
  fp = fopen(JS_TEMPLATE, "w");
  fprintf(fp,"var myCanvas = document.getElementById(\"lazy_canvas\");\n");
  fprintf(fp, "var ctx = myCanvas.getContext(\"2d\");\n");
  fclose(fp);
  return 1;
}

#endif
