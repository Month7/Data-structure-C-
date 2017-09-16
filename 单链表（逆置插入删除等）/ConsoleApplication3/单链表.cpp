#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	LNode *next;
}LNode, *LinkList;
void creatlist(LinkList L)                            //创建单链表 尾插法
{
	int n;
	LinkList p, q;
	p = L;
	printf("请输入n和n个数据元素:\n");
	scanf("%d", &n);
	while (n--)
	{
		q = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &q->data);
		q->next = NULL;
		p->next = q;
		p = q;
	}
}
void jishu(LinkList L)                           //计数功能
{
	int j = 0;
	LinkList p;
	p = L;
	while (p)
	{
		p = p->next;
		j++;
	}
	printf("长度：%d", j-1);
}
void showlist(LinkList L)                               //输出单链表函数
{
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%d", p->data);
		p = p->next;
	}
}
int deletelist(int i, LinkList L)                     //删除函数
{
	LinkList p, r;
	p = L;
	int k = 0;
	while (p->next != NULL&&k < (i - 1))
	{
		p = p->next;
		k++;
	}
	if (k != i - 1)
	{
		printf("位置错误！\n");
		system("pause");
		return 0;
	}
	else
	{
		r = p->next;
		p->next = p->next->next;
		free(r);
	}
	return 0;
}
void locatelist(LinkList L, int e)                           //按值查找函数
{
	LinkList p;
	p = L->next;
	while (p->next != NULL&&p->data != e)
		p = p->next;
	if (p)
	{
		printf("%d的前驱结点为%d", e, p->data);
	}
	else
	{
		printf("没找到！");
	}
}
void inslist(LinkList L,int j,int e)             //在i位置插入函数
{
	LinkList p, s;
	p = L;
	int k = 0;
	while (p != NULL&&k < j - 1)
	{
		p = p->next;
		k++;
	}
	if (k != j - 1)
	{
		printf("位置错误！");
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
void menulist()                           //菜单函数
{
	int n;
	printf("卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐\n");
	printf("                                 一个单链表                                 \n");
	printf("                        ■ 输入相应数字执行对应功能! ■                     \n");
	printf("                         <a> 输出单链表（正序）     ?                      \n");
	printf("                         <b>      删除操作          ?                      \n");
	printf("                         <c> 查看单链表长度         ?                      \n");
	printf("                         <d>   按值查找功能         ?                      \n");
	printf("                         <e>       插入功能         ?                      \n");
	printf("                         <f>       逆置功能         ?                      \n");
	printf("                         <#>       退出             ?                      \n");
	printf("卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐卐\n");
}
void Nizhilist(LinkList L)
{
	LinkList p, q;
	p = L->next;
	q = p->next;
	p->next = NULL;
	while (q)
	{
		p = q;
		q = q->next;
		p->next = L->next;
		L->next = p;
	}
}
int main()
{
	LinkList L, p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = -1;
	creatlist(L);
	char ch;
	menulist();
	while ((ch=getchar())!='#')
	{
		switch (ch)
		{
		case 'a':
			printf("表为：\n");
			showlist(L);
			break;
		case 'b':
			int i;
			printf("请输入删除的位置：\n");
			scanf("%d", &i);
			deletelist(i, L);
			printf("删除后的表为\n");
			showlist(L);
			break;
		case 'c':
			jishu(L);
			printf("\n");
			break;
		case 'd':
			int k;
			printf("请输入要查找的元素！");
			scanf("%d", &k);
			locatelist(L, k);
			printf("\n");
			break;
		case 'e':
			int j, e;
			printf("请输入插入位置和元素");
			scanf("%d,%d", &j,&e);
			inslist(L, j, e);
			printf("插入后的表为:\n");
			showlist(L);
			break;
		case'f':
			printf("逆置后的表为：");
			Nizhilist(L);
			showlist(L);
			break;
		}
	}
	return 0;
	system("peace");
}