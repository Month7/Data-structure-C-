#include "stdio.h"
#include "stdlib.h"
typedef char Elemtype;
typedef struct stack
{
	Elemtype data;
	struct stack * next;
}Sqstack;
void StackInit(Sqstack **head)                                 //初始化
{
	if ((*head = (Sqstack *)malloc(sizeof(Sqstack))) == NULL) exit(1);
	(*head)->next = NULL;
}
int StackPush(Sqstack *head, Elemtype x)                          //入栈
{
	Sqstack *p;
	if ((p = (Sqstack *)malloc(sizeof(Sqstack))) == NULL)
	{
		printf("内存空间不足无法插入");
		return 0;
	}
	p->data = x;
	p->next = head->next;
	head->next = p;
	return 1;
}
int StackPop(Sqstack *head, Elemtype *d)                           //出栈 
{
	Sqstack *p = head->next;
	if (p == NULL)
	{
		printf("堆栈已空出错!");
		return 0;
	}
	head->next = p->next;
	*d = p->data;
	free(p);
	return 1;
}
int StackTop(Sqstack *head, Elemtype *d)                       //取栈顶元素
{
	Sqstack *p = head->next;
	if (p == NULL)
	{
		printf("堆栈已空出错!");
		return 0;
	}
	*d = p->data;
	return 1;
}
int Compare(char a, char b)                                //比较操作符优先级 
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
int Transfer(char Expression[], int n, char save[])                         // 中缀变后缀 
{
	Sqstack *s;
	char x1, x2, y;
	int i;
	int j = 0;
	StackInit(&s);
	StackPush(s, '#');
	for (i = 0; i<n; i++)
	{
		x1 = Expression[i];
		if (x1 <= '9'&&x1 >= '0')
		{
			save[j] = x1;
			j++;
			y = Expression[i + 1];
			if (y == '+' || y == '-' || y == '*' || y == '/' || y == '(' || y == ')' || y == '#')
			{
				save[j] = ' ';                       //在数字后面，操作符前面加空格
				j++;
			}
		}
		else
		{
			StackTop(s, &x2);
			if (Compare(x2, x1) == '<')
				StackPush(s, x1);
			else if (Compare(x2, x1) == '>')
			{
				StackPop(s, &x2);
				save[j] = x2;
				j++;
				i--;
			}
			else if (Compare(x2, x1) == '=') StackPop(s, &x2);
		}

	}
	save[j] = '#';             //后缀表达式以'#'号结束
	return j;

}
void Calculate(char p[])       //后缀表达式求值
{
	int s[100];
	int i, j;
	i = j = 0;
	while (p[j] != '#')                      //
	{
		switch (p[j])
		{
		case'+':                           //将操作符前面的两个数值相加
			s[i - 2] = s[i - 2] + s[i - 1];
			i = i - 1;
			break;
		case'-':                           //将操作符前面的两个数值相减
			s[i - 2] = s[i - 2] - s[i - 1];
			i = i - 1;
			break;
		case'*':                           //将操作符前面的两个数值相乘
			s[i - 2] = s[i - 2] * s[i - 1];
			i = i - 1;
			break;
		case'/':                           //将操作符前面的两个数值相除
			s[i - 2] = s[i - 2] / s[i - 1];
			i = i - 1;
			break;
		case '0':                         //如果扫描到的是字符0~9，执行下面操作
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			s[i] = (int)p[j] - 48;         //48是0的ASCII码值，将数字字符char型向int类型转换
			j++;
			while (p[j] != ' ')   //判断一个操作数是否结束，每个操作数都是以空格结束
			{
				s[i] = s[i] * 10 + (int)p[j] - 48;     //求出数字字符的值
				j++;
			}
			i++;
			break;
		}
		j++;
	}printf("\n计算的结果为: %d", s[0]);
}
void main()
{
	int m;
	int i = 0;
	int k;
	char save[100];
	char a[100];
	printf("输入字符串,并以#号结束 \n");
	for (m = 0; m<100; m++)
	{
		scanf("%c", &a[m]);
		if (a[m] == '#')break;
	}
	Transfer(a, m + 1, save);
	k = Transfer(a, m + 1, save);
	printf("后缀表达式为:");
	for (m = 0; m<k; m++)
		printf("%c", save[m]);
	Calculate(save);
	printf("\n");
}
