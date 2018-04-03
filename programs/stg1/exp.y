%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE tnode *
#include "exp.h"
#include "exp.c"
#include "codegen.c"
int yylex(void);
FILE *yyin,*target_file;
int reg;
%}

%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{$$ = $2; printf("Answer : %d\n",evaluate($1)); 
						//printf("Prefix\n"); prefix($1);printf("\nPostfix\n"); postfix($1);
						fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
						reg=codegen($1,target_file);print(reg,target_file);fprintf(target_file,"INT 10"); 
						exit(1); }
;

expr : expr PLUS expr	{$$ = makeOperatorNode('+',$1,$3);}
| expr MINUS expr 		{$$ = makeOperatorNode('-',$1,$3);}
| expr MUL expr			{$$ = makeOperatorNode('*',$1,$3);}
| expr DIV expr			{$$ = makeOperatorNode('/',$1,$3);}
| '(' expr ')'			{$$ = $2;}
| NUM					{$$ = $1;}
;

%%


yyerror(char const *s)
{
	printf("yyerror %s",s);
}


int main(void) 
{
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("output.xsm","w");
	yyparse();
	return 0;
}