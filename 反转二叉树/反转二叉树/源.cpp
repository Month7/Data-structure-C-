#include<stdio.h>
#include<stdlib.h>
typedef struct Tree
{
	char data;
	Tree *Rchild, *Lchild;
}Tree,*CTree;
void create(CTree *t)
{
	char ch;
	ch = getchar();
	if (ch == '#') (*t) = NULL;
	else
	{
		(*t) = (CTree)malloc(sizeof(Tree));
		(*t)->data = ch;
		create(&((*t)->Lchild));
		create(&((*t)->Rchild));
	}
}
void show1(CTree t)  //ÏÈÐò±éÀúÊä³ö
{
	if (t)
	{
		printf("%2c", t->data);
		show1(t->Lchild);
		show1(t->Rchild);
	}
}
void exchange(CTree t)
{
	CTree p;
	p = t->Lchild;
	t->Lchild = t->Rchild;
	t->Rchild = p;
}
void overturn(CTree t)
{
	if (t)
	{
		overturn(t->Lchild);
		overturn(t->Rchild);
		exchange(t);
	}
}
int main()
{
	CTree t;
	create(&t);
	show1(t);
	printf("\n");
	overturn(t);
	show1(t);
	return 0;
}