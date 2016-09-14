#include <stdio.h>
#include <stdlib.h>

// how context object is called in js file
const char * CONTEXT = "ctx";

const char * JS_TEMPLATE = "../template/canvas.js";

int draw(Drawable *drawable);

int drawCircle(Circle *circle);
int drawElipse(Elipse *elipse);
int drawArc(Arc *arc);
int drawLine(Line *line);
int drawRectangle(Rectangle *rectangle);

void drawBackground(char *background);

// All methods should use this pointer
FILE * fp;

int draw(Drawable *drawable) {
  // only to append into model
  fp = fopen (JS_TEMPLATE, "a");

  fclose(fp);

  return 1;
}

int beginPath() {
  return fprintf(fp, "%s.beginPath();\n", CONTEXT);
}

int stroke() {
  return fprintf(fp, "%s.stroke();\n", CONTEXT);
}

int drawCircle(Circle *circle) {
  fp = fopen (JS_TEMPLATE, "a");

  beginPath();
  fprintf(fp, "%s.arc(100, 100, %f, 0, 2 * Math.PI);", CONTEXT, circle->radius);
  
  printf("%d %s",circle->drawable->position_x,circle->drawable->background); 
  if(circle->drawable->background != NULL){
  fprintf(fp, "%s.fillStyle = \"%s\";\n%s.fill()\n", CONTEXT, circle->drawable->background,CONTEXT);

  }
  stroke();

  fclose(fp);
  return 1;
}

int drawLine(Line *line){
  fp = fopen (JS_TEMPLATE, "a");

  beginPath();
  fprintf(fp, "moveTo(0,0)\n");//Para desenhar a linha precisa do moveTo setado
  fprintf(fp, "%s.lineTo(%f,%f);\n", CONTEXT, line->second_position_x,
  line->second_position_y );
  stroke();

  fclose(fp);
  return 1;
}

int drawRectangle(Rectangle *rectangle){
  fp = fopen (JS_TEMPLATE, "a");

  beginPath();
  fprintf(fp, "%s.rect(0,0,%f,%f);\n", CONTEXT, rectangle->width,
  rectangle->heigth );
  stroke();

  fclose(fp);
  return 1;
}

int drawElipse(Elipse *elipse){
  fp = fopen (JS_TEMPLATE, "a");
  double center_x =0, center_y=0;

  beginPath();
  fprintf(fp, "%s.ellipse(0,0,%f,%f,0,0,2 * Math.PI,false);\n", CONTEXT,
  elipse->focus1, elipse->focus2);
  stroke();

  fclose(fp);
  return 1;
}

int drawArc(Arc *arc){
  fp = fopen (JS_TEMPLATE, "a");

  beginPath();
  fprintf(fp, "%s.arc(%f,%f,%f,%f,%f * Math.PI ,%f * Math.PI);\n", CONTEXT,
  arc->center_x, arc->center_y,arc->radius,arc->start_angle,arc->final_angle );
  stroke();

  fclose(fp);
  return 1;
}

void drawBackground(char * background) {
  fp = fopen (JS_TEMPLATE, "a");
  fprintf(fp, "%s.fillStyle = %s", CONTEXT, background);
  fprintf(fp, "%s.fillRect(0,0,lazy_canvas.width,lazy_canvas.height)", CONTEXT);
}

void cleanCanvas(){
  fp = fopen(JS_TEMPLATE,"w");
  fprintf(fp,"var myCanvas = document.getElementById(\"lazy_canvas\");\nvar ctx = myCanvas.getContext(\"2d\");\n");

}

