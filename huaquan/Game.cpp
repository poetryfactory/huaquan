#include "Game.h"
Game::Game(BaseRule* s1, BaseRule* s2) :br1(*s1), br2(*s2)
{
    std::cout << "当前对局：" << std::endl;
};

void Game::Play(int n)
{
    system("cls");
    if (br1.getTotal()[0] != 0)
    {
        int c;
        std::cout << "=================================================================" << std::endl;
        std::cout << "                   是否清除玩家1记录？0-否 1-是                       " << std::endl;
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
        std::cout << "                   是否清除玩家2记录？0-否 1-是                       " << std::endl;
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
        std::cout << "玩家1出的拳型为" << mp1[(int)q1] << " ";
		Quan q2 = br2.Next();
        std::cout << "玩家2出的拳型为" << mp1[(int)q2] << " ";
        bool win1 = (q1 == Quan::Rock && q2 == Quan::Scissor) ||
            (q1 == Quan::Scissor && q2 == Quan::Paper) ||
            (q1 == Quan::Paper && q2 == Quan::Rock);
        bool win2 = (q2 == Quan::Rock && q1 == Quan::Scissor) ||
            (q2 == Quan::Scissor && q1 == Quan::Paper) ||
            (q2 == Quan::Paper && q1 == Quan::Rock);
        br1.Result(win1);
        br2.Result(win2);
        if (win1) {
            std::cout << "玩家1获胜！" << std::endl;
        }
        else if (win2) {
            std::cout << "玩家2获胜！" << std::endl;
        }
        else {
            std::cout << "平局！" << std::endl;
        }
	}
    br1.Show();
    br2.Show();
}