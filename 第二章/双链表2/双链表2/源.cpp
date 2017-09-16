#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct DLnode
{
	int data;
	DLnode *pre, *next;
}DLnode,*Linklist;
Linklist createlist()
{
	Linklist p, q, L;
	int n;
	L = (Linklist)malloc(sizeof(DLnode));
	p = L;
	printf("������n��n��Ԫ��");
	scanf("%d", &n);
	while (n--)
	{
		q= (Linklist)malloc(sizeof(DLnode));
		scanf("%d", &q->data);
		q->pre = p;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	L = L->next;
	L->pre = NULL;
	return L;
}
void showlist(Linklist L)
{
	Linklist p, q;
	p = L;
	printf("�������:\n");
	while (p)
	{
		printf("%d", p->data);
		q = p;
		p = p->next;
	}
	printf("\n�������:\n");
	while (q)
	{
		printf("%d", q->data);
		q = q->pre;
	}
}
void Deletelist(Linklist L, int e)
{
	Linklist p;
	int i = 0;
	p = L->next;
	while (p&&i<e-1)
	{
		p = p->next;
		i++;
	}
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
}
void Inserlist(Linklist L,int n,int e)
{
	Linklist p, q;
	int i = 0;
	p = L->next;
	while (p&&i < n - 1)
	{
		p = p->next;
		i++;
	}
	if (i != n - 1)
	{
		printf("λ�ô���");
	}
	else
		q = (Linklist)malloc(sizeof(DLnode));
	    q->data = e;
		q->pre = p->pre;
		p->pre->next = q;
		q->next = p;
		p->pre = q;
}
void menu()
{
	printf("��������������������������������������������������\n");
	printf("         ����������     ˫����        ��������    \n");
	printf("                ��������ĸִ����Ӧ����            \n");
	printf("                <a>   ���˫����                  \n");
	printf("                <b>ɾ������                       \n");
	printf("                <c>���빦��                       \n");
	printf("                <#>�˳�                           \n");
}
int main()
{
	Linklist L;
	L = createlist();
	char c;
	menu();
	while ((c = getchar()) != '#')
	{
		switch (c)
		{
		case 'a':
			showlist(L);
			break;
		case 'b':
			int i;
			printf("������ɾ��λ�ã�");
			scanf("%d", &i);
			printf("ɾ����ı�Ϊ");
			Deletelist(L, i);
			showlist(L);
			break;
		case'c' :
			int n, e;
			printf("���������λ�ú�Ԫ��");
			scanf("%d,%d", &n, &e);
			Inserlist(L, n, e);
			showlist(L);
			break;
		}
	}
	return 0;
}