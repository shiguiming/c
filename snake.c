#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <MMsystem.h>
#include <conio.h>
#include "head.h"
#include "time.h"

#pragma comment(lib ,"winmm.lib")


void FirstPage();   //显示首页
void MyPalySound();   //播放音乐
void TestSpace();   //检测空格 进入游戏
void MyStopMusic();   //停止播放音乐
void PrintBorder();   //打印边框
void ShowBackground();  //打印背景
void SetSnakeRandPos();  //随机产生蛇的位置
void DrawSnake();       //画蛇
void SnakeMove();    //蛇移动
void DropSnake();   //销毁蛇
void ChangeDir();   //改变蛇方向

int main(void)
{
	FirstPage();  //显示首页
	//MyPalySound();  //播放音乐
	TestSpace();   //输入检测的效果
	//MyStopMusic(); //停止播放音乐
	system("cls");   //清空封面


	//进入游戏界面
	printf("开始游戏\n");



	//PrintBorder();  //边框
	SetSnakeRandPos(); //设置蛇的位置
	ShowBackground();

	DrawSnake(); //画蛇

	while (1)   //打印背景
	{
		system("cls");
		//ChangeDir();
		SnakeMove(); //蛇移动
		ShowBackground(); //显示背景
		Sleep(500); //间隔时间
	}



	system("pause");
	return 0;
}

void FirstPage()
{
	printf(" 欢迎进入贪吃蛇世界\n");
	printf("  按空格键开始游戏\n");
	printf(" W A S D 控制蛇的方向\n");
}

void MyPalySound()
{
	PlaySound("猪猪侠.wav", NULL, SND_FILENAME | SND_ASYNC);
	//绝对路径：完整路径 
	//相对路径：不需要加前缀目录 音乐文件放在项目目录里

	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE| SND_ASYNC);
	//添加资源文件 导入
}

void TestSpace()
{
	char chInput;
	while (1)
	{
		chInput = _getch(); //_getch() 调试时不显示 getchar()显示
		if (' ' == chInput) //变量写右侧 
			break;
	}
}

void MyStopMusic()
{
	PlaySound(NULL, 0, 0);
}

void PrintBorder()
{
	for (int i = 0; i < 20; i++)
	{
		printf(strGameBack[i]);
		printf("\n");
	}
}

void SetSnakeRandPos()
{
	int nX = -1;
	int nY = -1;
	srand((unsigned int)time(NULL));  //种种子
	nX = rand() % 19 + 1;
	nY = rand() % 18 + 1;

	//初始化蛇的结点1
	arrSnake[0][0] = nY;         //行
	arrSnake[0][1] = nX * 2;     //列
	arrSnake[0][2] = to_right;   //方向
	//初始化蛇的结点2
	arrSnake[1][0] = nY;
	arrSnake[1][1] = nX * 2 + 2;
	arrSnake[1][2] = to_right;
	//初始化蛇的结点3
	arrSnake[2][0] = nY;
	arrSnake[2][1] = nX * 2 + 4;
	arrSnake[2][2] = to_right;

	//画到背景上
	//DrawSnake();
}

void DrawSnake()
{
	int i = 0;
	for (i; arrSnake[i][0] != 0; i++)
	{
		strncpy(&strGameBack[arrSnake[i][0]][arrSnake[i][1]], "█", 2);
	}
}

void ShowBackground()
{
	for (int i = 0; i < 20; i++)
	{
		printf(strGameBack[i]);
		printf("\n");
	}
}

void SnakeMove()
{
	int i = DEF_SNAKE_LONG - 1;
	//销毁蛇
	DropSnake();

	for (i; i >= 1; i--)
	{
		if (0 != arrSnake[i][0])
		{
			arrSnake[i][0] = arrSnake[i - 1][0];
			arrSnake[i][1] = arrSnake[i - 1][1];
			arrSnake[i][2] = arrSnake[i - 1][2];
		}
	}
	arrSnake[0][2] = g_nSnakedir;
	//处理蛇头
	if (to_lift == arrSnake[0][2] || to_right == arrSnake[0][2])
	{
		arrSnake[0][1] += arrSnake[0][2];
	}
	else
	{
		arrSnake[0][0] += arrSnake[0][2];
	}
	DrawSnake();
}

void DropSnake()
{
	int i = 0;
	for (i; arrSnake[i][0] != 0; i++)
	{
		strncpy(&strGameBack[arrSnake[i][0]][arrSnake[i][1]], "  ", 2);
	}
}
void ChangeDir()
{
	if (GetAsyncKeyState('W'))
	{
		g_nSnakedir = to_up;
	}
	else if (GetAsyncKeyState('A'))
	{
		g_nSnakedir = to_lift;
	}
	else if (GetAsyncKeyState('S'))
	{
		g_nSnakedir = to_down;
	}
	else if (GetAsyncKeyState('D'))
	{
		g_nSnakedir = to_right;
	}
}