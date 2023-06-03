#pragma once
#include "BaseRule.h"
class Random :public BaseRule
{
public:
	static std::vector<std::pair<int, int>> TotalCount;
	static std::vector<std::pair<int, int>> WinCount;
	virtual Quan Next();
	virtual void Result(bool win);
	Random();
	~Random();
};

