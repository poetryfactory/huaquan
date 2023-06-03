#include "Game.h"
Game::Game(BaseRule* s1, BaseRule* s2) :br1(*s1), br2(*s2)
{
    std::cout << "Game:" << std::endl;
};

void Game::Play(int n)
{
	for (int i = 0; i < n; i++)
	{
		Quan q1 = br1.Next();
		Quan q2 = br2.Next();
        bool win1 = (q1 == Quan::Rock && q2 == Quan::Scissor) ||
            (q1 == Quan::Scissor && q2 == Quan::Paper) ||
            (q1 == Quan::Paper && q2 == Quan::Rock);
        bool win2 = (q2 == Quan::Rock && q1 == Quan::Scissor) ||
            (q2 == Quan::Scissor && q1 == Quan::Paper) ||
            (q2 == Quan::Paper && q1 == Quan::Rock);
        br1.Result(win1);
        br2.Result(win2);
        /*if (win1) {
            std::cout << "Player 1 wins!" << std::endl;
        }
        else if (win2) {
            std::cout << "Player 2 wins!" << std::endl;
        }
        else {
            std::cout << "Tie!" << std::endl;
        }*/
	}
}