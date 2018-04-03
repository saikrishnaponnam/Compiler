%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
int arg=0,func=0;
void yyerror(char const *s);
#include "symboltable.h"
#include "abstracttree.h"
#include "abstracttree.c"
#include "symboltable.c"
#include "codegen.c"
//int yydebug=1;
int yylex(void);
FILE *yyin,*target_file;
int reg,decl=1,size=0;
struct Typetable *type,*functype;
char *tuplename;

%}

%token START END NUM STRING ID PLUS MINUS MUL DIV MOD READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CNTU LT LE GT GE EQ NE
%token DECL ENDDECL MAIN1 RETURN INTG STR TUPLE POINTER TYPE ENDTYPE ALLOC FREE INIT NUL

%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE EQ NE

%%

program : TypeDefBlock GDeclarations FDeclarations mainblk	{end(target_file); printf("%d",count);}
		| TypeDefBlock GDeclarations mainblk				{end(target_file);}
		| mainblk											{end(target_file);}
		;

TypeDefBlock  : TYPE TypeDefList ENDTYPE		{print1();}
              |                                               
              ;

TypeDefList   : TypeDefList TypeDef 			{}
              | TypeDef
              ;

TypeDef       : ID '{' {Tptr = TInstall($1->varname,0,NULL);} FieldDeclList '}'   { Tptr->fields=Fhead;Tptr->size=size;size=0;Fhead=NULL;}
              ;

FieldDeclList : FieldDeclList FieldDecl 	{}
              | FieldDecl 					{}
              ;

FieldDecl    : TypeName ID ';' 				{FInstall($2->varname,size,type);size++;}

TypeName     : INTG				{type=typeint;}
             | STR 				{type=typestr;}
             | ID       		{type=TLookup($1->varname);if(type==NULL) {printf("Invalid Type %s at line %d\n",$1->type->name,lcnt);exit(1);}}
             ;


Body : START Slist END ';'	{$$=$2;} 
	 | START END	';'		{$$=NULL;}
	;


Slist : Slist Stmt	{$$=createtree(0,nodetype_NULL,typevoid,NULL,$1,$2,NULL);} 
	  | Stmt		{$$=$1;}
	  ;

Stmt :	InputStmt		{$$=$1;} 
	|	OutputStmt		{$$=$1;}
	|	AsgStmt			{$$=$1;}
	|	IfStmt			{$$=$1;}
	|	WhileStmt		{$$=$1;}
	|	BREAK	';'		{$$=createtree(0,nodetype_BRK,typevoid,NULL,NULL,NULL,NULL);}
	|	CNTU	';'		{$$=createtree(0,nodetype_CNTU,typevoid,NULL,NULL,NULL,NULL);}
	|	RET 			{$$=$1;}
	|	FreeStmt        {$$=$1;}
	;

RET : RETURN expr ';'		{$$=createtree(0,nodetype_RET,typevoid,NULL,$2,NULL,NULL);}
	;

InputStmt:	READ '(' ID ')' ';' {
									Ltemp=LLookup($3->varname);
									if(Ltemp==NULL)
									{
										tempst=GLookup($3->varname);
										if(tempst==NULL)
										{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
										else {$3->Gentry=tempst;$3->type=tempst->type;}
									}
									else
									{
										$3->Lentry=Ltemp;
										$3->type=Ltemp->type;
									}
									$$=createtree(0,nodetype_READ,typevoid,NULL,$3,NULL,NULL);
								}
		|	READ '(' ID '[' expr ']' ')' ';' {
												tempst=GLookup($3->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
												else 
												{
													$3->Gentry=tempst;
													if(tempst->type==TLookup("arrint"))
														$3->type=typeint;
													else if(tempst->type==TLookup("arrstr"))
														$3->type=typestr;
												}
												$$=createtree(0,nodetype_ARRREAD,typevoid,NULL,$3,$5,NULL);
											 }
		|	READ '(' ID '[' expr ']' '[' expr ']' ')' ';' {
															tempst=GLookup($3->varname);
															if(tempst==NULL)
															{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
															else
															{ 
																$3->Gentry=tempst;
																if(tempst->type==TLookup("arrint"))
																	$3->type=typeint;
																else if(tempst->type==TLookup("arrstr"))
																	$3->type=typestr;
															}
															struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,typeint,NULL,NULL,NULL,NULL);
															$5=createtree(0,nodetype_MUL,typeint,NULL,$5,temp,NULL);
															$5=createtree(0,nodetype_PLUS,typeint,NULL,$5,$8,NULL);
															$$=createtree(0,nodetype_ARRREAD,typevoid,NULL,$3,$5,NULL);
														   }
		|	READ '(' FIELD ')'			{$$=createtree(0,nodetype_UREAD,typevoid,NULL,$3,NULL,NULL);}
	;

OutputStmt:	WRITE '(' expr ')' ';'	{$$=createtree(0,nodetype_WRITE,typevoid,NULL,$3,NULL,NULL);}
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
											if(tempst->type==TLookup("intptr"))
												$1->type=typeint;
											else if(tempst->type==TLookup("strptr"))
												$1->type=typestr;
											else
												$1->type=tempst->type;
										}
										//printf("A2\n");
									}
									else
									{
										$1->Lentry=Ltemp;
										if(Ltemp->type==TLookup("intptr"))
											$1->type=typeint;
										else if(Ltemp->type==TLookup("strptr"))
											$1->type=typestr;
										else
											$1->type=Ltemp->type;
										//printf("A3\n");
									}
									$$=createtree(0,nodetype_ASGN,typevoid,NULL,$1,$3,NULL);
									//printf("Asgn node OK\n");
								}
		|	ID '[' expr ']' '=' expr ';'	{
												tempst=GLookup($1->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
												else {	$1->Gentry=tempst;
														if(tempst->type==TLookup("arrint"))
															$1->type=typeint;
														else if(tempst->type==TLookup("arrstr"))
															$1->type=typestr;
													 }
												$$=createtree(0,nodetype_ARRASGN,typevoid,NULL,$1,$3,$6);
											}
		|	ID '[' expr ']' '[' expr ']' '=' expr ';' { tempst=GLookup($1->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
												else {	$1->Gentry=tempst;
														if(tempst->type==TLookup("arrint"))
															$1->type=typeint;
														else if(tempst->type==TLookup("arrstr"))
															$1->type=typestr;
													 }
												struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,typeint,NULL,NULL,NULL,NULL);
												$3=createtree(0,nodetype_MUL,typeint,NULL,$3,temp,NULL);
												$3=createtree(0,nodetype_PLUS,typeint,NULL,$3,$6,NULL);
												$$=createtree(0,nodetype_ARRASGN,typevoid,NULL,$1,$3,$9); 
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
													if(tempst->type==TLookup("intptr"))
														$2->type=typeint;
													else if(tempst->type==TLookup("strptr"))
														$2->type=typestr;
													else
														$1->type=tempst->type;
												}
											}
											else
											{
												$2->Lentry=Ltemp;
												if(Ltemp->type==TLookup("intptr"))
													$2->type=typeint;
												else if(Ltemp->type==TLookup("strptr"))
													$2->type=typestr;
												else
													$1->type=tempst->type;
											}
											$$=createtree(0,nodetype_PASGN,typevoid,NULL,$2,$4,NULL);
										}
		| ID '=' ALLOC '(' ')' ';'		{
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
													$1->type=tempst->type;
												}
											}
											else
											{
												$1->Lentry=Ltemp;
												$1->type=Ltemp->type;
											}
											$$=createtree(0,nodetype_ALLOCID,typevoid,NULL,$1,NULL,NULL);
										}
		| FIELD '=' ALLOC '(' ')' ';'	{$$=createtree(0,nodetype_ALLOCFIELD,typevoid,NULL,$1,NULL,NULL);}	
		| ID '=' INIT '(' ')' ';'		{
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
													$1->type=tempst->type;
												}
											}
											else
											{
												$1->Lentry=Ltemp;
												$1->type=Ltemp->type;
											}
											$$=createtree(0,nodetype_INIT,typevoid,NULL,$1,$3,NULL);
										}
		| FIELD '=' expr  ';'             	{$$=createtree(0,nodetype_ASGN,typevoid,NULL,$1,$3,NULL);}
	;

FreeStmt : FREE '(' ID ')' ';' 		{
										Ltemp=LLookup($3->varname);
											//printf("A1\n");
										if(Ltemp==NULL)
										{
											tempst=GLookup($3->varname);
											if(tempst==NULL)
											{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
											else 
											{	
												$3->Gentry=tempst;
												$3->type=tempst->type;
											}
										}
										else
										{
											$3->Lentry=Ltemp;
											$3->type=Ltemp->type;
										}
										$$=createtree(0,nodetype_FREE,typevoid,NULL,$3,NULL,NULL);
									}
		 | FREE '(' FIELD ')' ';' 	{$$=createtree(0,nodetype_FREE,typevoid,NULL,$3,NULL,NULL);} 
		 ;

FIELD : FIELD '.' ID 		{
								Ftemp=FLookup($1->type,$3->varname);
								if(Ftemp==NULL)
									{yyerror("Invalid member");exit(1);}
								$3->type=Ftemp->type;
								$$=createtree(0,nodetype_FIELD,$3->type,NULL,$1,$3,NULL);
							}
	  |	ID '.' ID 			{
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
										if(tempst->type==TLookup("intptr"))
											$1->type=typeint;
										else if(tempst->type==TLookup("strptr"))
											$1->type=typestr;
										else
											$1->type=tempst->type;
										Ftemp=FLookup(tempst->type,$3->varname);
										if(Ftemp==NULL)
											{yyerror("Invalid member");exit(1);}
										$3->type=Ftemp->type;
									}
										//printf("A2\n");
								}
								else
								{
									$1->Lentry=Ltemp;
									$1->type=Ltemp->type;
									Ftemp=FLookup(Ltemp->type,$3->varname);
									if(Ftemp==NULL)
										{yyerror("Invalid member");exit(1);}
									$3->type=Ftemp->type;
									//printf("A3\n");
								}
	  							$$=createtree(0,nodetype_FIELD,$3->type,NULL,$1,$3,NULL);
	  						}
	  ;

IfStmt:		IF '(' expr ')'	THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(0,nodetype_IF,typevoid,NULL,$3,$6,$8);}
	|		IF '(' expr ')' THEN Slist ENDIF ';'			{$$=createtree(0,nodetype_IF,typevoid,NULL,$3,$6,NULL);}
	;

WhileStmt:	WHILE '(' expr ')' DO Slist ENDWHILE ';'	{$$=createtree(0,nodetype_WHILE,typevoid,NULL,$3,$6,NULL);}
		 |	DO Slist WHILE '(' expr ')' ';'				{$$=createtree(0,nodetype_DOWHILE,typevoid,NULL,$5,$2,NULL);}
		 |	REPEAT Slist UNTIL '(' expr ')' ';'			{$$=createtree(0,nodetype_REPEAT,typevoid,NULL,$5,$2,NULL);}
	;	


expr : expr PLUS expr		{$$ =createtree(0,nodetype_PLUS,typeint,NULL,$1,$3,NULL);}
	| expr MINUS expr 		{$$ =createtree(0,nodetype_MINUS,typeint,NULL,$1,$3,NULL);}
	| expr MUL expr			{$$ =createtree(0,nodetype_MUL,typeint,NULL,$1,$3,NULL);}
	| expr DIV expr			{$$ =createtree(0,nodetype_DIV,typeint,NULL,$1,$3,NULL);}
	| '(' expr ')'			{$$ = $2;}
	| NUM					{$$ = $1;}
	| STRING 				{$$	= $1;}
	| NUL					{$$ = $1;}
	| expr LT expr			{$$ =createtree(0,nodetype_LT,TLookup("bool"),NULL,$1,$3,NULL);}
	| expr LE expr			{$$ =createtree(0,nodetype_LE,TLookup("bool"),NULL,$1,$3,NULL);}
	| expr GT expr			{$$ =createtree(0,nodetype_GT,TLookup("bool"),NULL,$1,$3,NULL);}
	| expr GE expr			{$$ =createtree(0,nodetype_GE,TLookup("bool"),NULL,$1,$3,NULL);}
	| expr EQ expr			{$$ =createtree(0,nodetype_EQ,TLookup("bool"),NULL,$1,$3,NULL);}
	| expr NE expr			{$$ =createtree(0,nodetype_NE,TLookup("bool"),NULL,$1,$3,NULL);}
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
									$1->type=Ltemp->type;
								}
								$$ = $1;
							}
	| ID '[' expr ']'		{
								tempst=GLookup($1->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
								else {	$1->Gentry=tempst; 
										if(tempst->type==TLookup("arrint"))
											$1->type=typeint;
										else if(tempst->type==TLookup("arrstr"))
											$1->type=typestr;
									 }
								$$ = createtree(0,nodetype_ARRID,$1->type,NULL,$1,$3,NULL);
							}

	| ID '[' expr ']' '['expr']'{
								tempst=GLookup($1->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
								else {	$1->Gentry=tempst; 
										if(tempst->type==TLookup("arrint"))
											$1->type=typeint;
										else if(tempst->type==TLookup("arrstr"))
											$1->type=typestr;
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
										if(tempst->type==TLookup("intptr"))
											$2->type=typeint;
										else if(tempst->type==TLookup("strptr"))
											$2->type=typestr;
									}
								}
								else
								{
									$2->Lentry=Ltemp; 
									if(Ltemp->type==TLookup("intptr"))
										$2->type=typeint;
									else if(Ltemp->type==TLookup("strptr"))
										$2->type=typestr;
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
										if(tempst->type==TLookup("intptr"))
											$2->type=typeint;
										else if(tempst->type==TLookup("strptr"))
											$2->type=typestr;
										else
											$2->type=tempst->type;
									}
								}
								else
								{
									$2->Lentry=Ltemp; 
									if(Ltemp->type==TLookup("intptr"))
										$2->type=typeint;
									else if(Ltemp->type==TLookup("strptr"))
										$2->type=typestr;
									else
										$2->type=Ltemp->type;	
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
								$1->type=tempst->type;
								$$=createtree(0,nodetype_funcall,$1->type,NULL,$1,NULL,NULL);
							}
	| ID '(' ArgList ')'	{
								tempst=GLookup($1->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								$1->Gentry=tempst;
								$1->type=tempst->type;
								$$=createtree(0,nodetype_funcall,$1->type,NULL,$1,$3,NULL);
							}
	| FIELD 				{$$=createtree(0,nodetype_FIELDexpr,$1->type,NULL,$1,NULL,NULL);}
	;

ArgList	: ArgList ',' expr	{$$=createtree(0,nodetype_ARG,typevoid,NULL,$1,$3,NULL);}
		| expr				{$$=createtree(0,nodetype_ARG,typevoid,NULL,NULL,$1,NULL);}
		;


GDeclarations  	: DECL GDeclList ENDDECL 	{printf("Global Symbol Table\n");printsymtab();decl=0;generate(target_file);printf("GDeclarations ok\n");}
				| DECL ENDDECL				{decl=0;}
				;

GDeclList : GDeclList GDecl 				{}
		  | GDecl 							{}
		  ; 

GDecl : TypeName GidList ';'				{}
	  ; 

GidList : GidList ',' Gid  					{}
		| Gid 								{}
		;

Gid 	:	ID 					{
									GInstall($1->varname,type,1,1,NULL);
								}
		|	ID '[' NUM ']'		{
									if(type==typeint)
										GInstall($1->varname,TLookup("arrint"),$3->val,1,NULL);
									else if(type==typestr)
										GInstall($1->varname,TLookup("arrstr"),$3->val,1,NULL);
								}
		|	ID '[' NUM ']' '[' NUM ']'	{
											if(type==typeint)
												GInstall($1->varname,TLookup("arrint"),$3->val,$6->val,NULL);
											else if(type==typestr)
												GInstall($1->varname,TLookup("arrstr"),$3->val,$6->val,NULL);
										}
		|	MUL	ID 				{
									if(type==typeint)
										GInstall($2->varname,TLookup("intptr"),1,1,NULL);
									else if(type==typestr)
										GInstall($2->varname,TLookup("strptr"),1,1,NULL);
								}
		|	ID '(' {functype=type;} ParamList ')' {
									//printf("function to enter Gtable %d\n",type);
									func=1;
									GInstall($1->varname,functype,0,1,Phead);printf("installed fun\n");
									func=0;
									Phead=NULL;
								}



		;



FDeclarations	: FDeclarations Fdef 		{} 
				| Fdef						{}
				; 

Fdef :	TypeName ID '('	{functype=type;}  ParamList ')' '{' LDeclarations Body '}' {
																//printf("%d %s\n",$9->nodetype,$9->varname);
																validateparams(functype,$2->varname,Phead);
																//printf("f1\n");
																$2->Lentry=Lhead;
																//printf("f2\n");
																tempst=GLookup($2->varname);
																//printf("f3\n");
																$2->Gentry=tempst;
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
			| Param                     {arg=0;}
			|
			;

Param 	:	TypeName ID 		{
									PInstall($2->varname,type,passtype_val);
									if(decl==0)
									{arg=1;LInstall($2->varname,type);arg=0;}
								}
		|	TypeName MUL ID 	{
									if(type==typeint)
										type=TLookup("intptr");
									else if(type==typestr)	
										type=TLookup("strptr");
									PInstall($3->varname,type,passtype_ref);
									if(decl==0)
									{arg=1;	LInstall($3->varname,type);arg=0;}
								}
		;


mainblk	: INTG MAIN1 '(' ')' '{' LDeclarations Body'}'	{	
															GInstall("main",typeint,0,1,NULL);
															//printf("m1\n");
															$$=createtree(0,nodetype_MAIN,typeint,NULL,$7,NULL,NULL);
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

LDecl 	:	TypeName IdList	';'		{} 
		; 

IdList 	: IdList ',' ID 	{arg=0;LInstall($3->varname,type);} 
		| ID 				{arg=0;LInstall($1->varname,type);}
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

	TypeTableCreate();
	typeint=TLookup("int");
	typevoid=TLookup("void");
	typestr=TLookup("str");
	
	yyparse();
	return 0;
}