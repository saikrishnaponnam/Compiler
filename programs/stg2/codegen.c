
int count=-1;

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

void scan(int adrs,FILE *fp )
{
	fprintf(fp,"MOV SP,4121\n");
	int i=getreg();
	fprintf(fp,"MOV R%d,7\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,-1\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,%d\n",i,adrs);
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
	fprintf(fp,"MOV SP,4121\n");
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

int codegen(struct tnode *t,FILE *fp)
{
	int i,j;
	switch(t->nodetype)
	{
		case nodetype_NULL:
			codegen(t->left,fp);
			codegen(t->right,fp);
			break;
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
		case nodetype_LEAF:
			i=getreg();
			fprintf(fp, "MOV R%d,%d\n",i,t->val);
			return i;
			break;
		case nodetype_ID:
			i=getreg();
			fprintf(fp, "MOV R%d,[%d]\n",i,4096+*(t->varname)-'a');
			return i;
			break;
		case nodetype_READ:
			scan(4096+*(t->left->varname)-'a',fp);
			break;
		case nodetype_WRITE:
			i=codegen(t->left,fp);
			print(i,fp);
			freereg();
			break;
		case nodetype_ASGN:
			i=codegen(t->right,fp);
			fprintf(fp,"MOV [%d],R%d\n",4096+*(t->left->varname)-'a',i );
			return i;
			break;
	}
}

int generate(struct tnode *t,FILE *fp)
{
	fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	codegen(t,fp);
	end(fp);
}



