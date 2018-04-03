struct tnode* createtree(int val, int nodetype,int type,char *c,struct tnode *l, struct tnode *r,struct tnode *p3)
{
	switch(nodetype)
	{
//
		case nodetype_NULL:
			break;
		case nodetype_LEAF:
			break;
		case nodetype_ID:
			break;
		case nodetype_ARRID:
			break;
		
//ARITHMETIC 
		case nodetype_PLUS:
			
		case nodetype_MUL:
			
		case nodetype_MINUS:
			
		case nodetype_DIV:
			if(l->type!=type_int||r->type!=type_int)
				{yyerror("type mismatch 1");exit(1);}
			break;

//INPUT AND OUTPUT
		case nodetype_READ:
		case nodetype_ARRREAD:
			if(l->nodetype!=nodetype_ID)
				{yyerror("type mismatch expected variable");exit(1);}
			break;
		case nodetype_WRITE:
			if(l->type!=type_int&&l->type!=type_char)
				{yyerror("type mismatch 2");exit(1);}
			break;


//ASSINGNMENT
		case nodetype_ASGN:
			if(l->type!=r->type)
				{yyerror("type mismatch 3");exit(1);}
			break;
		case nodetype_ARRASGN:
			if(l->type!=p3->type||r->type!=type_int)
				{yyerror("type mismatch 4");exit(1);}
			break;
		case nodetype_PASGN:
			if(l->type!=r->type)
				{yyerror("type mismatch 5");exit(1);}
			break;

//COMPARISONS
		case nodetype_LT:

		case nodetype_LE:

		case nodetype_GT:

		case nodetype_GE:

		case nodetype_EQ:

		case nodetype_NE:
			if(l->type!=r->type||l->type!=type_int)
				{yyerror("type mismatch expected integers values");exit(1);}
			break;

//CONTROL STATEMENTS
		case nodetype_IF:
			
		case nodetype_WHILE:
			
		case nodetype_DOWHILE:
			
		case nodetype_REPEAT:
			if(l->type!=type_bool)
				{yyerror("type mismatch expected boolean");exit(1);}
		case nodetype_BRK:
		case nodetype_CNTU:
			break;

//POINTERS		
		case nodetype_POINTER:
			break;
		case nodetype_ADDR:
			break;
	}


	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->type=type;
	temp->nodetype=nodetype;
	if(c!=NULL)
	{
		if(type==type_char)
		{
			temp->str=(char *)malloc(sizeof(c));
			strcpy(temp->str,c);	
		}
		else
		{
			temp->varname=(char *)malloc(sizeof(c));
			strcpy(temp->varname,c);
		}
	}
	else
		temp->varname=NULL;
	temp->Gentry=NULL;
	temp->left=l;
	temp->right=r;
	temp->end=p3;
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
		case nodetype_LT:
			return abst_evaluate(t->left)<abst_evaluate(t->right);
			break;
		case nodetype_LE:
			return abst_evaluate(t->left)<=abst_evaluate(t->right);
			break;
		case nodetype_GT:
			return abst_evaluate(t->left)>abst_evaluate(t->right);
			break;
		case nodetype_GE:
			return abst_evaluate(t->left)>=abst_evaluate(t->right);
			break;
		case nodetype_EQ:
			return abst_evaluate(t->left)==abst_evaluate(t->right);
			break;
		case nodetype_NE:
			return abst_evaluate(t->left)!=abst_evaluate(t->right);
			break;		
		case nodetype_IF:
			if(abst_evaluate(t->left))
				abst_evaluate(t->right);
			else if(t->end!=NULL)
				abst_evaluate(t->end);
			break;
		case nodetype_WHILE:
			while(abst_evaluate(t->left))
				abst_evaluate(t->right);
			break;

	}
}	