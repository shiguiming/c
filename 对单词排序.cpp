#include<stdio.h>//来两个头文件
#include<string.h>

int main()//声明主函数
{
	int i, j;//定义循环参数
	char word[5][20];//定义一个二维数组
	printf("请输入要排序的五个单词:");//提示用户输入需要排排序的单词
	for (i = 0; i < 5; i++)//采用循环使用户输入这5个单词
	{
		scanf_s("%s", &word[i]);//输入语句输入单词
	}
	// 使用冒泡法对单词进行排序
	for (i = 0; i < 5; i++)//循环排序
	{
		for (j = 0; j < 4; j++)//循环排序
		{
			if (strcmp(word[j], word[j + 1]) < 0)//判断两个单词的长度并交换位置
			{
				char *p;//定义一个字符型的指针
				char m[20];//定义一个数组
				p = m;
				strcpy(p, word[j]);//使用函数复制单词并拷贝到下一个地址
				strcpy(word[j], word[j + 1]);
				strcpy(word[j + 1], p);
			}
		}
	}
	// 输入排序后的单词
	printf("排序后:\n");//排序后采用循环的办法将其输出
	for (i = 0; i < 5; i++)
	{
		printf("%s ", word[i]);//输出语句
	}
	return 0;
}
