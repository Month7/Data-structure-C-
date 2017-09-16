#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct
{
	int data[MAX];
	int front;
	int rear;
}Queue;

void Init(Queue *s);
void In(Queue*s, int x);
void Out(Queue*s, int *m);
void Get(Queue*s, int *m);
void spack(int n);

void Init(Queue *s)
{
	s->front = 0;
	s->rear = 0;
}
void In(Queue*s, int x)
{
	s->data[s->rear] = x;
	s->rear = (s->rear + 1) % MAX;
}
void Out(Queue*s, int *m)
{
	*m = s->data[s->front];
	s->front = (s->front + 1) % MAX;
}
void Get(Queue*s, int *m)
{
	*m = s->data[s->front];
}
void spack(int n)    //打印n个空格
{
	int i;
	for (i = 1; i < n + 1;i++)
	printf("  ");
}
int main()
{
	int n, i, m, x, k;
	printf("请输入杨辉三角层数");
	scanf("%d", &m);
	Queue s;
	Init(&s);
	In(&s, 1);
	for (n = 2; n <= m; n++)
	{
		spack(m + 3 - n);
		In(&s, 1);
		for (i = 1; i <= n - 2; i++)
		{
			Out(&s, &k);
			printf("%-4d", k);
			Get(&s, &x);
			k += x;
			In(&s, k);
		}
		Out(&s, &k);
		printf("%-4d\n", k);
		In(&s, 1);
	}
	spack(m + 3 - n);
	while (s.front != s.rear)
	{
		Out(&s, &m);
		printf("%-4d", m);
	}
	printf("\n");
	return 0;
}
