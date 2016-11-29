%{
#include "structure/objects.h"
#include "figure/drawable.h"
#include "instance.h"
#include "attribution.h"
#include "figure/print.h"
#include "stack_machine.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE *yyin;
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
%token COMMA_KEYWORD

/* Some keywords */
%token END_BLOCK NEW_KEYWORD DEF_KEYWORD DRAW_KEYWORD
%token FOR_KEYWORD IN_KEYWORD RANGE_KEYWORD

/* Data */
%token VARIABLE
%token TYPES
%token NUMBER TEXT

/* Associates type with token, support only two types */

%type<numeral> Expression NUMBER
%type<string> Parameter
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
   | Input Line {}
   ;
Line:
   BREAK_LINE { printf(">>"); }
   | Expression BREAK_LINE { printf("%f\n>>",$1); }
   | Instance BREAK_LINE
   | Attribution BREAK_LINE
   | Action BREAK_LINE
   | Loop BREAK_LINE
   | Parameter BREAK_LINE { printf("Parâmetro %s", $1); }
   | END_BLOCK {
     push_instruction(HALT, NULL, NULL, NULL, 0);
     run_loop();
   }
   /* Search a variable */
   | VARIABLE BREAK_LINE {
      ObjectNode *finded = search_element($1);
      if(finded != NULL) {
        printf(">=");
        print_object(finded);
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
     if(block_type != 0) {
       push_instruction(INSTANCE, $1, $3, NULL, 0);
     } else {
       instance_object($1, $3);
     }
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
       if(block_type != 0) {
         push_instruction(ATTRIBUTION, $1, $3, NULL, 0);
       } else {
         include_text_on_object_attribute($1, $3, $5);
       }
   }
   ;
   /* Attribution of object with textual type */
   | VARIABLE DOT VARIABLE EQUALS NUMBER {
     include_number_on_object_attribute($1, $3, $5);
   }
   ;
Action:
  DRAW_KEYWORD LEFT_PARENTHESIS VARIABLE RIGHT_PARENTHESIS {
    ObjectNode *finded = search_element($3);
    if(finded == NULL) {
      printf("Variable %s not found\n", $3);
    } else {
      if(block_type != 0) {
        push_instruction(ACTION, $3, NULL, NULL, 0);
      } else {
        draw(finded);
      }
    }
  }
  ;
Parameter:
  VARIABLE { $$=$1; }
  | Parameter COMMA_KEYWORD VARIABLE {
    strcat($$, $1);
    strcat($$, ",");
    strcat($$, $3);
  }
  ;
Loop:
  FOR_KEYWORD VARIABLE IN_KEYWORD RANGE_KEYWORD LEFT_PARENTHESIS Expression COMMA_KEYWORD Expression RIGHT_PARENTHESIS {
    put_new_number($2, VAR_NUMBER, $6);
    current_scope_id++;
    printf("in range(%f, %f)\n", $6, $8);
    init_for($2, (int) $6, (int) $8);
  }
  ;
%%

int yyerror(char *s) {
   printf(">> ERROR: %s\n",s);
}

int main(int argc, char *argv[]) {
  clean_canvas();

  if(strcmp(argv[1],"-c")!=0) {
    printf("%s\n",argv[1]);
    // source file is argument 1
    FILE *entry_file = fopen(argv[1], "r");

    if(!entry_file) {
      printf("Error opening %s.\n", argv[1]);
      exit(1);
    }

    yyin = entry_file;
  } else {
   // First output interpreter
   printf(">> Welcome to LazyCanvas Console\n");
   printf(">> ");
  }

  yyparse();

  return 0;
}
