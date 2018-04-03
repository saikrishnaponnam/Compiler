%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  int yyerror();
  int yylex();
  #define YYSTYPE char*;
  FILE *yyin;
%}



%token DIGIT

%left '+'
%left '*'

%%

start : expr '\n'  { printf("3545%s\n",$1);}
  ;


expr:  expr '+' expr  {strcpy($$,strcat("+",strcat($1,$3)));}
  | expr '*' expr     {strcpy($$,strcat("*",strcat($1,$3)));}
  | '(' expr ')'      {$$=$2;}
  | DIGIT             {$$=$1;}
  ;

%%

int yyerror()
{
  printf("Error");
}

int main()
{
  FILE *fp=fopen("input","r");
  if(fp)
    yyin=fp;
  else
    printf("input file error\n");
  yyparse();
  return 1;
}
