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
	int n;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	printf("请输入长度n和n个元素");
	scanf("%d", &n);
	p = L;
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
		printf("%d", p -> data);
		p = p->next;
	}
}
void Deletelist(Linklist L)
{
	Linklist p, q, r;
	p = L->next;
	while (p&&p->next)
	{
		q = p;
		if (p->data == q->next->data)
		{
			r = q->next;
			q->next = r->next;
			free(r);
		}
		else
			p = p->next;
			q = q->next;
	}
}
int main()
{
	Linklist L;
	L = createlist();
	printf("表为：\n");
	showlist(L);
	printf("修改后的表为：\n");
	Deletelist(L);
	showlist(L);
	return 0;
}