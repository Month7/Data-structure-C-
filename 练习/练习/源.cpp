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
		show(t->Lchild);
		show(t->Rchild);
		printf("%2c", t->data);
	}
}
void Rebuit(char a[], char b[], int i, int j, int k, int h, Bitree *t)
{
	(*t) = (Bitree)malloc(sizeof(Tree));
	(*t)->data = a[i];
	int m = k;
	while (b[m]!=a[i])
	{
		m++;
	}
	if (m == k)
		(*t)->Lchild = NULL;
	else
		Rebuit(a, b, i + 1, i + m - k, k, m - 1, &((*t)->Lchild));
	if (m == h)
		(*t)->Rchild = NULL;
	else
		Rebuit(a, b, i + m - k + 1, j, m + 1, h, &((*t)->Rchild));
}
int main()
{
	Bitree t;
	char a[MAX], b[MAX];
	int n;
	printf("请输入结点个数\n");
	scanf("%d",&n);
	int i, j;
	printf("请输入先序序列");
	for (i = 0; i < n; i++)
	{
		scanf("%s", &a[i]);
	}
	printf("请输入后序序列");
	for (j = 0; j < n; j++)
	{
		scanf("%s", &b[j]);
	}
	Rebuit(a, b, 0, n, 0, n, &t);
	printf("后序输出二叉树：\n");
	show(t);
	printf("\n");
	return 0;
}
