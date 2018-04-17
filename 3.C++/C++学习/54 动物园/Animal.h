#pragma once
#pragma once
#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;


class Animal
{
public:
	Animal();
	virtual ~Animal();

	//纯虚函数
	virtual void voice() = 0;
};

//此函数是根据 抽象类来进行封装的。 这种函数 就叫架构函数。
void AnimalVoice(Animal *ap);

