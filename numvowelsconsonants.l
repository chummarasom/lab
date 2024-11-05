%{
#include <stdio.h>
int v = 0;
int c = 0;
%}
%%
[ \t\n]     ;
[aeiouAEIOU] { v++; }
[a-zA-Z]    { c++; }
.           ;
%%
int yywrap() {
    return 1;
}
int main() {
    printf("Enter the string: ");
    yylex();
    printf("No of vowels = %d\n", v);
    printf("No of consonants = %d\n", c);
    return 0;
}
