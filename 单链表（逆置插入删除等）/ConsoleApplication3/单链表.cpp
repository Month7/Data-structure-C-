#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	LNode *next;
}LNode, *LinkList;
void creatlist(LinkList L)                            //���������� β�巨
{
	int n;
	LinkList p, q;
	p = L;
	printf("������n��n������Ԫ��:\n");
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
void jishu(LinkList L)                           //��������
{
	int j = 0;
	LinkList p;
	p = L;
	while (p)
	{
		p = p->next;
		j++;
	}
	printf("���ȣ�%d", j-1);
}
void showlist(LinkList L)                               //�����������
{
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%d", p->data);
		p = p->next;
	}
}
int deletelist(int i, LinkList L)                     //ɾ������
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
		printf("λ�ô���\n");
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
void locatelist(LinkList L, int e)                           //��ֵ���Һ���
{
	LinkList p;
	p = L->next;
	while (p->next != NULL&&p->data != e)
		p = p->next;
	if (p)
	{
		printf("%d��ǰ�����Ϊ%d", e, p->data);
	}
	else
	{
		printf("û�ҵ���");
	}
}
void inslist(LinkList L,int j,int e)             //��iλ�ò��뺯��
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
		printf("λ�ô���");
	}
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
void menulist()                           //�˵�����
{
	int n;
	printf("�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e\n");
	printf("                                 һ��������                                 \n");
	printf("                        �� ������Ӧ����ִ�ж�Ӧ����! ��                     \n");
	printf("                         <a> �������������     ?                      \n");
	printf("                         <b>      ɾ������          ?                      \n");
	printf("                         <c> �鿴��������         ?                      \n");
	printf("                         <d>   ��ֵ���ҹ���         ?                      \n");
	printf("                         <e>       ���빦��         ?                      \n");
	printf("                         <f>       ���ù���         ?                      \n");
	printf("                         <#>       �˳�             ?                      \n");
	printf("�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e\n");
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
			printf("��Ϊ��\n");
			showlist(L);
			break;
		case 'b':
			int i;
			printf("������ɾ����λ�ã�\n");
			scanf("%d", &i);
			deletelist(i, L);
			printf("ɾ����ı�Ϊ\n");
			showlist(L);
			break;
		case 'c':
			jishu(L);
			printf("\n");
			break;
		case 'd':
			int k;
			printf("������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &k);
			locatelist(L, k);
			printf("\n");
			break;
		case 'e':
			int j, e;
			printf("���������λ�ú�Ԫ��");
			scanf("%d,%d", &j,&e);
			inslist(L, j, e);
			printf("�����ı�Ϊ:\n");
			showlist(L);
			break;
		case'f':
			printf("���ú�ı�Ϊ��");
			Nizhilist(L);
			showlist(L);
			break;
		}
	}
	return 0;
	system("peace");
}