#include "Game.h"
Game::Game(BaseRule* s1, BaseRule* s2) :br1(*s1), br2(*s2)
{
    std::cout << "��ǰ�Ծ֣�" << std::endl;
};

void Game::Play(int n)
{
    system("cls");
    if (br1.getTotal()[0] != 0)
    {
        int c;
        std::cout << "=================================================================" << std::endl;
        std::cout << "                   �Ƿ�������1��¼��0-�� 1-��                       " << std::endl;
        std::cout << "=================================================================" << std::endl;
        std::cin >> c;
        if (c)
        {
            br1.clear();
        }
    }
    if (br2.getTotal()[0] != 0)
    {
        int c;
        std::cout << "=================================================================" << std::endl;
        std::cout << "                   �Ƿ�������2��¼��0-�� 1-��                       " << std::endl;
        std::cout << "=================================================================" << std::endl;
        std::cin >> c;
        if (c)
        {
            br2.clear();
        }
    }
	for (int i = 0; i < n; i++)
	{
		Quan q1 = br1.Next();
        std::cout << "���1����ȭ��Ϊ" << mp1[(int)q1] << " ";
		Quan q2 = br2.Next();
        std::cout << "���2����ȭ��Ϊ" << mp1[(int)q2] << " ";
        bool win1 = (q1 == Quan::Rock && q2 == Quan::Scissor) ||
            (q1 == Quan::Scissor && q2 == Quan::Paper) ||
            (q1 == Quan::Paper && q2 == Quan::Rock);
        bool win2 = (q2 == Quan::Rock && q1 == Quan::Scissor) ||
            (q2 == Quan::Scissor && q1 == Quan::Paper) ||
            (q2 == Quan::Paper && q1 == Quan::Rock);
        br1.Result(win1);
        br2.Result(win2);
        if (win1) {
            std::cout << "���1��ʤ��" << std::endl;
        }
        else if (win2) {
            std::cout << "���2��ʤ��" << std::endl;
        }
        else {
            std::cout << "ƽ�֣�" << std::endl;
        }
	}
    br1.Show();
    br2.Show();
}