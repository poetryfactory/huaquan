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
		std::cout << "����ȭ����";
		std::cout << "ս�����£�" << std::endl;
		std::cout << "ʯͷ�����ˣ�" << TotalCount[0] << "��,����ʤ��" << WinCount[0] << "��,ʤ��Ϊ��" << (float)WinCount[0] / TotalCount[0] * 100 << "%" << std::endl;
		std::cout << "���������ˣ�" << TotalCount[1] << "��,����ʤ��" << WinCount[1] << "��,ʤ��Ϊ��" << (float)WinCount[1] / TotalCount[1] * 100 << "%" << std::endl;
		std::cout << "�������ˣ�" << TotalCount[2] << "��,����ʤ��" << WinCount[2] << "��,ʤ��Ϊ��" << (float)WinCount[2] / TotalCount[2] * 100 << "%" << std::endl;
		std::cout << "�ܹ������ˣ�" << TotalCount[0] + TotalCount[1] + TotalCount[2] << "��,����ʤ��" << WinCount[0] + WinCount[1] + WinCount[2] << "��,ʤ��Ϊ��" << (((float)WinCount[0] + WinCount[1] + WinCount[2]) / (TotalCount[0] + TotalCount[1] + TotalCount[2])) * 100 << "%" << std::endl;
	}
}