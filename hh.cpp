#include <stdio.h>//д��ͷ�ļ�
int main(void)
{
	int a[100], i, j, k, t, n;//����һ�����飬����ѭ������
	printf("������Ҫ�������ĸ�����");
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
