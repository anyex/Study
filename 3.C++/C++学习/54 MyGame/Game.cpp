#define  _CRT_SECURE_NO_WARNINGS 

#include "Hero.h"
#include <iostream>
#include <cstring>
using namespace std;

class Legalist :public Hero {
public:
	Legalist(char *name) 
	{
		strcpy(this->name, name);
		this->MaxHp = 100;
		this->CurHp = 100;
		this->Damage = 20;
		this->Defence = 20;
		this->role = Legalists;
		this->Mp = 100;
		
    }
	
	
	
	virtual void setEquipment(Weaon w)
	{
	
	};//����װ��
private:
	
};

int main()
{
	cout << "-----------------------------��Ϸ��ʼ---------------------------" << endl;
	cout << "������ɫ���������ɫ����" << endl;
	char name[10];
	cin >> name;
	Legalist player(name);

	while (!player.Death())
	{
		cout << "����ǰ���δ�" << endl;
		cout << "1.��" << endl;
		cout << "2.��" << endl;


			 int chioce;
		cin >> chioce;
		switch (chioce)
		{
		case 1:
		{
			
		}
		default:
			break;
		}
	}
	
	return 0;
}