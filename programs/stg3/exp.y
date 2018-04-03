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

%token NUM ID PLUS MINUS MUL DIV START END NL READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE LT LE GT GE EQ NE INC DEC BREAK CNTU REPEAT UNTIL
%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE EQ NE

%%

program : START Slist END ';'	{printf("Evaluating tree\n"); //abst_evaluate($2);
									generate($2,target_file);
								} 
		| START END			{}
	;

Slist : Slist Stmt	{$$=createtree(0,nodetype_NULL,type_null,NULL,$1,$2,NULL);} 
	| Stmt			{$$=$1;}
	;

Stmt :	InputStmt		{$$=$1;} 
	|	OutputStmt		{$$=$1;}
	|	AsgStmt			{$$=$1;}
	|	IfStmt			{$$=$1;}
	|	WhileStmt		{$$=$1;}
	|	BREAK	';'		{$$=createtree(0,nodetype_BRK,type_null,NULL,NULL,NULL,NULL);}
	|	CNTU	';'		{$$=createtree(0,nodetype_CNTU,type_null,NULL,NULL,NULL,NULL);}
	;

InputStmt:	READ '(' ID ')' ';' {$$=createtree(0,nodetype_READ,type_null,NULL,$3,NULL,NULL);}
	;

OutputStmt:	WRITE '(' expr ')' ';' {$$=createtree(0,nodetype_WRITE,type_null,NULL,$3,NULL,NULL);}
	;

AsgStmt:	ID '=' expr ';'		{$$=createtree(0,nodetype_ASGN,type_null,NULL,$1,$3,NULL);}
	;



IfStmt:		IF '(' expr ')'	THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(0,nodetype_IF,type_null,NULL,$3,$6,$8);}
	|		IF '(' expr ')' THEN Slist ENDIF ';'			{$$=createtree(0,nodetype_IF,type_null,NULL,$3,$6,NULL);}
	;

WhileStmt:	WHILE '(' expr ')' DO Slist ENDWHILE ';'	{$$=createtree(0,nodetype_WHILE,type_null,NULL,$3,$6,NULL);}
		 |	DO Slist WHILE '(' expr ')' ';'				{$$=createtree(0,nodetype_DOWHILE,type_null,NULL,$5,$2,NULL);}
		 |	REPEAT Slist UNTIL '(' expr ')' ';'			{$$=createtree(0,nodetype_REPEAT,type_null,NULL,$5,$2,NULL);}
	;	


expr : expr PLUS expr		{$$ =createtree(0,nodetype_PLUS,type_int,NULL,$1,$3,NULL);}
	| expr MINUS expr 		{$$ =createtree(0,nodetype_MINUS,type_int,NULL,$1,$3,NULL);}
	| expr MUL expr			{$$ =createtree(0,nodetype_MUL,type_int,NULL,$1,$3,NULL);}
	| expr DIV expr			{$$ =createtree(0,nodetype_DIV,type_int,NULL,$1,$3,NULL);}
	| '(' expr ')'			{$$ = $2;}
	| NUM					{$$ = $1;}
	| ID 					{$$ = $1;}
	| expr LT expr			{$$ =createtree(0,nodetype_LT,type_bool,NULL,$1,$3,NULL);}
	| expr LE expr			{$$ =createtree(0,nodetype_LE,type_bool,NULL,$1,$3,NULL);}
	| expr GT expr			{$$ =createtree(0,nodetype_GT,type_bool,NULL,$1,$3,NULL);}
	| expr GE expr			{$$ =createtree(0,nodetype_GE,type_bool,NULL,$1,$3,NULL);}
	| expr EQ expr			{$$ =createtree(0,nodetype_EQ,type_bool,NULL,$1,$3,NULL);}
	| expr NE expr			{$$ =createtree(0,nodetype_NE,type_bool,NULL,$1,$3,NULL);}
	;

%%


void yyerror(char const *s)
{
	printf("yyerror %s",s);
}


int main(void) 
{
	FILE *fp=fopen("bubblesort","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w");
	yyparse();
	return 0;
}