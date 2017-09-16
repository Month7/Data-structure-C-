#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode, *Linklist;
void createlist(Linklist L)
{
	Linklist  p, q;
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
void Mergelist(Linklist La, Linklist Lb, Linklist Lc)
{
	Linklist p, q, r, s;
	p = La;
	q = Lb;
	s = Lc;
	while (p&&q)
	{
		if (p->data <= q->data)
		{
			r = p;
			p = p->next;
		}
		else
		{
			r = q;
			q = q->next;
		}
		r->next = s->next;
		s->next = r;
	}
	while (p)
	{
		r = p;
		p = p->next;
		r->next = s->next;
		s->next = r;
	}
	while (q)
	{
		r = q;
		p = q->next;
		r->next = s->next;
		s->next = r;
	}
}
int main()
{
	Linklist La, Lb, Lc;
	La = (Linklist)malloc(sizeof(Lnode));
	La->next = NULL;
	Lb = (Linklist)malloc(sizeof(Lnode));
	Lb->next = NULL;
	Lc = (Linklist)malloc(sizeof(Lnode));
	Lc->next = NULL;
	createlist(La);
    createlist(Lb);
	printf("La=");
	showlist(La);
	printf("\n");
	printf("Lb=");
	showlist(Lb);
	printf("\n");
	printf("Lc=");
	Mergelist(La, Lb, Lc);
	showlist(Lc);
	return 0;
}
