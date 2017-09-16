#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
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
		q = (Linklist)malloc(sizeof(Lnode));
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
void Deletelist(Linklist L,int min,int max)
{
	Linklist p, q, s;
	int i = 0;
	p = L;
	while (p&&p->data < min)
	{
		p = p->next;
	}
	q = p->next;
	while (q&&q->data <= max)
	{
		s = q;
		q = q->next;
		free(s);
	}
	p->next = q;
}
int main()
{
	Linklist L;
	L = createlist();
	printf("表为:");
	showlist(L);
	Deletelist(L, 2, 4);
	printf("删除后的表为:");
	showlist(L);
	return 0;
}