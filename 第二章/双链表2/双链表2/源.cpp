#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct DLnode
{
	int data;
	DLnode *pre, *next;
}DLnode,*Linklist;
Linklist createlist()
{
	Linklist p, q, L;
	int n;
	L = (Linklist)malloc(sizeof(DLnode));
	p = L;
	printf("请输入n和n个元素");
	scanf("%d", &n);
	while (n--)
	{
		q= (Linklist)malloc(sizeof(DLnode));
		scanf("%d", &q->data);
		q->pre = p;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	L = L->next;
	L->pre = NULL;
	return L;
}
void showlist(Linklist L)
{
	Linklist p, q;
	p = L;
	printf("正向输出:\n");
	while (p)
	{
		printf("%d", p->data);
		q = p;
		p = p->next;
	}
	printf("\n反向输出:\n");
	while (q)
	{
		printf("%d", q->data);
		q = q->pre;
	}
}
void Deletelist(Linklist L, int e)
{
	Linklist p;
	int i = 0;
	p = L->next;
	while (p&&i<e-1)
	{
		p = p->next;
		i++;
	}
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
}
void Inserlist(Linklist L,int n,int e)
{
	Linklist p, q;
	int i = 0;
	p = L->next;
	while (p&&i < n - 1)
	{
		p = p->next;
		i++;
	}
	if (i != n - 1)
	{
		printf("位置错误！");
	}
	else
		q = (Linklist)malloc(sizeof(DLnode));
	    q->data = e;
		q->pre = p->pre;
		p->pre->next = q;
		q->next = p;
		p->pre = q;
}
void menu()
{
	printf("■■■■■■■■■■■■■□□□□□□□□□□□□\n");
	printf("         ■■■■■     双链表        □□□□    \n");
	printf("                请输入字母执行相应功能            \n");
	printf("                <a>   输出双链表                  \n");
	printf("                <b>删除功能                       \n");
	printf("                <c>插入功能                       \n");
	printf("                <#>退出                           \n");
}
int main()
{
	Linklist L;
	L = createlist();
	char c;
	menu();
	while ((c = getchar()) != '#')
	{
		switch (c)
		{
		case 'a':
			showlist(L);
			break;
		case 'b':
			int i;
			printf("请输入删除位置！");
			scanf("%d", &i);
			printf("删除后的表为");
			Deletelist(L, i);
			showlist(L);
			break;
		case'c' :
			int n, e;
			printf("请输入插入位置和元素");
			scanf("%d,%d", &n, &e);
			Inserlist(L, n, e);
			showlist(L);
			break;
		}
	}
	return 0;
}