%{
#include "syntax.h"
%}

/* Definitions */
blank [ \t]+
/* Accept only numbers and letters beetwen (") */
text ("\"")([a-zA-Z0-9_]*)("\"")

/* To recognize negative numbers is used a pattern in parser.y */
digit [0-9]
integer {digit}+
exponant [eE][+-]?{integer}
number {integer}("."{integer})?{exponant}?

/* It are default objects in canvas */
types (Elipse|Arc|Circle|Line|Rectangle|Canvas)

/* Supported keywords of language */
keyword (new|def)

/* All variable name should follow this pattern*/
variable ([a-zA-Z_][a-zA-Z0-9_]*)

%% /* Roles */

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

  if(!strcmp(yytext,"Canvas")){
    
    return(CANVAS);

  }
  else{

    return(TYPES);

  }

}

{keyword} {
  return(KEYWORD);
}

{variable} {
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
