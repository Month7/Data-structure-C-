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
	printf("\t˳��ջ\n");
	printf("\tѡ����Ӧ����\n");
	printf("\t<a>��ջ\n");
	printf("\t<b>��ջ\n");
	printf("\t<c>��ȡջ��Ԫ��\n");
	printf("\t<#>�˳�\n");
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
			printf("��������ջ����");
			scanf("%d", &x);
			Push(&s, x);
			k = Push(&s, x);
			if (k)
				printf("��ջ����");
			break;
		case'b':
			Out(&s, &x);
			printf("��ջԪ��Ϊ%d", x);
			break;
		case'c':
			Get(&s, &x);
			printf("ջ��Ԫ��Ϊ%d", x);
			break;
		}
	}
	return 0;
}