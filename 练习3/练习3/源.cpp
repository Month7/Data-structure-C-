#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *next;
}node, *Linkstack;
void Init(Linkstack *s)
{
	*s = (Linkstack)malloc(sizeof(node));
	(*s)->next = NULL;
}
int Push(Linkstack *s, char x)
{
	Linkstack p;
	p= (Linkstack)malloc(sizeof(node));
	if (p == NULL)
		return 0;
	p->data = x;
	p->next = (*s);
	*s = p;
	return 1;
}
int Out(Linkstack *s, char *x)
{
	Linkstack p;
	p = *s;
	if (p == NULL)
		return 0;
	*x = (*s)->data;
	*s = (*s)->next;
	free(p);
	return 1;
}
int Get(Linkstack *s, char *x)
{
	*x = (*s)->data;
	return 1;
}
int compare(char a, char b)
{
	if ((a == '+' || a == '-') && (b == '*' || b == '/' || b == '('))
		return '<';
	else if ((a == '*' || a == '/') && b == '(')
		return '<';
	else if (a == '(' && (b == '+' || b == '-' || b == '*' || b == '/' || b == '('))
		return '<';
	else if (a == '('&&b == ')')
		return '=';
	else if (a == '#' && (b == '+' || b == '-' || b == '*' || b == '/' || b == '('))
		return '<';
	else if (a == '#'&&b == '#')
		return '=';
	else
		return '>';
}
int transfrom(char E[], char save[], int n)
{
	Linkstack s;
	Init(&s);
	char x1, x2, y;
	int i;
	int j = 0;
	Push(&s, '#');
	for (i = 0; i<n; i++)
	{
		x1 = E[i];
		if (x1 <= '9'&&x1 >= '0')
		{
			save[j] = x1;
			j++;
			y = E[i + 1];
			if (y == '+' || y == '-' || y == '*' || y == '/' || y == '(' || y == ')' || y == '#')
			{
				save[j] = ' ';
				j++;
			}
		}
		else
		{
			Get(&s, &x2);
			if (compare(x2, x1) == '<')
				Push(&s, x1);
			else if (compare(x2, x1) == '>')
			{
				Out(&s, &x2);
				save[j] = x2;
				j++;
				i--;
			}
			else if (compare(x2, x1) == '=') Out(&s, &x2);
		}
	}
	save[j] = '#';
	return j;
}
int main()
{
	char E[100];
	char save[100];
	int k;
	int m;
	printf("请输入数据，'#'结束");
	for (m = 0; m < 100; m++)
	{
		scanf("%c", &E[m]);
		if (E[m] == '#') break;
	}
	transfrom(E, save, m + 1);
	k= transfrom(E, save, m + 1);
	printf("后缀表达式为:");
	for (m = 0; m < k; m++)
		printf("%c", save[m]);
	return 0;
}