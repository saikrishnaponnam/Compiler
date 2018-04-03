%{
  #include <stdio.h>
  int yyerror();
  int yylex();
  #define YYSTYPE char*
  FILE *yyin;
%}

%token DIGIT

%left '+'
%left '*'

%%

start : expr '\n'  { printf("\n");}
  ;

expr:  expr '+' expr  {printf("+ ");}
  | expr '*' expr     {printf("* ");}
  | '(' expr ')'
  | DIGIT             {printf("%s ",$1);}
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
