#define type_expr 1
#define type_comp 2
#define type_stmt 3

#define nodetype_LEAF 0
#define nodetype_ID 1
#define nodetype_PLUS 2
#define nodetype_MUL 3
#define nodetype_MINUS 4
#define nodetype_DIV 5
#define nodetype_ASGN 6
#define nodetype_READ 7
#define nodetype_WRITE 8
#define nodetype_NULL 9


int *val[26];

typedef struct tnode 
{
	int type;
	int nodetype;
	int val;
	char *varname;	
	struct tnode *left,*right;
}tnode;

struct tnode* createtree(int val, int type, char *c,struct tnode *l, struct tnode *r);

int abst_evaluate(struct tnode *t);
