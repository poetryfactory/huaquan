#include <iostream>
#include <time.h>
#include"Game.h"
#include"HighRate.h"
#include"Random.h"
#include"LastWin.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Random::TotalCount[0] = { 0,0 };
    Random::WinCount[0] = { 0,0 };
    Random::TotalCount[1] = { 1,0 };
    Random::WinCount[1] = { 1,0 };
    Random::TotalCount[2] = { 2,0 };
    Random::WinCount[2] = { 2,0 };
    LastWin::TotalCount[0] = { 0,0 };
    LastWin::WinCount[0] = { 0,0 };
    LastWin::TotalCount[1] = { 1,0 };
    LastWin::WinCount[1] = { 1,0 };
    LastWin::TotalCount[2] = { 2,0 };
    LastWin::WinCount[2] = { 2,0 };
    HighRate::TotalCount[0] = { 0,2000 };
    HighRate::WinCount[0] = { 0,1000 };
    HighRate::TotalCount[1] = { 1,2000 };
    HighRate::WinCount[1] = { 1,1000 };
    HighRate::TotalCount[2] = { 2,2000 };
    HighRate::WinCount[2] = { 2,1000 };
    Random* random = new Random;
    Random* random1 = new Random;
    HighRate* hr = new HighRate;
    HighRate* hr1 = new HighRate;
    LastWin* lw = new LastWin;
    LastWin* lw1 = new LastWin;
    Game game3(lw1, hr1);
    game3.Play(1000000);
    delete random;
    delete random1;
    delete hr;
    delete hr1;
    delete lw;
    delete lw1;
}

