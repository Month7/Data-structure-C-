#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;
Linklist createlist()
{
	Linklist L, p, q;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	p = L;
	int n;
	printf("请输入n和n个数据元素");
	scanf("%d", &n);
	while (n--)
	{
		q= (Linklist)malloc(sizeof(Lnode));
		q->next = NULL;
		scanf("%d", &q->data);
		p->next = q;
		p = q;
	}
	return L;
}
void showlist(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p)
	{
		printf("%d", p->data);
		p = p->next;
	}
}
void locatelist(Linklist L, int e)
{
	Linklist p;
	p = L->next;
	while (p&&p->data != e)
	{
		p = p->next;
	}
	printf("%d的元素是%d", e, p->data);
}
void length(Linklist L)
{
	int i = 0;
	Linklist p;
	p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	printf("长度为%d", i);
}
int main()
{
	Linklist L;
	L = createlist();
	printf("表为：");
	showlist(L);
	printf("\n");
	length(L);
	printf("\n");
	int e;
	printf("请输入要查找的元素");
	scanf("%d", &e);
	locatelist(L, e);
	return 0;
}