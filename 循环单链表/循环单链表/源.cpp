#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Lnode
{
	char data;
	struct Lnode *next;
}Lnode,*Linklist;
Linklist createlist()
{
	Linklist L, p, q;
	L = (Linklist)malloc(sizeof(Lnode));
	p = L;
	char c;
	printf("���������ݣ�#����");
	while ((c = getchar())!='#')
	{
			q = (Linklist)malloc(sizeof(Lnode));
			q->data = c;
			p->next = q;
			p = q;
	}
	p->next = L;
	return L;
}
void showlist(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p != L)
	{
		printf("%c", p->data);
		p = p->next;
	}
}
int main()
{
	Linklist L;
	L = createlist();
	printf("��Ϊ");
	showlist(L);
	return 0;
}