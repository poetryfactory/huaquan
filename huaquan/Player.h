#pragma once
#include "BaseRule.h"
class Player :public BaseRule
{
public:
	virtual Quan Next();
	virtual void Result(bool win);
	virtual void Show();
};

