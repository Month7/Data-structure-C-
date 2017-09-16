#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *next;
}node,*Linkstack;
void Init(Linkstack *s)
{
	*s= (Linkstack)malloc(sizeof(node));
	(*s)->next = NULL;
}
int Push(Linkstack *s, char x)
{
	Linkstack p;
	p = (Linkstack)malloc(sizeof(node));
	if (p->next = NULL)
		return 0;
	p->data = x;
	p->next = *s;
	*s = p;
	return 1;
}
int Out(Linkstack *s, char *x)
{
	Linkstack p;
	p = *s;
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
int calculate(char a, char op, char b)
{
	char c;
	a = a - 48;
	b = b - 48;
	switch (op)
	{
	case '+':
		c = a + b + 48;
		break;
	case'-':
		c = a - b + 48;
		break;
	case'*':
		c = a*b + 48;
		break;
	case'/':
		c = a / b + 48;
		break;
	}
	return c;
}
int ExpEvaluation()
{
	Linkstack num, ope;
	Init(&num);
	Init(&ope);
	Push(&ope, '#');
	char c, x, op, a, b;
	Get(&ope, &x);
	printf("输入数据，'#'结束");
	c = getchar();
	while (c != '#' || x != '#')
	{
		if (c <= '9'&&c >= '0') 
		{
			Push(&num, c);
			c = getchar();
		}
		else
		{
			switch (compare(x, c))
			{
			case'<':
				Push(&ope, c);
				c = getchar();
				break;
			case'=':
				Out(&num, &x);
				c = getchar();
				break;
			case'>':
				Out(&ope, &op);
				Out(&num, &b);
				Out(&num, &a);
				x = calculate(b, op, a);
				Push(&num, x);
				break;
			}
		}
		Get(&ope, &x);
	}
	Get(&num, &x);
	return x;
}
int main()
{
	printf("%c", ExpEvaluation());
	return 0;
}