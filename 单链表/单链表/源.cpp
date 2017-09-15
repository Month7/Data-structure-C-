#include "stdio.h"
#include "stdlib.h"
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode,*Linklist;

void Create(Linklist L)
{
	Linklist p, q;
	p = L;
	int n;
	printf("请输入n和n个数据元素\n");
	scanf("%d",&n);
	while (n--)
	{
		q = (Linklist)malloc(sizeof(Lnode));
		q->next = NULL;
		scanf("%d",&q->data);
		p->next = q;
		p = q;
	}
}

void Show(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p)
	{
		printf("%d",p->data);
		p = p->next;
	}
}

// void Delete(Linklist L, int i)
// {
// 	Linklist p, q;
// 	int k;
// 	p = L->next;
// 	for(k = 0; k != i - 1; k++)
// 	{
// 		p = p->next;
// 		q = p->next;
// 	}
// 	p->next = q->next;
// 	free(q);
// }
void Nizhi(Linklist L)
{
	Linklist p, q, r;
	p = L->next;
	q = p->next;
	p->next = NULL;
	while(q)
	{ 
		p = q;
		q = q->next;
		p->next = L->next;
		L->next = p;
	}
}
int main()
{
	Linklist L;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	Create(L);
	Show(L);
// 	printf("请输入要删除的位置\n");
// 	int i;
// 	scanf("%d",&i);
// 	Delete(L,i);
// 	printf("删除后的单链表为:\n");
// 	Show(L);
	Nizhi(L);
	printf("逆置后的单链表为:\n");
	Show(L);
	return 0;
}