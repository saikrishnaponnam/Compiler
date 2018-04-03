%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
int arg=0,func=0;
void yyerror(char const *s);
#include "abstracttree.h"
#include "symboltable.h"
struct Classtable *Cptr;
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
%token CLASS ENDCLASS SELF Extends NEW DELETE BRKP

%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT LE GT GE EQ NE

%%

program : TypeDefBlock ClassDefBlock GDeclarations FDeclarations mainblk	{end(target_file); printf("%d",count);}
		;

TypeDefBlock  : TYPE TypeDefList ENDTYPE		{print1();generate(target_file);}
              |                                	{generate(target_file);}               
              ;

TypeDefList   : TypeDefList TypeDef 			{}
              | TypeDef 						{}
              ;

TypeDef       : ID '{' {Tptr = TInstall($1->varname,0,NULL);} FieldDeclList '}'   { Tptr->fields=Fhead;Tptr->size=size;size=0;Fhead=NULL;}
              ;

FieldDeclList : FieldDeclList FieldDecl 	{}
              | FieldDecl 					{}
              ;

FieldDecl    : TypeName ID ';' 				{FInstall($2->varname,size,type);size++;}

TypeName     : INTG				{type=typeint;}
             | STR 				{type=typestr;}
             | ID       		{
	             					type=TLookup($1->varname);
	             					if(type==NULL) 
	             					{
	             						Cptr=CLookup($1->varname); 
	             						if(Cptr==NULL)
	             						{printf("Invalid Type %s at line %d\n",$1->varname,lcnt);exit(1);}
             						}
             					}
             ;

ClassDefBlock : CLASS ClassDefList ENDCLASS		{Cptr=NULL;print2();}
              |									{Cptr=NULL;}
              ;

ClassDefList : ClassDefList ClassDef 			{}
             | ClassDef 						{}
			 ;

ClassDef     : Cname '{' DECL Fieldlists MethodDecl {decl=0;} ENDDECL MethodDefns '}'  {printf("Class OK\n");decl=1;}
			 ;

Cname        : ID       		{Cptr = CInstall($1->varname,NULL);printf("Class %s installed %d\n",$1->varname,varadrs-8);}         
             | ID Extends ID	{Cptr = CInstall($1->varname,$3->varname);printf("Derived %s Class installed %d\n",$1->varname,varadrs-8);}
			 ;

Fieldlists 	: Fieldlists Fld  	{} 
			|
			;   

Fld         : ID ID ';'				{Class_Finstall(Cptr,$1->varname,$2->varname);} //Installing the field to the class
			| INTG ID ';'			{Class_Finstall(Cptr,"int",$2->varname);}
			| STR ID ';'			{Class_Finstall(Cptr,"str",$2->varname);}
			;

MethodDecl  : MethodDecl MDecl 		{}
	   		| MDecl 				{}
			;

MDecl     : ID ID '(' ParamList ')' ';' {Class_Minstall(Cptr,$2->varname,TLookup($1->varname),Phead);Phead=NULL;} //Installing the method to class
		  | INTG ID '(' ParamList ')' ';' {Class_Minstall(Cptr,$2->varname,typeint,Phead);Phead=NULL;}
		  | STR ID '(' ParamList ')' ';' {Class_Minstall(Cptr,$2->varname,typestr,Phead);Phead=NULL;}
		  ;

MethodDefns : MethodDefns Fdef 		{}
            | Fdef 					{}
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
	|	BRKP			{$$=createtree(0,nodetype_BRKP,typevoid,NULL,NULL,NULL,NULL);}
	;

RET : RETURN expr ';'		{$$=createtree(0,nodetype_RET,typevoid,NULL,$2,NULL,NULL);}
	;

InputStmt:	READ '(' ID ')' ';' {	//ID will be of type int or str
									setID($3,0);
									$$=createtree(0,nodetype_READ,typevoid,NULL,$3,NULL,NULL);
								}
		| READ '(' ID '[' expr ']' ')' ';' {
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
		| READ '(' ID '[' expr ']' '[' expr ']' ')' ';' {
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
		| READ '(' FIELD ')'	';'		{$$=createtree(0,nodetype_UREAD,typevoid,NULL,$3,NULL,NULL);}
	;

OutputStmt:	WRITE '(' expr ')' ';'	{$$=createtree(0,nodetype_WRITE,typevoid,NULL,$3,NULL,NULL);}
	;

AsgStmt: ID '=' expr ';'		{
									setID($1,1);
									$$=createtree(0,nodetype_ASGN,typevoid,NULL,$1,$3,NULL);
									$$->cptr=$1->cptr;
									//printf("Asgn node OK %s\n",$1->varname);
								}
		| ID '[' expr ']' '=' expr ';'	{
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
		| ID '[' expr ']' '[' expr ']' '=' expr ';' { tempst=GLookup($1->varname);
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
		| MUL ID '=' expr	';'			{
											setID($2,1);
											$$=createtree(0,nodetype_PASGN,typevoid,NULL,$2,$4,NULL);
										}
		| FIELD '=' expr  ';'           {$$=createtree(0,nodetype_ASGN,typevoid,NULL,$1,$3,NULL);$$->cptr=$1->cptr;}
		| ID '=' ALLOC '(' ')' ';'		{
											setID($1,0);
											$$=createtree(0,nodetype_ALLOCID,typevoid,NULL,$1,NULL,NULL);
										}
		| FIELD '=' ALLOC '(' ')' ';'	{$$=createtree(0,nodetype_ALLOCFIELD,typevoid,NULL,$1,NULL,NULL);}	
		| ID '=' INIT '(' ')' ';'		{
											setID($1,0);
											$$=createtree(0,nodetype_INIT,typevoid,NULL,$1,$3,NULL);
										}
		| ID '=' NEW '(' ID ')' ';'			{
												tempst=GLookup($1->varname);
												if(tempst==NULL)
													{yyerror("undefined Variable");exit(1);}
												$1->Gentry=tempst;
												$1->cptr=tempst->cptr;
												$5->cptr=CLookup($5->varname);
												$$=createtree(0,nodetype_NEW,typevoid,NULL,$1,$5,NULL);
											}
		| FIELD '=' NEW '(' ID ')' ';' 		{
												$5->cptr=CLookup($5->varname);
												$$=createtree(0,nodetype_NEW,typevoid,NULL,$1,$5,NULL);
											}
	;

FreeStmt : FREE '(' ID ')' ';' 			{
											setID($3,0);
											$$=createtree(0,nodetype_FREE,typevoid,NULL,$3,NULL,NULL);
										}
		 | FREE '(' FIELD ')' ';' 		{$$=createtree(0,nodetype_FREE,typevoid,NULL,$3,NULL,NULL);} 
		 | DELETE '(' FIELD ')' ';'		{$$=createtree(0,nodetype_FREE,typevoid,NULL,$3,NULL,NULL);}
		 | DELETE '(' ID ')' ';'		{
											setID($3,0);
											$$=createtree(0,nodetype_FREE,typevoid,NULL,$3,NULL,NULL);
										}
		 ;

FIELD : FIELD '.' ID 		{	//right most of Field can't be a class variable it must be a type variable
								if($1->type==NULL)
									{yyerror("Invalid Reference");exit(1);}
								Ftemp=FLookup($1->type,$3->varname);
								if(Ftemp==NULL)
									{yyerror("Invalid Member");exit(1);}
								$3->type=Ftemp->type;
								$3->cptr=NULL;
								$$=createtree(0,nodetype_FIELD,$3->type,NULL,$1,$3,NULL);
								$$->cptr=NULL;
							}
	  |	ID '.' ID 			{	//will not occur for class variables i.e. ID1 can't be class variable
	  							Ltemp=LLookup($1->varname);
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
											{yyerror("Invalid Member");exit(1);}
										$3->type=Ftemp->type;
										$3->cptr=NULL;
									}
								}
								else
								{
									$1->Lentry=Ltemp;
									$1->type=Ltemp->type;
									Ftemp=FLookup(Ltemp->type,$3->varname);
									if(Ftemp==NULL)
										{yyerror("Invalid Member");exit(1);}
									$3->type=Ftemp->type;
									$3->cptr=NULL;
								}
	  							$$=createtree(0,nodetype_FIELD,$3->type,NULL,$1,$3,NULL);
	  							$$->cptr=NULL;
	  						}
	  | SELF '.' ID 		{	//ID can be class or type variable
	  							//printf("%s %s S1\n",$1->varname,$3->varname);
	  							Ltemp=LLookup("self");
	  							if(Ltemp==NULL)
	  								{yyerror("Invalid Refernce");exit(1);}
	  							$1->Lentry=Ltemp;
	  							$1->cptr=Cptr;
	  							Ftemp=CFLookup(Cptr,$3->varname);
	  							if(Ftemp==NULL)
									{yyerror("Invalid Member Field");exit(1);}
								$3->cptr=Ftemp->cptr;
								$3->type=Ftemp->type;
								$$=createtree(0,nodetype_FIELD,$3->type,NULL,$1,$3,NULL);
								$$->cptr=$3->cptr;
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
	| expr MOD expr			{$$ =createtree(0,nodetype_MOD,typeint,NULL,$1,$3,NULL);}
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
								setID($1,0);
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
								setID($2,1);
								$$ = createtree(0,nodetype_POINTER,$2->type,NULL,$2,NULL,NULL);
							}
	| '&'	ID 				{
								setID($2,1);
								$$ = createtree(0,nodetype_ADDR,$2->type,NULL,$2,NULL,NULL);
							}
	| ID '(' ArgList ')'	{
								tempst=GLookup($1->varname);
								if(tempst==NULL)
								{
									yyerror("Undefined function");
									exit(1);
								}
								$1->Gentry=tempst;
								$1->type=tempst->type;
								if(!comparearglist(tempst->paramlist,$3))
								{
									printf("Arguments count mismatach\n");exit(1);
								}
								$$=createtree(0,nodetype_funcall,$1->type,NULL,$1,$3,NULL);
							}
	| FIELD 				{$$=createtree(0,nodetype_FIELDexpr,$1->type,NULL,$1,NULL,NULL);}
	| FieldFunction			{
								printf("method call %s\n",$1->right->varname);
								$$=createtree(0,nodetype_funcall,$1->type,NULL,$1->right,$1->end,$1->left);
								//printf("ff7\n");
							}
	;

ArgList	: ArgList ',' expr	{$$=createtree(0,nodetype_ARG,typevoid,NULL,$1,$3,NULL);}
		| expr				{$$=createtree(0,nodetype_ARG,typevoid,NULL,NULL,$1,NULL);}
		|					{$$=NULL;}
		;

FieldFunction 	: SELF '.' ID '(' ArgList ')' 	{	//Occurs only in class function
													printf("se1\n");
													Ltemp=LLookup("self");
						  							if(Ltemp==NULL)
						  								{yyerror("Invalid Refernce");exit(1);}
						  							$1->Lentry=Ltemp;
						  							$1->cptr=Cptr;
						  							printf("se2\n");
						  							Mtemp=MLookup(Cptr,$3->varname,$5);
						  							printf("se3\n");
						  							if(Mtemp==NULL)
														{yyerror("Invalid Method");exit(1);}
													$3->cptr=Cptr;
													printf("se4\n");
													$3->type=Mtemp->type;
													$$=createtree(0,nodetype_FIELDFUNC,$3->type,NULL,$1,$3,$5);
													$$->cptr=$3->cptr;
												}
                | ID '.' ID '(' ArgList ')'  	{	//This will not occur inside a class. ID1 is a class variable
                									//printf("met1 %s\n",$3->varname );
                									//printf("e1\n");
                									Ltemp=LLookup($1->varname);
													if(Ltemp==NULL)
													{
														//printf("e2\n");
														tempst=GLookup($1->varname);
														if(tempst==NULL)
														{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
														else 
														{	
															$1->Gentry=tempst;
															Ctemp=tempst->cptr;
															$1->cptr=Ctemp;
															//printf("e3\n");
															Mtemp=MLookup(Ctemp,$3->varname,$5);
															if(Mtemp==NULL)
																{yyerror("Invalid Member Function-1");exit(1);}
															$3->type=Mtemp->type;
															//printf("e4\n");
														}
													}
													else
													{
														//printf("e5\n");
														$1->Lentry=Ltemp;
														//Ctemp=Ltemp->cptr;
														Mtemp=MLookup(Ctemp,$3->varname,$5);
														if(Mtemp==NULL)
															{yyerror("Invalid Member Function-2");exit(1);}
														$3->type=Mtemp->type;
													}
													//printf("e6\n");
						  							$$=createtree(0,nodetype_FIELDFUNC,$3->type,NULL,$1,$3,$5);
						  							$$->cptr=$1->cptr;
                								}	
                | FIELD '.' ID '(' ArgList ')'  {
                									if($1->cptr==NULL)
                										{yyerror("Invalid Refernce");exit(1);}
                									Mtemp=MLookup($1->cptr,$3->varname,$5);
                									if(Mtemp==NULL)
                										{yyerror("Invalid Member Function-3");exit(1);}
                									$3->type=Mtemp->type;
                									$$=createtree(0,nodetype_FIELDFUNC,$3->type,NULL,$1,$3,$5);
                								}
                ;

GDeclarations  	: DECL GDeclList ENDDECL 	{printsymtab();decl=0;printf("GDeclarations ok\n");}
				| DECL ENDDECL				{decl=0;}
				|							{decl=0;}
				;

GDeclList : GDeclList GDecl 				{Cptr=NULL;}
		  | GDecl 							{Cptr=NULL;}
		  ; 

GDecl : TypeName GidList ';'				{}
	  ; 

GidList : GidList ',' Gid  					{}
		| Gid 								{}
		;

Gid 	:	ID 					{
									if(Cptr==NULL)
										GInstall($1->varname,type,Cptr,1,1,NULL);
									else
										GInstall($1->varname,type,Cptr,2,1,NULL);
								}
		|	ID '[' NUM ']'		{
									if(type==typeint)
										GInstall($1->varname,TLookup("arrint"),NULL,$3->val,1,NULL);
									else if(type==typestr)
										GInstall($1->varname,TLookup("arrstr"),NULL,$3->val,1,NULL);
								}
		|	ID '[' NUM ']' '[' NUM ']'	{
											if(type==typeint)
												GInstall($1->varname,TLookup("arrint"),NULL,$3->val,$6->val,NULL);
											else if(type==typestr)
												GInstall($1->varname,TLookup("arrstr"),NULL,$3->val,$6->val,NULL);
										}
		|	MUL	ID 				{
									if(type==typeint)
										GInstall($2->varname,TLookup("intptr"),NULL,1,1,NULL);
									else if(type==typestr)
										GInstall($2->varname,TLookup("strptr"),NULL,1,1,NULL);
								}
		|	ID '(' {functype=type;} ParamList ')' {
									//printf("function to enter Gtable %d\n",type);
									func=1;
									GInstall($1->varname,functype,NULL,0,1,Phead);printf("installed fun\n");
									func=0;
									Phead=NULL;
								}



		;



FDeclarations	: FDeclarations Fdef 		{} 
				| 							{}
				; 

Fdef :	TypeName ID '('	{functype=type;}  ParamList ')' '{' LDeclarations Body '}' {
																//printf("%d %s\n",$9->nodetype,$9->varname);
																//printf("f0\n");
																validatefunc(functype,Cptr,$2->varname,Phead);
																$2->Lentry=Lhead;
																//printf("f1\n");
																if(Cptr==NULL)
																{
																	//printf("f2\n");
																	tempst=GLookup($2->varname);
																	$2->Gentry=tempst;
																	codegen_func($2->Gentry->flabel,$9,target_file);
																}
																else
																{

																	//printf("f3\n");
																	Mtemp=CMLookup(Cptr,$2->varname,Phead);
																	//printf("f4\n");
																	codegen_func(Mtemp->flabel,$9,target_file);
																}
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

																if(Cptr==NULL)
																	printf("FDefinition %d ok\n",tempst->flabel);
																else
																	printf("FDefinition %d ok\n",Mtemp->flabel);
															 }
	 ;

ParamList	: ParamList ',' Param 		{arg=0;//printf("parameter installed ok\n");
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
															GInstall("main",typeint,NULL,0,1,NULL);
															tempst=GLookup("main");
															tempst->flabel=0;
															//printf("m1\n");
															$$=createtree(0,nodetype_MAIN,typeint,NULL,$7,NULL,NULL);
															//printf("m2\n");
															codegen($$,target_file);
															printf("Main function ok\n");
														}
		;


LDeclarations	: DECL LDecList ENDDECL		{if(Cptr!=NULL) {arg=1;LInstall("self",typevoid);arg=0;}printL();} 
				| DECL ENDDECL 				{if(Cptr!=NULL) {arg=1;LInstall("self",typevoid);arg=0;}printL();}
				|							{if(Cptr!=NULL) {arg=1;LInstall("self",typevoid);arg=0;}printL();}
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
	type=NULL;
	functype=NULL;
	Cptr=NULL;


	varadrs=4096;
	flabel=1;
	lvaradrs=1;
	padrs=-3;
	clscnt=0;

	TypeTableCreate();
	typeint=TLookup("int");
	typevoid=TLookup("void");
	typestr=TLookup("str");
	
	yyparse();
	return 0;
}