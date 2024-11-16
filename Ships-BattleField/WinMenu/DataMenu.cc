#pragma once

#include "DataMenu.h"
#include "../Alphabet/Alphabet.cc"
#include "../Numbers/Number.cc"

DataMenu::DataMenu(Console& gameConsole, Player &winner) : gameConsole(gameConsole), winner(winner)
{

}

DataMenu::~DataMenu()
{

}

void DataMenu::drawResults()
{
    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 6);

    Alphabet::drawP(getGameConsole().getScreenHandle(), 11, 11, {80, 10});
    Alphabet::drawP(getGameConsole().getScreenHandle(), 11, 11, {79, 10});

    if (getWinner().getID() == 1)
    {
        Number::draw1(getGameConsole().getScreenHandle(), 11, 11, {100, 10});
        Number::draw1(getGameConsole().getScreenHandle(), 11, 11, {99, 10});
    }
    else
    {
        Number::draw2(getGameConsole().getScreenHandle(), 11, 11, {100, 10});
        Number::draw2(getGameConsole().getScreenHandle(), 11, 11, {99, 10});
    }

    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);

    Alphabet::drawW(getGameConsole().getScreenHandle(), 11, 11, {130, 10});
    Alphabet::drawI(getGameConsole().getScreenHandle(), 11, 11, {145, 10});
    Alphabet::drawN(getGameConsole().getScreenHandle(), 11, 11, {160, 10});
    Alphabet::drawS(getGameConsole().getScreenHandle(), 11, 11, {175, 10});

    Alphabet::drawW(getGameConsole().getScreenHandle(), 11, 11, {129, 10});
    Alphabet::drawI(getGameConsole().getScreenHandle(), 11, 11, {144, 10});
    Alphabet::drawN(getGameConsole().getScreenHandle(), 11, 11, {159, 10});
    Alphabet::drawS(getGameConsole().getScreenHandle(), 11, 11, {174, 10});

    Alphabet::drawT(getGameConsole().getScreenHandle(), 9, 9, {50, 30});
    Alphabet::drawO(getGameConsole().getScreenHandle(), 9, 9, {65, 30});
    Alphabet::drawT(getGameConsole().getScreenHandle(), 9, 9, {80, 30});
    Alphabet::drawA(getGameConsole().getScreenHandle(), 9, 9, {95, 30});
    Alphabet::drawL(getGameConsole().getScreenHandle(), 9, 9, {110, 30});

    DataMenu::drawTotal(getWinner().getWins());
}

void DataMenu::drawTotal(int total)
{
    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 6);

    switch (total)
    {
    case 1:
        Number::draw1(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;
    
    case 2:
        Number::draw2(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;

    case 3:
        Number::draw3(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;

    case 4:
        Number::drawLower4(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;

    case 5:
        Number::draw5(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;

    case 6:
        Number::draw6(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;

    case 7:
        Number::draw7(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;

    case 8:
        Number::draw8(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;

    case 9:
        Number::drawLower9(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        break;
    default:
        Number::draw1(getGameConsole().getScreenHandle(), 9, 9, {175, 30});
        Number::draw0(getGameConsole().getScreenHandle(), 9, 9, {140, 30});
        break;
    }
}
