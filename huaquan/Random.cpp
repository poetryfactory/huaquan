#include "Random.h"
std::vector<std::pair<int, int>> Random::TotalCount(3);
std::vector<std::pair<int, int>> Random::WinCount(3);
Random::Random()
{
	std::cout << "��ǰ����:�����ȭ��" << std::endl;
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
		std::cout << "�������";
		std::cout << "ս�����£�" << std::endl;
		std::cout << "ʯͷ�����ˣ�" << TotalCount[0].second << "��,����ʤ��" << WinCount[0].second << "��,ʤ��Ϊ��" << (float)WinCount[0].second / TotalCount[0].second * 100 << "%" << std::endl;
		std::cout << "���������ˣ�" << TotalCount[1].second << "��,����ʤ��" << WinCount[1].second << "��,ʤ��Ϊ��" << (float)WinCount[1].second / TotalCount[1].second * 100 << "%" << std::endl;
		std::cout << "�������ˣ�" << TotalCount[2].second << "��,����ʤ��" << WinCount[2].second << "��,ʤ��Ϊ��" << (float)WinCount[2].second / TotalCount[2].second * 100 << "%" << std::endl;
		std::cout << "�ܹ������ˣ�" << TotalCount[0].second + TotalCount[1].second + TotalCount[2].second << "��,����ʤ��" << WinCount[0].second + WinCount[1].second + WinCount[2].second << "��,ʤ��Ϊ��" << (((float)WinCount[0].second + WinCount[1].second + WinCount[2].second) / (TotalCount[0].second + TotalCount[1].second + TotalCount[2].second)) * 100 << "%" << std::endl;
	}
}