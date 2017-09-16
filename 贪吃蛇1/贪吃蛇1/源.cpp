#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <string.h> 
using namespace std;
typedef struct { int x, y; }Point;
char map[22][22];
Point snake[400], food, Next;            //�����ߡ�ʳ���һ����ͷ��λ��
int head, tail;                            //���ڴ�����ͷ����β���±�
int length, autotime;                   //�߳����Զ�ǰ������ʱ��
char direction;
inline void Update(char map[][32], int length, int autotime);    //ˢ�µ�ͼ
inline void welcome();    
inline void f();            //�������ʳ��λ��
inline void init();         //��ʼ��
inline int move();            //�ƶ�
inline void eat();
inline void noteat();


inline void Update(char map[][22], int length, int autotime)
{
	system("cls");                        
	int i, j;
	printf("\n");
	for (i = 0; i < 22; i++)
	{
		printf("\t");
		for (j = 0; j < 22; j++)
			printf("%c ", map[i][j]);
		if (i == 0)
			printf("\t̰������Ϸ");
		if (i == 2)
			printf("\t����Ϊ��%d", length);
		if (i == 6)
			printf("\t�Զ�ǰ��ʱ��");
		if (i == 8)
			printf("\t���Ϊ��%d ms", autotime);
		printf("\n");
	}
}
inline void welcome()
{
	printf("\t̰������Ϸv1.1\n");
	printf("\t�������������ƶ�����\n");
	printf("\t * Ϊʳ��\n");
	printf("\t�밴�������ʼ\n");
	getch();
	Update(map, length, autotime);
}
inline void f()                  //�������ʳ��λ��
{
	srand(int(time(0)));         //�������Ӻ���
	do
	{
		food.x = rand() % 20 + 1;
		food.y = rand() % 20 + 1;
	} while (map[food.x][food.y] != ' ');
		map[food.x][food.y] = '*';
}
inline void init()         //��ʼ��
{
	int i;
	int j;
	for (i=1; i <= 20; i++)
		for (j=1; j <= 20; j++)
			map[i][j] = ' ';
	for (i=0; i <= 21; i++)
		map[0][i] = map[21][i] = map[i][0] = map[i][21] = '#';
	map[2][3] = '@';
	map[2][1] =map[2][2]= '*';
	head = 2;
	tail = 0;
	snake[head].x = 2; snake[head].y = 3;
	snake[tail].x = 2; snake[tail].y = 1;
	snake[1].x = 2; snake[1].y = 2;
	f();
    length = 3; autotime = 500;
	direction = 77;
}
inline int move()
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
		puts("\tGame over!");                                    
		return 0;
	}
	if (Next.x == 0 || Next.x == 21 || Next.y == 0 || Next.y == 21)
	{
		puts("\tGame over!");
		return 0;
	}
	if(map[Next.x][Next.y]!=' '&&!(Next.x==food.x&&Next.y==food.y))
	{
		puts("\tGame over!");
		return 0;
	}
	if (length == 400)                                                        
	{
		puts("\tGood game!");
		return 0;
	}
	return 1;
}
inline void eat()
{
	length++;
	map[Next.x][Next.y] = '@';
	map[snake[head].x][snake[head].y] = '*';
	head = (head + 1)%400;
	snake[head].x = Next.x;
	snake[head].y = Next.y;
	f();
	Update(map,length,autotime);
}
inline void noteat()
{
	map[snake[tail].x][snake[tail].y] = ' ';        
	tail = (tail + 1) % 400;                        
	map[Next.x][Next.y] = '@';                        
	map[snake[head].x][snake[head].y] = '*';        
	head = (head + 1) % 400;                        
	snake[head].x = Next.x;                            
	snake[head].y = Next.y;
	Update(map,length, autotime);            
}
int main()
{
	init();
	welcome();
	while (1)
	{
		if (move())
		{
			if (Next.x == food.x&&Next.y == food.y)
				eat();
			else
				noteat();
		}
		else
			return 0;
	}
	return 0;
}
