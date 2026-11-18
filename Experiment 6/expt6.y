%{

   #include<stdio.h>
   #include<stdlib.h>

int yylex(void);
void yyerror(char *s);

%}

%token ID DIGIT NL

%left '+''-'
%left '*''/'

%%

stmt : exp NL
     {
        printf("Valid Expression\n");
     } 

exp : exp '+' exp
    | exp '-' exp
    | exp '*' exp
    | exp '/' exp
    | DIGIT
    | ID

%%

int main()
{

printf("Enter the Expression: \n");
yyparse();
return 0;
}

void yyerror(char *s)
{
 printf("Invalid Expression\n");
}
