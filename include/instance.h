#ifndef INSTANCE_H

#define INSTANCE_H

#include "object_types.h"
#include "structure/objects.h"
#include "attribute_name.h"
#include "figure/drawable.h"

void instance_object(char *variable_name, char *type_name);

void include_text_on_object_attribute(char* variable_name, char* attribute, void* text);

void include_number_on_object_attribute(char* variable_name, char* attribute, double number);

void attribution_on_circle(Circle *circle, char *attribute, void *text, char *variable_name);

void attribution_on_elipse(Elipse *elipse, char *attribute, void *text, char *variable_name);

void attribution_on_rectange(Rectangle *rectangle, char *attribute, void *text, char *variable_name);

void attribution_on_line(Line* line, char *attribute, void *text, char *variable_name);

void attribution_on_arc(Arc *arc, char *attribute, void *text, char *variable_name);

void print_no_attribute(char *variable_name, char *attribue);

double parse_double(void* text);

Drawable* init_drawable();

#endif
