%{
	#include<stdio.h>
	int n=0,f=0;
%}

char [a-zA-z]
digit [0-9]

%%


{digit}*[.]{digit}* {f++;}
{digit}+ {n++;}
[" "] {}

%%


int yywrap()
{
	return 1;
}

int main()
{
	FILE *fp;
	fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("input file error");
	yylex();
	printf("%d %d\n",n,f);
	return 1;
}