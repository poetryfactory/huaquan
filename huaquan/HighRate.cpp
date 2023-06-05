#include "HighRate.h"
HighRate::HighRate()
{
	winRate[0]=0.5f;
	winRate[1]=0.5f;
	winRate[2]=0.5f;
	TotalCount[0] = 2000;
	TotalCount[1] = 2000;
	TotalCount[2] = 2000;
	WinCount[0] = 1000;
	WinCount[1] = 1000;
	WinCount[2] = 1000;
}

Quan HighRate::Next()
{
	int index = winRate[0] <= winRate[1] ? 1 : 0;
	next = winRate[index] <= winRate[2] ? (Quan)2 : (Quan)index;
	TotalCount[(int)next]++;
	current = next;
	return next;
}

void HighRate::Result(bool win)
{
	if (win)
	{
		WinCount[(int)current]++;
	}
	winRate[(int)current] = (float)WinCount[(int)current] / TotalCount[(int)current];
}

void HighRate::clear()
{
	for (int i = 0;i < TotalCount.size();++i)
	{
		TotalCount[i] = 2000;
		WinCount[i] = 1000;
		winRate[i] = 0.5;
	}
}


void HighRate::Show()
{
	if (TotalCount[0] + TotalCount[1] + TotalCount[2] != 6000)
	{
		std::cout << std::endl;
		std::cout << "��ʤ�ʲ���";
		std::cout << "ս�����£�" << std::endl;
		std::cout << "ʯͷ�����ˣ�" << TotalCount[0] - 2000 << "��,����ʤ��" << WinCount[0] - 1000 << "��,ʤ��Ϊ��" << (((float)WinCount[0] - 1000) / (TotalCount[0] - 2000)) * 100 << "%" << std::endl;
		std::cout << "���������ˣ�" << TotalCount[1] - 2000 << "��,����ʤ��" << WinCount[1] - 1000 << "��,ʤ��Ϊ��" << (((float)WinCount[1] - 1000) / (TotalCount[1] - 2000)) * 100 << "%" << std::endl;
		std::cout << "�������ˣ�" << TotalCount[2] - 2000 << "��,����ʤ��" << WinCount[2] - 1000 << "��,ʤ��Ϊ��" << (((float)WinCount[2] - 1000) / (TotalCount[2] - 2000)) * 100 << "%" << std::endl;
		std::cout << "�ܹ������ˣ�" << TotalCount[0]+TotalCount[1]+TotalCount[2] - 6000 << "��,����ʤ��" << WinCount[0]+WinCount[1]+WinCount[2] - 3000 << "��,ʤ��Ϊ��" << (((float)WinCount[0]+WinCount[1]+WinCount[2] - 3000) / (TotalCount[0]+TotalCount[1]+TotalCount[2] - 6000)) * 100 << "%" << std::endl;
	}
}