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
		printf("����\n");
	return 0;
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = x;
	q->num++;
	return 1;
}
int Out(Sequeue *q, int *x)
{
	if (q->num == 0)
		printf("�ӿ�\n");
	return 0;
	q->front = (q->front + 1) % MAXSIZE;
	*x = q->data[q->front];
	q->num--;
	return 1;
}
void menu()
{
	printf("\t\t=====<0>����======\n");
	printf("\t\t=====<a>���======\n");
	printf("\t\t=====<b>����======\n");
	printf("\t\t=====<#>�˳�======\n");
}
int main()
{
	Sequeue s;
	int x;
	Init(&s);
			printf("�������Ԫ��\n");
			scanf("%d",&x);
			In(&s, x);
			Out(&s, &x);
			printf("����Ԫ��Ϊ%d", x);
	return 0;
}