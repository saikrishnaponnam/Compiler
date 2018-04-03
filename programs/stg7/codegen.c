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

int alloc(FILE *fp)
{
	int i=getreg();
	fprintf(fp,"MOV R%d,\"Alloc\"\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,8\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"CALL 0\n");
	int j=getreg();
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	freereg();
	return i;
}

int freecall(int adrs,FILE *fp)
{
	int i=getreg();
	fprintf(fp,"MOV R%d,\"Free\"\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,R%d\n",i,adrs);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"CALL 0\n");
	int j=getreg();
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	freereg();
	return i;
}

int initialise(FILE *fp)
{
	int i=getreg();
	fprintf(fp,"MOV R%d,\"Heapset\"\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,0\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"CALL 0\n");
	int j=getreg();
	fprintf(fp,"POP R%d\n",i);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	fprintf(fp,"POP R%d\n",j);
	freereg();
	return i;
}
int getadrs(struct tnode *t,FILE *fp)
{
	int i,j,k;
	if(t->left->nodetype!=nodetype_FIELD)
	{
		i=getreg();
		if(t->left->Lentry==NULL)
				fprintf(fp,"MOV R%d,[%d]\n",i,t->left->Gentry->binding);
		else
		{
			fprintf(fp, "MOV R%d,%d\n",i,t->left->Lentry->binding);
			k=getreg();
			fprintf(fp, "MOV R%d,BP\n",k);
			fprintf(fp, "ADD R%d,R%d\n",i,k);
			freereg();
			fprintf(fp, "MOV R%d,[R%d]\n",i,i);
		}
		if(strcmp(t->left->varname,"self")==0)
			fprintf(fp,"ADD R%d,%d\n",i,CFLookup(Cptr,t->right->varname)->fieldindex);
		else
			fprintf(fp,"ADD R%d,%d\n",i,FLookup(t->left->type,t->right->varname)->fieldindex);
		return i;
	}
	else
	{
		i=getadrs(t->left,fp);
		fprintf(fp,"MOV R%d,[R%d]\n",i,i);
		fprintf(fp,"ADD R%d,%d\n",i,FLookup(t->left->type,t->right->varname)->fieldindex);
		return i;
	}
}

int Bstack[100],wh=0,p=-1,Cstack[100],param=0;


int codegen(struct tnode *t,FILE *fp)
{
	int i,j,k,reg;
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
			if(t->type==typevoid)
				fprintf(fp, "MOV R%d,%s\n",i,t->str);
			if(t->type==typestr)
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
		
		case nodetype_FIELDexpr:
			i=getadrs(t->left,fp);
			fprintf(fp,"MOV R%d,[R%d]\n",i,i);
			return i;
			break;

//ARITHMETIC 
		case nodetype_PLUS:
			//printf("p0\n");
			i=codegen(t->left,fp);
			//printf("p1 %d\n",t->right->nodetype);
			j=codegen(t->right,fp);
			//printf("p2\n");
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
				scan(i,fp,1);
				
				freereg();
			}
			break;
		case nodetype_WRITE:
			//printf("write\n");
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
		case nodetype_UREAD:
			i=getadrs(t->left,fp);
			scan(i,fp,1);
			freereg();
			break;




//ASSINGNMENT
		case nodetype_ASGN:
			//printf("as0\n");
			i=codegen(t->right,fp);
			//printf("as1\n");
			if(t->left->nodetype==nodetype_FIELD)
			{
				j=getadrs(t->left,fp);
				fprintf(fp,"MOV [R%d],R%d\n",j,i);
				freereg();
			}
			else{
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
				fprintf(fp, "MOV [R%d],R%d\n",j,i);
				
				freereg();
			}}
			freereg();
			//printf("asgn done\n");
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
			//printf("if\n");
			i=codegen(t->left,fp);
			j=getlabel();
			//printf("if2 %d\n",t->right->nodetype);
			fprintf(fp,"JZ R%d,L%d\n",i,j);
			codegen(t->right,fp);
			//printf("if3\n");
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
			//printf("if done\n");
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
			reg=count;
			//printf("fc0\n");
			while(i<=count)
				fprintf(fp, "PUSH R%d\n",i++);
			struct tnode *temp=t->right;
			//printf("fc1\n");
			if(t->end!=NULL)					//for methods PUSH self
			{
				//printf("fc2\n");
				if(t->end->nodetype==nodetype_ID)
				{
					i=getreg();
					if(strcmp(t->end->varname,"self")==0)
					{
						//printf("fc3\n");
						fprintf(fp, "MOV R%d,%d\n",i,t->end->Lentry->binding);
						k=getreg();
						fprintf(fp, "MOV R%d,BP\n",k);
						fprintf(fp, "ADD R%d,R%d\n",i,k);
						freereg();
						fprintf(fp, "MOV R%d,[R%d]\n",i,i);
					}
					else
						fprintf(fp,"MOV R%d,[%d]\n",i,t->end->Gentry->binding);
					fprintf(fp,"PUSH R%d\n",i );
					freereg();
				}
				else if(t->end->nodetype==nodetype_FIELD)
				{
					//printf("fc4\n");
					i=getadrs(t->end,fp);
					fprintf(fp,"PUSH R%d\n",i);
					freereg();
				}
			}
			//printf("fc5\n");
			while(temp!=NULL)						//evaluate arguments and push to stack
			{
				codegen(temp,fp);
				temp=temp->left;
			}
			//printf("fc6\n");
			i=getreg();
			fprintf(fp, "PUSH R%d\n",i);			//return value
			freereg();
			//printf("fc7\n");
			if(t->end==NULL)
				fprintf(fp, "CALL F%d\n",t->left->Gentry->flabel);
			else
			{
				//printf("fc8\n");
				if(t->end->nodetype==nodetype_ID)
					if(strcmp(t->end->varname,"self")==0)
						fprintf(fp, "CALL F%d\n",CMLookup(t->end->cptr,t->left->varname)->flabel);
					else
						fprintf(fp, "CALL F%d\n",CMLookup(t->end->Gentry->cptr,t->left->varname)->flabel);
				else if(t->end->nodetype==nodetype_FIELD)
					fprintf(fp, "CALL F%d\n",CMLookup(t->end->right->cptr,t->left->varname)->flabel);
			}
			//printf("fc9\n");
			i=getreg();
			fprintf(fp, "POP R%d\n",i);				//save return value
			
			j=getreg();
			temp=t->right;
			if(t->end!=NULL)						//POP self
				fprintf(fp,"POP R%d\n",j);
			while(temp!=NULL)						//pop arguments
			{
				fprintf(fp,"POP R%d\n",j);
				temp=temp->left;
			}

			freereg();
			while(reg>=0)							//restore registers
				fprintf(fp, "POP R%d\n",reg--);
			//printf("func call %s done\n",t->left->varname);
			return i;
			break;
		/*case nodetype_Method:
			i=0;
			reg=count;
			while(i<=count)
				fprintf(fp, "PUSH R%d\n",i++);
			struct tnode *temp=t->left->end;
			while(temp!=NULL)						//evaluate arguments and push to stack
			{
				codegen(temp,fp);
				temp=temp->left;
			}
			i=getreg();
			fprintf(fp, "PUSH R%d\n",i);			//return value
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
		*/
		case nodetype_ARG:
			i=codegen(t->right,fp);
			fprintf(fp, "PUSH R%d\n",i);
			freereg();
			break;
		case nodetype_RET:
			//printf("ret\n");
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
			fprintf(fp, "MOV SP,%d\n",varadrs);
			fprintf(fp, "MOV BP,SP\n" );
			fprintf(fp, "PUSH BP\n" );
			fprintf(fp, "MOV BP,SP\n" );
			i=getreg();
			Ltemp=Lhead;
			while(Ltemp!=NULL)
			{
				if(Ltemp->binding>0)
					fprintf(fp, "PUSH R%d\n",i);
				Ltemp=Ltemp->next;
			}
			freereg();
			codegen(t->left,fp);
			break;
		
		case nodetype_FREE:
			i=0;
			reg=count;
			while(i<=count)						//save registers
				fprintf(fp, "PUSH R%d\n",i++);
			if(t->left->nodetype==nodetype_ID)
			{
				j=getreg();
				if(t->left->Lentry==NULL)
				{
					fprintf(fp,"MOV R%d,[%d]\n",j,t->left->Gentry->binding);
				}
				else
				{
					fprintf(fp, "MOV R%d,%d\n",j,t->left->Lentry->binding);
					k=getreg();
					fprintf(fp, "MOV R%d,BP\n",k);
					fprintf(fp, "ADD R%d,R%d\n",j,k);
					freereg();
					fprintf(fp, "MOV R%d,[R%d]\n",j,j);
				}
				i=freecall(j,fp);
				freereg();
				freereg();
			}
			else
			{
				j=getadrs(t->left,fp);
				i=freecall(j,fp);
				freereg();
				freereg();
			}
			while(reg>=0)							//restore registers
				fprintf(fp, "POP R%d\n",reg--);
			break;
		case nodetype_INIT:
			i=0;
			reg=count;
			while(i<=count)
				fprintf(fp, "PUSH R%d\n",i++);

			i=initialise(fp);
			if(t->left->Lentry==NULL){
				fprintf(fp,"MOV [%d],R%d\n",t->left->Gentry->binding,i);
			}
			else
			{
				j=getreg();
				fprintf(fp, "MOV R%d,%d\n",j,t->left->Lentry->binding);
				k=getreg();
				fprintf(fp, "MOV R%d,BP\n",k);
				fprintf(fp, "ADD R%d,R%d\n",j,k);
				freereg();
				fprintf(fp, "MOV [R%d],R%d\n",j,i);
				freereg();
			}
			freereg();
			while(reg>=0)							//restore registers
				fprintf(fp, "POP R%d\n",reg--);
			//printf("initialise done\n");
			break;

		case nodetype_ALLOCID:
			i=0;
			reg=count;
			while(i<=count)
				fprintf(fp, "PUSH R%d\n",i++);

			i=alloc(fp);
			if(t->left->Lentry==NULL)
				fprintf(fp,"MOV [%d],R%d\n",t->left->Gentry->binding,i);
			else
			{
				j=getreg();
				fprintf(fp, "MOV R%d,%d\n",j,t->left->Lentry->binding);
				k=getreg();
				fprintf(fp, "MOV R%d,BP\n",k);
				fprintf(fp, "ADD R%d,R%d\n",j,k);
				freereg();
				fprintf(fp, "MOV [R%d],R%d\n",j,i);
				freereg();
			}
			freereg();
			while(reg>=0)							//restore registers
				fprintf(fp, "POP R%d\n",reg--);
			break;
		case nodetype_ALLOCFIELD:
			i=0;
			reg=count;
			while(i<=count)
				fprintf(fp, "PUSH R%d\n",i++);

			i=alloc(fp);
			j=getadrs(t->left,fp);
			fprintf(fp,"MOV [R%d],R%d\n",j,i);
			freereg();
			freereg();
			while(reg>=0)							//restore registers
				fprintf(fp, "POP R%d\n",reg--);
			break;
		case nodetype_NEW:
			i=0;
			reg=count;
			//printf("n0\n");
			while(i<=count)
				fprintf(fp, "PUSH R%d\n",i++);
			i=alloc(fp);
			if(t->left->nodetype==nodetype_ID)
			{
				//printf("n1\n");
				if(t->left->Lentry==NULL)
					fprintf(fp,"MOV [%d],R%d\n",t->left->Gentry->binding,i);
				else
				{
					//printf("n2\n");
					j=getreg();
					fprintf(fp, "MOV R%d,%d\n",j,t->left->Lentry->binding);
					k=getreg();
					fprintf(fp, "MOV R%d,BP\n",k);
					fprintf(fp, "ADD R%d,R%d\n",j,k);
					freereg();
					fprintf(fp, "MOV [R%d],R%d\n",j,i);
					freereg();
				}
				freereg();
			}
			else if(t->left->nodetype==nodetype_FIELD)
			{
				//printf("n3\n");
				j=getadrs(t->left,fp);
				fprintf(fp,"MOV [R%d],R%d\n",j,i);
				freereg();
				freereg();
			}
			//printf("n4\n");
			while(reg>=0)							//restore registers
					fprintf(fp, "POP R%d\n",reg--);
			//printf("newdone\n");
			break;

		
	}
}

int generate(FILE *fp)
{
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
	fprintf(fp, "CALL F0\n" );
	//codegen(t,fp);
	//end(fp);
}

void codegen_func(int flabel,struct tnode *t,FILE *fp)
{
	count=-1;
	int i,j,k;
	fprintf(fp, "F%d:\n",flabel);
	fprintf(fp, "PUSH BP\n" );
	fprintf(fp, "MOV BP,SP\n" );
	//printf("f5\n");
	i=getreg();
	Ltemp=Lhead;
	while(Ltemp!=NULL)					// Local varibales to stack
	{
		if(Ltemp->binding>0)
			{fprintf(fp, "PUSH R%d\n",i);}
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
		if(Ltemp->binding>0)
			fprintf(fp, "POP R%d\n",i);
		Ltemp=Ltemp->next;
	}
	freereg();
	fprintf(fp, "POP BP\n" );
	fprintf(fp, "RET \n" );
	//printf("f8\n");
}

