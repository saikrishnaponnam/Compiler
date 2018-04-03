
typedef struct Gsymbol
{
	char *name;
	int type,size,binding,s2;
	struct Gsymbol *next;
	struct Paramstruct *paramlist;
	int flabel;
}Gsymbol;

typedef struct Lsymbol
{
	char *name;
	int type,binding;
	struct Lsymbol *next;
}Lsymbol;

typedef struct Paramstruct
{
	char *name;
	int type,passtype;
	struct Paramstruct *next;
}Paramstruct; 

int varadrs,flabel,lvaradrs,padrs;

struct Gsymbol *Ghead,*tempst;
struct Gsymbol *GLookup(char * name);
void GInstall(char *name, int type, int size,int s2,struct Paramstruct *paramlist);


struct Lsymbol *Lhead,*Ltemp;
struct Lsymbol *LLookup(char * name);
void LInstall(char *name, int type);


struct Paramstruct *Phead,*Ptemp;
void PInstall(char *name,int type,int passtype);

void validateparams(int type,char *name,struct Paramstruct *paramlist);