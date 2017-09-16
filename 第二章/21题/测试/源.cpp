#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Lnode
{
	char data;
	struct Lnode *next;
}Lnode, *Linklist;
void creatlist(Linklist L)
{
	int n;
	Linklist p, q;
	p = L;
	printf("请输入数据'#'结束:\n");
	while (1)
	{
		q = (Linklist)malloc(sizeof(Lnode));
		scanf("%c", &q->data);
		q->next = NULL;
		p->next = q;
		p = q;
		if (q->data == '#') break;
	}
}
void showlist(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p)
	{
		printf("%c", p->data);
		p = p->next;
	}
}void showlist1(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p!=L)
	{
		printf("%c", p->data);
		p = p->next;
	}
}
void Drividelist(Linklist L, Linklist La, Linklist Lb, Linklist Lc)
{
	Linklist p, q, r, s;
	s = L->next;
	p = La;
	q = Lb;
	r = Lc;
	while (s)
	{
		if ((s->data >= 'a'&&s->data <= 'z') || (s->data >= 'A'&&s->data <= 'Z'))
		{
			p->next = s;
			p = s;
		}
		else
		if (s->data >= '0'&&s->data <= '9')
		{
			q->next = s;
			q = s;
		}
		else
		{
			r->next = s;
			r = s;
		}
		s = s->next;
	}
	p->next = La;
	q->next = Lb;
	r->next = Lc;
}
int main()
{
	Linklist L, La, Lb, Lc;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	La = (Linklist )malloc(sizeof(Lnode));
	Lb= (Linklist )malloc(sizeof(Lnode));
	Lc = (Linklist )malloc(sizeof(Lnode));
	int i;									
	char m;									
	while (1)
	{
		creatlist(L);		
		Drividelist(L, La, Lb, Lc);	
		printf("\n字母:");	
		showlist1(La);			
		printf("\n数字:");	
		showlist1(Lb);			
		printf("\n其它:");	
		showlist1(Lc);			
		printf("\n是否结束?是,输入0;否,输入1\n");	
		scanf("%d", &i);								
		printf("\n");
		if (i == 1) scanf("%c", &m);					
		if (i == 0) break;								
	}
	printf("谢谢使用，再见! \n\n");
	return 0;
}
