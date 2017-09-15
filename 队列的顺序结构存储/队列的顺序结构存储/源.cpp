#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100
typedef struct queue
{
	char data[MAXSIZE];
	int front;
	int	rear;
	int count;
}SeqQueue;
void Init(SeqQueue **q)
{
	(*q) = (SeqQueue*)malloc(sizeof(SeqQueue));
	if ((*q)!=NULL)
	{
//		q->front = q->rear;
		(*q)->front = MAXSIZE;
		(*q)->rear = MAXSIZE;
		(*q)->count = 0;
	}//if
}//Init
void In(SeqQueue *q, char c)
{
//	q->rear[q->count]
	if (q->count==MAXSIZE)
	{
		printf("队满，不能入队\n");
	}
	else
	{
		q->rear = (q->rear+1) % MAXSIZE;
		q->data[q->rear] = c;
		q->count++;
		printf("入队成功！\n");
	}
}
void Out(SeqQueue *q, char *x)
{
	if (q->count==0)
	{
		printf("队空不能出队\n");
	}
	else
	{
		q->front = (q->front + 1) % MAXSIZE;
		*x = q->data[q->front];
		q->count--;
		printf("出队成功！\n");
//		printf("出队元素为%c",x);
	}
}//Out
int main()
{
	SeqQueue *q;
	Init(&q);
	char c, x;
	printf("请输入要入队的数据");
	scanf("%c",&c);
	In(q,c);
	Out(q, &x);
	printf("出队数据为%c", x);
	return 0;
}