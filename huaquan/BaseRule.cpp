#include "BaseRule.h"
BaseRule::BaseRule():next((Quan)0),current((Quan)0)
{
    TotalCount[0]=0;
    TotalCount[1]=0;
    TotalCount[2]=0;
    WinCount[0]=0;
    WinCount[1]=0;
    WinCount[2]=0;
}

void BaseRule::clear()
{
    for (int i = 0;i < TotalCount.size();++i)
    {
        TotalCount[i] = 0;
        WinCount[i] = 0;
    }
}

std::map<int, int> BaseRule::getTotal()
{
    return TotalCount;
}
std::map<int, int> BaseRule::getWin()
{
    return WinCount;
}


BaseRule::~BaseRule()
{
}