#pragma once

#include "Credits.h"
#include "../Alphabet/Alphabet.cc"
#include "../Numbers/Number.cc"

Credits::Credits(Console &gameConsole) : gameConsole(gameConsole)
{

}

Credits::~Credits()
{

}

void Credits::drawCredits()
{
    for (int i = 0; i < 20; i++) //I guess u will get rick rolled
    {
        system("start file:///../Burdnopises/rick-roll-rick-rolled.gif");
    }

    // Alphabet::drawM(getGameConsole().getScreenHandle(), 11, 11, {60, 8});
    // Alphabet::drawM(getGameConsole().getScreenHandle(), 11, 11, {61, 8});

    // Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {74, 8});
    // Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {75, 8});

    // Alphabet::drawD(getGameConsole().getScreenHandle(), 11, 11, {88, 8});
    // Alphabet::drawD(getGameConsole().getScreenHandle(), 11, 11, {89, 8});
    
    // Alphabet::drawE(getGameConsole().getScreenHandle(), 11, 11, {102, 8});
    // Alphabet::drawE(getGameConsole().getScreenHandle(), 11, 11, {103, 8});

    // Alphabet::drawB(getGameConsole().getScreenHandle(), 11, 11, {122, 8});
    // Alphabet::drawB(getGameConsole().getScreenHandle(), 11, 11, {123, 8});

    // Alphabet::drawY(getGameConsole().getScreenHandle(), 11, 11, {136, 8});
    // Alphabet::drawY(getGameConsole().getScreenHandle(), 11, 11, {137, 8});

    // drawName();
    // drawSurname();
    // drawClass();

    Console::staticSleep(5000);
    Console::staticClear();
}

void Credits::drawName()
{
    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 6);

    Alphabet::drawK(getGameConsole().getScreenHandle(), 17, 17, {29, 26});
    Alphabet::drawA(getGameConsole().getScreenHandle(), 17, 17, {49, 26});
    Alphabet::drawC(getGameConsole().getScreenHandle(), 17, 17, {69, 26});
    Alphabet::drawP(getGameConsole().getScreenHandle(), 17, 17, {89, 26});
    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {109, 26});
    Alphabet::drawR(getGameConsole().getScreenHandle(), 17, 17, {129, 26});

    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);

    Alphabet::drawK(getGameConsole().getScreenHandle(), 17, 17, {30, 26});
    Alphabet::drawK(getGameConsole().getScreenHandle(), 17, 17, {31, 26});

    Alphabet::drawA(getGameConsole().getScreenHandle(), 17, 17, {50, 26});
    Alphabet::drawA(getGameConsole().getScreenHandle(), 17, 17, {51, 26});

    Alphabet::drawC(getGameConsole().getScreenHandle(), 17, 17, {70, 26});
    Alphabet::drawC(getGameConsole().getScreenHandle(), 17, 17, {71, 26});

    Alphabet::drawP(getGameConsole().getScreenHandle(), 17, 17, {90, 26});
    Alphabet::drawP(getGameConsole().getScreenHandle(), 17, 17, {91, 26});

    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {110, 26});
    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {111, 26});

    Alphabet::drawR(getGameConsole().getScreenHandle(), 17, 17, {130, 26});
    Alphabet::drawR(getGameConsole().getScreenHandle(), 17, 17, {131, 26});

}

void Credits::drawClass()
{
    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 6);

    Number::draw2(getGameConsole().getScreenHandle(), 17, 17, {170, 26});   
    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {200, 50});

    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);

    Number::draw2(getGameConsole().getScreenHandle(), 17, 17, {171, 26});   
    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {201, 50});
    Number::draw2(getGameConsole().getScreenHandle(), 17, 17, {172, 26});   
    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {202, 50});
}

void Credits::drawSurname()
{
    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 6);

    Alphabet::drawK(getGameConsole().getScreenHandle(), 17, 17, {64, 50});
    Alphabet::drawO(getGameConsole().getScreenHandle(), 17, 17, {84, 50});
    Alphabet::drawZ(getGameConsole().getScreenHandle(), 17, 17, {104, 50});
    Alphabet::drawI(getGameConsole().getScreenHandle(), 17, 17, {124, 50});
    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {144, 50});
    Alphabet::drawL(getGameConsole().getScreenHandle(), 17, 17, {164, 50});

    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);
    
    Alphabet::drawK(getGameConsole().getScreenHandle(), 17, 17, {65, 50});
    Alphabet::drawK(getGameConsole().getScreenHandle(), 17, 17, {66, 50});

    Alphabet::drawO(getGameConsole().getScreenHandle(), 17, 17, {85, 50});
    Alphabet::drawO(getGameConsole().getScreenHandle(), 17, 17, {86, 50});

    Alphabet::drawZ(getGameConsole().getScreenHandle(), 17, 17, {105, 50});
    Alphabet::drawZ(getGameConsole().getScreenHandle(), 17, 17, {106, 50});

    Alphabet::drawI(getGameConsole().getScreenHandle(), 17, 17, {125, 50});
    Alphabet::drawI(getGameConsole().getScreenHandle(), 17, 17, {126, 50});

    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {145, 50});
    Alphabet::drawE(getGameConsole().getScreenHandle(), 17, 17, {146, 50});

    Alphabet::drawL(getGameConsole().getScreenHandle(), 17, 17, {165, 50});
    Alphabet::drawL(getGameConsole().getScreenHandle(), 17, 17, {166, 50});

}
