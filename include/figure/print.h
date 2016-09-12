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
  stroke();

  fclose(fp);
  return 1;
}

void drawBackground(char * background) {
  fp = fopen (JS_TEMPLATE, "a");
  fprintf(fp, "%s.background = %s", CONTEXT, background);
}
