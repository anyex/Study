#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//家具类
class Furniture
{
public:
	int m; //材质  
};
//如果子类虚继承本类， 编译器会将父类中的成员， 只拷贝一份到孙子中。

//床类
class Bed : virtual  public Furniture
{
public:
	void sleep()
	{
		cout << "在床上睡觉" << endl;
	}
};

//沙发类
class Sofa :virtual public Furniture
{
public:
	void sit()
	{
		cout << "在沙发上睡觉" << endl;
	}
};

//沙发床
class SofaBed :public Bed, public Sofa
{
public:
	void sitAndSleep()
	{
		sit();//sofa
		sleep();//bed
	}
};

int main(void)
{
	Bed b;
	b.sleep();

	cout << "  ---- " << endl;

	Sofa s; //m 
	s.m = 100;
	s.sit();
	cout << "------- " << endl;

	SofaBed sb;
	sb.sitAndSleep();

	sb.m; //多继承 ,如果不虚继承就会出现歧义，导致不知道访问Bed还是sofa的m
	/*
	 sb.Bed::m ;
	 sb.Sofa::m;
	*/

	return 0;
}
