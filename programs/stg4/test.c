#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=1,b,*p;
	b=&a;p=&a;
	printf("%d %d %d\n",a,&a,b);
}