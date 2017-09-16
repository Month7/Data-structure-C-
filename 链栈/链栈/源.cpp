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
	printf("\t链栈\n");
	printf("\t请选择相应功能\n");
	printf("\t<a>入栈\n");
	printf("\t<b>出栈\n");
	printf("\t<c>进制转化\n");
	printf("\t<#>退出\n");
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
			printf("请输入入栈数据\n");
			scanf("%d", &x);
			Push(&L, x);
			break;
		case'b':
			Out(&L, &x);
			printf("出栈数据为%d\n", x);
			break;
		case'c':
			printf("请输入数据\n");
			scanf("%d", &num);
			printf("请输入进制\n");
			scanf("%d", &mode);
			convert(num, mode);
		}
	}
	return 0;
}
