#pragma once
#include"global.h"
#include<iostream>
#include<algorithm>
#include<vector>
class BaseRule
{
protected:
	Quan next;
	Quan current;
public:
	BaseRule();
	virtual Quan Next() = 0;
	virtual void Result(bool win)=0;
	~BaseRule();
};

