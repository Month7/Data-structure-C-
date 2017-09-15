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
Bitree Search(Bitree t,int key)          //查找
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
void Insert(Bitree *t, Bitree s)       //插入一个新结点
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
void Show(Bitree t)                  //中序遍历输出
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
	printf("请输入数据（-1结束）\n");
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
	printf("中序遍历输出二叉树为:\n");
	Show(t);
	printf("\n");
	printf("请输入要查找的元素\n");
	scanf("%d",&i);
	p = Search(t, i);
	printf("查找到的元素为%d",p->data);
	printf("\n");
	return 0;
}