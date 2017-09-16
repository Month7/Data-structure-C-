#include<stdio.h>
#include<string.h>
#define MAX 50
#define FALSE 0
#define TURE 1

//����ջ
typedef struct
{
	char elem[MAX];
	int top;
}SeqStack;

//����ѭ������
typedef struct
{
	char element[MAX];
	int front;
	int rear;
}SeqQuene;

//��ʼ��ջ
void InitStack(SeqStack *S)
{
	S->top = -1;//����һ����ջ
}

//��ջ
int Push(SeqStack *S, char x, int cnt)
{
	if (S->top == cnt - 1)
		return(FALSE);
	S->top++;
	S->elem[S->top] = x;
	return(TURE);
}

//��ջ
int Pop(SeqStack * S, char * x)
{
	if (S->top == -1)
		return(FALSE);
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return(TURE);
	}
}

//��ʼ������
void InitQuene(SeqQuene *Q)
{
	Q->front = Q->rear = 0;
}

//���
int EnterQuene(SeqQuene *Q, char x, int cnt)
{
	if ((Q->rear + 1) % (cnt + 1) == Q->front)
		return(FALSE);
	Q->element[Q->rear] = x;
	Q->rear = (Q->rear + 1) % (cnt + 1);
	return(TURE);
}

//����
int DeleteQuene(SeqQuene *Q, char *x, int cnt)
{
	if (Q->front == Q->rear)
		return(FALSE);
	*x = Q->element[Q->front];
	Q->front = (Q->front + 1) % (cnt + 1);
	return(TURE);
}

//������
int main()
{
	int i, cnt, flag;
	SeqStack s;
	SeqQuene q;
	char a[MAX], b[MAX], c[MAX];
	flag = 0;
	printf("��������#������С��%d�Ļ������У�\n", MAX);
	for (i = 0; i<MAX + 1; i++)
	{
		scanf("%c", &a[i]);
		if (a[i] == '#')
			break;
	}
	cnt = i;
	printf("��������%d���ַ���\n", cnt);
	InitStack(&s);
	InitQuene(&q);
	for (i = 0; i<cnt; i++)
	{
		EnterQuene(&q, a[i], cnt);
		Push(&s, a[i], cnt);
	}

	printf("�����ַ���Ϊ��\n");
	for (i = 0; i<cnt + 1; i++)
	{
		DeleteQuene(&q, &b[i], cnt);
		printf("%c", b[i]);
	}
	printf("\n");

	printf("�����ַ���Ϊ��\n");
	for (i = 0; i<cnt + 1; i++)
	{
		Pop(&s, &c[i]);
		printf("%c", c[i]);
	}
	printf("\n");

	for (i = 0; i<cnt + 1; i++)
	{
		if (c[i] == b[i])
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
	}

	if (flag)
		printf("�������ǻ������У�");
	else
		printf("�����в��ǻ������У�");
	printf("\n");
	return 0;
}
