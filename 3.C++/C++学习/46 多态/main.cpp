#include <iostream>
using namespace std;

class Hero
{
public:
	virtual int getAd()
	{
		return 10;
	}
};

class SuperHero :public Hero
{
public:
	virtual int getAd()
	{
		return 100;
	}
};

class BugHero :public Hero
{
public:
	virtual int getAd()
	{
		return 10000;
	}

};

class Monster {
public:
	int getAd()
	{
		return 30;
	}
};

void PlayerFight(Hero *hero, Monster *m)
{
	if (hero->getAd() > m->getAd())
	{
		cout << "Ӣ��սʤ�˹���" << endl;
	}

	else
		cout << "Ӣ�۹���" << endl;
}

int main()
{
	Hero hero1;
	Monster mon1;
	SuperHero hero2;
	BugHero hero3;

	PlayerFight(&hero1, &mon1);
	PlayerFight(&hero2, &mon1); //Hero *hero = &hero2;

	PlayerFight(&hero3, &mon1);


	return 0;




}

/*
��̬������������Ҫ����
	1.Ҫ�м̳�
	2.Ҫ��������д������麯��
	3.����ָ��(������)ָ���������
�����ص�����
	������������ڶ��ͬ������������Щ�����Ĳ�����ͬ���ڱ���׶ζ��Ͱ��˺����ĵ��õ�ַ
	��̬��ָ�������¶��常����鷽����������ݸ������Ĳ�ͬ���࣬��̬������������ĸ÷�����
*/