#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
	char data;
	struct node *next;
}Queue;
typedef struct mystruct
{
	Queue *front, *rear;
}Linkqueue;
void Init(Linkqueue *q)
{
// 	(*q)->front = (Queue*)malloc(sizeof(Queue));
// 	(*q)->front->next = NULL;
// 	(*q)->rear = (*q)->front;
// 	(*q)->rear = NULL;
//	(*q)->rear = (*q)->front;
//	(*q)->front->next = NULL;
//	(*q)->rear->next = NULL;
	q->front = q->rear = NULL;
}
void In(Linkqueue *q, char e)
{
	Queue *p;
	p = (Queue*)malloc(sizeof(Queue));
	p->data = e;
	p->next = NULL;
	if (q->front==q->rear)
	{
		q->front = q->rear = p;
	}
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
	printf("����ɹ���\n");
}
void Out(Linkqueue *q, char *x)
{
	Queue *p;
	p = q->front;
	*x = q->front->data;
	q->front=p->next;
	free(p);
}
int main()
{
	Linkqueue q;
	Init(&q);
	char c, x;
	printf("������Ҫ����е�����\n");
	scanf("%c",&c);
	In(&q,c);
	Out(&q, &x);
	printf("�����е�����Ϊ%c", x);
	return 0;
}