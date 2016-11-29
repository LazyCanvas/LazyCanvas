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
#include <stdbool.h>
#include "../structure/objects.h"
#include "drawable.h"

// how context object is called in js file
extern const char *CONTEXT;

/**
 * Set Drawable structure of figures
 *
 * @see Drawable on /figure/drawable.h
 *
 * @see Drawable on /figure/drawable.h
 */
extern const char *JS_TEMPLATE;

// All methods should use this pointer
FILE * fp;

/**
 * Draws a specific ObjectNode previously putted into object stack
 *
 * @return true if fprintf execute right
 */
int draw(ObjectNode *node);

/**
 * Set Drawable structure of figures
 *
 * @see Drawable on /figure/drawable.h
 */
int draw_drawable(Drawable *drawable);

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
 * Clean template canvas.js
 *
 * @return true if fprintf execute right
 */
int clean_canvas(void);

void print_rotate(Drawable *drawable);

void print_unrotate(Drawable *drawable);

#endif
