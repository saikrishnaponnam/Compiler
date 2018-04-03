struct Gsymbol* GLookup(char * name)
{
	struct Gsymbol *temp=Ghead;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return NULL;
}


void GInstall(char *name, int type, int size,int s2,struct Paramstruct *paramlist)
{
	if(GLookup(name)!=NULL)
	{
		printf("Variable is already defined %s\n",name);
		exit(1);
	}
	struct Gsymbol *new=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->type=type;
	new->size=size*s2;
	new->s2=s2;
	new->paramlist=paramlist;
	new->binding=varadrs;
	varadrs=varadrs+size;
	if(type==type_function_int||type==type_function_char)
	{
		new->flabel=flabel;
		flabel++;
	}
	if(Ghead==NULL)
	{
		new->next=NULL;
		Ghead=new;
		return;
	}
	new->next=Ghead;
	Ghead=new;
}

void printsymtab()
{
	struct Gsymbol *temp=Ghead;
	printf("%s %s %s %s flabel\n","name","type","size","binding" );
	while(temp!=NULL)
	{
		printf("%s %d %d %d %d\n",temp->name,temp->type,temp->size,temp->binding,temp->flabel );
		temp=temp->next;
	}
}

struct Lsymbol *LLookup(char * name)
{
	struct Lsymbol *temp=Lhead;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,name)==0)
			return temp;
		temp=temp->next;
	} 
	return NULL;
}

void LInstall(char *name, int type)
{
	if(LLookup(name)!=NULL)
	{
		printf("local Variable is already defined %s\n",name);
		exit(1);
	}
	struct Lsymbol *new=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->type=type;
	if(type==type_argint||type==type_argchar||type==type_argcharref||type==type_argintref)
	{
		new->binding=padrs;
		padrs--;
	}
	else
	{
		new->binding=lvaradrs;
		lvaradrs++;
	}

	if(Lhead==NULL)
	{
		new->next=NULL;
		Lhead=new;
		return;
	}
	new->next=Lhead;
	Lhead=new; 
}

void PInstall(char *name,int type,int passtype)
{
	struct Paramstruct *new=(struct Paramstruct *)malloc(sizeof(struct Paramstruct)),*temp;
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->type=type;
	new->next=NULL;
	new->passtype=passtype;
	
	if(Phead==NULL)
	{
		Phead=new;
		return;
	}
	temp=Phead;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new;
}


void validateparams(int type,char *name,struct Paramstruct *paramlist)
{
	tempst=GLookup(name);
	if(tempst==NULL)
	{
		yyerror("Function undeclared");
		exit(1);
	}
	if((tempst->type==type_function_int&&type!=type_int)||(tempst->type==type_function_char&&type!=type_char))	//return type check
	{
		yyerror("return type mismatch");
		exit(1);
	}

	Ptemp=tempst->paramlist;
	while(Ptemp!=NULL&&paramlist!=NULL)
	{
		if(strcmp(Ptemp->name,paramlist->name)!=0)
		{
			yyerror("Parameter name mismatch");
			exit(1);
		}
		if(Ptemp->type!=paramlist->type)
		{
			yyerror("Parameter type mismatch");
			exit(1);
		}	
		Ptemp=Ptemp->next;
		paramlist=paramlist->next;
	}
	if(Ptemp!=NULL)
	{
		yyerror("Less number of arguments");
		exit(1);
	}
	if(paramlist!=NULL)
	{
		yyerror("More number of arguments");
		exit(1);
	}

}