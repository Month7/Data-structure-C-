#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
void In_post_order(char *ind, char *post, int l1, int r1, int l2, int r2, BinaryTree **root)
{
	//l1,r1和l2,r2分别为当前子树的中序序列和后序序列的下上界  
	int m;

	*root = (BinaryTree*)malloc(sizeof(BinaryTree));
	(*root)->data = post[r2];//根据post数组生成二叉树的根节点(后序序列最后一个数)  

	m = l1;//m指向ind数组的中序序列的第一个节点  
	while (ind[m] != post[r2])//找到根节点在中序序列中的所在位置  
	{
		m++;
	}

	//根节点是中序序列的第一个节点时则无左子树  
	if (m == l1)
	{
		(*root)->lchild = NULL;
	}
	else
	{
		//根据根节点所划分出中序序列的两个部分继续构造左右两颗子树  
		////检查错误  
		//int a1,a2,b1,b2;  
		//a1 = l1;  
		//a2 = m-1;  
		//b1 = l2;  
		//b2 = l2+m-l1-1;  

		//printf("\n--1--%d %d %d %d\n",a1,a2,b1,b2);  

		In_post_order(ind, post, l1, m - 1, l2, l2 + m - l1 - 1, &(*root)->lchild);
	}

	//根节点时中序序列的两个部分的最后一个节点时则无右子树  
	if (m == r1)
	{
		(*root)->rchild = NULL;
	}
	else
	{
		/*//检查错误
		int a1,a2,b1,b2;
		a1 = m+1;
		a2 = r1;
		b1 = l2+m-l1;
		b2 = r2-1;

		printf("\n--2--%d %d %d %d\n",a1,a2,b1,b2);
		*/
		//根据根节点所划分出中序序列的两个部分继续构造左右两颗子树  
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
	printf("请输入要输出的杨辉三角的行数N=");
	scanf("%d", &N);
	yhsj(s, N);
	return 0;
}