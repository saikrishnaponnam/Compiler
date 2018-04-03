%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
#include "abstracttree.h"
#include "abstracttree.c"
#include "symboltable.h"
#include "symboltable.c"
#include "codegen.c"

int yylex(void);
void yyerror(char const *s);
FILE *yyin,*target_file;
int reg,type;

%}

%token START END NL NUM STRING ID PLUS MINUS MUL DIV INC DEC READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CNTU LT LE GT GE EQ NE
%token DECL ENDDECL INTG STR POINTER 

%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE EQ NE

%%

program: Declarations main {//printf("Evaluating tree\n"); 
								//abst_evaluate($2);
								generate($2,target_file);
							exit(1);}


main : START Slist END ';'	{$$=$2;} 
		| START END	';'		{}
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

InputStmt:	READ '(' ID ')' ';' {
									tempst=Lookup($3->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
									else $3->Gentry=tempst;
									$$=createtree(0,nodetype_READ,type_null,NULL,$3,NULL,NULL);
								}
		|	READ '(' ID '[' expr ']' ')' ';' {
									tempst=Lookup($3->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
									else $3->Gentry=tempst;
									$$=createtree(0,nodetype_ARRREAD,type_null,NULL,$3,$5,NULL);
								}
		|	READ '(' ID '[' expr ']' '[' expr ']' ')' ';' {
									tempst=Lookup($3->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
									else $3->Gentry=tempst;
									struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,type_int,NULL,NULL,NULL,NULL);
									$5=createtree(0,nodetype_MUL,type_int,NULL,$5,temp,NULL);
									$5=createtree(0,nodetype_PLUS,type_int,NULL,$5,$8,NULL);
									$$=createtree(0,nodetype_ARRREAD,type_null,NULL,$3,$5,NULL);
								}
	;

OutputStmt:	WRITE '(' expr ')' ';'	{$$=createtree(0,nodetype_WRITE,type_null,NULL,$3,NULL,NULL);}
	;

AsgStmt:	ID '=' expr ';'		{
									tempst=Lookup($1->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
									else {	$1->Gentry=tempst;
											if(tempst->type==type_int||tempst->type==type_intptr)
												$1->type=type_int;
											else if(tempst->type==type_char||tempst->type==type_strptr)
												$1->type=type_char;
										 }
									$$=createtree(0,nodetype_ASGN,type_null,NULL,$1,$3,NULL);
								}
		|	ID '[' expr ']' '=' expr ';'	{
												tempst=Lookup($1->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
												else {	$1->Gentry=tempst;
														if(tempst->type==type_arrint)
															$1->type=type_int;
														else if(tempst->type==type_str)
															$1->type=type_char;
													 }
												$$=createtree(0,nodetype_ARRASGN,type_null,NULL,$1,$3,$6);
											}
		|	ID '[' expr ']' '[' expr ']' '=' expr ';' { tempst=Lookup($1->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
												else {	$1->Gentry=tempst;
														if(tempst->type==type_arrint)
															$1->type=type_int;
														else if(tempst->type==type_str)
															$1->type=type_char;
													 }
												struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,type_int,NULL,NULL,NULL,NULL);
												$3=createtree(0,nodetype_MUL,type_int,NULL,$3,temp,NULL);
												$3=createtree(0,nodetype_PLUS,type_int,NULL,$3,$6,NULL);
												$$=createtree(0,nodetype_ARRASGN,type_null,NULL,$1,$3,$9); }
		|	MUL ID '=' expr	';'			{
											tempst=Lookup($2->varname);
											if(tempst==NULL)
											{yyerror("undefined Variable");printf("%s\n",$2->varname );exit(1);}
											else {	$2->Gentry=tempst;
													if(tempst->type==type_intptr)
														$2->type=type_int;
													else if(tempst->type==type_strptr)
														$2->type=type_char;
												 }
											$$=createtree(0,nodetype_PASGN,type_null,NULL,$2,$4,NULL);
										}	
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
	| STRING 				{$$	= $1;}
	| expr LT expr			{$$ =createtree(0,nodetype_LT,type_bool,NULL,$1,$3,NULL);}
	| expr LE expr			{$$ =createtree(0,nodetype_LE,type_bool,NULL,$1,$3,NULL);}
	| expr GT expr			{$$ =createtree(0,nodetype_GT,type_bool,NULL,$1,$3,NULL);}
	| expr GE expr			{$$ =createtree(0,nodetype_GE,type_bool,NULL,$1,$3,NULL);}
	| expr EQ expr			{$$ =createtree(0,nodetype_EQ,type_bool,NULL,$1,$3,NULL);}
	| expr NE expr			{$$ =createtree(0,nodetype_NE,type_bool,NULL,$1,$3,NULL);}
	| ID 					{
								tempst=Lookup($1->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable ");printf(" %s\n",$1->varname );exit(1);}
								else {$1->Gentry=tempst; $1->type=tempst->type;}
								$$ = $1;
							}
	| ID '[' expr ']'		{
								tempst=Lookup($1->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
								else {	$1->Gentry=tempst; 
										if(tempst->type==type_arrint)
											$1->type=type_int;
										else if(tempst->type==type_str)
											$1->type=type_char;
									 }
								$$ = createtree(0,nodetype_ARRID,$1->type,NULL,$1,$3,NULL);
							}
	| ID '[' expr ']' '['expr']'{
								tempst=Lookup($1->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
								else {	$1->Gentry=tempst; 
										if(tempst->type==type_arrint)
											$1->type=type_int;
										else if(tempst->type==type_str)
											$1->type=type_char;
									 }
								$$ = createtree(0,nodetype_ARRID,$1->type,NULL,$1,$3,$6);
							}
	| MUL ID				{
								tempst=Lookup($2->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$2->varname );exit(1);}
								if(tempst->type!=type_intptr&&tempst->type!=type_strptr)
								{yyerror("type mismatch");printf("%s\n",$2->varname );exit(1);}
								else {$2->Gentry=tempst; 
										if(tempst->type==type_intptr)
											$2->type=type_int;
										else if(tempst->type==type_strptr)
											$2->type=type_char;
									 }
								$$ = createtree(0,nodetype_POINTER,$2->type,NULL,$2,NULL,NULL);
							}
	| '&'	ID 				{
								tempst=Lookup($2->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$2->varname );exit(1);}
								else {$2->Gentry=tempst; 
										if(tempst->type==type_int||tempst->type==type_intptr)
											$2->type=type_int;
										else if(tempst->type==type_char||tempst->type==type_strptr)
											$2->type=type_char;
									 }
								$$ = createtree(0,nodetype_ADDR,$2->type,NULL,$2,NULL,NULL);
							}
	;

Declarations:	DECL DeclList ENDDECL	{printsymtab();}
			|	DECL ENDDECL			{}
			;

DeclList:		DeclList Decl 			{}
		|		Decl 					{}
		;

Decl:	Type VarList ';'				{}
	;

Type:	INTG 		{type=type_int;}
	|	STR 		{type=type_char;}
	;

VarList :	VarList ',' ID 		{Install($3->varname,type,1,1);}
		|	VarList ',' MUL ID 	{Install($4->varname,type,1,1);}
		|	ID 					{Install($1->varname,type,1,1);}
		|	VarList ',' ID '[' NUM ']' {		
											if(type==type_int)
												Install($3->varname,type_arrint,$5->val,1);
											else if(type==type_char)
												Install($3->varname,type_str,$5->val,1);	
										}
		|	VarList ',' ID '[' NUM ']' '[' NUM ']' {		
											if(type==type_int)
												Install($3->varname,type_arrint,$5->val,$8->val);
											else if(type==type_char)
												Install($3->varname,type_str,$5->val,$8->val);	
										}
		|	ID '[' NUM ']' '[' NUM ']'	{
											if(type==type_int)
												Install($1->varname,type_arrint,$3->val,$6->val);
											else if(type==type_char)
												Install($1->varname,type_str,$3->val,$6->val);
										}
		|	ID '[' NUM ']'		{
									if(type==type_int)
										Install($1->varname,type_arrint,$3->val,1);
									else if(type==type_char)
										Install($1->varname,type_str,$3->val,1);
								}
		|	MUL	ID 				{
									if(type==type_int)
										Install($2->varname,type_intptr,1,1);
									else if(type==type_char)
										Install($2->varname,type_strptr,1,1);
								}
		;

%%


void yyerror(char const *s)
{
	printf("yyerror %s at line %d\n",s,lcnt);
}


int main(void) 
{
	FILE *fp=fopen("input3","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w");
	lcnt=1;
	Ghead=NULL;varadrs=4096;
	yyparse();
	return 0;
}