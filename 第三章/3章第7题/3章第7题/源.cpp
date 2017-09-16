#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct
{
	char data[MAX];
	int top;
}Seqstack;
void Init(Seqstack *s)
{
	s->top = -1;
}
int judge(Seqstack *s)
{
	Init(s);
	char temp;
	char a[MAX];
	int i, j;
	printf("请输入以'#'结束的字符串\n");
	for (i = 0; i < MAX; i++)
	{
		scanf("%c", &a[i]);
		if (a[i] == '#') break;
	}
	for (j = 0; j < i / 2; j++)
		s->data[++s->top] = a[j];
	if (i % 2 == 1)
		j++;
	while (s->top > -1)
	{
		temp = s->data[s->top--];
		if (temp != a[j])
			return 0;
		else
			j++;
	}
	return 1;
}
int main()
{
	Seqstack s;
	int n;
	n= judge(&s);
	if (n == 1)
		printf("是回文字符！\n");
	else if(n == 0)
		printf("不是回文字符！\n");
	return 0;
}