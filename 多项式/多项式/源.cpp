#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Lnode
{
	int exp;                                              //指数
	int coef;                                             //系数
	struct Lnode *next;
}Lnode,*Linklist;
Linklist crearelist()
{
	Linklist  L, p, q;
	int n;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	p = L;
	printf("输入长度n和元素\n");
	scanf("%d", &n);
	while (n--)
	{
		q=(Linklist)malloc(sizeof(Lnode));
		scanf("%d,%d", &q->coef, &q->exp);
		q->next = NULL;
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
		{
			printf("%d^%d+", p->coef, p->exp);
		}
		else
		{
			printf("%d", p->coef);
		}
		p = p->next;
	}
}
void addlist(Linklist La,Linklist Lb)
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
			{
				sum = L1->coef + L2->coef;
			}
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
		else if (L2->exp < L1->exp)
		{
			La->next = L2;
			La = La->next;
			L2 = L2->next;
		}
		if(L1)
		{
			La->next = L1;
		}
		if(L2)
		{
			La->next = L2;
		}
	}
}
int main()
{
	Linklist La,Lb;
	La=crearelist();
	Lb = crearelist();
	printf("La=");
	showlist(La);
	printf("\nLb=");
	showlist(Lb);
	printf("\n");
	printf("La+Lb=");
	addlist(La, Lb);
	showlist(La);
	return 0;
}