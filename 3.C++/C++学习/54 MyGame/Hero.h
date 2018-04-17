#pragma once


//玩家职业
enum Player {
	Confucianism,//儒
	Monhism,//墨
	Taoists,//道
	Legalists,//法
		};

//装备
enum Weaon
{
	DAO,
	JIAN,
	QIANG,
	XIE,
	QINGYUEYI
};
class Hero
{
public:
	
	virtual void setEquipment(Weaon w);//设置装备

	bool Death();//判断是否死亡
	bool useHeal();//恢复生命值
	void transFer(Hero &P);//英雄获取物品
	void showRole();//显示玩家信息
protected:
	int MaxHp;//生命值
	int CurHp;
	int Mp;//魔法值
	int Damage;//伤害值
	int Defence;//护甲
	char name[10];//角色名称
	Player role;//职业
	bool death;//是否死亡

};

