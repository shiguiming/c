#include <stdio.h>//写个头文件
int main(void)
{
	int a[100], i, j, k, t, n;//定义一个数组，定义循环变量
	printf("请输入要排序数的个数：");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (j = 0; j < n - 1; j++)
	{
		k = j;
		for (i = j + 1; i < n; i++)
			if (a[k] > a[i])
				k = i;
		t = a[j]; a[j] = a[k]; a[k] = t; 
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}
