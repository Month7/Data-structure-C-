#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct DLnode
{
	int data;
	struct DLnode *per, *next;
}DLnode,*Linklist;
Linklist createlist()
{
	Linklist s, q, L;
	L = (Linklist)malloc(sizeof(DLnode));
	q = L;
	int n;
	printf("请输入n和n个元素");
	scanf("%d", &n);
	while (n--)
	{
		s = (Linklist)malloc(sizeof(DLnode));
		scanf("%d", &s->data);
		s->per = q;
		q->next = s;
		q = s;
	}
	q->next = NULL;
	L = L->next;
	L->per = NULL;
	return L;
}
void showlist(Linklist L)
{
	Linklist q, p;
	q = L;
	printf("正向输出双链表:\n");
	while (q)
	{
		printf("%d",q->data);
		p = q;
		q = q->next;
	}
	printf("逆向输出双链表:\n");
	while (p)
	{
		printf("%d", p->data);
		p = p->per;
	}
} 
int main()
{
	Linklist L;
	L = createlist();
	showlist(L);
	return 0;
}