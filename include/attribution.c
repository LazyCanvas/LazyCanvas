#include "attribution.h"

/**
 * Create a new numerical variable
 *
 * See /structure/objects.h
 */
void put_new_number(char *variable_name, StructureType type, double value) {

   Number *structure = (Number*) malloc(sizeof(Number));
   structure->value = value;

   int pushed = push(variable_name, current_scope_id, structure, type);

   if(pushed) {
      printf(">> #%s(%f)\n", variable_name, value);
   } else {
      printf(">> Variable '%s' already used\n", variable_name);
   }
}

/**
 * Create a new text variable
 *
 * See /structure/objects.h
 */
void put_new_text(char *variable_name, StructureType type, char* value) {

   Text *structure = (Text*) malloc(sizeof(Text));
   structure->value = value;

   int pushed = push(variable_name, current_scope_id, structure, type);

   if(pushed) {
      printf(">> #%s(%s)\n", variable_name, value);
   } else {
      printf(">> Variable '%s' already used\n", variable_name);
   }
}
