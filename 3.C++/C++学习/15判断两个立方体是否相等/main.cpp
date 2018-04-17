#include "cube.h"
#include <iostream>
using namespace std;
int main()
{
	Cube c1(1,2,3);
	Cube c2(2, 3, 4);
	if (c1.isEqual(c2))
	{
		cout << "c1 == c2" << endl;

	}
	else
		cout << "c1!=c2" << endl;
	cout << "c1的面积:" << c1.Area() << ",c1的体积" << c1.Volume() << endl;;

	return 0;
}