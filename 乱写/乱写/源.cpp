#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Lnode
{
	char data;
	struct Lnode *next;
}Lnode,*Linklist;
Linklist create()
{
	Linklist L, p, q;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	p = L;
	char c;
	int flag = 1;
	printf("��������'#'����");
	while (flag)
	{
		c = getchar();
		if (c != '#')
		{
			q = (Linklist)malloc(sizeof(Lnode));
			q->data = c;
			p->next = q;
			p = q;
		}
		else
			flag = 0;
		q->next = NULL;
	}
	return L;
}
void showlist(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p)
	{
		printf("%c", p->data);
		p = p->next;
	}
}
void Nizhi(Linklist L)
{
	Linklist p, q;
	p = L->next;
	q = p->next;
	p->next = NULL;
	while (q)
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
	L = create();
	printf("��Ϊ");
	showlist(L);
	printf("���ú�ı�Ϊ");
	Nizhi(L);
	showlist(L);
	return 0;
}