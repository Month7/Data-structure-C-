#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
	char data;
	struct node *Lchild, *Rchild;
}Bit,*Bitree;
void Create(Bitree *t)
{
	char c;
	c = getchar();
	if (c=='#')
	{
		*t = NULL;
	}
	else
	{
		(*t) = (Bitree)malloc(sizeof(Bit));
		(*t)->data = c;
		Create(&((*t)->Lchild));
		Create(&((*t)->Rchild));
	}
}
void Show1(Bitree t)           //先序遍历输出
{
	if (t)
	{
		printf(" %c ", t->data);
		Show1(t->Lchild);
		Show1(t->Rchild);
	}
}
void Show2(Bitree t)         //中序遍历输出
{
	if (t)
	{
		Show2(t->Lchild);
		printf(" %c ", t->data);
		Show2(t->Rchild);
	}
}
void Show3(Bitree t)         //后序遍历输出
{
	if (t)
	{
		Show3(t->Lchild);
		Show3(t->Rchild);
		printf(" %c ", t->data);
	}
}
int main()
{
	Bitree t;
	printf("请输入先序序列创建二叉树\n");
	Create(&t);
	printf("先序遍历输出结果为:\n");
	Show1(t);
	printf("\n");
	printf("中序遍历输出结果为:\n");
	Show2(t);
	printf("\n");
	printf("后序遍历输出结果为:\n");
	Show3(t);
	printf("\n");
	return 0;
}