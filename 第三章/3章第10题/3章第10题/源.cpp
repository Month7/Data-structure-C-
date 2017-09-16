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
	printf("=======第10题=======\n");
	printf("\t<a>入队\n");
	printf("\t<b>出队\n");
	printf("\t<c>判空\n");
	printf("\t<d>输出队列\n");
	printf("\t<#>退出\n");
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
			printf("输入数据\n");
			scanf("%d", &x);
			In(&s, x);
			break;
		case'b':
			y = Out(&s);
			printf("出队数据为;%d\n", y);
			break;
		case'c':
			if (Empty(&s))
				printf("队为空\n");
			else
				printf("队非空\n");
			break;
		case'd':
			printf("队列为\n");
			show(&s);
			break;
		}
	}
	return 0;
}