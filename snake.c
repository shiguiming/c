#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <MMsystem.h>
#include <conio.h>
#include "head.h"
#include "time.h"

#pragma comment(lib ,"winmm.lib")


void FirstPage();   //��ʾ��ҳ
void MyPalySound();   //��������
void TestSpace();   //���ո� ������Ϸ
void MyStopMusic();   //ֹͣ��������
void PrintBorder();   //��ӡ�߿�
void ShowBackground();  //��ӡ����
void SetSnakeRandPos();  //��������ߵ�λ��
void DrawSnake();       //����
void SnakeMove();    //���ƶ�
void DropSnake();   //������
void ChangeDir();   //�ı��߷���

int main(void)
{
	FirstPage();  //��ʾ��ҳ
	//MyPalySound();  //��������
	TestSpace();   //�������Ч��
	//MyStopMusic(); //ֹͣ��������
	system("cls");   //��շ���


	//������Ϸ����
	printf("��ʼ��Ϸ\n");



	//PrintBorder();  //�߿�
	SetSnakeRandPos(); //�����ߵ�λ��
	ShowBackground();

	DrawSnake(); //����

	while (1)   //��ӡ����
	{
		system("cls");
		//ChangeDir();
		SnakeMove(); //���ƶ�
		ShowBackground(); //��ʾ����
		Sleep(500); //���ʱ��
	}



	system("pause");
	return 0;
}

void FirstPage()
{
	printf(" ��ӭ����̰��������\n");
	printf("  ���ո����ʼ��Ϸ\n");
	printf(" W A S D �����ߵķ���\n");
}

void MyPalySound()
{
	PlaySound("������.wav", NULL, SND_FILENAME | SND_ASYNC);
	//����·��������·�� 
	//���·��������Ҫ��ǰ׺Ŀ¼ �����ļ�������ĿĿ¼��

	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE| SND_ASYNC);
	//�����Դ�ļ� ����
}

void TestSpace()
{
	char chInput;
	while (1)
	{
		chInput = _getch(); //_getch() ����ʱ����ʾ getchar()��ʾ
		if (' ' == chInput) //����д�Ҳ� 
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
	srand((unsigned int)time(NULL));  //������
	nX = rand() % 19 + 1;
	nY = rand() % 18 + 1;

	//��ʼ���ߵĽ��1
	arrSnake[0][0] = nY;         //��
	arrSnake[0][1] = nX * 2;     //��
	arrSnake[0][2] = to_right;   //����
	//��ʼ���ߵĽ��2
	arrSnake[1][0] = nY;
	arrSnake[1][1] = nX * 2 + 2;
	arrSnake[1][2] = to_right;
	//��ʼ���ߵĽ��3
	arrSnake[2][0] = nY;
	arrSnake[2][1] = nX * 2 + 4;
	arrSnake[2][2] = to_right;

	//����������
	//DrawSnake();
}

void DrawSnake()
{
	int i = 0;
	for (i; arrSnake[i][0] != 0; i++)
	{
		strncpy(&strGameBack[arrSnake[i][0]][arrSnake[i][1]], "��", 2);
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
	//������
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
	//������ͷ
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