#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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
		printf("Î»ÖÃ´íÎó£¡\n");
		return -1;
	}
	if (L->last>MAXSIZE)
	{
		printf("±íÂú£¡\n");
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
void MergeList1(SeqList La, SeqList Lb, SeqList *Lc)
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (i <=La.last&&j <=Lb.last)
		if (La.elem[i] <= Lb.elem[j])
			Lc->elem[k++] = La.elem[i++];
		else
			Lc->elem[k++] = Lb.elem[j++];
	while (i <=La.last)
		Lc->elem[k++] = La.elem[i++];
	while (j <=Lb.last)
		Lc->elem[k++] = Lb.elem[j++];
	Lc->last=k-1;
}
int main()
{
	SeqList *La, *Lb, *Lc;
	int i;
	int j;
	int a[3] = { 2,2,3};
	int b[4] = { 1,3,3,4 };
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);
	for (i = 0; i < 3; i++)
		ListInsert(La, i + 1, a[i]);
	for (i = 0; i < 4; i++)
		ListInsert(Lb, i + 1, b[i]);
	printf("La=");
	Print(La);
	printf("Lb=");
	Print(Lb);
	printf("Lc=");
	MergeList1(*La, *Lb, Lc);
	Print(Lc);
	return 0;
}