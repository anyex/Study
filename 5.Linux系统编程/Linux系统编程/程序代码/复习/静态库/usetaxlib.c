#include <stdio.h>
int tax(int salary,int insurance);
int main()
{
	int my_tax = tax(9000,1000);
	printf("需要缴纳的税费为：%d",my_tax);
	return 0;
}