#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int exp;        //指数
	int coef;       //系数
	struct node *next;
}node,*Linklist;
Linklist create()
{
	Linklist L, p, q;
	L = (Linklist)malloc(sizeof(node));
	L->next = NULL;
	p = L;
	int a, b, n;
	printf("请输入总长度n和数据");
	scanf("%d", &n);
	while (n--)
	{
		q = (Linklist)malloc(sizeof(node));
		q->next = NULL;
		scanf("%d,%d", &a, &b);
		q->coef = a;
		q->exp = b;
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
		if (p->exp)
			printf("%d^%d", p->coef, p->exp);
		if (p->next)
			printf("+");
		else
			printf("%d", p->coef);
		p = p->next;
	}
}
void add(Linklist La, Linklist Lb)
{
	Linklist L1, L2, s;
	int sum = 0;
	L1 = La->next;
	L2 = Lb->next;
	while (L1&&L2)
	{
		if (L1->exp < L2->exp)
		{
			La->next = L1;
			La = La->next;
			L1 = L1->next;
		}
		else if (L1->exp == L2->exp)
		{
			sum = L1->coef + L2->coef;
			if (sum)
			{
				L1->coef = sum;
				La->next = L1;
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
		else if (L1->exp>L2->exp)
		{
			La->next = L2;
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
	printf("输入La数据\n");
	La = create();
	printf("输入Lb数据\n");
	Lb = create();
	printf("La=:");
	showlist(La);
	printf("\n");
	printf("Lb=");
	showlist(Lb);
	printf("\n");
	printf("La+Lb=");
	add(La, Lb);
	showlist(La);
	return 0;
}