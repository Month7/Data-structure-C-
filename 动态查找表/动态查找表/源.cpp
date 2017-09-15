#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#define NULL 0
typedef struct ElemType
{
	int key;
}ElemType;
typedef struct E
{
	ElemType data;
	struct E *Lchild, *Rchild;
}E,*Bitree;
Bitree Search(Bitree t,int key)          //����
{
	if (t==NULL)
	{
		return NULL;
	}
	if (key<t->data.key)
	{
		return Search((t->Lchild),key);
	}
	if (key > t->data.key)
	{
		return Search((t->Rchild), key);
	}
}
void Insert(Bitree *t, Bitree s)       //����һ���½��
{
	if (*t==NULL)
	{
		*t = s;
	}
	else if(s->data.key<(*t)->data.key)
	{
		Insert(&((*t)->Lchild),s);
	}
	else if (s->data.key > (*t)->data.key)
	{
		Insert(&((*t)->Rchild), s);
	}
}
void Show(Bitree t)                  //����������
{
	if (t)
	{
		Show(t->Lchild);
		printf("%d ",t->data.key);
		Show(t->Rchild);
	}
}
int main()
{
	Bitree t, s, p;
	t = NULL;
	int key, i;
	printf("���������ݣ�-1������\n");
	scanf("%d",&key);
	while (key!=-1)
	{
		s = (Bitree)malloc(sizeof(E));
		s->data.key = key;
		s->Lchild = NULL;
		s->Rchild = NULL;
		Insert(&t,s);
		scanf("%d", &key);
	}
	printf("����������������Ϊ:\n");
	Show(t);
	printf("\n");
	printf("������Ҫ���ҵ�Ԫ��\n");
	scanf("%d",&i);
	p = Search(t, i);
	printf("���ҵ���Ԫ��Ϊ%d",p->data);
	printf("\n");
	return 0;
}