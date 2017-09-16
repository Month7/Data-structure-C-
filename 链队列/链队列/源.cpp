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

//��ʼ������
void InitQueue(linkqueue *q)
{
	q->front = q->rear = NULL;
}

//�ж϶���Ϊ�գ���Ϊ�������������洢���У������ö���������У����Զ��в��ᡮ���硯
int QueueEmpty(linkqueue *q)
{
	return ((q->front == NULL) && (q->rear == NULL));
}

//���
void EnQueue(linkqueue *q, datatype x)
{
	Qnode *p;
	p = (Qnode *)malloc(sizeof(Qnode));

	if(p != NULL);

	p->data = x;
	p->next = NULL;

	//����Ϊ�յ����
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
//����
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
//ȡͷָ��
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
