#include "iostream"
using namespace std;
class MyDate {
public:
	void init_date()
	{
		cout << "�꣬�£���" << endl;
		cin >> year;
		cin >> month;
		cin >> day;
	};

	void print_date()
	{
		cout << year << "��" << month << "��" << day << "��" << endl;
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

protected://��������Ȩ�ޣ�����ļ̳�����private�������ڵ������У���privateһ��
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
		cout << "������" << endl;
	}
	else
		cout << "��������" << endl;

	cout << "�޸�ǰ��year = " << mydate.getYear() << endl;
	mydate.setYear(2018);
	cout << "�޸ĺ�year = " << mydate.getYear() << endl;

	return 0;
}