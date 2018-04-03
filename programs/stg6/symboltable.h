
typedef struct Gsymbol
{
	char *name;
	struct Typetable *type;
	int size,binding,s2;
	struct Gsymbol *next;
	struct Paramstruct *paramlist;
	int flabel;
}Gsymbol;

typedef struct Lsymbol
{
	char *name;
	struct Typetable *type;
	int binding;
	struct Lsymbol *next;
}Lsymbol;

typedef struct Paramstruct
{
	char *name;
	struct Typetable *type;
	int passtype;
	struct Paramstruct *next;
}Paramstruct; 

typedef struct Typetable
{
	char *name;
	int size;
	struct Fieldlist *fields;
	struct Typetable *next;
}Typetable;

typedef struct Fieldlist
{
	char *name;
	int fieldindex;
	struct Typetable *type;
	struct Fieldlist *next;
}Fieldlist;

int varadrs,flabel,lvaradrs,padrs;

struct Gsymbol *Ghead,*tempst;
struct Gsymbol *GLookup(char * name);
void GInstall(char *name, struct Typetable *type, int size,int s2,struct Paramstruct *paramlist);


struct Lsymbol *Lhead,*Ltemp;
struct Lsymbol *LLookup(char * name);
void LInstall(char *name, struct Typetable *type);


struct Paramstruct *Phead,*Ptemp;
void PInstall(char *name,struct Typetable *type,int passtype);

void validateparams(struct Typetable *type,char *name,struct Paramstruct *paramlist);

struct Typetable *Thead,*Ttemp,*Tptr;
struct Fieldlist *Fhead,*Ftemp;

void TypeTableCreate();
struct Typetable *TLookup(char *name);
struct Typetable *TInstall(char *name,int size,struct Fieldlist *fields);
struct Fieldlist *FLookup(struct Typetable *type,char *name);
int Getsize(struct Typetable *type);

struct Typetable *typeint,*typevoid,*typestr;
