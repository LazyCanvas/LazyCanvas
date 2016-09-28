%{
#include "structure/objects.c"
#include "figure/drawable.h"
#include "instance.c"
#include "attribution.c"
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
%token EQUALS DOT END_BLOCK
%token PLUS MINUS TIMES DIVIDE POWER
%token LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token BREAK_LINE

%token VARIABLE
%token TYPES
%token KEYWORD
%token NUMBER TEXT

%token CANVAS

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
   VARIABLE EQUALS TYPES DOT KEYWORD {
     instance_object($1, $3);
   }
   ;
Attribution:
   VARIABLE
   | VARIABLE EQUALS NUMBER {
     put_new_number($1, VAR_NUMBER, $3);
   }
   ;
   | VARIABLE EQUALS TEXT {
     put_new_text($1, VAR_TEXT, $3);
   }
   ;
   /* Attribution of object with numerical type */
   | VARIABLE DOT VARIABLE EQUALS TEXT {
      include_text_on_object_attribute($1, $$3, $6);
   }
   /* Attribution of object with textual type */
   | VARIABLE DOT VARIABLE EQUALS NUMBER {
     printf("Numerical Attribution\n");
   }
   ;

%%

int yyerror(char *s) {
   printf("%s\n",s);
}

int main(void) {
   printf(">> Welcome to LazyCanvas Console\n");
   printf(">> ");
   yyparse();
}
