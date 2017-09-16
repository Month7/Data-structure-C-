#include<stdio.h>
#include<stdlib.h>
#define MAXVALUE 10000         //���Ȩֵ
#define MAXLEAF 30             //Ҷ�ӽ�����
#define MAXNODE MAXLEAF*2-1    //������
#define MAXBIT 20              //������������󳤶�
typedef struct
{
	int weight;
	int Lchild;
	int Rchild;
	int parent;
}HNodeType;
typedef struct
{
	int bit[MAXBIT];
	int start;
}HCodeType;
typedef HNodeType haffmantree[MAXNODE];
typedef HCodeType haffmancode[MAXBIT];
int n;
void select(haffmantree t, int k, int *p1, int *p2)
{
	int i;
	*p1 = *p2 = 0;
	int small1 = MAXVALUE;
	int small2 = MAXVALUE;
	for (i = 0; i < k; i++)
	{
		if (t[i].weight < small1&&t[i].parent == -1)
		{
			small2 = small1;
			small1 = t[i].weight;
			*p2 = *p1;
			*p1 = i;
		}
		if (t[i].weight < small2&&t[i].parent == -1)
		{
			small2 = t[i].weight;
			*p2 = i;
		}
	}
}
void HaffmanTree(haffmantree t)
{
	int i, j, m1, m2;
	printf("������Ҷ�ӽ�����\n");
	scanf("%d", &n);
	int m = 2 * n - 1;
	for (i = 0; i < m; i++)                    //��ʼ��
	{
		t[i].weight = 0;
		t[i].parent = -1;
		t[i].Lchild = -1;
		t[i].Rchild = -1;
	}
	for (i = 0; i < n; i++)
	{
		printf("������Ҷ�ӽ��Ȩֵ\n");
		scanf("%d", &t[i].weight);
	}
	for (i = 0; i < n - 1; i++)
	{
		select(t,  i - 1, &m1, &m2);
		t[m1].parent = n + i;
		t[m2].parent = n + i;
		t[n + i].weight = t[m1].weight + t[m2].weight;
		t[n + i].Lchild = m1;
		t[n + i].Rchild = m2;
	}
}
void HaffmanCode(haffmantree t, haffmancode h)                                          //�������������
{
	int i, j, c, p;
	HaffmanTree(t);
	HCodeType cd;
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p = t[c].parent;                             
		printf("cd.start=%d\n", cd.start);
		printf("p=%d\n", p);
		printf("c=%d\n", c);
		printf("t[p].Lchild=%d", t[p].Lchild);
		while (p != -1)
		{
			if (t[p].Lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
	/*		printf("�Ƿ�ִ��");*/
			cd.start = cd.start - 1;
			c = p;
			p = t[c].parent;
		}
		//printf("ѭ����cd.start=%d\n", cd.start);
		for (j = cd.start + 1; j < n; j++)                           //����
		{
			h[i].bit[j] = cd.bit[j];
		}
		h[i].start = cd.start;
	}
	for (i = 0; i < n; i++)                                        //����
	{
		//printf("cd.start=%d\n", h[i].start);
		//printf("n=%d", n);
		for (j = h[i].start + 1; j < n; j++)
		{
			printf("%d�ı���Ϊ%d", i,h[i].bit[j]);
			//printf("���2");
		}
		printf("\n");
	}
}
int main()
{
	haffmantree t;
	haffmancode h;
	HaffmanCode(t, h);
	return 0;
}