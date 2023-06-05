#pragma once
#include"BaseRule.h"
#include<iostream>
#include"Random.h"
#include"HighRate.h"
#include"LastWin.h"
#include"Least.h"
#include<stdlib.h>
class Game
{
private:
	BaseRule& br1;
	BaseRule& br2;
public:
	Game(BaseRule* s1, BaseRule* s2);
	void Play(int n);
	std::unordered_map<int, std::string> mp1 = { {0,"Ê¯Í·"},{1,"¼ôµ¶"},{2,"²¼"} };
};

