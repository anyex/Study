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
	
	};//设置装备
private:
	
};

int main()
{
	cout << "-----------------------------游戏开始---------------------------" << endl;
	cout << "创建角色，请输入角色名称" << endl;
	char name[10];
	cin >> name;
	Legalist player(name);

	while (!player.Death())
	{
		cout << "大侠前往何处" << endl;
		cout << "1.北" << endl;
		cout << "2.南" << endl;


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