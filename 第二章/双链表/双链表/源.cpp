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
	printf("������n��n��Ԫ��");
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
	printf("�������˫����:\n");
	while (q)
	{
		printf("%d",q->data);
		p = q;
		q = q->next;
	}
	printf("�������˫����:\n");
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