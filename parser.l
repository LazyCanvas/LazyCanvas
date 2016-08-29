%{
#include "global.h"
#include "syntax.h"
#include <stdlib.h>
%}

/* Definitions */
blank [ \t]+
digit [0-9]
integer {digit}+
exponant [eE][+-]?{integer}
number {integer}("."{integer})?{exponant}?
types (Elipse|Arc|Circle|Line|Rectangle)
keyword (new|def)
variable ([a-zA-Z_][a-zA-Z0-9_]*)
parameter (blank|({variable}))

%% /* Roles */

{blank} {/* Ignore white characters */ }

{number} {
   yylval=atof(yytext);
   return(NUMBER);
}

{types} {
  return(TYPES);
}

{keyword} {
  return(KEYWORD);
}

{variable} {
  return(VARIABLE);
}

{parameter} {
  return(PARAMETER);
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
