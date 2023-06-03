#include "Random.h"
std::vector<std::pair<int, int>> Random::TotalCount(3);
std::vector<std::pair<int, int>> Random::WinCount(3);
Random::Random()
{
	std::cout << "当前策略:随机出拳。" << std::endl;
}

Quan Random::Next()
{
	next = (Quan)(rand() % 3);
	TotalCount[(int)next].second++;
	current = next;
	return (Quan)next;
}

void Random::Result(bool win)
{
	if (win)
	{
		WinCount[(int)current].second++;
	}
}

Random::~Random()
{
	if (TotalCount[0].second != 0)
	{
		std::cout << "随机策略";
		std::cout << "战绩如下：" << std::endl;
		std::cout << "石头共出了：" << TotalCount[0].second << "局,共获胜：" << WinCount[0].second << "局,胜率为：" << (float)WinCount[0].second / TotalCount[0].second * 100 << "%" << std::endl;
		std::cout << "剪刀共出了：" << TotalCount[1].second << "局,共获胜：" << WinCount[1].second << "局,胜率为：" << (float)WinCount[1].second / TotalCount[1].second * 100 << "%" << std::endl;
		std::cout << "布共出了：" << TotalCount[2].second << "局,共获胜：" << WinCount[2].second << "局,胜率为：" << (float)WinCount[2].second / TotalCount[2].second * 100 << "%" << std::endl;
		std::cout << "总共进行了：" << TotalCount[0].second + TotalCount[1].second + TotalCount[2].second << "局,共获胜：" << WinCount[0].second + WinCount[1].second + WinCount[2].second << "局,胜率为：" << (((float)WinCount[0].second + WinCount[1].second + WinCount[2].second) / (TotalCount[0].second + TotalCount[1].second + TotalCount[2].second)) * 100 << "%" << std::endl;
	}
}