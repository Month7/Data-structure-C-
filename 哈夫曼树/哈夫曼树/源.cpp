#include<stdio.h>
#define n 8                                        //Ҷ�ӽ����Ŀ
#define m (2*n-1)                                  //�ܽ����Ŀ����֤��
#define MAXVALUE 10000                             //���Ȩֵ
#define MAXBIT 20                                  //������������󳤶�
typedef struct                                     
{
	char ch;
	int weight;                                    
	int parent;                                    
	int Lchild, Rchild;
}Htreetype;
typedef struct
{
	int bit[n];                                   //λ��
	int start;                                    //������λ���е���ʼλ��
	char ch;       
}Hcodetype;
void select(Htreetype t[], int k, int *p1, int *p2)  //ѡ��Ȩֵ��С�Ľ��
{
	*p1 = *p2 = 0;
	int small1, small2;
	small1 = small2 = MAXVALUE;
	int i;
	for (i = 0; i < k; i++)
	{
		if (t[i].parent == -1)
		{
			if (t[i].weight < small1)
			{
				small2 = small1;
				small1 = t[i].weight;
				*p2 = *p1;
				*p1 = i;
			}
			else if (t[i].weight < small2)
			{
				small2 = t[i].weight;
				*p2 = i;
			}
		}
	}
}
void HuffmanTree(Htreetype t[])                  //�����������
{
	int i, j, p1, p2, f;
	p1 = p2 = 0;
	char c;
	for (i = 0; i < m; i++)                       //��ʼ��
	{
		t[i].weight = 0;
		t[i].Lchild = -1;
		t[i].parent = -1;
		t[i].Rchild = -1;
	}
	printf("����%d���ַ�\n", n);
	for (i = 0; i < n; i++)                            //�����ַ��Ͷ�Ӧ��Ȩֵ
	{
		printf("�������%d���ַ���Ȩֵ','�ָ�", i + 1);
		scanf("%c,%d", &c,&f);
		getchar();
		t[i].ch = c;
		t[i].weight = f;
	}
	for (i = n; i < m; i++)                            //�����������
	{
		select(t, i, &p1, &p2);
		t[p1].parent = i;
		t[p2].parent = i;
		t[i].Lchild = p1;
		t[i].Rchild = p2;
		t[i].weight = t[p1].weight + t[p2].weight;
	}
}
void HuffmanCode(Hcodetype code[],Htreetype t[])                                   //����������
{
	int i, c, p;
	Hcodetype cd;      //�����������ʱ�洢
	HuffmanTree(t);
	for (i = 0; i < n; i++)
	{
		cd.start = n;
		cd.ch = t[i].ch;
		c = i;               //��Ҷ�ӽ������
		p = t[i].parent;     //t[p]��t[i]��˫��
		while (p != -1)
		{
			cd.start--;
			if (t[p].Lchild == c)
				cd.bit[cd.start] = '0';        //��������Ϊ0
			else
				cd.bit[cd.start] = '1';        //��������Ϊ1
			c = p;                             //�ƶ�
			p = t[c].parent;
		}
		code[i] = cd;                         //��i+1���ַ��ı������code
	}
}
void show(Htreetype t[], Hcodetype code[])
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		printf("%c: ", code[i].ch);
		for (j = code[i].start; j<n; j++)
			printf("%c ", code[i].bit[j]);
		printf("\n");
	}
}
void Print()
{
	printf("����XPS-15\n");
	
}
int main()
{
	Htreetype t[m];
	Hcodetype code[n];
	HuffmanCode(code, t);
	show(t,code);
	return 0;
}
