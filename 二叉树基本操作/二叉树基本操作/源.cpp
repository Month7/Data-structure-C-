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
void Show1(Bitree t)           //����������
{
	if (t)
	{
		printf(" %c ", t->data);
		Show1(t->Lchild);
		Show1(t->Rchild);
	}
}
void Show2(Bitree t)         //����������
{
	if (t)
	{
		Show2(t->Lchild);
		printf(" %c ", t->data);
		Show2(t->Rchild);
	}
}
void Show3(Bitree t)         //����������
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
	printf("�������������д���������\n");
	Create(&t);
	printf("�������������Ϊ:\n");
	Show1(t);
	printf("\n");
	printf("�������������Ϊ:\n");
	Show2(t);
	printf("\n");
	printf("�������������Ϊ:\n");
	Show3(t);
	printf("\n");
	return 0;
}