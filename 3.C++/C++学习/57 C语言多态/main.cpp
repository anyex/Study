
#pragma warning(disable:4996)

#include <iostream>

using namespace std;

//定义一个开锦囊的方法(函数)，类似于C++的纯虚函数
typedef void(TIPS_FUNC)(void);

//写一个锦囊的结构体
struct tips
{
	char from[64];//锦囊谁写的
	char to[64];//锦囊写给谁的
	TIPS_FUNC *fp;//具体的锦囊内容
};

//写一个供赵云调用的架构函数
void open_tips(struct tips *tp)
{
	cout << "打开了锦囊" << endl;
	cout << "此锦囊由" << tp->from << ",写给" << tp->to << endl;
	tp->fp();
}

//实现一个一个的锦囊  //类似于实现一个纯虚函数
void tips_1(void)
{
	cout << "一到东吴就大张旗鼓找乔国老" << endl;
}

void tips_2(void)
{
	cout << "骗刘备 操作压境" << endl;
}

void tips_3(void)
{
	cout << "找孙尚香求救" << endl;
}

void tips_4(void)
{
	cout << "你们就死在东吴把" << endl;
}

struct tips* create_tips(char *from, char *to, TIPS_FUNC* fp)
{
	struct tips *tp = (struct tips*)malloc(sizeof(struct tips));
	if (tp == NULL)
	{
		return NULL;
	}
	strcpy(tp->from, from);
	strcpy(tp->to, to);
	//注册回调函数
	tp->fp = fp;//给结构体的函数指针赋值，即回调函数

}

void destory_tips(struct tips* tp)
{
	if (tp != NULL)
	{
		free(tp);
	}
}

int main()
{
	struct tips * tp1 = create_tips("孔明", "赵云", tips_1);
	struct tips * tp2 = create_tips("孔明", "赵云", tips_2);
	struct tips * tp3 = create_tips("孔明", "赵云", tips_3);
	struct tips *tp4 = create_tips("庞统", "赵云", tips_4);


	// 赵云去拆机囊
	cout << "刚来到 东吴境内 ，打开了第一个锦囊" << endl;
	open_tips(tp1);

	cout << "刘备乐不思蜀 ，打开第二个锦囊 " << endl;

	open_tips(tp2);

	cout << "孙权追杀刘备, 打开第三个锦囊" << endl;
	open_tips(tp3);
	cout << "赵云发现  抵挡不住 军队，想到了庞统的最后一个锦囊 打开了" << endl;

	open_tips(tp4);


	destory_tips(tp1);
	destory_tips(tp2);
	destory_tips(tp3);
	destory_tips(tp4);

	return 0;
}