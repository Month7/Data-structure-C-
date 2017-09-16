/**********俄罗斯方块游戏**********
作者:C语言程序设计编写组
版本:v1.0
创建时间:2015.8
主要功能:
1.方块生成:可生成7种基本图形
2.方块控制：实现左移、右移、快速下移、自由下落和行满自动消除功能的效果。
3.更新显示：移动方块时，需先消除先前的方块，然后在新坐标位置重绘新方块。
4.速度分数更新：通过游戏分数能够实现对行数的划分。
5.系统帮助：通过帮助了解游戏的操作方式。
***********************************/
#include <stdio.h>  
#include <windows.h>  
#include <stdlib.h>  
#include <time.h>  
#include <conio.h> 
int r, p, q = 0, speed = 25;
int image[20][10];
/*
■■■■   ■■        ■■     ■ ■     ■          ■   ■■■
■■    ■■       ■ ■     ■■■  ■■■     ■
*/
static int brickX[7][4] = { { 0,1,2,3 },{ 0,1,1,2 },{ 2,1,1,0 },{ 1,1,2,2 },{ 0,0,1,2 },{ 2,2,1,0 },{ 0,1,1,2 } };
static	int brickY[7][4] = { { 0,0,0,0 },{ 0,0,1,1 },{ 0,0,1,1 },{ 0,1,0,1 },{ 0,1,1,1 },{ 0,1,1,1 },{ 0,0,1,0 } };
/*存放方块的x,y坐标*/
unsigned int x[4];
unsigned int y[4];
/*函数声明*/
void Welcome(void);  /*欢迎界面*/
void Display(int binimage[20][10]);   /* 显示游戏面板函数*/
void GotoXY(int x, int y);  /*输出定位函数*/
void Pause(void);    /*暂停*/
void Block_Random(); /*随机生成一个砖块*/
int move(int offsetX, int offsetY, int binImage[20][10]);  /*左移、右移、下移*/
int rotate(int binImage[20][10]);  /*旋转函数*/
void output(int binImage[20][10]); /*输出到显示面板*/
unsigned int removeFullLines();     /*检查是否有一行填满*/
void copyimage(int destimage[20][10], int sourceimage[20][10]); /*拷贝数组*/
int score = 0;  /*记录分数*/
int difficulty;  /*难度*/
				 /*主函数*/
int main(void)
{
	int i, j;
	int gameOver = 0;   /*游戏是否结束*/
	int brickInFlight = 0;  /*砖块是否处于飞行状态*/
	int brickType = 0;   /*砖块类别*/
	unsigned int initOrientation = 0; /*初始状态*/
	int notCollide = 0;  /*砖块是否冲突*/
	int arrowKey = 0;
	int tempimage[20][10];
	score = 0;
	difficulty = 500;
	for (i = 0; i<20; i++)
		for (j = 0; j<10; j++)    /*初始化游戏面板*/
			image[i][j] = 0;
	for (i = 0; i<20; i++)
		for (j = 0; j<10; j++)    /*初始化临时游戏面板*/
			tempimage[i][j] = 0;
	Welcome();          /*欢迎界面*/
	Display(image);          /*显示游戏面板*/
							 /*开始游戏*/
	while (!gameOver)
	{
		if (!brickInFlight)
		{
			/*没有砖块落下时，需要新建一个砖块.新建砖块需要随机指定砖块的形状和初
			始状态.*/
			copyimage(tempimage, image);
			Block_Random();
			notCollide = move(10 / 2, 0, image); /*检查是否冲突*/
			if (notCollide) {
				brickInFlight = 1;
				output(tempimage);
				Display(tempimage);  /*显示image*/
			}
			else {
				/*新建砖块同游戏面板的顶部有冲突，表明面板剩余空间已经放不下新砖块。游戏结束*/
				gameOver = 1;
				brickInFlight = 0;
			}
		}
		else
		{  /*当前有砖块正在下落，因此需要检测用户的按键*/
			copyimage(tempimage, image);
			if (kbhit())/*Checks the console for keyboard input*/
			{  /*检测是否有键按下*/
				arrowKey = getch();  /*检查用户输入*/
				if (arrowKey == 'd') /*右移*/
					notCollide = move(1, 0, image);
				else if (arrowKey == 'a') /*左移*/
					notCollide = move(-1, 0, image);
				else if (arrowKey == 'w') /*旋转*/
					notCollide = rotate(image);
				else if (arrowKey == 's')  /*一键加速下落*/
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
				else if (arrowKey == 'p') /*暂停*/
					Pause();
			}
			/*砖块靠重力下落. */
			Sleep(difficulty);
			notCollide = move(0, 1, image);
			if (notCollide)
			{
				output(tempimage);
				Display(tempimage);
			}
			else
			{
				/*砖块落在底部或已固定的砖块上，不再下落. */
				brickInFlight = 0;
				output(image);
				Display(tempimage);
				/*检查是否需要消行*/
				switch (removeFullLines())  /*计分方式。还可以实现更复杂的计分方式*/
				{
				case 1:score++; break;
				case 2:score += 3; break;
				case 3:score += 5; break;
				case 4:score += 8; break;
				}
				switch (score / 100)  /*等级确定*/
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
				/*检查消行后，更新外部图像面板*/
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
/*显示*/
void Display(int binimage[20][10])
{
	int i, j;
	GotoXY(1, 1);
	for (i = 0; i<20; i++)
	{
		printf("■");
		for (j = 0; j<10; j++)
		{
			switch (binimage[i][j])
			{
			case 0:printf("  "); break;
			case 1:printf("□"); break;
			}
		}
		printf("■\n");
	}
	for (i = 0; i<12; i++)
		printf("■");
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
/*随机生成7种基本形状的一种*/
void Block_Random()
{
	int k, i;
	k = (rand() % 7);
	for (i = 0; i<4; i++) {
		x[i] = brickX[k][i];
		y[i] = brickY[k][i];
	}
}
/*欢迎界面*/
void Welcome(void)
{
	printf("【C语言俄罗斯方块】V0.13b build080906\n");
	printf("[旋转：W  下落：X  左移：A  右移：D   瞬间下落：S  暂停：P 退出：Q]\n");
	printf("*平均每提高100分 速度会加快一个级别\n");
	printf("*瞬间下落：S/5 为快速下落 按下后直接落到底部\n");
	system("pause");
	system("cls");
}
/*暂停*/
void Pause(void)
{
	char c;
	GotoXY(1, 23); printf("Pause! ");
	do
	{
		c = getch();
	} while (c != 'p');
}
/*移动*/
int move(int offsetX, int offsetY, int binImage[20][10])
{
	int i;
	int X[4], Y[4];
	for (i = 0; i<4; i++)/*针对每一个小方格的移动*/
	{
		X[i] = x[i] + offsetX;
		Y[i] = y[i] + offsetY;
		if (X[i]<0 || X[i] >= 10 || Y[i]<0 || Y[i] >= 20)  /*判断是否能够移动成功*/
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
/*旋转*/
int rotate(int binImage[20][10])
{
	int i;
	int xt[4], yt[4];
	for (i = 0; i<4; i++) {/*进行顺时针90度坐标变换*/
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
/*输出变换的结果*/
void output(int binImage[20][10])
{
	int i;
	for (i = 0; i<4; i++)
		binImage[y[i]][x[i]] = 1;
}
/*删除满行*/
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
		/*一行完全被填满*/
		if (flag == 0)
		{
			for (m = i; m>0; m--)  /*如果一行完全被填满，删除该行*/
				for (j = 0; j<10; j++)
					image[m][j] = image[m - 1][j];
			for (j = 0; j<10; j++)
				image[0][j] = 0;  /*第一行为0*/
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