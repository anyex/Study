#pragma once


//���ְҵ
enum Player {
	Confucianism,//��
	Monhism,//ī
	Taoists,//��
	Legalists,//��
		};

//װ��
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
	
	virtual void setEquipment(Weaon w);//����װ��

	bool Death();//�ж��Ƿ�����
	bool useHeal();//�ָ�����ֵ
	void transFer(Hero &P);//Ӣ�ۻ�ȡ��Ʒ
	void showRole();//��ʾ�����Ϣ
protected:
	int MaxHp;//����ֵ
	int CurHp;
	int Mp;//ħ��ֵ
	int Damage;//�˺�ֵ
	int Defence;//����
	char name[10];//��ɫ����
	Player role;//ְҵ
	bool death;//�Ƿ�����

};

