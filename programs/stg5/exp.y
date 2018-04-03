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
//int yydebug=1;
int yylex(void);
void yyerror(char const *s);
FILE *yyin,*target_file;
int reg,type,functype,decl=1,size=0;
char *tuplename;

%}

%token START END NL NUM STRING  ID PLUS MINUS MUL DIV INC DEC READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CNTU LT LE GT GE EQ NE
%token DECL ENDDECL MAIN1 RETURN INTG STR TUPLE POINTER 

%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE EQ NE

%%

program : GDeclarations FDeclarations mainblk	{end(target_file); printf("%d",count);}
		| GDeclarations mainblk					{end(target_file);}
		| mainblk								{end(target_file);}
		;


Body : START Slist END ';'	{$$=$2;} 
	 | START END	';'		{$$=NULL;}
	;


Slist : Slist Stmt	{$$=createtree(0,nodetype_NULL,type_null,NULL,$1,$2,NULL);} 
	  | Stmt		{$$=$1;}
	  ;

Stmt :	InputStmt		{$$=$1;} 
	|	OutputStmt		{$$=$1;}
	|	AsgStmt			{$$=$1;}
	|	IfStmt			{$$=$1;}
	|	WhileStmt		{$$=$1;}
	|	BREAK	';'		{$$=createtree(0,nodetype_BRK,type_null,NULL,NULL,NULL,NULL);}
	|	CNTU	';'		{$$=createtree(0,nodetype_CNTU,type_null,NULL,NULL,NULL,NULL);}
	|	RET 			{$$=$1;}
	;

RET : RETURN expr ';'		{$$=createtree(0,nodetype_RET,type_null,NULL,$2,NULL,NULL);}
	;

InputStmt:	READ '(' ID ')' ';' {
									Ltemp=LLookup($3->varname);
									if(Ltemp==NULL)
									{
										tempst=GLookup($3->varname);
										if(tempst==NULL)
										{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
										else $3->Gentry=tempst;
									}
									else
										$3->Lentry=Ltemp;
									$$=createtree(0,nodetype_READ,type_null,NULL,$3,NULL,NULL);
								}
		|	READ '(' ID '[' expr ']' ')' ';' {
												Ltemp=LLookup($3->varname);
												if(Ltemp==NULL)
												{
													tempst=GLookup($3->varname);
													if(tempst==NULL)
													{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
													else $3->Gentry=tempst;
												}
												else
													$3->Lentry=Ltemp;
												$$=createtree(0,nodetype_ARRREAD,type_null,NULL,$3,$5,NULL);
											 }
		|	READ '(' ID '[' expr ']' '[' expr ']' ')' ';' {
															Ltemp=LLookup($3->varname);
															if(Ltemp==NULL)
															{
																tempst=GLookup($3->varname);
																if(tempst==NULL)
																{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
																else $3->Gentry=tempst;
															}
															else
																$3->Lentry=Ltemp;
															struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,type_int,NULL,NULL,NULL,NULL);
															$5=createtree(0,nodetype_MUL,type_int,NULL,$5,temp,NULL);
															$5=createtree(0,nodetype_PLUS,type_int,NULL,$5,$8,NULL);
															$$=createtree(0,nodetype_ARRREAD,type_null,NULL,$3,$5,NULL);
														   }
	;

OutputStmt:	WRITE '(' expr ')' ';'	{$$=createtree(0,nodetype_WRITE,type_null,NULL,$3,NULL,NULL);}
	;

AsgStmt:	ID '=' expr ';'		{
									//printf("A0\n");
									Ltemp=LLookup($1->varname);
									//printf("A1\n");
									if(Ltemp==NULL)
									{
										tempst=GLookup($1->varname);
										if(tempst==NULL)
										{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
										else 
										{	
											$1->Gentry=tempst;
											if(tempst->type==type_int||tempst->type==type_intptr)
												$1->type=type_int;
											else if(tempst->type==type_char||tempst->type==type_strptr)
												$1->type=type_char;
										}
										//printf("A2\n");
									}
									else
									{
										$1->Lentry=Ltemp;
										if(Ltemp->type==type_int||Ltemp->type==type_intptr||Ltemp->type==type_argint||Ltemp->type==type_argintref)
											$1->type=type_int;
										else if(Ltemp->type==type_char||Ltemp->type==type_strptr||Ltemp->type==type_argchar||Ltemp->type==type_argcharref)
											$1->type=type_char;
										//printf("A3\n");
									}
									$$=createtree(0,nodetype_ASGN,type_null,NULL,$1,$3,NULL);
									//printf("Asgn node OK\n");
								}
		|	ID '[' expr ']' '=' expr ';'	{
												tempst=GLookup($1->varname);
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
		|	ID '[' expr ']' '[' expr ']' '=' expr ';' { tempst=GLookup($1->varname);
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
												$$=createtree(0,nodetype_ARRASGN,type_null,NULL,$1,$3,$9); 
											}
		|	MUL ID '=' expr	';'			{
											Ltemp=LLookup($2->varname);
											if(Ltemp==NULL)
											{
												tempst=GLookup($2->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$2->varname );exit(1);}
												else 
												{	
													$2->Gentry=tempst;
													if(tempst->type==type_intptr)
														$2->type=type_int;
													else if(tempst->type==type_strptr)
														$2->type=type_char;
												}
											}
											else
											{
												$2->Lentry=Ltemp;
												if(Ltemp->type==type_intptr||Ltemp->type==type_argintref)
													$2->type=type_int;
												else if(Ltemp->type==type_strptr||Ltemp->type==type_argcharref)
													$2->type=type_char;
											}
											$$=createtree(0,nodetype_PASGN,type_null,NULL,$2,$4,NULL);
										}	
			| ID '.' ID '=' expr ';'		{
												tempst=GLookup($1->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
												else 
												{	
													$1->Gentry=tempst;
													Ptemp=$1->Gentry->paramlist;
													int j=0;
													while(Ptemp!=NULL)
													{
														if(strcmp(Ptemp->name,$3->varname)==0)
															break;
														j++;
														Ptemp=Ptemp->next;
													}
													if(Ptemp==NULL)
														{yyerror("Invalid reference");exit(1);}
													if(Ptemp->type==type_int)
														$1->type=type_int;
													else if(Ptemp->type==type_char)
														$1->type=type_char;
												}	
											$$=createtree(0,nodetype_TASGN,type_null,NULL,$1,$3,$5);
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
								Ltemp=LLookup($1->varname);
								if(Ltemp==NULL)
								{
									tempst=GLookup($1->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable ");printf(" %s\n",$1->varname );exit(1);}
									else {$1->Gentry=tempst; $1->type=tempst->type;}
								}
								else
								{
									$1->Lentry=Ltemp;
									if(Ltemp->type==type_argint||Ltemp->type==type_argintref)
										$1->type=type_int;
									else if(Ltemp->type==type_argchar||Ltemp->type==type_argcharref)
										$1->type=type_char;
									else
										$1->type=Ltemp->type;	
								}
								$$ = $1;
							}
	| ID '[' expr ']'		{
								tempst=GLookup($1->varname);
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
								tempst=GLookup($1->varname);
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
								Ltemp=LLookup($2->varname);
								if(Ltemp==NULL)
								{
									tempst=GLookup($2->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$2->varname );exit(1);}
									else 
									{	
										$2->Gentry=tempst; 
										if(tempst->type==type_intptr)
											$2->type=type_int;
										else if(tempst->type==type_strptr)
											$2->type=type_char; 
									}
								}
								else
								{
									$2->Lentry=Ltemp; 
									if(Ltemp->type==type_intptr||Ltemp->type==type_argintref)
										$2->type=type_int;
									else if(Ltemp->type==type_strptr||Ltemp->type==type_argcharref)
										$2->type=type_char;
								}
								$$ = createtree(0,nodetype_POINTER,$2->type,NULL,$2,NULL,NULL);
							}
	| '&'	ID 				{
								Ltemp=LLookup($2->varname);
								if(Ltemp==NULL)
								{
									tempst=GLookup($2->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$2->varname );exit(1);}
									else
									{
										$2->Gentry=tempst; 
										if(tempst->type==type_int||tempst->type==type_intptr)
											$2->type=type_int;
										else if(tempst->type==type_char||tempst->type==type_strptr)
											$2->type=type_char;
									}
								}
								else
								{
									$2->Lentry=Ltemp; 
									if(Ltemp->type==type_int||Ltemp->type==type_intptr||Ltemp->type==type_argint||Ltemp->type==type_argintref)
										$2->type=type_int;
									else if(Ltemp->type==type_char||Ltemp->type==type_strptr||Ltemp->type==type_argchar||Ltemp->type==type_argcharref)
										$2->type=type_char;	
								}
								$$ = createtree(0,nodetype_ADDR,$2->type,NULL,$2,NULL,NULL);
							}
	| ID '(' ')'			{	
								tempst=GLookup($1->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								$1->Gentry=tempst;
								if(tempst->type==type_function_int)
									$1->type=type_int;
								else if(tempst->type==type_function_char)
									$1->type=type_char;
								$$=createtree(0,nodetype_funcall,$1->type,$1->varname,$1,NULL,NULL);
							}
	| ID '(' ArgList ')'	{
								tempst=GLookup($1->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								$1->Gentry=tempst;
								if(tempst->type==type_function_int)
									$1->type=type_int;
								else if(tempst->type==type_function_char)
									$1->type=type_char;
								else
								{
									yyerror("Variable is not a function");
									exit(1);
								}
								$$=createtree(0,nodetype_funcall,$1->type,$1->varname,$1,$3,NULL);
							}
	|	ID '.' ID 			{
								tempst=GLookup($1->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								$1->Gentry=tempst;
								Ptemp=$1->Gentry->paramlist;
								while(Ptemp!=NULL)
								{
									if(strcmp(Ptemp->name,$3->varname)==0)
										break;
									Ptemp=Ptemp->next;
								}
								if(Ptemp==NULL)
								{yyerror("Invalid reference");exit(1);}
								if(Ptemp->type==type_int)
									$1->type=type_int;
								else if(Ptemp->type==type_char)
									$1->type=type_char;
								$$=createtree(0,nodetype_tuple,$1->type,NULL,$1,$3,NULL);
							}
	;

ArgList	: ArgList ',' expr	{$$=createtree(0,nodetype_ARG,type_null,NULL,$1,$3,NULL);}
		| expr				{$$=createtree(0,nodetype_ARG,type_null,NULL,NULL,$1,NULL);}
		;

Type:	INTG 		{type=type_int;}
	|	STR 		{type=type_char;}
	|	TUPLE	ID '(' {functype=type;} ParamList ')' { Ptemp=Phead;Phead=NULL;type=type_tuple; }
	;

GDeclarations  	: DECL GDeclList ENDDECL 	{printf("Global Symbol Table\n");printsymtab();decl=0;generate(target_file);printf("GDeclarations ok\n");}
				| DECL ENDDECL				{decl=0;}
				;

GDeclList : GDeclList GDecl 				{}
		  | GDecl 							{}
		  ; 

GDecl : Type GidList ';'						{}
	  ; 

GidList : GidList ',' Gid  					{}
		| Gid 								{}
		;

Gid 	:	ID 					{
									if(type==type_tuple)
									{
										GInstall($1->varname,type,size,1,Ptemp);
									}
									else
										GInstall($1->varname,type,1,1,NULL);
								}
		|	ID '[' NUM ']'		{
									if(type==type_int)
										GInstall($1->varname,type_arrint,$3->val,1,NULL);
									else if(type==type_char)
										GInstall($1->varname,type_str,$3->val,1,NULL);
								}
		|	ID '[' NUM ']' '[' NUM ']'	{
											if(type==type_int)
												GInstall($1->varname,type_arrint,$3->val,$6->val,NULL);
											else if(type==type_char)
												GInstall($1->varname,type_str,$3->val,$6->val,NULL);
										}
		|	MUL	ID 				{
									if(type==type_int)
										GInstall($2->varname,type_intptr,1,1,NULL);
									else if(type==type_char)
										GInstall($2->varname,type_strptr,1,1,NULL);
								}
		|	ID '(' {functype=type;} ParamList ')' {
									//printf("function to enter Gtable %d\n",type);
									if(functype==type_int)
										{GInstall($1->varname,type_function_int,0,1,Phead);printf("installed fun\n");}
									else if(functype==type_char)
										{GInstall($1->varname,type_function_char,0,1,Phead);printf("installed fun\n");}
									else if(functype==type_tuple)
										{Ptemp=Phead;type=type_tuple;}
									Phead=NULL;
								}



		;



FDeclarations	: FDeclarations Fdef 		{} 
				| Fdef						{}
				; 

Fdef :	Type ID '('	{functype=type;}  ParamList ')' '{' LDeclarations Body '}' {
																//printf("%d %s\n",$9->nodetype,$9->varname);
																validateparams(functype,$2->varname,Phead);
																//printf("f1\n");
																$2->Lentry=Lhead;
																//printf("f2\n");
																tempst=GLookup($2->varname);
																//printf("f3\n");
																$2->Gentry=tempst;
																//printf("f4\n");
																codegen_func($2,$9,target_file);
																//printf("f9\n");															
																Ltemp=Lhead;						//clear LSymbol table
																while(Ltemp!=NULL)
																{
																	Lhead=Ltemp;
																	Ltemp=Ltemp->next;
																	free(Lhead->name);
																	free(Lhead);
																}
																//printf("f10\n");
																Lhead=NULL;
																lvaradrs=1;
																padrs=-3;
																Phead=NULL;
																printf("FDefinition %d ok\n",tempst->flabel);
															 }
	 ;

ParamList	: ParamList ',' Param 		{//printf("parameter installed ok\n");
										}
			| Param                     {size=1;}
			|
			;

Param 	:	Type ID 		{
								if(type==type_int) 
									type=type_argint;
								else 
									type=type_argchar;
								PInstall($2->varname,type,passtype_val);
								if(decl==0)
									LInstall($2->varname,type);
								size++;
							}
		|	Type MUL ID 	{
								if(type==type_int) 
									type=type_argintref;
								else 
									type=type_argcharref;
								PInstall($3->varname,type,passtype_ref);
								if(decl==0)
									LInstall($3->varname,type);
								size++;
							}
		;


mainblk	: INTG MAIN1 '(' ')' '{' LDeclarations Body'}'	{	
															GInstall("main",type_function_int,0,1,NULL);
															//printf("m1\n");
															$$=createtree(0,nodetype_MAIN,type_int,NULL,$7,NULL,NULL);
															//printf("m2\n");
															codegen($$,target_file);
															printf("Main function ok\n");
														}
		;


LDeclarations	: DECL LDecList ENDDECL		{} 
				| DECL ENDDECL 				{}
				|							{}
				;

LDecList	: LDecList LDecl 		{} 
			| LDecl 				{}
			;

LDecl 	:	Type IdList	';'		{} 
		; 

IdList 	: IdList ',' ID 	{LInstall($3->varname,type);} 
		| ID 				{LInstall($1->varname,type);}
		; 


%%


void yyerror(char const *s)
{
	printf("yyerror %s at line %d\n",s,lcnt);
}


int main(void) 
{
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w");
	
	lcnt=1;
	Ghead=NULL;
	Lhead=NULL;
	Phead=NULL;

	varadrs=4096;
	flabel=1;
	lvaradrs=1;
	padrs=-3;

	yyparse();
	return 0;
}