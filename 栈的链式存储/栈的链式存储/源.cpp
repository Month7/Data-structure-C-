#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
	char data;
	struct node *next;
}link,*Link;
typedef struct 
{
	Link top;
}Linkstack;
void Init(Linkstack **L)
{
	(*L) = (Linkstack *)malloc(sizeof(Linkstack));
	(*L)->top = NULL;
}
void Push(Linkstack *L,char x)
{
	Link p;
	p = (Link)malloc(sizeof(link));
	p->next = L->top;
	p->data = x;
	L->top = p;
	printf("��ջ�ɹ���\n");
}
void Out(Linkstack *L,char *x)
{
	Link p;
	*x = L->top->data;
	p = L->top;
//	p->next = p->next->next;
	p = L->top->next;
	free(p);
}
int main()
{
	Linkstack *L;
	Init(&L);
	printf("������Ҫ��ջ������\n");
	char c, x;
	scanf("%c",&c);
	Push(L,c);
	Out(L,&x);
	printf("��ջ����Ϊ%c", x);
	return 0;
}