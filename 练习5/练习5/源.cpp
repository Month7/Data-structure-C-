#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct Tree
{
	char data;
	struct Tree *Lchild, *Rchild;
}Tree,*Bitree;
void show(Bitree t)
{
	if (t)
	{
		printf("%2c", t->data);
		show(t->Lchild);
		show(t->Rchild);
	}
}
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
		Rebuit(a, b, i, m - 1, k, k + m - i - 1, &((*t)->Lchild));
	if (m == j)
		(*t)->Rchild = NULL;
	else
		Rebuit(a, b, m + 1, j, k + m - i, h - 1, &((*t)->Rchild));
}
int main()
{
	Bitree t;
	int n;
	printf("请输入结点个数\n");
	scanf("%d", &n);
	char a[MAX];
	char b[MAX];
	int i, j;
	printf("请输入中序序列\n");
	for (i = 0; i < n; i++)
	{
		scanf("%s", &a[i]);
	}
	printf("请输入后序序列\n");
	for (j = 0; j < n; j++)
	{
		scanf("%s", &b[j]);
	}
	printf("恢复二叉树成功！\n前序序列为:\n");
	Rebuit(a, b, 0, n, 0, n, &t);
	show(t);
	return 0;
}