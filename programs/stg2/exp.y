%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
#include "abstracttree.h"
#include "abstracttree.c"
#include "codegen.c"
int yylex(void);
void yyerror(char const *s);
FILE *yyin,*target_file;
int reg;
%}

%token NUM ID PLUS MINUS MUL DIV START END NL READ WRITE
%left PLUS MINUS
%left MUL DIV

%%

program : START Slist END ';'	{printf("Evaluating tree\n"); abst_evaluate($2);
									generate($2,target_file);
								} 
		| START END			{}
	;

Slist : Slist Stmt	{$$=createtree(0,nodetype_NULL,NULL,$1,$2);} 
	| Stmt			{$$=$1;}
	;

Stmt :	InputStmt		{$$=$1;} 
	|	OutputStmt		{$$=$1;}
	|	AsgStmt			{$$=$1;}
	;

InputStmt:	READ '(' ID ')' ';' {$$=createtree(0,nodetype_READ,NULL,$3,NULL);}
	;

OutputStmt:	WRITE '(' expr ')' ';' {$$=createtree(0,nodetype_WRITE,NULL,$3,NULL);}
	;

AsgStmt:	ID '=' expr ';'		{$$=createtree(0,nodetype_ASGN,NULL,$1,$3);}
	;

expr : expr PLUS expr		{$$ =createtree(0,nodetype_PLUS,NULL,$1,$3);}
	| expr MINUS expr 		{$$ =createtree(0,nodetype_MINUS,NULL,$1,$3);}
	| expr MUL expr			{$$ =createtree(0,nodetype_MUL,NULL,$1,$3);}
	| expr DIV expr			{$$ =createtree(0,nodetype_DIV,NULL,$1,$3);}
	| '(' expr ')'			{$$ = $2;}
	| NUM					{$$ = $1;}
	| ID 					{$$ = $1;}
	;

%%


void yyerror(char const *s)
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