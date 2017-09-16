#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define error(s) 

typedef char datatype;
typedef struct queuenode
{
	datatype data;
	struct queuenode *next;
}Qnode;

typedef struct
{
	Qnode *front;
	Qnode *rear;
}linkqueue;

//初始化队列
void InitQueue(linkqueue *q)
{
	q->front = q->rear = NULL;
}

//判断队列为空，因为不是用数组来存储队列，而是用堆来管理队列，所以队列不会‘上溢’
int QueueEmpty(linkqueue *q)
{
	return ((q->front == NULL) && (q->rear == NULL));
}

//入队
void EnQueue(linkqueue *q, datatype x)
{
	Qnode *p;
	p = (Qnode *)malloc(sizeof(Qnode));

	if(p != NULL);

	p->data = x;
	p->next = NULL;

	//队列为空的情况
	if (QueueEmpty(q))
	{
		q->front = q->rear = p;
	}
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}
//出队
datatype DeQueue(linkqueue *q)
{
	datatype x;
	Qnode *p;

	if(QueueEmpty(q) == 0);

	p = q->front;
	x = p->data;
	q->front = p->next;

	if (q->rear == p)
	{
		q->rear = NULL;
	}

	free(p);
	return x;
}
//取头指针
datatype QueueFront(linkqueue *q)
{
	if (QueueEmpty(q))
	{
		error("queue is empty");
	}
	return (q->front->data);
}

int main()
{
	int x;
	linkqueue p;
	InitQueue(&p);
	EnQueue(&p, 2);
	x = DeQueue(&p);
	printf("%d", x);
	return 0;
}
