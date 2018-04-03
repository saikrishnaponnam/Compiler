%{

#include <stdio.h>
int ch=0,w=0,l=0;

%}

char [a-zA-Z0-9]



%%

{char}+ {ch+=yyleng; w+=1;}
[\n] {l+=1;}
[' '] {}

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
	{
		printf("Input File error\n");
		return 1; 
	}
	yylex();
	printf("%d %d %d\n",ch,w,l+1);
	return 1;
}

