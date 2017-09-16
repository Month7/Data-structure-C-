#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node,*Linklist;
Linklist create(int m)
{
	Linklist L, p, q;
	L = (Linklist)malloc(sizeof(node));
	p = L;
	int i;
	for (i = 1; i <=m;i++)
	{
		q = (Linklist)malloc(sizeof(node));
		q->data = i;
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
		printf("%d", p->data);
		p = p->next;
	}
}
void Joseph(Linklist L,int m, int k)
{
	Linklist p, q;
	p = L;
	int i;
	for (i = 1; i < m + 1; i++)
		p = p->next;
	while (p)
	{
		for (i = 1; i < k ; i++)
			p = p->next;
		q = p->next;
		if(p->data)
		printf("%d   ", q->data);
		if (p->next == p)
			p = NULL;
		else
		{
			p->next = q->next;
			p = p->next;
			free(q);
		}
	}
}
int main()
{
	Linklist L;
	int m, k, n;
	printf("请输入圆桌人数\n");
	scanf("%d", &n);
	L = create(n);
	showlist(L);
	printf("\n请输入第一次开始报数人的位置\n");
	scanf("%d", &m);
	printf("请输入报到第几个数的人出列\n");
	scanf("%d", &k);
	printf("出列的顺序如下\n");
	Joseph(L, m, k);
	return 0;
}