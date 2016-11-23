%{
#include "syntax.h"
%}

/* Definitions */
blank [ \t]+
/* Accept only numbers and letters beetwen (") */
text ("\"")(.+)("\"")

/* To recognize negative numbers is used a pattern in parser.y */
digit [0-9]
integer {digit}+
exponant [eE][+-]?{integer}
number {integer}("."{integer})?{exponant}?

/* It are default objects in canvas */
types (Elipse|Arc|Circle|Line|Rectangle)

/* All variable name should follow this pattern*/
variable ([a-zA-Z_][a-zA-Z0-9_]*)

%% /* Roles */

"new" return(NEW_KEYWORD);
"draw" return(DRAW_KEYWORD);
"for" return(FOR_KEYWORD);
"in" return(IN_KEYWORD);
"range" return(RANGE_KEYWORD);
"," return(COMMA_KEYWORD);
"end" return(END_BLOCK);
"if" return(IF_KEYWORD);
{blank} {/* Ignore white characters */ }


{text} {
  int string_size = sizeof(char)*strlen(yytext);
  yylval.string = (char*) malloc(string_size);
	strcpy(yylval.string, yytext);
  return(TEXT);
}

{number} {
  /* Set numeric value to token */
   yylval.numeral=atof(yytext);
   return(NUMBER);
}

{types} {
  yylval.string = strdup(yytext);
  return(TYPES);
}

{variable} {
  yylval.string = strdup(yytext);
  return(VARIABLE);
}

"+" return(PLUS);
"-" return(MINUS);
"*" return(TIMES);
"/" return(DIVIDE);
"^" return(POWER);
"(" return(LEFT_PARENTHESIS);
")" return(RIGHT_PARENTHESIS);
"=" return(EQUALS);
"\n" return(BREAK_LINE);
"." return(DOT);
%%

yywrap () {
   return 0;
}
