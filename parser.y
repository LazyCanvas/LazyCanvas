%{
#include "structure/objects.h"
#include "figure/drawable.h"
#include "instance.h"
#include "attribution.h"
#include "figure/print.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int yylex();
%}

/* This part define which types syntax will work */
%union {
  char * string;
  double numeral;
}

/* Operators */
%token EQUALS DOT
%token PLUS MINUS TIMES DIVIDE POWER
%token LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token BREAK_LINE

/* Some keywords */
%token END_BLOCK NEW_KEYWORD DEF_KEYWORD DRAW_KEYWORD

/* Data */
%token VARIABLE
%token TYPES
%token NUMBER TEXT

/* Associates type with token, support only two types */
%type<numeral> Expression NUMBER
%type<string> TEXT
%type<string> VARIABLE
%type<string> TYPES

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER

%start Input

%%

Input:
   /* Empty */
   | Input Line { printf(">> "); }
   ;
Line:
   BREAK_LINE
   | Expression BREAK_LINE { printf(">> %f\n",$1); }
   | Instance BREAK_LINE
   | Attribution BREAK_LINE
   | Action BREAK_LINE
   /* Search a variable */
   | VARIABLE BREAK_LINE {
      ObjectNode *finded = search_element($1);
      if(finded != NULL) {
        // TODO print variable value
        printf(">> %s\n", finded->name);
      } else {
        printf(">> Variable not exists\n");
      }
   }
   ;
Expression:
   NUMBER { $$=$1; }
   | Expression PLUS Expression { $$=$1+$3; }
   | Expression MINUS Expression { $$=$1-$3; }
   | Expression TIMES Expression { $$=$1*$3; }
   | Expression DIVIDE Expression { $$=$1/$3; }
   | MINUS Expression %prec NEG { $$=-$2; }
   | Expression POWER Expression { $$=pow($1,$3); }
   | LEFT_PARENTHESIS Expression RIGHT_PARENTHESIS { $$=$2; }
   ;
Instance:
   VARIABLE EQUALS TYPES DOT NEW_KEYWORD {
     instance_object($1, $3);
   }
   ;
Attribution:
   VARIABLE EQUALS Expression {
     put_new_number($1, VAR_NUMBER, $3);
   }
   ;
   | VARIABLE EQUALS TEXT {
     put_new_text($1, VAR_TEXT, $3);
   }
   ;
   /* Attribution of object with numerical type */
   | VARIABLE DOT VARIABLE EQUALS TEXT {
      include_text_on_object_attribute($1, $3, $5);
   }
   ;
   /* Attribution of object with textual type */
   | VARIABLE DOT VARIABLE EQUALS NUMBER {
     include_number_on_object_attribute($1, $3, $5);
   }
   ;
Action:
  DRAW_KEYWORD LEFT_PARENTHESIS VARIABLE RIGHT_PARENTHESIS {
    printf("Draw %s was called\n", $3);

    ObjectNode *finded = search_element($3);
    if(finded == NULL) {
      printf("Variable %s not found\n", $3);
    } else {
      draw(finded);
    }
  }
%%

int yyerror(char *s) {
   printf(">> ERROR: %s\n",s);
}

int main(void) {
   printf(">> Welcome to LazyCanvas Console\n");
   printf(">> ");
   yyparse();
}
