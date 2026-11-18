#include<stdio.h>

int main()
{

char op,a[20],b[20],c[20],*instruction;
char filename[100];

printf("Enter the input filename:");
scanf("%s",filename);

FILE  *in=fopen(filename,"r");
FILE *out=fopen("output.txt","w");

while(fscanf(in," %c %s %s %s",&op,a,b,c)==4)
{
   switch(op)
         {
              case'+': instruction = "ADD"; break;
              case'-': instruction = "SUB"; break;
              case'*': instruction = "MUL"; break;
              case'/': instruction = "DIV"; break;
              case'=':
                       fprintf(out,"MOV R0 %s\nMOV %s R0\n",a,c);
                       continue;
             default:continue;

          }
           fprintf(out, "MOV R0 %s\n",a);
           fprintf(out, "%s R0 %s\n",instruction,b);
           fprintf(out, "MOV %s R0\n",c);
}

fclose(in);
fclose(out);
printf("Target Code Generated in output.txt\n");
return 0;
}

