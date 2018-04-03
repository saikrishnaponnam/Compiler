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


void GInstall(char *name, struct Typetable *type, int size,int s2,struct Paramstruct *paramlist)
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
	if(func==1)
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
		printf("%s %s %d %d %d\n",temp->name,temp->type->name,temp->size,temp->binding,temp->flabel );
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

void LInstall(char *name, struct Typetable *type)
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
	if(arg==1)
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

void PInstall(char *name,struct Typetable *type,int passtype)
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


void validateparams(struct Typetable *type,char *name,struct Paramstruct *paramlist)
{
	tempst=GLookup(name);
	if(tempst==NULL)
	{
		yyerror("Function undeclared");
		exit(1);
	}
	if((tempst->type!=type))	//return type check
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

void TypeTableCreate()
{
	struct Typetable *new=(struct Typetable*)malloc(sizeof(struct Typetable));
	new->name=(char *)malloc(4);
	strcpy(new->name,"int");
	new->size=1;
	new->fields=NULL;
	new->next=NULL;
	Thead=new;

	TInstall("intptr",1,NULL);
	TInstall("str",1,NULL);
	TInstall("strptr",1,NULL);
	TInstall("bool",1,NULL);
	TInstall("void",0,NULL);
	TInstall("arrint",0,NULL);
	TInstall("arrstr",0,NULL);
	//TInstall("tuple",0,NULL);
}

struct Typetable* TLookup(char *name)
{
	Ttemp=Thead;
	while(Ttemp!=NULL)
	{
		if(strcmp(Ttemp->name,name)==0)
			return Ttemp;
		Ttemp=Ttemp->next;
	}
	return NULL;
}

struct Typetable* TInstall(char *name,int size,struct Fieldlist *fields)
{
	struct Typetable *new=(struct Typetable*)malloc(sizeof(struct Typetable)),*Ttemp;
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->size=size;
	new->fields=fields;
	new->next=NULL;
	Ttemp=Thead;
	while(Ttemp->next!=NULL)
		Ttemp=Ttemp->next;
	Ttemp->next=new;
	return new;
}


struct Fieldlist* FLookup(struct Typetable *type,char *name)
{
	Ftemp=type->fields;
	while(Ftemp!=NULL)
	{
		if(strcmp(Ftemp->name,name)==0)
			return Ftemp;
		Ftemp=Ftemp->next;
	}
	return NULL;
}

void FInstall(char *name,int index,struct Typetable *type)
{
	struct Fieldlist *new=(struct Fieldlist*)malloc(sizeof(struct Fieldlist));
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->fieldindex=index;
	new->type=type;
	if(Fhead==NULL)
	{
		new->next=NULL;
		Fhead=new;
		return;
	}
	new->next=Fhead;
	Fhead=new;
}

int Getsize(struct Typetable *type)
{
	return type->size;
}

void print1()
{
	Ttemp=Thead;
	while(Ttemp!=NULL)
	{
		printf("%s %d\n",Ttemp->name,Ttemp->size);
		Ftemp=Ttemp->fields;
		while(Ftemp!=NULL){
			printf("%s %d %s\n",Ftemp->name,Ftemp->fieldindex,Ftemp->type->name);
			Ftemp=Ftemp->next;
		}
		Ttemp=Ttemp->next;
		printf("\n");
	}
}