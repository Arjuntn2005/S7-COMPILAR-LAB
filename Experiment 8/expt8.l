%{

  #include "y.tab.h"
  #include<stdlib.h>
%}

%%
[0-9]+ {
          yylval=atoi(yytext);
          return DIGIT;


       }
\n   {return NL;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}

%%

int yywrap()
{
 return 1;
}

