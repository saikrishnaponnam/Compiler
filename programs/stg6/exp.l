%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "abstracttree.h"
#include "symboltable.h"
#define YYSTYPE tnode *
int number;

%}

%%

"begin"	{return START;}
"end"	{return END;}
"main"	{return MAIN1;}
"read"	{return READ;}
"write"	{return WRITE;	}
"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}
"while"	{return WHILE;}
"do"	{return DO;}
"endwhile"	{return ENDWHILE;}
"break"	{return BREAK;}
"continue"	{return CNTU;}
"decl"	{return DECL;}
"enddecl" {return ENDDECL;}
"repeat"	{return REPEAT;}
"until"		{return UNTIL;}
"int"	{return INTG;}
"str"	{return STR;}
"tuple"	{return TUPLE;}
"return"	{return RETURN;}
"type"		{return TYPE;}
"endtype"	{return ENDTYPE;}
"alloc"		{return ALLOC;}
"free"		{return FREE;}
"initialize" {return INIT;}
"null"		{yylval=createtree(0,nodetype_LEAF,typevoid,yytext,NULL,NULL,NULL);return NUL;}

["][a-z]+["]	{yylval=createtree(0,nodetype_LEAF,typestr,yytext,NULL,NULL,NULL); return STRING;}
[a-zA-Z]+[a-zA-Z0-9]*	{yylval=createtree(0,nodetype_ID,typevoid,yytext,NULL,NULL,NULL); return ID;}
[0-9]+	{number = atoi(yytext); yylval = createtree(number,nodetype_LEAF,typeint,NULL,NULL,NULL,NULL); return NUM;}

"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"%"		{return MOD;}
"="		{return *yytext;}
"<"		{return LT;}
"<="	{return LE;}
">"		{return GT;}
">="	{return GE;}
"=="	{return EQ;}
"!="	{return NE;}

[;,&{}.]	{return *yytext;}
[\t]	{}
[' ']	{}
"["		{return *yytext;}
"]"		{return *yytext;}
[()]	{return *yytext;}
[\n]	{lcnt++;}
.		{yyerror("unknown character\n");exit(1);}

%%


int yywrap() 
{
	return 1;
}