#include "Least.h"

Least::Least()
{

}

Quan Least::Next()
{
	int index = TotalCount[0] <= TotalCount[1] ? 0 : 1;
	next = TotalCount[index] <= TotalCount[2] ? (Quan)index : (Quan)2;
	TotalCount[(int)next]++;
	current = (Quan)next;
	return (Quan)next;
}

void Least::Result(bool win)
{
	if (win)
	{
		WinCount[(int)current]++;
	}
}

void Least::Show()
{
	if (TotalCount[0] + TotalCount[1] + TotalCount[2] != 0)
	{
		std::cout << std::endl;
		std::cout << "最少拳策略";
		std::cout << "战绩如下：" << std::endl;
		std::cout << "石头共出了：" << TotalCount[0] << "局,共获胜：" << WinCount[0] << "局,胜率为：" << (float)WinCount[0] / TotalCount[0] * 100 << "%" << std::endl;
		std::cout << "剪刀共出了：" << TotalCount[1] << "局,共获胜：" << WinCount[1] << "局,胜率为：" << (float)WinCount[1] / TotalCount[1] * 100 << "%" << std::endl;
		std::cout << "布共出了：" << TotalCount[2] << "局,共获胜：" << WinCount[2] << "局,胜率为：" << (float)WinCount[2] / TotalCount[2] * 100 << "%" << std::endl;
		std::cout << "总共进行了：" << TotalCount[0] + TotalCount[1] + TotalCount[2] << "局,共获胜：" << WinCount[0] + WinCount[1] + WinCount[2] << "局,胜率为：" << (((float)WinCount[0] + WinCount[1] + WinCount[2]) / (TotalCount[0] + TotalCount[1] + TotalCount[2])) * 100 << "%" << std::endl;
	}
}
