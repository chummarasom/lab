%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
%}
%token DIGIT ALPHA
%%
var : ALPHA
|var ALPHA
|var DIGIT;
%%
int main(int argc,char * argv[])
{
printf("Enter an Identifier:");
yyparse();
printf("\nValid Identifier\n");
return 0;
}
int yyerror()
{
printf("\nInvalid Identifier\n");
exit(1);
}
int yywrap()
{
return 1;
}
