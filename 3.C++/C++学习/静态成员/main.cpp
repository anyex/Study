#include <iostream>
using namespace std;

class Box {
public:
	Box(int l, int w):length(l),width(w)
	{
	}

	int volume()
	{
		return length*width*height;
	}
	int length;//4
	int width;//4
static int height;
	
};

int Box::height = 100;//在外部初始化

int main()
{
	Box b1(10, 20);
	Box b2(30, 40);

	cout << "b1:" << b1.volume() << "," << b1.height << endl;
	cout << "b2:" << b2.volume() << "," << b2.height << endl;
	Box::height;

	cout << "sizeof(b1):" << sizeof(b1) << endl;//8
	cout << "sizeof(b2)" << sizeof(b2) << endl;//8

	return 0;
}