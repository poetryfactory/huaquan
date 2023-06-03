#include "LastWin.h"
std::vector<std::pair<int, int>> LastWin::TotalCount(3);
std::vector<std::pair<int, int>> LastWin::WinCount(3);
LastWin::LastWin()
{
	std::cout << "��ǰ����:ʹ��Ӯ����һ�ֵĳ�ȭ��" << std::endl;
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
		std::cout << "Ӯ�Ͼֲ���";
		std::cout << "ս�����£�" << std::endl;
		std::cout << "ʯͷ�����ˣ�" << TotalCount[0].second << "��,����ʤ��" << WinCount[0].second << "��,ʤ��Ϊ��" << (float)WinCount[0].second / TotalCount[0].second * 100 << "%" << std::endl;
		std::cout << "���������ˣ�" << TotalCount[1].second << "��,����ʤ��" << WinCount[1].second << "��,ʤ��Ϊ��" << (float)WinCount[1].second / TotalCount[1].second * 100 << "%" << std::endl;
		std::cout << "�������ˣ�" << TotalCount[2].second << "��,����ʤ��" << WinCount[2].second << "��,ʤ��Ϊ��" << (float)WinCount[2].second / TotalCount[2].second * 100 << "%" << std::endl;
		std::cout << "�ܹ������ˣ�" << TotalCount[0].second + TotalCount[1].second + TotalCount[2].second << "��,����ʤ��" << WinCount[0].second + WinCount[1].second + WinCount[2].second << "��,ʤ��Ϊ��" << (((float)WinCount[0].second + WinCount[1].second + WinCount[2].second) / (TotalCount[0].second + TotalCount[1].second + TotalCount[2].second)) * 100 << "%" << std::endl;
	}
}