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
	fprintf(fp,"MOV SP,%d\n",varadrs);
	int i=getreg();
	fprintf(fp,"MOV R%d,7\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,-1\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	if(scantype==nodetype_READ)
		fprintf(fp,"MOV R%d,%d\n",i,addrs);
	else if(scantype==nodetype_ARRREAD)
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
	fprintf(fp,"MOV SP,%d\n",varadrs);
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
	switch(t->nodetype)
	{
//
		case nodetype_NULL:
			codegen(t->left,fp);
			codegen(t->right,fp);
			break;
		case nodetype_LEAF:
			i=getreg();
			if(t->type==type_char)
				fprintf(fp, "MOV R%d,%s\n",i,t->str);
			else
				fprintf(fp, "MOV R%d,%d\n",i,t->val);
			return i;
			break;
		case nodetype_ID:
			i=getreg();
			fprintf(fp, "MOV R%d,[%d]\n",i,t->Gentry->binding);
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
			}
			fprintf(fp,"ADD R%d,R%d\n",i,j);
			fprintf(fp,"MOV R%d,[R%d]\n",i,i);
			freereg();
			freereg();
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

//INPUT AND OUTPUT
		case nodetype_READ:
			scan((t->left->Gentry)->binding,fp,nodetype_READ);
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
			scan(i,fp,nodetype_ARRREAD);
			freereg();
			break;


//ASSINGNMENT
		case nodetype_ASGN:
			i=codegen(t->right,fp);
			fprintf(fp,"MOV [%d],R%d\n",t->left->Gentry->binding,i );
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
		
	}
}

int generate(struct tnode *t,FILE *fp)
{
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
	codegen(t,fp);
	end(fp);
}


