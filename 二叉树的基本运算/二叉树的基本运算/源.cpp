#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int count = 0;
typedef struct Tree
{
	char data;
	Tree *Lchild, *Rchild;
}Tree, *Ctree;
void create(Ctree *t)
{
	char ch;
	ch = getchar();
	if (ch == '#')
		*t = NULL;
	else
	{
		*t = (Ctree)malloc(sizeof(Tree));
		(*t)->data = ch;
		create(&(*t)->Lchild);
		create(&(*t)->Rchild);
	}
}
void show1(Ctree t)
{
	if (t)
	{
		printf("%2c", t->data);
		show1(t->Lchild);
		show1(t->Rchild);
	}
}
void show2(Ctree t)
{
	if (t)
	{
		show2(t->Lchild);
		printf("%2c", t->data);
		show2(t->Rchild);
	}
}
void show3(Ctree t)
{
	if (t)
	{
		show2(t->Lchild);
		show2(t->Rchild);
		printf("%2c", t->data);
	}
}
void leaf(Ctree t)
{
	if (t != NULL)
	{
		leaf(t->Lchild);
		leaf(t->Rchild);
		if (t->Lchild == NULL&&t->Rchild == NULL)
			count++;
	}
}
void exchange(Ctree t)
{
	Ctree s;
	s = t->Lchild;
	t->Lchild = t->Rchild;
	t->Rchild = s;
}
void fanzhuan(Ctree t)
{
	if (t == NULL)
		return;
	else
	{
		fanzhuan(t->Lchild);
		fanzhuan(t->Rchild);
		exchange(t);
	}
}
void menu()
{
	printf("----------------二叉树的基本操作-------------\n");
	printf("\t\t <a>先序输出树\n");
	printf("\t\t <b>中序输出树\n");
	printf("\t\t <c>后序输出树\n");
	printf("\t\t <d>统计叶子数目\n");
	printf("\t\t <e>反转二叉树\n");
	printf("\t\t <$>退出\n");
}
int main()
{
	Ctree t;
	t = NULL;
	printf("先序创建树");
	create(&t);
	menu();
	char c;
	while ((c = getchar()) != '$')
	{
		switch (c)
		{
		case 'a':
			printf("先序输出树");
			show1(t);
			printf("\n");
			break;
		case'b':
			printf("中序输出树");
			show2(t);
			printf("\n");
			break;
		case'c':
			printf("后序输出树");
			show3(t);
			printf("\n");
			break;
		case'd':
			leaf(t);
			printf("叶子的数目为:%d", count);
			break;
		case'e':
			fanzhuan(t);
			printf("反转后先序输出树");
			show1(t);
			printf("\n");
			break;
		}
	}
	return 0;
}