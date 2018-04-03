%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
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

int yywrap()
{
	return 1;
}
