int count=-1,lcount=-1;

int getreg()
{
	if(count<19)
	{
		count++;
		return count;
	}
	else
		printf("Out of Registers\n");
}

void freereg()
{
	if(count!=-1)
		count--;
	else
		printf("Freeing register error\n");
}

int getlabel()
{
	lcount++;
	return lcount;
}

void scan(int addrs,FILE *fp,int scantype)
{
	//fprintf(fp,"MOV SP,%d\n",varadrs);
	int i=getreg();
	fprintf(fp,"MOV R%d,7\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,-1\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	if(scantype==0)							//value
		fprintf(fp,"MOV R%d,%d\n",i,addrs);
	else if(scantype==1)					//value in register
		fprintf(fp,"MOV R%d,R%d\n",i,addrs);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"INT 6\n");
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	freereg();
}	


void print(int reg,FILE *fp)
{
	//fprintf(fp,"MOV SP,%d\n",varadrs);
	int i=getreg();
	fprintf(fp,"MOV R%d,5\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,-2\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",reg);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"INT 7\n");
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",i);
	
	freereg();
}

void end(FILE *fp)
{
	fprintf(fp,"INT 10" );
}

int Bstack[100],wh=0,p=-1,Cstack[100];


int codegen(struct tnode *t,FILE *fp)
{
	int i,j,k;
	if(t!=NULL)
	switch(t->nodetype)
	{
//
		case nodetype_NULL:
			codegen(t->left,fp);
			codegen(t->right,fp);
			break;
		case nodetype_LEAF:
			//("Leaf\n");
			i=getreg();
			if(t->type==type_char)
				fprintf(fp, "MOV R%d,%s\n",i,t->str);
			else
				fprintf(fp, "MOV R%d,%d\n",i,t->val);
			return i;
			break;
		case nodetype_ID:
			//printf("id\n");
			i=getreg();
			if(t->Lentry==NULL)
				fprintf(fp, "MOV R%d,[%d]\n",i,t->Gentry->binding);
			else
			{

				fprintf(fp, "MOV R%d,%d\n",i,t->Lentry->binding );
				j=getreg();
				fprintf(fp, "MOV R%d,BP\n",j );
				fprintf(fp, "ADD R%d,R%d\n",i,j);
				freereg();
				fprintf(fp, "MOV R%d,[R%d]\n",i,i);
			}
			return i;
			break;
		case nodetype_ARRID:
			i=getreg();
			fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding );
			j=codegen(t->right,fp);
			if(t->end!=NULL)
			{
				k=codegen(t->end,fp);
				fprintf(fp,"MUL R%d,%d\n",j,t->left->Gentry->s2);
				fprintf(fp,"ADD R%d,R%d\n",j,k );
				freereg();
			}
			fprintf(fp,"ADD R%d,R%d\n",i,j);
			fprintf(fp,"MOV R%d,[R%d]\n",i,i);
			
			freereg();
			
			return i;
			break;

		case nodetype_tuple:
			i=getreg();
			fprintf(fp, "MOV R%d,%d\n",i,t->left->Gentry->binding);
			Ptemp=t->left->Gentry->paramlist;
			j=0;
			while(Ptemp!=NULL)
			{
				if(strcmp(Ptemp->name,t->right->varname)==0)
					break;
				j++;
				Ptemp=Ptemp->next;
			}
			fprintf(fp,"ADD R%d,%d\n",i,j);
			fprintf(fp,"MOV R%d,[R%d]\n",i,i);
			return i;
			break;
		
//ARITHMETIC 
		case nodetype_PLUS:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp, "ADD R%d,R%d\n",i,j );
			
			freereg();
			return i;
			break;
		case nodetype_MUL:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp, "MUL R%d,R%d\n",i,j );
			
			freereg();
			return i;
			break;
		case nodetype_MINUS:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp, "SUB R%d,R%d\n",i,j );
			
			freereg();
			return i;
			break;
		case nodetype_DIV:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp, "DIV R%d,R%d\n",i,j );
			
			freereg();
			return i;
			break;
		case nodetype_MOD:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp, "MOD R%d R%d\n",i,j );
			
			freereg();
			return i;
			break;

//INPUT AND OUTPUT
		case nodetype_READ:
			if(t->left->Lentry==NULL)
				scan((t->left->Gentry)->binding,fp,0);
			else
			{
				i=getreg();
				fprintf(fp, "MOV R%d,%d\n",i,t->left->Lentry->binding);
				j=getreg();
				fprintf(fp, "MOV R%d,BP\n",j);
				fprintf(fp, "ADD R%d,R%d\n",i,j);
				freereg();
				//if(t->left->Lentry->type==type_argintref||t->left->Lentry->type==type_argcharref)
				//	fprintf(fp, "MOV R%d,[R%d]\n",i,i);
				scan(i,fp,1);
				
				freereg();
			}
			break;
		case nodetype_WRITE:
			i=codegen(t->left,fp);
			print(i,fp);
			
			freereg();
			break;
		case nodetype_ARRREAD:
			i=getreg();
			fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding);
			j=codegen(t->right,fp);
			fprintf(fp,"ADD R%d,R%d\n",i,j);
			
			freereg();
			scan(i,fp,1);
			
			freereg();
			break;


//ASSINGNMENT
		case nodetype_ASGN:
			i=codegen(t->right,fp);
			if(t->left->Lentry==NULL)
				fprintf(fp,"MOV [%d],R%d\n",t->left->Gentry->binding,i );
			else
			{
				j=getreg();
				fprintf(fp, "MOV R%d,%d\n",j,t->left->Lentry->binding);
				k=getreg();
				fprintf(fp, "MOV R%d,BP\n",k);
				fprintf(fp, "ADD R%d,R%d\n",j,k);
				
				freereg();
				//if(t->left->Lentry->type==type_argintref||t->left->Lentry->type==type_argcharref)
				//	fprintf(fp, "MOV R%d,[R%d]\n",j,j );
				fprintf(fp, "MOV [R%d],R%d\n",j,i);
				
				freereg();
			}
			freereg();
			break;
		case nodetype_ARRASGN:
			i=getreg();
			fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding );
			j=codegen(t->right,fp);
			fprintf(fp,"ADD R%d,R%d\n",i,j);
			
			freereg();
			j=codegen(t->end,fp);
			fprintf(fp,"MOV [R%d],R%d\n",i,j);
			
			freereg();
			break;
		case nodetype_PASGN:
			j=codegen(t->left,fp);
			i=codegen(t->right,fp);
			fprintf(fp,"MOV [R%d],R%d\n",j,i);
			freereg();
			freereg();
			break;
		case nodetype_TASGN:
			i=codegen(t->end,fp);
			j=getreg();
			fprintf(fp, "MOV R%d,%d\n",j,t->left->Gentry->binding);
			Ptemp=t->left->Gentry->paramlist;
			k=0;
			while(Ptemp!=NULL)
			{
				if(strcmp(Ptemp->name,t->right->varname)==0)
					break;
				k++;
				Ptemp=Ptemp->next;
			}
			fprintf(fp,"ADD R%d,%d\n",j,k);
			fprintf(fp,"MOV [R%d],R%d\n",j,i);
			freereg();
			freereg();

			break;

//COMPARISONS
		case nodetype_LT:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp,"LT R%d,R%d\n",i,j);
			
			freereg();
			return i;
			break;
		case nodetype_LE:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp,"LE R%d,R%d\n",i,j);
			
			freereg();
			return i;
			break;
		case nodetype_GT:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp,"GT R%d,R%d\n",i,j);
			
			freereg();
			return i;
			break;
		case nodetype_GE:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp,"GE R%d,R%d\n",i,j);
			
			freereg();
			return i;
			break;
		case nodetype_EQ:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp,"EQ R%d,R%d\n",i,j);
			freereg();
			return i;
			break;
		case nodetype_NE:
			i=codegen(t->left,fp);
			j=codegen(t->right,fp);
			fprintf(fp,"NE R%d,R%d\n",i,j);
			freereg();
			return i;
			break;

//CONTROL STATEMENTS
		case nodetype_IF:
			i=codegen(t->left,fp);
			j=getlabel();
			fprintf(fp,"JZ R%d,L%d\n",i,j);
			codegen(t->right,fp);
			if(t->end!=NULL)
			{
				k=getlabel();
				fprintf(fp,"JMP L%d\n",k);
				fprintf(fp,"L%d:\n",j);
				codegen(t->end,fp);
				fprintf(fp,"L%d:\n",k);
			}
			else
				fprintf(fp,"L%d:\n",j);
			freereg();
			break;
		case nodetype_WHILE:
			wh++;
			i=getlabel();
			j=getlabel();
			Bstack[++p]=j;
			Cstack[p]=i;
			fprintf(fp,"L%d:\n",i);
			k=codegen(t->left,fp);
			fprintf(fp,"JZ R%d,L%d\n",k,j);
			freereg();
			codegen(t->right,fp);
			fprintf(fp,"JMP L%d\n",i);
			fprintf(fp,"L%d:\n",j);
			wh--;
			p--;
			break;
		case nodetype_BRK:
			if(wh!=0&&p!=-1)
				fprintf(fp,"JMP L%d\n",Bstack[p]);
			break;
		case nodetype_CNTU:
			if(wh!=0&&p!=-1)
				fprintf(fp,"JMP L%d\n",Cstack[p]);
			break;
		case nodetype_DOWHILE:
			wh++;
			i=getlabel();
			j=getlabel();
			Bstack[++p]=j;
			Cstack[p]=i;
			fprintf(fp,"L%d:\n",i);
			codegen(t->right,fp);
			k=codegen(t->left,fp);
			fprintf(fp,"JZ R%d,L%d\n",k,j);
			freereg();
			fprintf(fp,"JMP L%d\n",i);
			fprintf(fp,"L%d:\n",j);
			wh--;
			p--;
			break;
		case nodetype_REPEAT:
			wh++;
			i=getlabel();
			j=getlabel();
			Bstack[++p]=j;
			Cstack[p]=i;
			fprintf(fp,"L%d:\n",i);
			codegen(t->right,fp);
			k=codegen(t->left,fp);
			fprintf(fp,"JNZ R%d,L%d\n",k,j);
			freereg();
			fprintf(fp,"JMP L%d\n",i);
			fprintf(fp,"L%d:\n",j);
			wh--;
			p--;
			break;

//POINTERS		
		case nodetype_POINTER:
			i=getreg();
			j=codegen(t->left,fp);
			fprintf(fp,"MOV R%d,[R%d]\n",i,j);
			freereg();
			return i;
			break;
		case nodetype_ADDR:
			i=getreg();
			fprintf(fp,"MOV R%d,%d\n",i,t->left->Gentry->binding);
			return i; 
			break;

//Functions
		case nodetype_funcall:
			i=0;
			int reg=count;
			while(i<=count)
				fprintf(fp, "PUSH R%d\n",i++);

			//count=-1;
			struct tnode *temp=t->right;
			while(temp!=NULL)						//evaluate arguments and push to stack
			{
				codegen(temp,fp);
				temp=temp->left;
			}
			i=getreg();
			fprintf(fp, "PUSH R%d\n",i);			//return value
			//fprintf(fp, "PUSH R%d\n",i);			//return address
			freereg();
			fprintf(fp, "CALL F%d\n",t->left->Gentry->flabel);

			i=getreg();
			fprintf(fp, "POP R%d\n",i);				//save return value
			
			j=getreg();
			temp=t->right;
			while(temp!=NULL)						//pop arguments
			{
				fprintf(fp,"POP R%d\n",j);
				temp=temp->left;
			}
			freereg();
			while(reg>=0)							//restore registers
				fprintf(fp, "POP R%d\n",reg--);
			return i;
			break;
		case nodetype_ARG:
			i=codegen(t->right,fp);
			fprintf(fp, "PUSH R%d\n",i);
			freereg();
			break;
		case nodetype_RET:
			i=codegen(t->left,fp);
			j=getreg();
			k=getreg();
			fprintf(fp, "MOV R%d,BP\n",j );
			fprintf(fp, "MOV R%d,2\n",k );
			fprintf(fp, "SUB R%d,R%d\n",j,k );
			freereg();
			fprintf(fp, "MOV [R%d],R%d\n",j,i );
			freereg();
			freereg();
			break;

		case nodetype_MAIN:
			fprintf(fp, "F0:\n" );
			fprintf(fp, "PUSH BP\n" );
			fprintf(fp, "MOV BP,SP\n" );
			i=getreg();
			//printf("m3\n");
			Ltemp=Lhead;
			//printf("m4\n");
			while(Ltemp!=NULL)
			{
				//printf("m5\n");
				if(Ltemp->type!=type_argint&&Ltemp->type!=type_argchar&&Ltemp->type!=type_argintref&&Ltemp->type!=type_argcharref)
					fprintf(fp, "PUSH R%d\n",i);
				Ltemp=Ltemp->next;
			}
			//printf("m6\n");
			freereg();
			//printf("m7\n");
			codegen(t->left,fp);
			//printf("m8\n");
			
			break;

		
	}
}

int generate(FILE *fp)
{
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
	fprintf(fp, "MOV SP,%d\n",varadrs);
	fprintf(fp, "MOV BP,SP\n" );
	fprintf(fp, "CALL F0\n" );
	//codegen(t,fp);
	//end(fp);
}

void codegen_func(struct tnode *id,struct tnode *t,FILE *fp)
{
	count=-1;
	int i,j,k;
	fprintf(fp, "F%d:\n",id->Gentry->flabel);
	fprintf(fp, "PUSH BP\n" );
	fprintf(fp, "MOV BP,SP\n" );
	//printf("f5\n");
	i=getreg();
	Ltemp=Lhead;
	while(Ltemp!=NULL)					// Local varibales to stack
	{
		if(Ltemp->type!=type_argint&&Ltemp->type!=type_argchar&&Ltemp->type!=type_argintref&&Ltemp->type!=type_argcharref)
			{fprintf(fp, "PUSH R%d\n",i);printf("%s %d\n",Ltemp->name,Ltemp->binding);}
		Ltemp=Ltemp->next;
	}
	//printf("f6\n");
	freereg();
	//printf("%d %s\n",t->nodetype,t->varname);
	codegen(t,fp);
	//printf("f7\n");
	i=getreg();
	Ltemp=Lhead;
	while(Ltemp!=NULL)
	{
		if(Ltemp->type!=type_argint&&Ltemp->type!=type_argchar&&Ltemp->type!=type_argintref&&Ltemp->type!=type_argcharref)
			fprintf(fp, "POP R%d\n",i);
		Ltemp=Ltemp->next;
	}
	freereg();
	fprintf(fp, "POP BP\n" );
	fprintf(fp, "RET \n" );
	//printf("f8\n");
}
