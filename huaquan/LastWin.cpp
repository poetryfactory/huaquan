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
		std::cout << "Ӯ�Ͼֲ���";
		std::cout << "ս�����£�" << std::endl;
		std::cout << "ʯͷ�����ˣ�" << TotalCount[0] << "��,����ʤ��" << WinCount[0] << "��,ʤ��Ϊ��" << (float)WinCount[0] / TotalCount[0] * 100 << "%" << std::endl;
		std::cout << "���������ˣ�" << TotalCount[1] << "��,����ʤ��" << WinCount[1] << "��,ʤ��Ϊ��" << (float)WinCount[1] / TotalCount[1] * 100 << "%" << std::endl;
		std::cout << "�������ˣ�" << TotalCount[2] << "��,����ʤ��" << WinCount[2] << "��,ʤ��Ϊ��" << (float)WinCount[2] / TotalCount[2] * 100 << "%" << std::endl;
		std::cout << "�ܹ������ˣ�" << TotalCount[0] + TotalCount[1] + TotalCount[2] << "��,����ʤ��" << WinCount[0] + WinCount[1] + WinCount[2] << "��,ʤ��Ϊ��" << (((float)WinCount[0] + WinCount[1] + WinCount[2]) / (TotalCount[0] + TotalCount[1] + TotalCount[2])) * 100 << "%" << std::endl;
	}
}