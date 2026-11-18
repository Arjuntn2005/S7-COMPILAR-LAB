%{
#include<stdio.h>
int lines=0,chars=0,words=0;
%}

%%

[\t\r]+  ;

\n  {lines++;}

[^ \t\r\n]+  {
               words++;
               chars+=yyleng;
            }

%%

int yywrap()
{
  return 1;
}

int main()
{
   char filename[100];

   printf("Enter the input file:\n");
   scanf("%99s",filename);

   yyin=fopen(filename,"r");

   yylex();
   
   printf("Number of Characters:%d\n",chars);
   printf("Number of Lines:%d\n",lines);
   printf("Number of words:%d\n",words);

   fclose(yyin);

   return 0;
}   
