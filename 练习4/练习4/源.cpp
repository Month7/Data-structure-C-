#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int zhishu;
	int xishu;
	struct node *next;
}node,*Linklist;
Linklist create()
{
	Linklist L, p, q;
	int n, a, b;
	L = (Linklist)malloc(sizeof(node));
	L->next = NULL;
	p = L;
	printf("输入长度n");
	scanf("%d", &n);
	while (n--)
	{
		q = (Linklist)malloc(sizeof(node));
		q->next = NULL;
		scanf("%d,%d", &a,&b);
		q->xishu = a;
		q->zhishu = b;
		p->next = q;
		p = q;
	}
	return L;
}
void show(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p)
	{
		if (p->zhishu)
			printf("%d^%d+", p->xishu, p->zhishu);
		else
			printf("%d", p->xishu);
		p = p->next;
	}
	printf("\n");
}
void add(Linklist La, Linklist Lb)
{
	Linklist L1, L2, s;
	int sum = 0;
	L1 = La->next;
	L2 = Lb->next;
	while (L1&&L2)
	{
		if (L1->zhishu < L2->zhishu)
		{
			La->next = L1;
			La = La->next;
			L1 = L1->next;
		}
		else if (L1->zhishu == L2->zhishu)
		{
			sum = L1->xishu + L2->xishu;
			if (sum)
			{
				L1->xishu = sum;
				La->next=L1;
				La = La->next;
				L1 = L1->next;
				s = L2;
				L2 = L2->next;
				free(s);
			}
			else
			{
				s = L1;
				L1 = L1->next;
				free(s);
				s = L2;
				L2 = L2->next;
				free(s);
			}
		}
		else if(L1->zhishu>L2->zhishu)
		{
			La->next=L2;
			L2 = L2->next;
			La = La->next;
		}
		if (L1)
			La->next = L1;
		if (L2)
			La->next = L2;
	}
}
int main()
{
	Linklist La, Lb;
	La = create();
	Lb = create();
	printf("表达式La为:");
	show(La);
	printf("表达式Lb为:");
	show(Lb);
	printf("和为:\n");
	add(La, Lb);
	show(La);
	return 0;
}