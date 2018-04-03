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


void GInstall(char *name, struct Typetable *type,struct Classtable *cptr,int size,int s2,struct Paramstruct *paramlist)
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
	new->cptr=cptr;
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
	printf("Global Symbol Table\n");
	printf("========================================================\n");
	struct Gsymbol *temp=Ghead;
	printf("flabel %s %s %s %s\n","name","type","size","binding" );
	while(temp!=NULL)
	{
		if(temp->type==NULL)
			printf("%d %s %s %d %d\n",temp->flabel,temp->name,temp->cptr->name,temp->size,temp->binding);
		else
			printf("%d %s %s %d %d\n",temp->flabel,temp->name,temp->type->name,temp->size,temp->binding);
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

struct Classtable *CLookup(char *name)
{
	if(name==NULL)
		return NULL;
	Ctemp=Chead;
	while(Ctemp!=NULL)
	{
		if(strcmp(name,Ctemp->name)==0)
			return Ctemp;
		Ctemp=Ctemp->next;
	}
	return NULL;
}

struct Classtable *CInstall(char *name,char *parentclassname)
{
	struct Classtable *new=(struct Classtable *)malloc(sizeof(struct Classtable));
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->Memberfield=NULL;
	new->Vfuncptr=NULL;
	//printf("C2\n");
	new->parentptr=CLookup(parentclassname);
	new->class_index=clscnt++;
	new->fieldcount=0;
	new->menthodcount=0;
	//printf("C3\n");
	if(Chead==NULL)
	{
		new->next=NULL;
		Chead=new;
		return new;
	}
	new->next=Chead;
	Chead=new;
	return new;
}

struct Fieldlist *CFLookup(struct Classtable *cptr,char *name)
{
	Ftemp=cptr->Memberfield;
	while(Ftemp!=NULL)
	{
		//printf("%s\n",Ftemp->name);
		if(strcmp(Ftemp->name,name)==0)
			return Ftemp;
		Ftemp=Ftemp->next;
	}
	return NULL;
}

void Class_Finstall(struct Classtable *cptr,char *type,char *name)
{
	if(CMLookup(cptr,name)!=NULL)
		{printf("variable already declared\n");exit(1);}
	struct Fieldlist *new=(struct Fieldlist *)malloc(sizeof(struct Fieldlist));
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	Ttemp=TLookup(type);
	if(Ttemp==NULL)
	{
		Ctemp=CLookup(type);
		if(Ctemp==NULL)
			{printf("Unkown Field type %s at %d\n",type,lcnt);exit(1);}
		new->cptr=Ctemp;
		new->type=NULL;
	}
	else
	{
		new->type=Ttemp;
		new->cptr=NULL;
	}
	new->fieldindex=(cptr->fieldcount)++;

	if((cptr->Memberfield)==NULL)
	{
		new->next=NULL;
		(cptr->Memberfield)=new;
		return;
	}
	new->next=(cptr->Memberfield);
	(cptr->Memberfield)=new;
}

struct Memberfunclist *CMLookup(struct Classtable *cptr,char *name)
{
	Mtemp=cptr->Vfuncptr;
	while(Mtemp!=NULL)
	{
		//printf("%s\n",Mtemp->name);
		if(strcmp(Mtemp->name,name)==0)
			return Mtemp;
		Mtemp=Mtemp->next;
	}
	return NULL;
}

void Class_Minstall(struct Classtable *cptr,char *name,struct Typetable *type,struct Paramstruct *paramlist)
{
	if(CMLookup(cptr,name)!=NULL)
		{printf("Over loading not permitted\n");exit(1);}
	struct Memberfunclist *new=(struct Memberfunclist *)malloc(sizeof(struct Memberfunclist));
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->type=type;
	new->paramlist=paramlist;
	new->funcposition=(cptr->menthodcount)++;
	//printf("%d %s %s\n",new->funcposition,name,cptr->name);
	new->flabel=flabel++;
	if((cptr->Vfuncptr)==NULL)
	{
		new->next=NULL;
		(cptr->Vfuncptr)=new;
		return;
	}
	new->next=(cptr->Vfuncptr);
	(cptr->Vfuncptr)=new;
}

void validateparams(struct Typetable *type,struct Classtable *cptr,char *name,struct Paramstruct *paramlist)
{
	if(cptr==NULL)
	{
		printf("c1\n");
		struct Gsymbol *temp=GLookup(name);
		if(temp==NULL)
		{
			yyerror("Function undeclared");
			exit(1);
		}
		if((temp->type!=type))	//return type check
		{
			yyerror("return type mismatch");
			exit(1);
		}

		Ptemp=temp->paramlist;
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
	else
	{
		//printf("c2 %s %s\n",cptr->name,name);
		struct Memberfunclist *temp=CMLookup(cptr,name);
		if(temp==NULL)
		{
			yyerror("Member Function undeclared");
			exit(1);
		}
		if((temp->type!=type))	//return type check
		{
			//printf("%s %s\n",temp->type->name,type->name);
			yyerror("return type mismatch");
			exit(1);
		}
		Ptemp=temp->paramlist;
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
	//printf("valid\n");
}

void print1()
{
	printf("TYPE TABLE\n");
	printf("============================================\n");
	Ttemp=Thead;
	while(Ttemp!=NULL)
	{
		printf("%s %d\n",Ttemp->name,Ttemp->size);
		Ftemp=Ttemp->fields;
		while(Ftemp!=NULL){
			printf("<--->  %d %s %s\n",Ftemp->fieldindex,Ftemp->name,Ftemp->type->name);
			Ftemp=Ftemp->next;
		}
		Ttemp=Ttemp->next;
	}
}

void print2()
{
	printf("CLASS TABLE\n");
	printf("==============================================\n");
	Ctemp=Chead;
	while(Ctemp!=NULL)
	{
		printf("class %d %s %d %d\n",Ctemp->class_index,Ctemp->name,Ctemp->fieldcount,Ctemp->menthodcount);
		Ftemp=Ctemp->Memberfield;
		while(Ftemp!=NULL){
			if(Ftemp->type!=NULL)
				printf("%d %s %s\n",Ftemp->fieldindex,Ftemp->name,Ftemp->type->name);
			else
				printf("%d %s %s\n",Ftemp->fieldindex,Ftemp->name,Ftemp->cptr->name);
			Ftemp=Ftemp->next;
		}
		Mtemp=Ctemp->Vfuncptr;
		while(Mtemp!=NULL)
		{
			printf("%d %s %s %d\n",Mtemp->funcposition,Mtemp->name,Mtemp->type->name,Mtemp->flabel);
			Mtemp=Mtemp->next;
		}
		Ctemp=Ctemp->next;
	}
}

void printL()
{
	Ltemp=Lhead;
	if(Ltemp==NULL)
		printf("L NULL\n");
	while(Ltemp!=NULL)
	{
		printf("%d %s %s\n",Ltemp->binding,Ltemp->name,Ltemp->type->name);
		Ltemp=Ltemp->next;
	}
}

