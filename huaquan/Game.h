#pragma once
#include"BaseRule.h"
#include<iostream>
class Game
{
private:
	BaseRule& br1;
	BaseRule& br2;
public:
	Game(BaseRule* s1, BaseRule* s2);
	void Play(int n);
};

