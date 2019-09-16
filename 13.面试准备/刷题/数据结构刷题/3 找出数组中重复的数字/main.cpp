/*
在一个长度为n的数组里的所有数字都在0~n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，例如，如果输入
长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3

*/

//排列数组值和下标的关系
#include <stdio.h>
int a[] = { 2,3,1,0,2,5,3 };

void sortArray(int a[], int len)
{
	for (int i = 0;i < len;i++)
	{
			while (a[i] != i)//最多循环两次，可以认为复杂度为O(n)
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
