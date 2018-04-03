#define type_int 1
#define type_bool 2
#define type_char 3
#define type_null 4
#define type_arrint 5
#define type_str 6
#define type_intptr 7
#define type_strptr 8
#define type_function_int 9
#define type_function_char 10
#define type_argint 11
#define type_argchar 12
#define type_argintref 13
#define type_argcharref 14
#define type_tuple 15

#define passtype_ref 1
#define passtype_val 2

#define nodetype_LEAF 0
#define nodetype_ID 1
#define nodetype_ARRID 23
#define nodetype_tuple 37

#define nodetype_PLUS 2
#define nodetype_MUL 3
#define nodetype_MINUS 4
#define nodetype_DIV 5 
#define nodetype_MOD 100

#define nodetype_ASGN 6
#define nodetype_ARRASGN 24
#define nodetype_PASGN 32
#define nodetype_TASGN 38

#define nodetype_READ 7
#define nodetype_WRITE 8
#define nodetype_ARRREAD 25
#define nodetype_UREAD 44

#define nodetype_IF 10
#define nodetype_THEN 11
#define nodetype_ELSE 12
#define nodetype_ENDIF 13
#define nodetype_WHILE 14
#define nodetype_DO 15
#define nodetype_ENDWHILE 16
#define nodetype_BRK 26
#define nodetype_CNTU 27
#define nodetype_DOWHILE 28
#define nodetype_REPEAT 29

#define nodetype_LT 17
#define nodetype_LE 18
#define nodetype_GT 19
#define nodetype_GE 20
#define nodetype_EQ 21
#define nodetype_NE 22

#define nodetype_NULL 9
#define nodetype_POINTER 30
#define nodetype_ADDR 31
#define nodetype_FIELD 39
#define nodetype_FIELDexpr 43
#define nodetype_FIELDFUNC 49
#define nodetype_Method 50

#define nodetype_funcall 33
#define nodetype_ARG 34
#define nodetype_RET 35
#define nodetype_MAIN 36
#define nodetype_ALLOCID 40
#define nodetype_FREE 41
#define nodetype_INIT 42
#define nodetype_ALLOCFIELD 45
#define nodetype_NEW 46
#define nodetype_DELETE 47

#define nodetype_SELF 48

int *val[26],lcnt;



typedef struct tnode 
{
	struct Typetable *type;
	int nodetype;
	int val;
	char *varname,*str;	
	struct tnode *left,*right,*end;
	//struct tnode *arglist;
	struct Gsymbol *Gentry;
	struct Classtable *cptr;
	struct Lsymbol *Lentry;
}tnode;

struct tnode* createtree(int val, int nodetype,struct Typetable *type, char *c,struct tnode *l, struct tnode *r,struct tnode *p3);

int abst_evaluate(struct tnode *t);
