#pragma once
#include "BaseRule.h"
#include<iostream>
class LastWin :public BaseRule
{
public:
	LastWin();
	virtual Quan Next();
	virtual void Result(bool win);
	virtual void Show();
};

