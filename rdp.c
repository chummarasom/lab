#include<stdio.h>
#include<string.h>
char input[10];
int i=0,error=0;
void E();
void T();
void Eprime();
void Tprime();
void F();
void main()
{
  printf("Enter an arithmetic expression : ");
  scanf("%s",input);
  E();
  if(strlen(input)==i&&error==0)
  printf("\nAccepted..!!!");
  else
  printf("\nRejected..!!!");
}
void E()
{
  T();
  Eprime();
}
void Eprime()
{
  if(input[i]=='+')
  {
   i++;
   T();
   Eprime();
  }
}
void T()
{
  F();
  Tprime();
}
void Tprime()
{
  if(input[i]=='*')
  {
   i++;
   F();
   Tprime();
  }
}
void F()
{
  if(input[i]=='a')
  i++;
  else if(input[i]=='(')
  {
   i++;
   E();
   if(input[i]==')')
   i++;
   else
   error=1;
  }
  else
  error=1;
}
