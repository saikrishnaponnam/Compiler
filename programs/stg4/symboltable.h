
typedef struct Gsymbol
{
	char *name;
	int type,size,binding,s2;
	struct Gsymbol *next;
}Gsymbol;


struct Gsymbol *Ghead,*tempst;
int varadrs;

struct Gsymbol *Lookup(char * name);
void Install(char *name, int type, int size,int s2);