/*选择排序第一个排序了解排序的过程练习排序的过程
学习排序的精髓，慢慢打下c语言的基础*/
#include<stdio.h>
void Select_Sort(int *arr, int len);//定义一个函数
int main()
{              
	              //主函数就不写了，不知道写什么，等有时间了再过来写

}
void Select_Sort(int *arr, int len)//用来选择字符串最短的
{
	int small = 0;//定义一个变量用来作为判断字符串的长度的
	for (int i = 0; i < len - 1; i++)//定义一个循环用来循环调换字符串的位置
	{
		small = i;
		int j = i + 1;
		for (j=0; j < len; j++)//又是一个循环来判断字符串的长度
		{
			if (arr[j] < arr[small]) 
			{
				small = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[small];
		arr[small] = temp;
	}
}
