#include <iostream>

using namespace std;

class Student {
public:
	Student(int num, double score) {
		m_num = num;
		m_score = score;

		count++;
		sum_score += score;
	}

	static double getAvg()
	{
		return sum_score / count;
	}
private:
	int m_num; //学号
	double m_score; //成绩

					//定义一个记录学生个数的静态变量
	static int count; //记录目前Student类已经创建了多少个学生对象。
	static double sum_score;// 所有已经定义学生对象的总score和。

};

//初始化静态成员变量
int Student::count = 0;
double Student::sum_score = 0.0;

int main(void)
{
	Student s1(1, 80);
	Student s2(2, 90);
	Student s3(3, 80);

	//Student::sum_score / Student::count;
	//使用一个静态的成员函数
	double avg = Student::getAvg(); //可以给他当成一个 类的全局函数

									//s1.getAvg();

	cout << "目前的学生的平均分数是" << avg << endl;

	return 0;
}

/*
无论静态函数还是非静态函数都是属于类的
静态成员函数不接受隐含的this变量，所以它无法访问自己类的非静态成员

类的静态成员(变量和方法)属于类本身，在类加载的时候就会分配内存，
可以通过类名直接去访问；非静态成员（变量和方法）属于类的对象，
所以只有在类的对象产生（创建类的实例）时才会分配内存，
然后通过类的对象（实例）去访问。

在一个类的静态成员中去访问其非静态成员之所以会出错是因为
在类的非静态成员不存在的时候类的静态成员就已经存在了，
访问一个内存中不存在的东西当然会出错。

*/