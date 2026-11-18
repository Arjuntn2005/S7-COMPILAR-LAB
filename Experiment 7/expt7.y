%{

   #include<stdio.h>
   #include<stdlib.h>

   int yylex(void);
   void yyerror(char *s);
%}

%token ID KEYWORD NL

%%
stmt : exp NL
     {
        printf("Valid Identifier\n");
     }

exp : ID
%%

int main()
{
  printf("Enter the identifier: \n");
  yyparse();
  return 0;
}

void yyerror(char *s)
{
  printf("Invalid Identifier\n");
}
