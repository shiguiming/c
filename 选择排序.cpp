/*ѡ�������һ�������˽�����Ĺ�����ϰ����Ĺ���
ѧϰ����ľ��裬��������c���ԵĻ���*/
#include<stdio.h>
void Select_Sort(int *arr, int len);//����һ������
int main()
{              
	              //�������Ͳ�д�ˣ���֪��дʲô������ʱ�����ٹ���д

}
void Select_Sort(int *arr, int len)//����ѡ���ַ�����̵�
{
	int small = 0;//����һ������������Ϊ�ж��ַ����ĳ��ȵ�
	for (int i = 0; i < len - 1; i++)//����һ��ѭ������ѭ�������ַ�����λ��
	{
		small = i;
		int j = i + 1;
		for (j=0; j < len; j++)//����һ��ѭ�����ж��ַ����ĳ���
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
