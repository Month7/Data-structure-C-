#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next, *rear;
}*Linkque;
void Init(Linkque *s)
{
	*s = (Linkque)malloc(sizeof(node));
	(*s)->rear = (*s);
}
void In(Linkque *s, int x)
{
	Linkque p;
	p= (Linkque)malloc(sizeof(node));
	p->data = x;
	p->next = (*s);
	(*s)->rear->next = p;
	(*s)->rear = p;
}
int Out(Linkque *s)
{
	Linkque p;
	int x;
	x = (*s)->next->data;
	p = (*s)->next;
	p->next = (*s)->next->next;
	free(p);
	return x;
}
void show(Linkque *s)
{
	Linkque p;
	p = (*s)->next;
	while (p != (*s))
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
int Empty(Linkque *s)
{
	if ((*s)->rear == (*s))
		return 1;
	else
		return 0;
}
void menu()
{
	printf("=======��10��=======\n");
	printf("\t<a>���\n");
	printf("\t<b>����\n");
	printf("\t<c>�п�\n");
	printf("\t<d>�������\n");
	printf("\t<#>�˳�\n");
}
int main()
{
	Linkque s;
	Init(&s);
	menu();
	char c;
	int x, y;
	while ((c = getchar()) != '#')
	{
		switch (c)
		{
		case'a':
			printf("��������\n");
			scanf("%d", &x);
			In(&s, x);
			break;
		case'b':
			y = Out(&s);
			printf("��������Ϊ;%d\n", y);
			break;
		case'c':
			if (Empty(&s))
				printf("��Ϊ��\n");
			else
				printf("�ӷǿ�\n");
			break;
		case'd':
			printf("����Ϊ\n");
			show(&s);
			break;
		}
	}
	return 0;
}