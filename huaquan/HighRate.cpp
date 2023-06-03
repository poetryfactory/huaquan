#include "HighRate.h"
std::vector<std::pair<int, int>> HighRate::TotalCount(3);
std::vector<std::pair<int, int>> HighRate::WinCount(3);
HighRate::HighRate()
{
	winRate.push_back({ 0,0.5 });
	winRate.push_back({ 1,0.5 });
	winRate.push_back({ 2,0.5 });
	std::cout << "��ǰ����:���ʤ�ʳ�ȭ��" << std::endl;
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
		std::cout << "��ʤ�ʲ���";
		std::cout << "ս�����£�" << std::endl;
		std::cout << "ʯͷ�����ˣ�" << TotalCount[0].second - 2000 << "��,����ʤ��" << WinCount[0].second - 1000 << "��,ʤ��Ϊ��" << (((float)WinCount[0].second - 1000) / (TotalCount[0].second - 2000)) * 100 << "%" << std::endl;
		std::cout << "���������ˣ�" << TotalCount[1].second - 2000 << "��,����ʤ��" << WinCount[1].second - 1000 << "��,ʤ��Ϊ��" << (((float)WinCount[1].second - 1000) / (TotalCount[1].second - 2000)) * 100 << "%" << std::endl;
		std::cout << "�������ˣ�" << TotalCount[2].second - 2000 << "��,����ʤ��" << WinCount[2].second - 1000 << "��,ʤ��Ϊ��" << (((float)WinCount[2].second - 1000) / (TotalCount[2].second - 2000)) * 100 << "%" << std::endl;
		std::cout << "�ܹ������ˣ�" << TotalCount[0].second+TotalCount[1].second+TotalCount[2].second - 6000 << "��,����ʤ��" << WinCount[0].second+WinCount[1].second+WinCount[2].second - 3000 << "��,ʤ��Ϊ��" << (((float)WinCount[0].second+WinCount[1].second+WinCount[2].second - 3000) / (TotalCount[0].second+TotalCount[1].second+TotalCount[2].second - 6000)) * 100 << "%" << std::endl;
	}
}