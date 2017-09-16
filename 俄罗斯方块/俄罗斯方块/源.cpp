/**********����˹������Ϸ**********
����:C���Գ�����Ʊ�д��
�汾:v1.0
����ʱ��:2015.8
��Ҫ����:
1.��������:������7�ֻ���ͼ��
2.������ƣ�ʵ�����ơ����ơ��������ơ���������������Զ��������ܵ�Ч����
3.������ʾ���ƶ�����ʱ������������ǰ�ķ��飬Ȼ����������λ���ػ��·��顣
4.�ٶȷ������£�ͨ����Ϸ�����ܹ�ʵ�ֶ������Ļ��֡�
5.ϵͳ������ͨ�������˽���Ϸ�Ĳ�����ʽ��
***********************************/
#include <stdio.h>  
#include <windows.h>  
#include <stdlib.h>  
#include <time.h>  
#include <conio.h> 
int r, p, q = 0, speed = 25;
int image[20][10];
/*
��������   ����        ����     �� ��     ��          ��   ������
����    ����       �� ��     ������  ������     ��
*/
static int brickX[7][4] = { { 0,1,2,3 },{ 0,1,1,2 },{ 2,1,1,0 },{ 1,1,2,2 },{ 0,0,1,2 },{ 2,2,1,0 },{ 0,1,1,2 } };
static	int brickY[7][4] = { { 0,0,0,0 },{ 0,0,1,1 },{ 0,0,1,1 },{ 0,1,0,1 },{ 0,1,1,1 },{ 0,1,1,1 },{ 0,0,1,0 } };
/*��ŷ����x,y����*/
unsigned int x[4];
unsigned int y[4];
/*��������*/
void Welcome(void);  /*��ӭ����*/
void Display(int binimage[20][10]);   /* ��ʾ��Ϸ��庯��*/
void GotoXY(int x, int y);  /*�����λ����*/
void Pause(void);    /*��ͣ*/
void Block_Random(); /*�������һ��ש��*/
int move(int offsetX, int offsetY, int binImage[20][10]);  /*���ơ����ơ�����*/
int rotate(int binImage[20][10]);  /*��ת����*/
void output(int binImage[20][10]); /*�������ʾ���*/
unsigned int removeFullLines();     /*����Ƿ���һ������*/
void copyimage(int destimage[20][10], int sourceimage[20][10]); /*��������*/
int score = 0;  /*��¼����*/
int difficulty;  /*�Ѷ�*/
				 /*������*/
int main(void)
{
	int i, j;
	int gameOver = 0;   /*��Ϸ�Ƿ����*/
	int brickInFlight = 0;  /*ש���Ƿ��ڷ���״̬*/
	int brickType = 0;   /*ש�����*/
	unsigned int initOrientation = 0; /*��ʼ״̬*/
	int notCollide = 0;  /*ש���Ƿ��ͻ*/
	int arrowKey = 0;
	int tempimage[20][10];
	score = 0;
	difficulty = 500;
	for (i = 0; i<20; i++)
		for (j = 0; j<10; j++)    /*��ʼ����Ϸ���*/
			image[i][j] = 0;
	for (i = 0; i<20; i++)
		for (j = 0; j<10; j++)    /*��ʼ����ʱ��Ϸ���*/
			tempimage[i][j] = 0;
	Welcome();          /*��ӭ����*/
	Display(image);          /*��ʾ��Ϸ���*/
							 /*��ʼ��Ϸ*/
	while (!gameOver)
	{
		if (!brickInFlight)
		{
			/*û��ש������ʱ����Ҫ�½�һ��ש��.�½�ש����Ҫ���ָ��ש�����״�ͳ�
			ʼ״̬.*/
			copyimage(tempimage, image);
			Block_Random();
			notCollide = move(10 / 2, 0, image); /*����Ƿ��ͻ*/
			if (notCollide) {
				brickInFlight = 1;
				output(tempimage);
				Display(tempimage);  /*��ʾimage*/
			}
			else {
				/*�½�ש��ͬ��Ϸ���Ķ����г�ͻ���������ʣ��ռ��Ѿ��Ų�����ש�顣��Ϸ����*/
				gameOver = 1;
				brickInFlight = 0;
			}
		}
		else
		{  /*��ǰ��ש���������䣬�����Ҫ����û��İ���*/
			copyimage(tempimage, image);
			if (kbhit())/*Checks the console for keyboard input*/
			{  /*����Ƿ��м�����*/
				arrowKey = getch();  /*����û�����*/
				if (arrowKey == 'd') /*����*/
					notCollide = move(1, 0, image);
				else if (arrowKey == 'a') /*����*/
					notCollide = move(-1, 0, image);
				else if (arrowKey == 'w') /*��ת*/
					notCollide = rotate(image);
				else if (arrowKey == 's')  /*һ����������*/
				{
					notCollide = move(0, 1, image);
					while (notCollide)
					{
						notCollide = move(0, 1, image);
						if (notCollide)
						{
							output(tempimage);
							Display(tempimage);
						}
						copyimage(tempimage, image);
					}
				}
				else if (arrowKey == 'p') /*��ͣ*/
					Pause();
			}
			/*ש�鿿��������. */
			Sleep(difficulty);
			notCollide = move(0, 1, image);
			if (notCollide)
			{
				output(tempimage);
				Display(tempimage);
			}
			else
			{
				/*ש�����ڵײ����ѹ̶���ש���ϣ���������. */
				brickInFlight = 0;
				output(image);
				Display(tempimage);
				/*����Ƿ���Ҫ����*/
				switch (removeFullLines())  /*�Ʒַ�ʽ��������ʵ�ָ����ӵļƷַ�ʽ*/
				{
				case 1:score++; break;
				case 2:score += 3; break;
				case 3:score += 5; break;
				case 4:score += 8; break;
				}
				switch (score / 100)  /*�ȼ�ȷ��*/
				{
				case 0:difficulty = 500; break;
				case 1:difficulty = 200; break;
				case 2:difficulty = 170; break;
				case 3:difficulty = 150; break;
				case 4:difficulty = 120; break;
				case 5:difficulty = 100; break;
				case 6:difficulty = 70; break;
				case 7:difficulty = 50; break;
				case 8:difficulty = 20; break;
				case 9:difficulty = 0; break;
				}
				/*������к󣬸����ⲿͼ�����*/
				copyimage(tempimage, image);
			}
			Display(tempimage);
		}
	}
	GotoXY(1, 24);
	printf("Game Over");
	getch();
	return 0;
}
/*��ʾ*/
void Display(int binimage[20][10])
{
	int i, j;
	GotoXY(1, 1);
	for (i = 0; i<20; i++)
	{
		printf("��");
		for (j = 0; j<10; j++)
		{
			switch (binimage[i][j])
			{
			case 0:printf("  "); break;
			case 1:printf("��"); break;
			}
		}
		printf("��\n");
	}
	for (i = 0; i<12; i++)
		printf("��");
	GotoXY(1, 22); printf("SCORE:%d", score);
	GotoXY(1, 23); printf("LEVEL=%d", score / 100);
}
/*----------------------------------------*/
void GotoXY(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*�������7�ֻ�����״��һ��*/
void Block_Random()
{
	int k, i;
	k = (rand() % 7);
	for (i = 0; i<4; i++) {
		x[i] = brickX[k][i];
		y[i] = brickY[k][i];
	}
}
/*��ӭ����*/
void Welcome(void)
{
	printf("��C���Զ���˹���顿V0.13b build080906\n");
	printf("[��ת��W  ���䣺X  ���ƣ�A  ���ƣ�D   ˲�����䣺S  ��ͣ��P �˳���Q]\n");
	printf("*ƽ��ÿ���100�� �ٶȻ�ӿ�һ������\n");
	printf("*˲�����䣺S/5 Ϊ�������� ���º�ֱ���䵽�ײ�\n");
	system("pause");
	system("cls");
}
/*��ͣ*/
void Pause(void)
{
	char c;
	GotoXY(1, 23); printf("Pause! ");
	do
	{
		c = getch();
	} while (c != 'p');
}
/*�ƶ�*/
int move(int offsetX, int offsetY, int binImage[20][10])
{
	int i;
	int X[4], Y[4];
	for (i = 0; i<4; i++)/*���ÿһ��С������ƶ�*/
	{
		X[i] = x[i] + offsetX;
		Y[i] = y[i] + offsetY;
		if (X[i]<0 || X[i] >= 10 || Y[i]<0 || Y[i] >= 20)  /*�ж��Ƿ��ܹ��ƶ��ɹ�*/
			return 0;
		if (binImage[Y[i]][X[i]] != 0)
			return 0;
	}
	for (i = 0; i<4; i++)
	{
		x[i] = X[i];
		y[i] = Y[i];
	}
	return 1;
}
/*��ת*/
int rotate(int binImage[20][10])
{
	int i;
	int xt[4], yt[4];
	for (i = 0; i<4; i++) {/*����˳ʱ��90������任*/
		xt[i] = y[i] + x[1] - y[1];
		yt[i] = x[1] + y[1] - x[i];
		if (xt[i]<0 || xt[i] >= 10 || yt[i]<0 || yt[i] >= 20)
			return 0;
		if (binImage[yt[i]][xt[i]] != 0)
			return 0;
	}
	for (i = 0; i<4; i++)
	{
		x[i] = xt[i];
		y[i] = yt[i];
	}
	return 1;
}
/*����任�Ľ��*/
void output(int binImage[20][10])
{
	int i;
	for (i = 0; i<4; i++)
		binImage[y[i]][x[i]] = 1;
}
/*ɾ������*/
unsigned int removeFullLines()
{
	unsigned int flag, EmptyLine = 0;
	unsigned int i, j, m;
	for (i = 0; i<20; i++)
	{
		flag = 0;
		for (j = 0; j<10; j++)
		{
			if (image[i][j] == 0)
				flag = 1;
		}
		/*һ����ȫ������*/
		if (flag == 0)
		{
			for (m = i; m>0; m--)  /*���һ����ȫ��������ɾ������*/
				for (j = 0; j<10; j++)
					image[m][j] = image[m - 1][j];
			for (j = 0; j<10; j++)
				image[0][j] = 0;  /*��һ��Ϊ0*/
			EmptyLine++;
			i--;
		}
	}
	return EmptyLine;
}
void copyimage(int destimage[20][10], int sourceimage[20][10])
{
	int i, j;
	for (i = 0; i<20; i++)
		for (j = 0; j<10; j++)
			destimage[i][j] = sourceimage[i][j];
}