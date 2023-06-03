#include "HighRate.h"
std::vector<std::pair<int, int>> HighRate::TotalCount(3);
std::vector<std::pair<int, int>> HighRate::WinCount(3);
HighRate::HighRate()
{
	winRate.push_back({ 0,0.5 });
	winRate.push_back({ 1,0.5 });
	winRate.push_back({ 2,0.5 });
	std::cout << "当前策略:最高胜率出拳。" << std::endl;
}

Quan HighRate::Next()
{
	next = (Quan)winRate[0].first;
	TotalCount[(int)next].second++;
	current = next;
	return next;
}

void HighRate::Result(bool win)
{
	if (win)
	{
		WinCount[(int)current].second++;
	}
	winRate[0].second = (float)WinCount[(int)current].second / TotalCount[(int)current].second;
	std::sort(winRate.begin(), winRate.end(),
		[&](std::pair<int, float> a, std::pair<int, float> b)
		{
			return a.second > b.second;
		});
}

HighRate::~HighRate()
{
	if (TotalCount[0].second != 2000)
	{
		std::cout << "高胜率策略";
		std::cout << "战绩如下：" << std::endl;
		std::cout << "石头共出了：" << TotalCount[0].second - 2000 << "局,共获胜：" << WinCount[0].second - 1000 << "局,胜率为：" << (((float)WinCount[0].second - 1000) / (TotalCount[0].second - 2000)) * 100 << "%" << std::endl;
		std::cout << "剪刀共出了：" << TotalCount[1].second - 2000 << "局,共获胜：" << WinCount[1].second - 1000 << "局,胜率为：" << (((float)WinCount[1].second - 1000) / (TotalCount[1].second - 2000)) * 100 << "%" << std::endl;
		std::cout << "布共出了：" << TotalCount[2].second - 2000 << "局,共获胜：" << WinCount[2].second - 1000 << "局,胜率为：" << (((float)WinCount[2].second - 1000) / (TotalCount[2].second - 2000)) * 100 << "%" << std::endl;
		std::cout << "总共进行了：" << TotalCount[0].second+TotalCount[1].second+TotalCount[2].second - 6000 << "局,共获胜：" << WinCount[0].second+WinCount[1].second+WinCount[2].second - 3000 << "局,胜率为：" << (((float)WinCount[0].second+WinCount[1].second+WinCount[2].second - 3000) / (TotalCount[0].second+TotalCount[1].second+TotalCount[2].second - 6000)) * 100 << "%" << std::endl;
	}
}