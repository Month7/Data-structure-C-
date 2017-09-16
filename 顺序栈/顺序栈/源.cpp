#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 20
typedef struct
{
	char data[MAXSIZE];
	int top;
}Seqstack;
void Init(Seqstack *s)
{
	s->top = -1;
}
int Push(Seqstack *s, char x)
{
	if (s->top == MAXSIZE - 1)
		return 0;
	else
		s->data[s->top] = x;
	s->top++;
	return 1;
}
int Out(Seqstack *s, char *x)
{
	if (s->top = -1)
		return 0;
	else
		*x = s->data[s->top];
	s->top--;
	return 1;
}
int Get(Seqstack *s, char *x)
{
	if (s->top = -1)
		return 0;
	else
		*x = s->data[s->top];
	s->top--;
	return 1;
}
void menu()
{
	printf("\t顺序栈\n");
	printf("\t选择相应功能\n");
	printf("\t<a>入栈\n");
	printf("\t<b>出栈\n");
	printf("\t<c>获取栈顶元素\n");
	printf("\t<#>退出\n");
}
int main()
{
	Seqstack s;
	Init(&s);
	menu();
	char x, c;
	int k;
	while ((c = getchar()) != '#')
	{
		switch (c)
		{
		case'a':
			printf("请输入入栈数据");
			scanf("%d", &x);
			Push(&s, x);
			k = Push(&s, x);
			if (k)
				printf("入栈结束");
			break;
		case'b':
			Out(&s, &x);
			printf("出栈元素为%d", x);
			break;
		case'c':
			Get(&s, &x);
			printf("栈顶元素为%d", x);
			break;
		}
	}
	return 0;
}