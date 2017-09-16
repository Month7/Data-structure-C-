#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;
typedef struct { int x, y; }Point;
char map[22][22];                        //����һ��22*22�ĵ�ͼ�����߽磩
Point snake[400], food, Next;            //�����ߡ�ʳ���һ����ͷ��λ��
int head, tail;                            //���ڴ�����ͷ����β���±�
int grade, length, autotime;            //��Ϸ�ȼ����߳����Զ�ǰ������ʱ��
char direction;                            //ǰ������
										   //��inline��������������ʡ��������ʱ�ĵ��ÿ���

										   //ˢ�µ�ͼ
inline void Update(char map[][22], int grade, int length, int autotime)
{
	system("cls");                        //����
	int i, j;
	printf("\n");
	for (i = 0; i < 22; i++)
	{
		printf("\t");
		for (j = 0; j < 22; j++)
			printf("%c ", map[i][j]);
		if (i == 0)
			printf("\t�ȼ�Ϊ��%d", grade);
		if (i == 2)
			printf("\t����Ϊ��%d", length);
		if (i == 6)
			printf("\t�Զ�ǰ��ʱ��");
		if (i == 8)
			printf("\t���Ϊ��%d ms", autotime);
		printf("\n");
	}
}

//��ӭ����
inline void hello()
{
	puts("\n\n\n\t\t\t̰������Ϸ������ʼ��");                        //׼����ʼ
	double start;
	for (int i = 3; i >= 0; i--)
	{
		start = (double)clock() / CLOCKS_PER_SEC;                //�õ�����ĿǰΪֹ���е�ʱ��
		while ((double)clock() / CLOCKS_PER_SEC - start <= 1);    //����1��֮��
		if (i > 0)
		{
			system("cls");                                        //����
			printf("\n\n\n\t\t\t���뵹��ʱ��%d\n", i);                //����ʱ
		}
		else
			Update(map, grade, length, autotime);                //ˢ�µ�ͼ
	}
}

//�������ʳ��λ��
inline void f()
{
	srand(int(time(0)));                                        //�������Ӻ���
	do
	{
		food.x = rand() % 20 + 1;
		food.y = rand() % 20 + 1;
	} while (map[food.x][food.y] != ' ');
	map[food.x][food.y] = '!';                                    //ʳ��Ϊ��!��
}

//��ʼ��
inline void init()
{
	int i, j;
	for (i = 1; i <= 20; i++)
		for (j = 1; j <= 20; j++)
			map[i][j] = ' ';
	for (i = 0; i <= 21; i++)
		map[0][i] = map[21][i] = map[i][0] = map[i][21] = '*';    //�߽�
	map[1][1] = map[1][2] = 'O';                                //��������β��
	map[1][3] = '@';                                            //��ͷ
	head = 2; tail = 0;                                            //��ʼʱͷ��β���±�
	snake[head].x = 1; snake[head].y = 3;                        //��ʼʱ��ͷ�ڵ�ͼ�ϵ��±�
	snake[tail].x = 1; snake[tail].y = 1;                        //��ʼʱ��β�ڵ�ͼ�ϵ��±�
	snake[1].x = 1; snake[1].y = 2;                                //��ʼʱ�����ڵ�ͼ�ϵ��±�
	f();                                                        //�������ʳ��λ��
	grade = 1; length = 3; autotime = 500;                        //��ʼ�ĵȼ������ȡ��Զ�ǰ��ʱ��
	direction = 77;                                                //��ʼ���˶���������
}

//Ԥǰ��
inline int GO()
{
	bool timeover = true;
	double start = (double)clock() / CLOCKS_PER_SEC;            //�õ�����ĿǰΪֹ���е�ʱ��
																//�Զ�����1����ߵȴ�1���ڵļ�������
	while ((timeover = ((double)clock() / CLOCKS_PER_SEC - start <= autotime / 1000.0)) && !_kbhit());
	//��������
	if (timeover)
	{
		_getch();
		direction = _getch();                                    //��ȡ����
	}
	switch (direction)
	{
	case 72:
		Next.x = snake[head].x - 1; Next.y = snake[head].y;        //����
		break;
	case 80:
		Next.x = snake[head].x + 1; Next.y = snake[head].y;        //����
		break;
	case 75:
		Next.x = snake[head].x; Next.y = snake[head].y - 1;        //����
		break;
	case 77:
		Next.x = snake[head].x; Next.y = snake[head].y + 1;        //����
		break;
	default:
		puts("\tGame over!");                                    //���·Ƿ������Ϸʧ��
		return 0;
	}
	if (Next.x == 0 || Next.x == 21 || Next.y == 0 || Next.y == 21)            //ײ���߽�
	{
		puts("\tGame over!");
		return 0;
	}
	if (map[Next.x][Next.y] != ' '&&!(Next.x == food.x&&Next.y == food.y))    //�Ե��Լ�
	{
		puts("\tGame over!");
		return 0;
	}
	if (length == 400)                                                        //��߳�
	{
		puts("\tGood game!");
		return 0;
	}
	return 1;
}

//�Ե�ʳ��
inline void EAT()
{
	length++;                                        //��������1
	int _grade = length / 10 + 1;                    //����ȼ�
	if (_grade != grade)
	{
		grade = _grade;
		if (autotime >= 100)
			autotime = 550 - grade * 50;            //����һ���Զ�ʱ�����50����
	}
	map[Next.x][Next.y] = '@';                        //��ͷλ�ñ仯
	map[snake[head].x][snake[head].y] = 'O';        //ԭ��ͷλ�ñ仯Ϊ����
	head = (head + 1) % 400;                        //��ͷ�±��1
	snake[head].x = Next.x; snake[head].y = Next.y;    //��ͷ�±�仯
	f();                                            //�������ʳ��λ��
	Update(map, grade, length, autotime);            //ˢ�µ�ͼ
}

//û�Ե�ʳ��
inline void FAILURE()
{
	map[snake[tail].x][snake[tail].y] = ' ';        //��βԭ����λ�ñ�ɡ� ��
	tail = (tail + 1) % 400;                        //��β�±��1
	map[Next.x][Next.y] = '@';                        //��ͷλ�ñ仯
	map[snake[head].x][snake[head].y] = 'O';        //ԭ��ͷλ�ñ仯Ϊ����
	head = (head + 1) % 400;                        //��ͷ�±��1
	snake[head].x = Next.x;                            //��ͷ�±�仯
	snake[head].y = Next.y;
	Update(map, grade, length, autotime);            //ˢ�µ�ͼ
}

//main����
int main()
{
	init();                    //��ʼ��
	hello();                //��ӭ����
	while (1)
	{
		if (GO())            //Ԥǰ��
		{
			if (Next.x == food.x&&Next.y == food.y)
				EAT();        //�Ե�ʳ��
			else
				FAILURE();    //û�Ե�ʳ��
		}
		else
			return 0;        //ʧ�ܻ���ʤ������Ϸ����
	}
	system("peace");
	return 0;
}