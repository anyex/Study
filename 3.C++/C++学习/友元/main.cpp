#include <iostream>
#include <cmath>
using namespace std;

class Point;//ǰ��������������������ָ�������


class ManagerPoint
{
public:
	double Distance(Point& a, Point& b);
};

class Point {
public:
	Point(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
	void Getxy();
	friend double Distance(Point &a, Point &b);//ȫ�ֺ�����Ϊ��Ԫ����
	friend double ManagerPoint::Distance(Point& a, Point& b);//���Ա������Ϊ��Ԫ����
private:
	double x, y;
};
void Point::Getxy()
{
	cout << "(" << x << "," << y << ")" << endl;

}

double ManagerPoint::Distance(Point& a, Point& b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return sqrt(dx*dx + dy*dy);
}

double Distance(Point &a, Point &b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return sqrt(dx*dx + dy*dy);
}

void test()
{
	Point p1(3.0, 4.0), p2(6.0, 8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1, p2);
	cout << "Distance is  " << d << endl;
}
int main()
{
	test();

	return 0;
}