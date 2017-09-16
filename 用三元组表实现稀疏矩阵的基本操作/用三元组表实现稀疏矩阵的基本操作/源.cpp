#include<stdio.h>
#include<string.h>
#define MAX 10
typedef struct
{
	int i, j, v;
}S;
typedef struct
{
	S data[MAX];
	int m, n, t;
}SPMatrix;
void creat(SPMatrix *s)
{
	printf("输入（行，列，值），（-1，-1，-1）结束");
	int k, i, j, val, maxrow, maxcol;
	i = j = 0;
	maxrow = 0;
	maxcol = 0;
	k = 0;
	while (i != -1 && j != -1)
	{
		scanf("%d,%d,%d", &i, &j, &val);
		s->data[k].i = i;
		s->data[k].j = j;
		s->data[k].v = val;
		if (maxrow < i) maxrow = i;
		if (maxcol < j) maxcol = j;
		k++;
	}
	s->m = maxrow;
	s->n = maxcol;
	s->t = k - 1;
}
void show(SPMatrix*s)
{
	int p, q, t;
	t = 0;
	for (p=0 ; p <= s->m; p++)
	{
		for (q=0 ; q <= s->n; q++)
		{
			if (s->data[t].i == p&&s->data[t].j == q)
			{
				printf("%d ", s->data[t].v);
				t++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}
void Nizhi(SPMatrix *s, SPMatrix*a)
{
	int p, q, col;
	a->n = s->m;
	a->m = s->n;
	a->t = s->t;
	if (a->t)
	{
		q = 0;
		for (col = 1; col <=(s->n); col++)
			for (p = 0; p<=(s->t); p++)
				if (s->data[p].j==col)
				{
					a->data[q].i = s->data[p].j;
					a->data[q].j = s->data[p].i;
					a->data[q].v = s->data[p].v;
					q++;
				}
	}
	printf("a->data[3]=%d", a->data[3]);
}
int main()
{
	SPMatrix s, a;
	creat(&s);
	printf("转置前的矩阵：");
	show(&s);
	printf("转置后的矩阵：");
	Nizhi(&s, &a);
	show(&a);
	return 0;
}