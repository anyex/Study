#include "Hero.h"
#include <cstring>
#include <iostream>
using namespace std;




 
   //����װ��
 void  Hero::setEquipment(Weaon w)
 {
 
 
 }

  //�ж��Ƿ�����
 bool Hero::Death()
 {
	 if (this->CurHp <= 0)
	 {
		 return true;
	}

	 return false;

 }

 //�ָ�����ֵ
 bool Hero::useHeal()
 {
	 this->CurHp = this->MaxHp;
	 return true;
}

 //��ʾ�����Ϣ
 void Hero::showRole()
 {
	 cout << "���: " << this->name<<endl;
	 cout << "ְҵ��" << this->role << endl;
	 cout << "���ף�" << this->Defence << endl;
	 cout << "������" << this->Damage << endl;
	 

}