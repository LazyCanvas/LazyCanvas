/**
 * This file describes final functions of Canvas.
 * Basically, we have a parser that gets objects like Circles and Rectangles
 * and generates code in javascript to draw in HTML canvas.
 * Each function draw_* should be called only when is need draw the wanted figure.
 */
#ifndef PRINT_H

#define PRINT_H

#include <stdio.h> structures
#include <stdlib.h>
#include <stdbool.h>

// how context object is called in js file
const char *CONTEXT = "ctx";


/**
 * Set Drawable structure of figures
 *
 * @see Drawable on /figure/drawable.h
 *
 * @see Drawable on /figure/drawable.h
 */
const char *JS_TEMPLATE = "../../template/canvas.js";

/**
 * Draws a specific ObjectNode previously putted into object stack
 *
 * @return true if fprintf execute right
 */
int draw(ObjectNode *node);

/**
 * Init drawings in canvas declaring: ctx.beginPath();
 *
 * @return true if fprintf execute right
 */
int begin_path(void);

/**
 * Makes border of figure
 */
int stroke(void);

/**
 * Fills figure
 */
int fill(void);

/**
 * Draws structures
 *
 * @see Drawable on /figure/drawable.h
 */
int draw_rectangle(Rectangle *rectangle);
int draw_circle(Circle *circle);
int draw_elipse(Elipse *elipse);
int draw_line(Line *line);
int draw_arc(Arc *arc);

/**
 * Set Drawable structure of figures
 *
 * @see Drawable on /figure/drawable.h
 */
int draw_drawable(Drawable *drawable);

/**
 * Clean template canvas.js
 *
 * @return true if fprintf execute right
 */
int clean_canvas(void);

// All methods should use this pointer
FILE * fp;

int draw(ObjectNode *node) {
  // only to append into template file
  fp = fopen (JS_TEMPLATE, "a");

  switch(node->object_type) {
    case CIRCLE:
      draw_circle((Circle*) node->structure);
    break;
    case ELIPSE:
      draw_elipse((Elipse*) node->structure);
    break;
    case RECTANGLE:
      draw_rectangle((Rectangle*) node->structure);
    break;
    case LINE:
      draw_line((Line*) node->structure);
    break;
    case ARC:
      draw_arc((Arc*) node->structure);
    break;
    default:
      printf("Invalid Type\n");
    break;
  }

  fclose(fp);

  return 1;
}

int draw_drawable(Drawable *drawable) {
  int read_success;

  if(drawable->background != NULL) {
    read_success = fprintf(fp, "%s.fillStyle = %s\n", CONTEXT, drawable->background);
  }

  if(drawable->line_width > 0  && read_success > 0) {
    read_success = fprintf(fp, "%s.lineWidth = %f\n", CONTEXT, drawable->line_width);
  }

  if(read_success > 0) {
    read_success = stroke();
  } else {
    // TODO print error
    printf("Deu ruim\n");
  }

  if(read_success > 0) {
    read_success = fill();
  } else {
    printf("Deu ruim\n", );
  }

  int success = false;

  if(read_success > 0) {
    success = true;
  }

  return success;
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
  int read_success = begin_path();

  if(read_success > 0 ) {
    read_success = fprintf(fp, "%s.arc(%f, %f, %f, 0, 2 * Math.PI);",
      circle->drawable->position_x, circle->drawable->position_y,
      CONTEXT, circle->radius);
  }

  int success = false;
  success = draw_drawable(circle->drawable);

  if(success && read_success > 0) {
    success = true;
  } else {
    success = false;
  }

  return read_success;
}

int draw_line(Line *line) {
  int read_success = begin_path();

  if(read_success > 0) {
    read_success = fprintf(fp, "%s.moveTo(%f,%f)\n", CONTEXT,
      line->drawable->position_x, line->drawable->position_y);
    if(read_success > 0) {
      read_success = fprintf(fp, "%s.lineTo(%f,%f);\n", CONTEXT,
        line->second_position_x, line->second_position_y );
    }
  }

  int success = false;
  success = draw_drawable(line->drawable);

  if(success && read_success > 0) {
    success = true;
  } else {
    success = false;
  }

  return success;
}

int draw_rectangle(Rectangle *rectangle) {
  begin_path();
  fprintf(fp, "%s.rect(0,0,%f,%f);\n", CONTEXT, rectangle->width,
  rectangle->heigth );
  draw_drawable(rectangle->drawable);

  return 1;
}

// This command in canvas not exist
int draw_elipse(Elipse *elipse) {
  begin_path();
  fprintf(fp, "%s.ellipse(0,0,%f,%f,0,0,2 * Math.PI,false);\n", CONTEXT,
  elipse->focus1, elipse->focus2);
  draw_drawable(elipse->drawable);

  return 1;
}

int draw_arc(Arc *arc) {
  begin_path();
  fprintf(fp, "%s.arc(%f,%f,%f,%f * Math.PI , %f * Math.PI);\n", CONTEXT,
    arc->center_x, arc->center_y, arc->radius, arc->start_angle, arc->final_angle);
  draw_drawable(arc->drawable);

  return 1;
}

int clean_canvas() {
  int read_success;
  fp = fopen(JS_TEMPLATE, "w");

  read_success = fprintf(fp, "var myCanvas = document.getElementById(\"lazy_canvas\");\n");
  if(read_success > 0) {
    read_success = fprintf(fp, "var ctx = myCanvas.getContext(\"2d\");\n");
  }

  fclose(fp);

  int success = false;

  if(read_success > 0) {
    success = true;
  }

  return success;
}

#endif
