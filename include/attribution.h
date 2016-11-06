#ifndef ATTRIBUTION_H
#define ATTRIBUTION_H

#include "object_types.h"
#include "variable.h"
#include "structure/objects.h"
#include "figure/drawable.h"

/**
 * Create a new numerical variable
 *
 * See /structure/objects.h
 */
void put_new_number(char *variable_name, StructureType type, double value);

/**
 * Create a new text variable
 *
 * See /structure/objects.h
 */
void put_new_text(char *variable_name, StructureType type, char* value);

#endif
