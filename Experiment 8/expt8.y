%{
  #include<stdio.h>
  #include<stdlib.h>

int yylex(void);
void yyerror(char *s);
int error=0;
%}

%token DIGIT NL

%left'+''-'
%left'*''/'

%%

stmt : exp NL
     {
        if(!error)
        printf("Result:%d\n",$1);
        
     }
     ;
exp : exp '+' exp
    {
      $$ = $1+$3;
    }
    | exp '-' exp
    {
      $$ = $1 - $3;
    }

    | exp '*' exp
    {
      $$ = $1 * $3;
    }

    | exp '/' exp
    {
      if($3==0)
       {

          yyerror("Division by zero");
          error=1;
       }
      else
       {
           $$ = $1 / $3;
       }
    }
    |DIGIT
    {
      $$=$1;
    }
    ;
%%

int main()
{
printf("Enter the Expresion:");
yyparse();
return 0;
}
void yyerror(char *s)
{
printf("Error\n");
}


