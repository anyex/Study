/*
��һ������Ϊn����������������ֶ���0~n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ����磬�������
����Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3

*/

//��������ֵ���±�Ĺ�ϵ
#include <stdio.h>
int a[] = { 2,3,1,0,2,5,3 };

void sortArray(int a[], int len)
{
	for (int i = 0;i < len;i++)
	{
			while (a[i] != i)//���ѭ�����Σ�������Ϊ���Ӷ�ΪO(n)
			{
				if (a[i] == a[a[i]])
				{
					printf("%d\t", a[i]);
					break;
				}

				int temp = a[i];
				a[i] = a[temp];
				a[temp] = temp;
			}
			

		
		
	}
}

int main()
{
	sortArray(a, 7);
	return 0;
}
