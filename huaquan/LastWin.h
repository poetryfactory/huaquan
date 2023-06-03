#pragma once
#include "BaseRule.h"
#include<iostream>
class LastWin :public BaseRule
{
public:
	static std::vector<std::pair<int, int>> TotalCount;
	static std::vector<std::pair<int, int>> WinCount;
	LastWin();
	virtual Quan Next();
	virtual void Result(bool win);
	~LastWin();
};

