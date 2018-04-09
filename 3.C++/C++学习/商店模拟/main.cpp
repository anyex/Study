//ĳ�̵꾭��һ�ֻ�����ﹺ������������Ϊ��λ������������ͬ
//�̵���Ҫ��¼Ŀǰ������������������C++ģ���̵깺�������������
#include <iostream>
using namespace std;
class  Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "����һ������Ϊ" << weight << "�Ļ���" << endl;

	};

	Goods(int w)
	{//��Ҫ����һ��w�Ļ�����Ҳֿ�����������
		weight = w;
		next = NULL;
		total_weight += w;
		cout << "������һ������Ϊ" << weight << "�Ļ���" << endl;
	}
	~Goods()
	{
	   //�ֿ���������
		cout << "��������Ϊ��" << weight << "�Ļ���" << endl;
		total_weight -= weight;
	};
	static int get_total_weight()
	{
		return total_weight;//��̬�������ؾ�̬����
	}

	Goods *next;
	
private:
	int weight;//����
	static int total_weight;//�ֿ��������
};

void sale(Goods * &head)
{
	if (head == NULL) {
		cout << "�ֿ����Ѿ�û�л����ˡ���" << endl;
		return;
	}

	Goods *temp = head;
	head = head->next;

	delete temp;
	cout << "saled." << endl;
}
void buy(Goods * &head, int w)
{
	//����һ������ ������w
	Goods *new_goods = new Goods(w);

	if (head == NULL) {
		head = new_goods;
	}
	else {
		new_goods->next = head;
		head = new_goods;
	}

}

int main(void)
{
	int choice = 0;
	Goods *head = NULL;
	int w;

	do {
		cout << "1 ����" << endl;
		cout << "2 ����" << endl;
		cout << "0 �˳�" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			//����
			cout << "�����Ҫ�������������" << endl;
			cin >> w;
			buy(head, w);
			break;
		case 2:
			//����
			sale(head);
			break;
		case 0:
			//�˳�
			return 0;
		default:
			break;
		}

		cout << "��ǰ�ֿ����������" << Goods::get_total_weight() << endl;

	} while (1);

	return 0;
}