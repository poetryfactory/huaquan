#pragma once
#include "BaseRule.h"
class HighRate :public BaseRule
{
private:
	std::vector<std::pair<int,float>> winRate;
public:
	static std::vector<std::pair<int, int>> TotalCount;
	static std::vector<std::pair<int, int>> WinCount;
	HighRate();
	virtual Quan Next();
	void Result(bool win);
	~HighRate();
};

