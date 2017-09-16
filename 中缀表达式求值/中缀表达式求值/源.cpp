#include "stdio.h"
#include "stdlib.h"
typedef char Elemtype;
typedef struct stack
{
	Elemtype data;
	struct stack * next;
}Sqstack;
void StackInit(Sqstack **head)                                 //��ʼ��
{
	if ((*head = (Sqstack *)malloc(sizeof(Sqstack))) == NULL) exit(1);
	(*head)->next = NULL;
}
int StackPush(Sqstack *head, Elemtype x)                          //��ջ
{
	Sqstack *p;
	if ((p = (Sqstack *)malloc(sizeof(Sqstack))) == NULL)
	{
		printf("�ڴ�ռ䲻���޷�����");
		return 0;
	}
	p->data = x;
	p->next = head->next;
	head->next = p;
	return 1;
}
int StackPop(Sqstack *head, Elemtype *d)                           //��ջ 
{
	Sqstack *p = head->next;
	if (p == NULL)
	{
		printf("��ջ�ѿճ���!");
		return 0;
	}
	head->next = p->next;
	*d = p->data;
	free(p);
	return 1;
}
int StackTop(Sqstack *head, Elemtype *d)                       //ȡջ��Ԫ��
{
	Sqstack *p = head->next;
	if (p == NULL)
	{
		printf("��ջ�ѿճ���!");
		return 0;
	}
	*d = p->data;
	return 1;
}
int Compare(char a, char b)                                //�Ƚϲ��������ȼ� 
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
int Transfer(char Expression[], int n, char save[])                         // ��׺���׺ 
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
				save[j] = ' ';                       //�����ֺ��棬������ǰ��ӿո�
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
	save[j] = '#';             //��׺���ʽ��'#'�Ž���
	return j;

}
void Calculate(char p[])       //��׺���ʽ��ֵ
{
	int s[100];
	int i, j;
	i = j = 0;
	while (p[j] != '#')                      //
	{
		switch (p[j])
		{
		case'+':                           //��������ǰ���������ֵ���
			s[i - 2] = s[i - 2] + s[i - 1];
			i = i - 1;
			break;
		case'-':                           //��������ǰ���������ֵ���
			s[i - 2] = s[i - 2] - s[i - 1];
			i = i - 1;
			break;
		case'*':                           //��������ǰ���������ֵ���
			s[i - 2] = s[i - 2] * s[i - 1];
			i = i - 1;
			break;
		case'/':                           //��������ǰ���������ֵ���
			s[i - 2] = s[i - 2] / s[i - 1];
			i = i - 1;
			break;
		case '0':                         //���ɨ�赽�����ַ�0~9��ִ���������
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			s[i] = (int)p[j] - 48;         //48��0��ASCII��ֵ���������ַ�char����int����ת��
			j++;
			while (p[j] != ' ')   //�ж�һ���������Ƿ������ÿ�������������Կո����
			{
				s[i] = s[i] * 10 + (int)p[j] - 48;     //��������ַ���ֵ
				j++;
			}
			i++;
			break;
		}
		j++;
	}printf("\n����Ľ��Ϊ: %d", s[0]);
}
void main()
{
	int m;
	int i = 0;
	int k;
	char save[100];
	char a[100];
	printf("�����ַ���,����#�Ž��� \n");
	for (m = 0; m<100; m++)
	{
		scanf("%c", &a[m]);
		if (a[m] == '#')break;
	}
	Transfer(a, m + 1, save);
	k = Transfer(a, m + 1, save);
	printf("��׺���ʽΪ:");
	for (m = 0; m<k; m++)
		printf("%c", save[m]);
	Calculate(save);
	printf("\n");
}
