#include <stdio.h>

int tax(int salary,int insurance)
{
	int tax_salary = salary - insurance;
	
	int tmp = tax_salary - 3500;
	if(tmp <= 0)
	{
		printf("您不需要纳税");
		return 0;
	}
	
	if(tmp <= 1500)
		return tmp * 0.03;
	
	if((tmp > 1500)&&(tmp <= 4500))
		return tmp * 0.1 - 105;
	
	if((tmp > 9000)&&(tmp <= 35000))
		return tmp * 0.2 - 555;
	
	if((tmp > 35000)&&(tmp <= 55000))
		return tmp * 0.3 - 2755;
	
	if((tmp > 55000)&&(tmp <= 80000))
		return tmp * 0.35 - 5505;
	
	if((tmp > 80000))
		return tmp * 0.45 - 13505;
	
	
	
}