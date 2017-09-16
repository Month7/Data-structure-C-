#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}node,*Linkstack;
int Push(Linkstack*top, int x)
{
	Linkstack s;
	s = (Linkstack)malloc(sizeof(node));
	if (s == NULL)
		return 0;
	else
		s->data = x;
	s->next = (*top);
	(*top) = s;
	return 1;
}
int Out(Linkstack*top, int *x)
{
	Linkstack p;
	p = *top;
	*x = (*top)->data;
	*top = (*top)->next;
	free(p);
	return 1;
}
void convert(int num, int mode)
{
	int h;
	Linkstack top;
	top = NULL;
	if (num > 0)
	{
		while (num)
		{
			h = num%mode;
			Push(&top, h);
			num = num / mode;
		}
		while (top)
		{
			Out(&top, &h);
			printf("%d", h);
		}
	}
	else if (num < 0)
	{
		printf("-");
		num = num*(-1);
		while (num)
		{
			h = num%mode;
			Push(&top, h);
			num = num / mode;
		}
		while (top)
		{
			Out(&top, &h);
			printf("%d", h);
		}
	}
	else
		printf("0");
}
void menu()
{
	printf("\t��ջ\n");
	printf("\t��ѡ����Ӧ����\n");
	printf("\t<a>��ջ\n");
	printf("\t<b>��ջ\n");
	printf("\t<c>����ת��\n");
	printf("\t<#>�˳�\n");
}
int main()
{
	Linkstack L;
	menu();
	char c;
	int x, num, mode;
	while ((c = getchar()) != '#')
	{
		switch (c)
		{
		case 'a':
			printf("��������ջ����\n");
			scanf("%d", &x);
			Push(&L, x);
			break;
		case'b':
			Out(&L, &x);
			printf("��ջ����Ϊ%d\n", x);
			break;
		case'c':
			printf("����������\n");
			scanf("%d", &num);
			printf("���������\n");
			scanf("%d", &mode);
			convert(num, mode);
		}
	}
	return 0;
}
