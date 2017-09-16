#include<stdio.h>
#include<string.h>
#define MAX 50
#define FALSE 0
#define TURE 1

//定义栈
typedef struct
{
	char elem[MAX];
	int top;
}SeqStack;

//定义循环队列
typedef struct
{
	char element[MAX];
	int front;
	int rear;
}SeqQuene;

//初始化栈
void InitStack(SeqStack *S)
{
	S->top = -1;//构造一个空栈
}

//入栈
int Push(SeqStack *S, char x, int cnt)
{
	if (S->top == cnt - 1)
		return(FALSE);
	S->top++;
	S->elem[S->top] = x;
	return(TURE);
}

//出栈
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

//初始化队列
void InitQuene(SeqQuene *Q)
{
	Q->front = Q->rear = 0;
}

//入队
int EnterQuene(SeqQuene *Q, char x, int cnt)
{
	if ((Q->rear + 1) % (cnt + 1) == Q->front)
		return(FALSE);
	Q->element[Q->rear] = x;
	Q->rear = (Q->rear + 1) % (cnt + 1);
	return(TURE);
}

//出队
int DeleteQuene(SeqQuene *Q, char *x, int cnt)
{
	if (Q->front == Q->rear)
		return(FALSE);
	*x = Q->element[Q->front];
	Q->front = (Q->front + 1) % (cnt + 1);
	return(TURE);
}

//主函数
int main()
{
	int i, cnt, flag;
	SeqStack s;
	SeqQuene q;
	char a[MAX], b[MAX], c[MAX];
	flag = 0;
	printf("请输入由#结束且小于%d的回文序列：\n", MAX);
	for (i = 0; i<MAX + 1; i++)
	{
		scanf("%c", &a[i]);
		if (a[i] == '#')
			break;
	}
	cnt = i;
	printf("输入了有%d个字符。\n", cnt);
	InitStack(&s);
	InitQuene(&q);
	for (i = 0; i<cnt; i++)
	{
		EnterQuene(&q, a[i], cnt);
		Push(&s, a[i], cnt);
	}

	printf("正序字符串为：\n");
	for (i = 0; i<cnt + 1; i++)
	{
		DeleteQuene(&q, &b[i], cnt);
		printf("%c", b[i]);
	}
	printf("\n");

	printf("逆序字符串为：\n");
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
		printf("此序列是回文序列！");
	else
		printf("此序列不是回文序列！");
	printf("\n");
	return 0;
}
