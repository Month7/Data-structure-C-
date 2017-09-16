#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct Tree
{
	char data;
	Tree *Lchild, *Rchild;
}Tree, *BitTree;
void PreTree(char a[], char b[], int i, int j, int k, int h, BitTree *t)
{
	int m;
	(*t) = (BitTree)malloc(sizeof(Tree));
	(*t)->data = a[i];
	m = k;
	while (b[m] != a[i])
		m++;
	if (m == k)
		(*t)->Lchild = NULL;
	else
		PreTree(a, b, i + 1, i + m - k, k, m - 1, &((*t)->Lchild));
	if (m == h)
		(*t)->Rchild = NULL;
	else
		PreTree(a, b, i + m - k + 1, j, m + 1, h, &((*t)->Rchild));
}
void show(BitTree t)                            //以后序遍历输出二叉树
{
	if (t)
	{
		show((t->Lchild));
		show((t->Rchild));
		printf("%2c", t->data);
	}
}
int main()
{
	BitTree t;
	char a[MAX];
	char b[MAX];
	int i, j, n;
	printf("输入结点个数");
	scanf("%d", &n);
	printf("请输入前序\n");
	flushall();
	for (i = 0; i < n; i++)
	{
		scanf("%c", &a[i]);
	}
	printf("请输入中序\n");
	flushall();
	for (j = 0; j < n; j++)
	{
		scanf("%c", &b[j]);
	}
	PreTree(a, b, 0, n - 1, 0, n - 1, &t);
	printf("后序输出二叉树：\n");
	show(t);
	return 0;
}