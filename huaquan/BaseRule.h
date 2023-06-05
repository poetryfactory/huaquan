#pragma once
#include"global.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
class BaseRule
{
protected:
	Quan next;
	Quan current;
	std::map<int, int> TotalCount;
	std::map<int, int> WinCount;
public:
	BaseRule();
	virtual Quan Next() = 0;
	virtual void Result(bool win)=0;
	virtual void clear();
	virtual void Show()=0;
	std::map<int, int> getTotal();
	std::map<int, int> getWin();
	~BaseRule();
};

