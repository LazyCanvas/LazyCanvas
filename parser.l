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

%% /* Roles */

{blank} {/* Ignore white characters */ }

{number} {
   yylval=atof(yytext);
   return(NUMBER);
}

"+" return(PLUS);
"-" return(MINUS);
"*" return(TIMES);
"/" return(DIVIDE);
"^" return(POWER);
"(" return(LEFT_PARENTHESIS);
")" return(RIGHT_PARENTHESIS);
"\n" return(BREAK_LINE);
"end" return(END_BLOCK);
"draw" return(DRAW);
"function" return(FUNCTION);

%%

yywrap () {
   return 0;
}
