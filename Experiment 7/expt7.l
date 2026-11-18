%{

 #include"y.tab.h"

%}

%%
"int"|"double"|"switch"|"char"|"if"|"else"|"while"|"for" { return KEYWORD;}

[a-zA-z_][a-zA-Z0-9_]* { return ID;}

\n    return NL;
%%

int yywrap()
{
return 1;
}

