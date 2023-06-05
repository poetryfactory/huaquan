#pragma once
#include "BaseRule.h"
class Least:public BaseRule
{
public:
	Least();
	virtual Quan Next();
	void Result(bool win);
	virtual void Show();
};

