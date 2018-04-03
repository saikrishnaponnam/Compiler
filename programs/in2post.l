%{
    #include <stdio.h> 
    #include <string.h>
	#include "y.tab.h"
%}

char [a-zA-Z]

%%

{char}+	{
          yylval = (char*)malloc((yyleng+1)*sizeof(char));
          strcpy(yylval,yytext);
          return DIGIT;
        }
"+"	  	return *yytext;
"*"	  	return *yytext;
[()]	return *yytext;
[\n]	return *yytext;

%%

yywrap()
{
	return 1;
}