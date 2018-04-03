
struct tnode* createtree(int val, int type, char *c,struct tnode *l, struct tnode *r)
{
	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->nodetype=type;
	if(c!=NULL)
	{
		temp->varname=(char *)malloc(sizeof(c));
		strcpy(temp->varname,c);
	}
	else
		temp->varname=NULL;
	temp->left=l;
	temp->right=r;
	return temp;
}

int abst_evaluate(struct tnode *t)
{
	switch(t->nodetype)
	{
		case nodetype_NULL:
			abst_evaluate(t->left);
			abst_evaluate(t->right);
			return 1;
			break;
		case nodetype_PLUS:
			return abst_evaluate(t->left)+abst_evaluate(t->right);
			break;
		case nodetype_MUL:
			return abst_evaluate(t->left)*abst_evaluate(t->right);
			break;
		case nodetype_MINUS:
			return abst_evaluate(t->left)-abst_evaluate(t->right);
			break;
		case nodetype_DIV:
			return abst_evaluate(t->left)/abst_evaluate(t->right);
			break;
		case nodetype_LEAF:
			return t->val;
			break;
		case nodetype_ID:
			if(val[*(t->varname)-'a']!=NULL)
				return *val[*(t->varname)-'a'];
			else
			{
				printf("error\n");
				exit(1);
			}
			break;
		case nodetype_READ:
			if(val[*(t->left->varname)-'a']==NULL)
				val[*(t->left->varname)-'a']=malloc(sizeof(int*));
			scanf("%d",val[*(t->left->varname)-'a']);
			return 1;
			break;
		case nodetype_WRITE:
			printf("%d\n",abst_evaluate(t->left));
			break;
		case nodetype_ASGN:
			if(val[*(t->left->varname)-'a']==NULL)
				val[*(t->left->varname)-'a']=malloc(sizeof(int*));
			*val[*(t->left->varname)-'a']=abst_evaluate(t->right);
			return 1;
			break;
	}
}