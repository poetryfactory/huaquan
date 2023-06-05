#include "LastWin.h"

LastWin::LastWin()
{

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
	TotalCount[(int)next]++;
	current = (Quan)next;
	return (Quan)next;
}

void LastWin::Result(bool win)
{
	if (win)
	{
		WinCount[(int)current]++;
	}
}

void LastWin::Show()
{
	if (TotalCount[0] != 0)
	{
		std::cout << std::endl;
		std::cout << "赢上局策略";
		std::cout << "战绩如下：" << std::endl;
		std::cout << "石头共出了：" << TotalCount[0] << "局,共获胜：" << WinCount[0] << "局,胜率为：" << (float)WinCount[0] / TotalCount[0] * 100 << "%" << std::endl;
		std::cout << "剪刀共出了：" << TotalCount[1] << "局,共获胜：" << WinCount[1] << "局,胜率为：" << (float)WinCount[1] / TotalCount[1] * 100 << "%" << std::endl;
		std::cout << "布共出了：" << TotalCount[2] << "局,共获胜：" << WinCount[2] << "局,胜率为：" << (float)WinCount[2] / TotalCount[2] * 100 << "%" << std::endl;
		std::cout << "总共进行了：" << TotalCount[0] + TotalCount[1] + TotalCount[2] << "局,共获胜：" << WinCount[0] + WinCount[1] + WinCount[2] << "局,胜率为：" << (((float)WinCount[0] + WinCount[1] + WinCount[2]) / (TotalCount[0] + TotalCount[1] + TotalCount[2])) * 100 << "%" << std::endl;
	}
}