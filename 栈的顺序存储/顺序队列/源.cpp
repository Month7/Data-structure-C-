#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 20
typedef struct
{
	int elem[MAXSIZE];
	int top;
}Seqstack;
void Init(Seqstack *s)
{
	s->top = -1;
}
void Push(Seqstack *s,int e)     //��ջ
{
	if (s->top==MAXSIZE-1)
	{
		printf("ջ����������ջ\n");
	}
	else
	{
		s->elem[s->top] = e;
		s->top++;
		printf("��ջ�ɹ���\n");
	}
}
int Out(Seqstack *s, int *x)
{
	if (s->top==-1)
	{
		printf("ջ�գ����ܳ�ջ\n");
		return 0;
	}
	else
	{
		s->top--;
		*x = s->elem[s->top];
	}
	return *x;
}
int main()
{
	Seqstack s;
	Init(&s);
	printf("��������ջ����\n");
	int e;
	scanf("%d",&e);
	Push(&s,e);
// 	printf("����'1'��ջ\n");
// 	char c;
// 	int x, y;
// 	y = 0;
// 	x = 0;
// 	scanf("%c",&c);
// 	if (c=='$')
// 	{
// 		y=Out(&s,&x);
// 		printf("%d", y);
// 	}
// 	else
// 	{
// 		return 0;
// 	}
	int x;
	Out(&s,&x);
	printf("%d",x);
//	system("pause");
	return 0;
}