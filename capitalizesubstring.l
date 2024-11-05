%{
#include<stdio.h>
#include<string.h>
char replace_with[]="abc";
char replace[]="ABC";
%}
%%
"abc" {strcpy(yytext,replace);ECHO;}
%%
int yywrap()
{
return 1;
}
int main()
{
printf("Enter the string:\n");
yylex();
}
