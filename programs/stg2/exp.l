%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "abstracttree.h"
int number;

%}

%%

"begin"	{return START;}
"end"	{return END;}
"read"	{return READ;}
"write"	{return WRITE;	}
[a-z]+	{yylval=createtree(0,nodetype_ID,yytext,NULL,NULL); return ID;}
[0-9]+	{number = atoi(yytext); yylval = createtree(number,nodetype_LEAF,NULL,NULL,NULL); return NUM;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"="		{return *yytext;}
[;]		{return *yytext;}
[\t]	{}
[' ']	{}
[()]	{return *yytext;}
[\n]	{}
.	{yyerror("unknown character\n");exit(1);}

%%


int yywrap() 
{
	return 1;
}