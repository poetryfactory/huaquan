#include "Player.h"
Quan Player::Next()
{
	int a;
	std::cout << "������ȭ�ͣ�0-ʯͷ 1-���� 2-��" << std::endl;
	std::cin >> a;
	next = (Quan)a;
	TotalCount[(int)next]++;
	current = next;
	return next;
}

void Player::Result(bool win)
{
	if (win)
	{
		WinCount[(int)current]++;
	}
}

void Player::Show()
{
	if (TotalCount[0]+TotalCount[1]+TotalCount[2]!=0)
	{
		std::cout << std::endl;
		std::cout << "����ս�����£�" << std::endl;
		std::cout << "ʯͷ�����ˣ�" << TotalCount[0] << "��,����ʤ��" << WinCount[0] << "��,ʤ��Ϊ��" << (float)WinCount[0] / TotalCount[0] * 100 << "%" << std::endl;
		std::cout << "���������ˣ�" << TotalCount[1] << "��,����ʤ��" << WinCount[1] << "��,ʤ��Ϊ��" << (float)WinCount[1] / TotalCount[1] * 100 << "%" << std::endl;
		std::cout << "�������ˣ�" << TotalCount[2] << "��,����ʤ��" << WinCount[2] << "��,ʤ��Ϊ��" << (float)WinCount[2] / TotalCount[2] * 100 << "%" << std::endl;
		std::cout << "�ܹ������ˣ�" << TotalCount[0] + TotalCount[1] + TotalCount[2] << "��,����ʤ��" << WinCount[0] + WinCount[1] + WinCount[2] << "��,ʤ��Ϊ��" << (((float)WinCount[0] + WinCount[1] + WinCount[2]) / (TotalCount[0] + TotalCount[1] + TotalCount[2])) * 100 << "%" << std::endl;
	}
}