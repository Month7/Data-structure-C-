#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#define MAXSIZE 100
struct SeqList
{
	int elem[MAXSIZE];
	int last;
};
void InitList(SeqList **L)
{
	*L = (SeqList*)malloc(sizeof(SeqList));
	(*L)->last = -1;
}
int ListInsert(SeqList *L, int i, int e)
{
	int *p, *q;
	if (i<1 || i > L->last + 2)
	{
		printf("位置错误！\n");
		return -1;
	}
	if (L->last>MAXSIZE)
	{
		printf("表满！\n");
		return 0;
	}
	q = L->elem + i - 1;
	for (p = L->elem + L->last - 1; p >= q; p--)
		*(p + 1) = *p;
	*q = e;
	L->last++;
	return 1;
}
void Print(SeqList *L)
{
	int i;
	for (i = 0; i<L->last; i++)
		printf("%d ", *(L->elem + i));
	printf("\n");
}
void unionlist(SeqList *La, SeqList Lb) {
	int i, j, k;
	int Lc[MAXSIZE];//辅助数组，当然你也可以弄个SeqList 

	memcpy(Lc, La->elem, sizeof(int)*(La->last));//把La复制到Lc 
	i = j = k = 0;
	while (i<La->last&&j<Lb.last) {
		if (Lc[i]<Lb.elem[j]) {
			La->elem[k] = Lc[i++];
		}
		else {
			La->elem[k] = Lb.elem[j++];
		}
		k++;
	}
	//复制剩余的
	while (i<La->last) La->elem[k++] = Lc[i++];
	while (j<Lb.last) La->elem[k++] = Lb.elem[j++];
	La->last = k;
}

int main()
{
	SeqList *La, *Lb;
	int i;
	int a[3] = { 2,2,3 };
	int b[4] = { 1,3,3,4 };
	InitList(&La);
	InitList(&Lb);
	for (i = 0; i < 3; i++)
		ListInsert(La, i + 1, a[i]);
	for (i = 0; i < 4; i++)
		ListInsert(Lb, i + 1, b[i]);
	printf("La=");
	Print(La);
	printf("Lb=");
	Print(Lb);
	unionlist(La, *Lb);
	printf("La=");
	Print(La);
	return 0;
}