#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node  *pre,*next;
}node,*Linklist;
Linklist create()
{
	Linklist L, p, q;
	int n;
	L = (Linklist)malloc(sizeof(node));
	p = L;
	printf("������n��n��Ԫ��");
	scanf("%d", &n);
	while (n--)
	{
		q= (Linklist)malloc(sizeof(node));
		scanf("%d", &q->data);
		q->pre = p;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	L = L->next;
	L->pre = NULL;
	return L;
}
void showlist(Linklist L)
{
	Linklist p, q;
	p = L;
	printf("�������:\n");
	while (p)
	{
		printf("%d", p->data);
		q = p;
		p = p->next;
	}
	printf("\n�������:\n");
	while (q)
	{
		printf("%d", q->data);
		q = q->pre;
	}
}
int main()
{
	Linklist L;
	L = create();
	showlist(L);
	return 0;
}