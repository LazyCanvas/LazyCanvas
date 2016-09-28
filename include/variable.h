/**
 * Variables have only two types: Textual and numerical,
 * such that your attribution is dynamic
 */
#ifndef VARIABLE_H
#define VARIABLE_H

typedef struct text {
  char *value;
}Text;

typedef struct number {
  double value;
}Number;

#endif
