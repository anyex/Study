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
		cout << "英雄战胜了怪兽" << endl;
	}

	else
		cout << "英雄挂了" << endl;
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
多态发生的三个必要条件
	1.要有继承
	2.要有子类重写父类的虚函数
	3.父类指针(或引用)指向子类对象
和重载的区别：
	重载是允许存在多个同名方法，而这些方法的参数不同，在编译阶段都就绑定了函数的调用地址
	多态是指父类重新定义父类的虚方法，父类根据赋给它的不同子类，动态调用属于子类的该方法。
*/