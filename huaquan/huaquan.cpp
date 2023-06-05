#include <iostream>
#include <time.h>
#include"Game.h"
#include"HighRate.h"
#include"Random.h"
#include"LastWin.h"
#include"Least.h"
#include<stdlib.h>
#include<string>
#include<math.h>
#include"Player.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int mode = -1;
    Random* random = new Random;
    HighRate* hr = new HighRate;
    LastWin* lw = new LastWin;
    Least* le = new Least;
    Player* p = new Player;
    std::unordered_map<int, BaseRule*> mp2 = { {0,random},{1,hr},{2,lw},{3,le} };
    std::unordered_map<BaseRule*,std::string> mp3 = { {random,"随机策略  "},{hr,"  高胜率  "},{lw,"  赢上局  "},{le,"  最少拳  "}};
    while (mode != 0 && mode != 1)
    {
        system("cls");
        std::cout << "============================================" << std::endl;
        std::cout << "     请输入模式：0-人机  1-不同ai对战     " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cin >> mode;
        switch (mode)
        {
        case 0:
        {
            system("cls");
            std::cout << "=================================================================" << std::endl;
            std::cout << "                        你选择了--人机对战                       " << std::endl;
            std::cout << "=================================================================" << std::endl;
            int c = -1,t;
            std::cout << "=================================================================" << std::endl;
            std::cout << "=     请输入ai策略(空格隔开): 0-随机 1-高胜率 2-赢上局 3-最少拳    =" << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cin >> c;
            if (c < 0 || c>3)
            {
                std::cout << "ai策略输入有误，已重置为随机出拳！" << std::endl;
                c = 0;
            }
            std::cout << "=================================================================" << std::endl;
            std::cout << "                        请输入局数                              " << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cin >> t;
            Game game3(p, mp2[c]);
            game3.Play(abs(t));
            system("pause");
            mode = -1;
            break;
        }
        case 1:
        {
            int a, b, t;
            system("cls");
            std::cout << "=================================================================" << std::endl;
            std::cout << "                         你选择了--ai对战                       " << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cout << "      请输入ai策略(空格隔开): 0-随机 1-高胜率 2-赢上局 3-最少拳   " << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cin >> a >> b;
            if (a < 0 || a>3)
            {
                std::cout << "ai1策略输入有误，已重置为随机出拳！" << std::endl;
                a = 0;
            }
            if (b < 0 || b>3)
            {
                std::cout << "ai2策略输入有误，已重置为随机出拳！" << std::endl;
                b = 0;
            }
            std::cout << "=================================================================" << std::endl;
            std::cout << " 当前对局:" << mp3[mp2[a]] << "对战  " << mp3[mp2[b]] << "            " << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cout << "                        请输入局数                              " << std::endl;
            std::cout << "=================================================================" << std::endl;
            std::cin >> t;
            Game game3(mp2[a], mp2[b]);
            game3.Play(abs(t));
            system("pause");
            mode = -1;
            break;
        }
        default:
        {
            std::cout << "输入有误，请重新输入" << std::endl;
        }
        }
    }
    delete random;
    delete hr;
    delete lw;
    delete le;
}

