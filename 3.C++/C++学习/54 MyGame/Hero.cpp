#include "Hero.h"
#include <cstring>
#include <iostream>
using namespace std;




 
   //设置装备
 void  Hero::setEquipment(Weaon w)
 {
 
 
 }

  //判断是否死亡
 bool Hero::Death()
 {
	 if (this->CurHp <= 0)
	 {
		 return true;
	}

	 return false;

 }

 //恢复生命值
 bool Hero::useHeal()
 {
	 this->CurHp = this->MaxHp;
	 return true;
}

 //显示玩家信息
 void Hero::showRole()
 {
	 cout << "玩家: " << this->name<<endl;
	 cout << "职业：" << this->role << endl;
	 cout << "护甲：" << this->Defence << endl;
	 cout << "武力：" << this->Damage << endl;
	 

}