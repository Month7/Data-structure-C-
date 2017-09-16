#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Qnode;
typedef struct
{
	Qnode *front, *rear;
}Lqueue;
int Init(Lqueue *s)
{
	s->front = s->rear = NULL;
	return 1;
}
void in(Lqueue*s,int x)
{
	Qnode *newbase;
	newbase = (Qnode*)malloc(sizeof(Qnode));
	newbase->data = x; newbase->next = NULL;
	if (s->rear == NULL)
	{
		s->rear = newbase;
		s->front = s->rear;
		s->rear->next = NULL;
	}
	else
	{
		s->rear->next = newbase;
		s->rear = s->rear->next;
		s->rear->next = NULL;
	}
}
void out(Lqueue *s)
{
	Qnode *p, *q;
	if (s->rear == NULL)
		printf("为空\n");
	else
	{
		if (s->front == s->rear)
			printf("  %d", s->front->data);
		else
		{
			p = s->front;
			do
			{
				printf("  %d", p->data);
				q = p;
				p = p->next;
			} while (q != s->rear);
		}
	}
	printf("\n");
}
int get(Lqueue *s, int *x)
{
	Qnode *p;
	p = s->front;
	*x = p->data;
	s->front = p->next;
	free(p);
	return *x;
}
int YHSJ(Lqueue *s,int n)
{
	int i, m;
	Qnode *p, *q, *h, *r;
	int e, a;
	if (n == 1) out(s);
	if (n>1)
	{
		for (m = 1; m <= n; m++)//打印空格
			printf(" ");
		out(s);
		in(s, 1);
		p = s->front; q = p->next;
		for (i = 1; i <= n; i++)
		{
			r = s->rear;
			for (m = 1; m <= n - i; m++)//打印空格
				printf("&");
			out(s);
			while (p != r)
			{
				e = p->data + q->data;
				in(s, e);
				p = q;
				q = q->next;
				get(s, &a);
			}
			in(s, 1);
		}
	}
	return 1;
}
int main()
{
	Lqueue s;
	Init(&s);
	int n;
	printf("请输入n\n");
	scanf("%d", &n);
	YHSJ(&s, n);
	return 0;
}