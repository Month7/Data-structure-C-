#include<stdio.h>
#define MAX 100
typedef struct
{
	char data[MAX];
	int length;
}Sstring;
void In(Sstring *s)
{
	int i, j;
	char c;
	printf("�����봮���Ⱥ�Ԫ��\n");
	scanf("%d", &j);
	for (i = 0; i < j; i++)
	{
		scanf("%c", &c);
		scanf("%c", &c);
		s->data[i] = c;
	}
	s->data[i] = '\0';
	s->length = j;
}
void Out(Sstring *s)
{
	int i;
	printf("��Ϊ��");
	for (i = 0; i < s->length; i++)
	{
		printf("%c", s->data[i]);
	}
	printf("\n");
}
void Insert(Sstring *s, int n, Sstring *t)
{
	int i;
	if ((s->length + t->length) < MAX)
	{
		for (i = s->length + t->length; i > n + t->length; i--)
			s->data[i] = s->data[i - (t->length)];
		for (i = 0; i < t->length; i++)
			s->data[i + n] = t->data[i];
		s->length = s->length + t->length;
	}
}
void Delete(Sstring *s,int n,int m)
{
	int i, j;
	for (i = m; i < s->length; i++)
		s->data[i] = s->data[i + n];
	s->length = s->length - m;
}

int main()
{
	Sstring s, t;
	int n;
	In(&s);
	In(&t);
	Out(&s);
	Out(&t);
	printf("���������λ��");
	scanf("%d", &n);
	Insert(&s, n, &t);
	printf("������:");
	Out(&s);
	return 0;
}