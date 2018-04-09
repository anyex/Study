#include "iostream"
using namespace std;
class MyDate {
public:
	void init_date()
	{
		cout << "年，月，日" << endl;
		cin >> year;
		cin >> month;
		cin >> day;
	};

	void print_date()
	{
		cout << year << "年" << month << "月" << day << "日" << endl;
	}

	bool is_leap_year()
	{
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}

		return false;
	}

	int getYear()
	{
		return year;
	}

	void setYear(int set_year)
	{
		year = set_year;
	}

protected://保护控制权限，在类的继承中与private有区别，在单个类中，跟private一样
private:
	int year;
	int month;
	int day;
};

int main()
{
	MyDate mydate;
	mydate.init_date();
	mydate.print_date();

	
	if (mydate.is_leap_year())
	{
		cout << "是闰年" << endl;
	}
	else
		cout << "不是闰年" << endl;

	cout << "修改前：year = " << mydate.getYear() << endl;
	mydate.setYear(2018);
	cout << "修改后：year = " << mydate.getYear() << endl;

	return 0;
}