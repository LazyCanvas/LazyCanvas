%{
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
   VARIABLE EQUALS TYPES DOT KEYWORD { printf("New instance \n"); }
   | VARIABLE EQUALS CANVAS DOT KEYWORD 
     {  
        FILE * fp;

        fp = fopen ("template/canvas.html", "w+");
        fprintf(fp, "<!DOCTYPE html>\n");
        fprintf(fp, "<html>\n");
        fprintf(fp, "<body>\n");
        fprintf(fp, "<canvas id=\"myCanvas\" width=\"100\" height=\"100\"\n");
        fprintf(fp, "style=\"border:1px solid #c3c3c3;\">\n");
        fprintf(fp, "Your browser does not support the canvas element.\n");
        fprintf(fp, "</canvas>\n");
        fprintf(fp, "<script>\n");
        fprintf(fp, "var canvas = document.getElementById(\"myCanvas\");\n");
        fprintf(fp, "var ctx = canvas.getContext(\"2d\");\n");
        fprintf(fp, "ctx.fillStyle = \"#FF0000\";\n");
        fprintf(fp, "ctx.fillRect(0,0,150,75);\n");
        fprintf(fp, "</script>\n");

        fprintf(fp, "</body>\n");
        fprintf(fp, "</html>\n");
           
        fclose(fp);
      
        printf("Canvas criado e armazenado na pasta template!\n");
     }
   ;
Attribution:
   VARIABLE EQUALS NUMBER { printf("Number passed!\n"); }
   |
   VARIABLE EQUALS TEXT { printf("Text passed\n"); }
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
