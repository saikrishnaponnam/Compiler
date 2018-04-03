%{
	#include<stdio.h>
%}

ch2[a-zB-Z0-9]
char [a-zA-Z0-9]

%%

[A]{char}{char} {printf("%s ",yytext);}
ch2{char}* {}

%%

int yywrap()
{
	return 1;
}

int main()
{
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("input file error\n");
	yylex();
	return 1;
}