
typedef struct Gsymbol
{
	char *name;
	struct Typetable *type;
	int size,binding,s2;
	struct Gsymbol *next;
	struct Classtable *cptr;
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
	struct Paramstruct *next,*pre;
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
	struct Classtable *cptr;
	struct Fieldlist *next;
}Fieldlist;

typedef struct Classtable
{
	char *name;
	struct Fieldlist *Memberfield;
	struct Memberfunclist *Vfuncptr;
	struct Classtable *parentptr;
	int class_index;
	int fieldcount;
	int methodcount;
	struct Classtable *next;
}Classtable;

typedef struct Memberfunclist
{
	char *name;
	struct Typetable *type;
	struct Paramstruct *paramlist;
	int funcposition;
	int flabel;
	struct Memberfunclist *next;
}Memberfunclist;


int varadrs,flabel,lvaradrs,padrs,clscnt;

struct Gsymbol *Ghead,*tempst;
struct Gsymbol *GLookup(char * name);
void GInstall(char *name, struct Typetable *type,struct Classtable *cptr, int size,int s2,struct Paramstruct *paramlist);


struct Lsymbol *Lhead,*Ltemp;
struct Lsymbol *LLookup(char * name);
void LInstall(char *name, struct Typetable *type);


struct Paramstruct *Phead,*Ptemp;
void PInstall(char *name,struct Typetable *type,int passtype);

struct Typetable *Thead,*Ttemp,*Tptr;
struct Fieldlist *Fhead,*Ftemp;

void TypeTableCreate();
struct Typetable *TLookup(char *name);
struct Typetable *TInstall(char *name,int size,struct Fieldlist *fields);
struct Fieldlist *FLookup(struct Typetable *type,char *name);
int Getsize(struct Typetable *type);

struct Typetable *typeint,*typevoid,*typestr;

struct Classtable *Chead,*Ctemp;
struct Memberfunclist *Mhead,*Mtemp;

struct Classtable *CInstall(char *name,char *parentclassname);
struct Classtable *CLookup(char *name);
struct Fieldlist *CFLookup(struct Classtable *cptr,char *name);
struct Memberfunclist *CMLookup(struct Classtable *cptr,char *name,struct Paramstruct *paramlist);
struct Memberfunclist *MLookup(struct Classtable *cptr,char *name,struct tnode *arglist);
void Class_Finstall(struct Classtable *cptr,char *type,char *name);
void Class_Minstall(struct Classtable *cptr,char *name,struct Typetable *type,struct Paramstruct *paramlist);



void validatefunc(struct Typetable *type,struct Classtable *cptr,char *name,struct Paramstruct *paramlist);
void copyfields(struct Classtable *class,struct Fieldlist *fields);
void copymethods(struct Classtable *class,struct Memberfunclist *methods);
int compareparams(struct Paramstruct *p1,struct Paramstruct *p2);
int comparearglist(struct Paramstruct *paramlist,struct tnode *arglist);

void printsymtab();
void print1();
void print2();
void printL();