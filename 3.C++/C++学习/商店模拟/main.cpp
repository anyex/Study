//某商店经销一种货物，货物购进和卖出以箱为单位，各箱重量不同
//商店需要记录目前库存的总重量，现在用C++模拟商店购进和卖出的情况
#include <iostream>
using namespace std;
class  Goods
{
public:
	Goods()
	{
		weight = 0;
		next = NULL;
		cout << "购进一个重量为" << weight << "的货物" << endl;

	};

	Goods(int w)
	{//需要创建一个w的货物，并且仓库加上这个重量
		weight = w;
		next = NULL;
		total_weight += w;
		cout << "创建了一个重量为" << weight << "的货物" << endl;
	}
	~Goods()
	{
	   //仓库卖出货物
		cout << "卖出重量为：" << weight << "的货物" << endl;
		total_weight -= weight;
	};
	static int get_total_weight()
	{
		return total_weight;//静态函数返回静态变量
	}

	Goods *next;
	
private:
	int weight;//重量
	static int total_weight;//仓库的总重量
};

void sale(Goods * &head)
{
	if (head == NULL) {
		cout << "仓库中已经没有货物了。。" << endl;
		return;
	}

	Goods *temp = head;
	head = head->next;

	delete temp;
	cout << "saled." << endl;
}
void buy(Goods * &head, int w)
{
	//创建一个货物 重量是w
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
		cout << "1 进货" << endl;
		cout << "2 出货" << endl;
		cout << "0 退出" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			//进货
			cout << "请输出要创建货物的重量" << endl;
			cin >> w;
			buy(head, w);
			break;
		case 2:
			//出货
			sale(head);
			break;
		case 0:
			//退出
			return 0;
		default:
			break;
		}

		cout << "当前仓库的总重量是" << Goods::get_total_weight() << endl;

	} while (1);

	return 0;
}