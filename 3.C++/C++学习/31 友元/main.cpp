#include <iostream>
#include <cmath>

using namespace std;

class Point;
class PointManager
{
public:
	//如果解决循环前置声明的问题，应该将函数的声明和函数的定义分开
	double PointDistance(Point &p1, Point &p2);
};

class Point
{
public:
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void printPoint()
	{
		cout << "x = " << x << ", y = " << endl;
	}
	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}

	//Point 会允许这个全局的友元函数访问私有成员
	friend double PointDistance(Point &p1, Point &p2);
	//声明一个其他类的成员函数为自己的友元
	friend double PointManager::PointDistance(Point &p1, Point &P2);

private:
	int x;
	int y;
};


double PointManager::PointDistance(Point & p1, Point &p2)
{
	//int dd_x = p1.getX() - p2.getX();
	int dd_x = p1.x - p2.x;
	//int dd_y = p1.getY() - p2.getY();
	int dd_y = p1.y - p2.y;

	return sqrt(dd_x*dd_x + dd_y*dd_y);
}




//1 通过全局方式写一个亮点之间的距离
//如果发现有一个方式 是全局的不是类自己的成员函数
double PointDistance(Point & p1, Point &p2)
{
	//int dd_x = p1.getX() - p2.getX();
	int dd_x = p1.x - p2.x;
	//int dd_y = p1.getY() - p2.getY();
	int dd_y = p1.y - p2.y;

	return sqrt(dd_x*dd_x + dd_y*dd_y);
}

int main(void)
{
	Point p1(1, 2);
	Point p2(0, 0);

	cout << "两点之间的距离是 " << PointDistance(p1, p2) << endl;


	PointManager pm;
	cout << "两点之间的距离是 " << pm.PointDistance(p1, p2) << endl;



	return 0;
}

/*
只有类的成员函数才能访问类的私有成员，程序中的其他函数无法访问私有成员
为了让其他类外的函数也能访问私有成员，可以使用友元，但它需要在类体内进行说明，并用friend申明
友元关系不具对称性。即 A 是 B 的友元，但 B 不一定是 A 的友元。 友元关系不具传递性。即 B 是 A 的友元，C 是 B 的友元，但是 C 不一定是 A 的友元


*/