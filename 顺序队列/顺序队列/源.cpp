#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];
	int front, rear;
	int num;
}Sequeue;
int Init(Sequeue *q)
{
	q = (Sequeue*)malloc(sizeof(Sequeue));
	if (q == NULL)
		return 0;
	q->front = MAXSIZE;
	q->rear = MAXSIZE;
	q->num = 0;
	return 1;
}
int In(Sequeue *q, int x)
{
	if (q->num == MAXSIZE)
		printf("队满\n");
	return 0;
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = x;
	q->num++;
	return 1;
}
int Out(Sequeue *q, int *x)
{
	if (q->num == 0)
		printf("队空\n");
	return 0;
	q->front = (q->front + 1) % MAXSIZE;
	*x = q->data[q->front];
	q->num--;
	return 1;
}
void menu()
{
	printf("\t\t=====<0>队列======\n");
	printf("\t\t=====<a>入队======\n");
	printf("\t\t=====<b>出队======\n");
	printf("\t\t=====<#>退出======\n");
}
int main()
{
	Sequeue s;
	int x;
	Init(&s);
			printf("输入入队元素\n");
			scanf("%d",&x);
			In(&s, x);
			Out(&s, &x);
			printf("出队元素为%d", x);
	return 0;
}