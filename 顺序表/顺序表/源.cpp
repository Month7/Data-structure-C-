#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100
struct SeqList
{
	int elem[MAXSIZE];
	int length;
};
void Init(SeqList **s)
{
	(*s) = (SeqList*)malloc(sizeof(SeqList));
	(*s)->length = -1;
}
void Insert(SeqList *s, int i, int e)
{
	int *p, *q;
	if (i<1||i>s->length+2)
	{
		printf("位置错误！\n");
	}
	if (s->length>MAXSIZE)
	{
		printf("表满！\n");
	}
	else
	{
		q = s->elem - 1 + i;              //插入位置
		p = s->length - 1 + s->elem;
		for (p; p >= q;p--)
		{
			*(p + 1) = *p;
		}
		*q = e;
		s->length++;
	}
}
void Show(SeqList *s)
{
	int i;
	for (i = 0; i <=s->length;i++)
	{
		printf("%d",s->elem[i]);
	}
	printf("\n");
}
int main()
{
	SeqList *s;
	Init(&s);
	int a[3] = { 1,2,3 };
	int i;
	i = 0;
	for (i; i < 3;i++)
	{
		Insert(s,i+1,a[i]);
	}
	printf("顺序表为\n");
	Show(s);
	return 0;
}