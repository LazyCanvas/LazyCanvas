#include "print.h"

// how context object is called in js file
const char *CONTEXT = "ctx";

/**
 * Set Drawable structure of figures
 *
 * @see Drawable on /figure/drawable.h
 *
 * @see Drawable on /figure/drawable.h
 */
const char *JS_TEMPLATE = "template/canvas.js";


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
    read_success = fprintf(fp, "%s.fillStyle = %s;\n", CONTEXT, drawable->background);
  }

  if(drawable->line_width > 0  && read_success > 0) {
    read_success = fprintf(fp, "%s.lineWidth = %f;\n", CONTEXT, drawable->line_width);
  }

  if(read_success >= 0) {
    read_success = stroke();
  } else {
    // TODO print error
  }

  if(read_success >= 0) {
    read_success = fill();
  } else {
      // TODO print error
  }

  int success = false;

  if(read_success > 0) {
    success = true;
  }

  return success;
}

int begin_path() {
  return fprintf(fp, "%s.beginPath();\n", CONTEXT);
}

int stroke() {
  return fprintf(fp, "%s.stroke();\n", CONTEXT);
}

int fill() {
  return fprintf(fp, "%s.fill();\n", CONTEXT);
}

// TODO decide how rectangle should be draw
int draw_rectangle(Rectangle *rectangle) {
   begin_path();
   print_rotate(rectangle->drawable);
   if(!rectangle->drawable->rotate)
     fprintf(fp, "%s.rect(%f,%f,%f,%f);\n", CONTEXT,
     rectangle->drawable->position_x, rectangle->drawable->position_y,
     rectangle->width,  rectangle->heigth );
   else
     fprintf(fp, "%s.rect(%f / -2,%f / -2,%f,%f);\n", CONTEXT,
     rectangle->drawable->position_x, rectangle->drawable->position_y,
     rectangle->width,  rectangle->heigth );

   draw_drawable(rectangle->drawable);

   print_unrotate(rectangle->drawable);

   //fprintf(fp, "%s.rotate(%f*Math.PI/180);\n", CONTEXT, rectangle->drawable->rotate);
   //fprintf(fp, "%s.stroke();\n", CONTEXT);
   //fprintf(fp, "%s.fill();\n", CONTEXT);
   return 1;
}

int draw_circle(Circle *circle) {
  int read_success = begin_path();

  if(read_success > 0 ) {
    read_success = fprintf(fp, "%s.arc(%f, %f, %f, 0, 2 * Math.PI);\n",
      CONTEXT, circle->drawable->position_x, circle->drawable->position_y,
      circle->radius);
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

// This command in canvas not exist
int draw_elipse(Elipse *elipse) {
  begin_path();

  float
      centerX = elipse->drawable->position_x,
      centerY = elipse->drawable->position_y,
      width = elipse->width,
      heigth = elipse->heigth;

      fprintf(fp, "%s.moveTo(%f, %f - %f/2);\n", CONTEXT, centerX, centerY, heigth);

      fprintf(fp, "%s.bezierCurveTo(%f + %f/2, %f - %f/2, %f + %f/2, %f + %f/2, %f, %f + %f/2);\n", CONTEXT,
      centerX, width, centerY, heigth, centerX, width, centerY, heigth, centerX, centerY, heigth);
      fprintf(fp, "%s.bezierCurveTo(%f - %f/2, %f + %f/2, %f - %f/2, %f - %f/2, %f, %f - %f/2);\n", CONTEXT,
      centerX, width, centerY, heigth, centerX, width, centerY, heigth, centerX, centerY, heigth);


      draw_drawable(elipse->drawable);

  return 1;
}

int draw_line(Line *line) {
  int read_success = begin_path();
  //print_rotate(line->drawable);
  if(read_success > 0) {
      if( line->drawable->rotate > 0 ){
        fprintf(fp, "%s.translate(%f,%f);\n",CONTEXT,line->drawable->position_x, line->drawable->position_y);
        fprintf(fp, "%s.rotate(%f*Math.PI/180);\n", CONTEXT, line->drawable->rotate);
      }
        read_success = fprintf(fp, "%s.moveTo(%f,%f);\n", CONTEXT,
         line->drawable->position_x, line->drawable->position_y);

      if(read_success > 0) {
      read_success = fprintf(fp, "%s.lineTo(%f,%f);\n", CONTEXT,
        line->second_position_x, line->second_position_y );
    }
  }

  int success = false;
  success = draw_drawable(line->drawable);
  //print_unrotate(line->drawable);
  if(success && read_success > 0) {
    success = true;
  } else {
    success = false;
  }
  if( line->drawable->rotate > 0 ){
    fprintf(fp, "%s.rotate(-%f*Math.PI/180);\n", CONTEXT, line->drawable->rotate);
    fprintf(fp, "%s.translate(-%f,-%f);\n",CONTEXT,line->drawable->position_x, line->drawable->position_y);
  }

  return success;
}

int draw_arc(Arc *arc) {
  begin_path();

  fprintf(fp, "%s.arc(%f,%f,%f,(%f / 180) * Math.PI , (%f / 180) * Math.PI);\n", CONTEXT,
    arc->drawable->position_x, arc->drawable->position_y,
    arc->radius, arc->start_angle + arc->drawable->rotate, arc->final_angle + arc->drawable->rotate);

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

void print_rotate(Drawable *drawable){
  if(drawable->rotate && drawable->rotate > 0) {
    fprintf(fp, "%s.translate(lazy_canvas.width / 2, lazy_canvas.height / 2);\n",CONTEXT);
    fprintf(fp, "%s.rotate(%f*Math.PI/180);\n", CONTEXT, drawable->rotate);
  }
}
void print_unrotate(Drawable *drawable){
  if(drawable->rotate && drawable->rotate > 0) {
    fprintf(fp, "%s.rotate((-1)*%f*Math.PI/180);\n", CONTEXT, drawable->rotate);
    fprintf(fp, "%s.translate(-lazy_canvas.width / 2, -lazy_canvas.height / 2);\n",CONTEXT);
  }
}
