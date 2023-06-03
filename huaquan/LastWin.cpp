#include "LastWin.h"
std::vector<std::pair<int, int>> LastWin::TotalCount(3);
std::vector<std::pair<int, int>> LastWin::WinCount(3);
LastWin::LastWin()
{
	std::cout << "当前策略:使用赢得上一轮的出拳。" << std::endl;
}

Quan LastWin::Next()
{
	switch ((int)current)
	{
	case 0:
	{
		next = (Quan)2;
		break;
	}
	case 1:
	{
		next = (Quan)0;
		break;
	}
	case 2:
	{
		next = (Quan)1;
		break;
	}
	}
	TotalCount[(int)next].second++;
	current = (Quan)next;
	return (Quan)next;
}

void LastWin::Result(bool win)
{
	if (win)
	{
		WinCount[(int)current].second++;
	}
}

LastWin::~LastWin()
{
	if (TotalCount[0].second != 0)
	{
		std::cout << "赢上局策略";
		std::cout << "战绩如下：" << std::endl;
		std::cout << "石头共出了：" << TotalCount[0].second << "局,共获胜：" << WinCount[0].second << "局,胜率为：" << (float)WinCount[0].second / TotalCount[0].second * 100 << "%" << std::endl;
		std::cout << "剪刀共出了：" << TotalCount[1].second << "局,共获胜：" << WinCount[1].second << "局,胜率为：" << (float)WinCount[1].second / TotalCount[1].second * 100 << "%" << std::endl;
		std::cout << "布共出了：" << TotalCount[2].second << "局,共获胜：" << WinCount[2].second << "局,胜率为：" << (float)WinCount[2].second / TotalCount[2].second * 100 << "%" << std::endl;
		std::cout << "总共进行了：" << TotalCount[0].second + TotalCount[1].second + TotalCount[2].second << "局,共获胜：" << WinCount[0].second + WinCount[1].second + WinCount[2].second << "局,胜率为：" << (((float)WinCount[0].second + WinCount[1].second + WinCount[2].second) / (TotalCount[0].second + TotalCount[1].second + TotalCount[2].second)) * 100 << "%" << std::endl;
	}
}