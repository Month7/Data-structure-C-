#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#define  MAXSIZE 20
typedef struct MyStruct
{
	int key;
}E;
typedef struct MyStruct1
{
	int length;
	E *elem;
}STable;
void Create(STable *p)
{
	printf("�������\n");
	int n, i;
	scanf("%d",&n);
	p->elem = (E*)malloc((n + 1)*sizeof(E));
	printf("����������Ԫ��");
	for (i = 1; i <= n; i++)
	{
		scanf("%d",&(p->elem[i].key));
	}
	p->length = n;
}
int Search(STable *p, int k)
{
	int i;
	i = p->length;
	p->elem[0].key =k ;
	while (p->elem[i].key != k)
	{
		i--;
	}
	return i;
}
int main()
{
	STable p;
	int i;
	Create(&p);
	printf("������Ҫ���ҵĹؼ���");
	scanf("%d",&i);
	printf("���ҳɹ�����λ��Ϊ%d", Search(&p, i));
	return 0;
}