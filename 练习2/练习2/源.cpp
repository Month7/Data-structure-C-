#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
void In_post_order(char *ind, char *post, int l1, int r1, int l2, int r2, BinaryTree **root)
{
	//l1,r1��l2,r2�ֱ�Ϊ��ǰ�������������кͺ������е����Ͻ�  
	int m;

	*root = (BinaryTree*)malloc(sizeof(BinaryTree));
	(*root)->data = post[r2];//����post�������ɶ������ĸ��ڵ�(�����������һ����)  

	m = l1;//mָ��ind������������еĵ�һ���ڵ�  
	while (ind[m] != post[r2])//�ҵ����ڵ������������е�����λ��  
	{
		m++;
	}

	//���ڵ����������еĵ�һ���ڵ�ʱ����������  
	if (m == l1)
	{
		(*root)->lchild = NULL;
	}
	else
	{
		//���ݸ��ڵ������ֳ��������е��������ּ�������������������  
		////������  
		//int a1,a2,b1,b2;  
		//a1 = l1;  
		//a2 = m-1;  
		//b1 = l2;  
		//b2 = l2+m-l1-1;  

		//printf("\n--1--%d %d %d %d\n",a1,a2,b1,b2);  

		In_post_order(ind, post, l1, m - 1, l2, l2 + m - l1 - 1, &(*root)->lchild);
	}

	//���ڵ�ʱ�������е��������ֵ����һ���ڵ�ʱ����������  
	if (m == r1)
	{
		(*root)->rchild = NULL;
	}
	else
	{
		/*//������
		int a1,a2,b1,b2;
		a1 = m+1;
		a2 = r1;
		b1 = l2+m-l1;
		b2 = r2-1;

		printf("\n--2--%d %d %d %d\n",a1,a2,b1,b2);
		*/
		//���ݸ��ڵ������ֳ��������е��������ּ�������������������  
		In_post_order(ind, post, m + 1, r1, l2 + m - l1, r2 - 1, &(*root)->rchild);
	}
}

void PostTree(BinaryTree *root)
{
	if (root)
	{
		PostTree(root->lchild);
		PostTree(root->rchild);

		printf("%c ", root->data);
	}
}
int main()
{
	int flag = 1, N;
	elemtype e, headelem;
	linkq s;
	initqueue(s);
	insert(s, 1);
	printf("������Ҫ�����������ǵ�����N=");
	scanf("%d", &N);
	yhsj(s, N);
	return 0;
}