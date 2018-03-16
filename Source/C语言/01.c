#include "stdio.h"
#include "math.h"
int main()
{
  
		int a =8;
		long long b = 2;
        char c = 'a';
        short int d = 3;
        double e = 3.5;
        float f = 2.4;
        printf("sizeof(int) = %d\n",sizeof(int));
   
        printf("sizeof(long long) = %d\n",sizeof(long long));
        printf("sizeof(char) = %d\n",sizeof(char));
        printf("sizeof(short) = %d\n",sizeof(short));
        printf("sizeof(double) = %d\n",sizeof(double));
        printf("sizeof(float) = %d\n",sizeof(float));

		printf("int + double =%d\n",sizeof(a+e));
		printf("int + char =%d\n",sizeof(a+c));
		printf("double + float=%d\n",sizeof(e+f));
		printf("char + float =%d\n",sizeof(f+c));
}

/*
 *运算结果：
 *
	izeof(int) = 4
	sizeof(long long) = 8
	sizeof(char) = 1
	sizeof(short) = 4
	sizeof(double) = 4
	sizeof(float) = 4
	int + double =8
	int + char =4
	double + float=8
	char + float =4

	说明了:短整型向长整型看齐，有符号向无符号看齐，整形向浮点型看齐
   
 *
 * */
