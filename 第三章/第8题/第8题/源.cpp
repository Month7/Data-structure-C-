#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct 
{
	char data[MAX];
	int top;
}Seqstack;
void Init(Seqstack*s)
{
	s->top = -1;
}
int Push(Seqstack *s, char x)
{
	if (s->top == MAX - 1)
		return 0;
	s->data[++s->top] = x;
	return 1;
}
int Out(Seqstack *s, char *x)
{
	if (s->top == -1)
		return 0;
	*x = s->data[s->top--];
	return 1;
}
int judge(Seqstack *s)
{
	Init(s);
	int i, j, k;
	j = 0;
	char a[MAX], b[MAX];
	printf("输入表达式，以'#'结束\n");
	for ( i = 0; i < MAX; i++)
	{
		scanf("%c", &a[i]);
		if (a[i] == '#') break;
	}
	for (k = 0; k < i; k++)
	{
		if (a[k] == '(')
			Push(s, a[i]);
		if (a[k] == ')')
			if (s->top != -1)
				Out(s,&b[j]);
			else
				return 0;
	}
	if (s->top == -1)
		return 1;
	else
		return 0;
}
int main()
{
	Seqstack s;
	int n;
	n = judge(&s);
	printf("n=%d\n", n);
	if (n == 1)
		printf("配对！\n");
	if (n == 0)
		printf("不配对\n");
	return 0;
}