#include "stdio.h"
int main()
{
	int n = 0;
	float f = 0;
	double d = 0;
	char c = 0;
    char str[80];
    char str1[80];
	char str2[80]

 	scanf ("%d %f %lf",&n,&f,&d);//输入 1 2.333 4.5555
	printf("n=%d,f=%g\n",n,f);

	scanf("%f",&d);//输入6.6976，没有改变d的值
    printf("d=%g\n",d);

    scanf(" %c",&c);//输入a,用%c的时候，空格和转义字符均有效
    printf("c=%c d=%d\n",c,c);
    printf("The numbers of scanf with success:%d\n",scanf("%f,%lf",&f,&d));  

	scanf("n=%d",&n);//必须输入n=4这样的形式才能正确赋值给n
	//输入I am aff
	scanf("%s",str);//如果输入 I am aff ，则str中将只保存I,因为scanf遇见空格，回车，非法输入(不匹配格式符)就结束输入，但后面的还在缓冲区内
    scanf("%s",str1);//str1为 am
	
    scanf("%s",str2);//str2为 aff
//scanf("%[^/n]");//不接收空格
  

}

/*  
 *结果：
 *    1 2.333 4.555
 *    n=1,f=2.333
 *    6.6976
 *    d=4.555
 *    a
 *    c=a d=97
 *    1 2.4
 *    The numbers of scanf with success:1
 *    说明：
 *    		scanf语句必须按格式化输入，否则将会一直保存在缓存中
 *    		scanf语句遇见空格和
 *       
 *
 * /
