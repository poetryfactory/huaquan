#pragma once
#include "BaseRule.h"
class Random :public BaseRule
{
public:
	virtual Quan Next();
	virtual void Result(bool win);
	virtual void Show();
	Random();
};

