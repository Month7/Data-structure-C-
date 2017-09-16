#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct Tree
{
	char data;
	struct Tree *Lchild, *Rchild;
}Tree,*Bitree;
void Rebuit(char a[], char b[], int i, int j, int k, int h, Bitree *t)
{
	int m;
	m = i;
	(*t) = (Bitree)malloc(sizeof(Tree));
	(*t)->data = b[h];
	while (a[m] != b[h])
	{
		m++;
	}
	if (m == i)
		(*t)->Lchild = NULL;
	else
		Rebuit(a, b, i, m - 1, k, k + m - i - 1,&((*t)->Lchild));
	if (m == j)
		(*t)->Rchild = NULL;
	else
		Rebuit(a, b, m + 1, j, k + m - i, h - 1, &((*t)->Rchild));
}
void show(Bitree t)
{
	if (t)
	{
		printf("%2c", t->data);
		show(t->Lchild);
		show(t->Rchild);
	}
}
int main()
{
	Bitree t;
	int n;
	char a[MAX], b[MAX];
	printf("请输入结点个数\n");
	scanf("%d", &n);
	printf("请输入中序序列\n");
	int i, j;
	flushall();
	for (i = 0; i < n; i++)
	{
		scanf("%c", &a[i]);
	}
	printf("请输入后序序列\n");
	flushall();
	for (j = 0; j < n; j++)
	{
		scanf("%c", &b[j]);
	}
	Rebuit(a, b, 0, n - 1, 0, n - 1, &t);
	printf("恢复成功！\n前序序列输出为:\n");
	show(t);
	return 0;
}