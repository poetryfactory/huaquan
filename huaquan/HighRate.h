#pragma once
#include "BaseRule.h"
class HighRate :public BaseRule
{
public:
	std::map<int,float> winRate;
	HighRate();
	virtual Quan Next();
	void Result(bool win);
	virtual void clear();
	virtual void Show();
};

