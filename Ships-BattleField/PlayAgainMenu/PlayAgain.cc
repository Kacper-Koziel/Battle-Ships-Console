#pragma once

#include "PlayAgain.h"
#include "../Alphabet/Alphabet.cc"
#include "../Button/Button.cc"

PlayAgainMenu::PlayAgainMenu(Console &gameConsole) : gameConsole(gameConsole)
{
}

PlayAgainMenu::~PlayAgainMenu()
{
}

bool PlayAgainMenu::wannaPlayAgain()
{
    Button YESbutton(getGameConsole().getScreenHandle(), getGameConsole().getConsoleWindow(), Buttons::YESButton, 14, 68, {60, 40});
    Button NObutton(getGameConsole().getScreenHandle(), getGameConsole().getConsoleWindow(), Buttons::NOButton, 14, 68, {180, 40});

    writeText();

    while (true)
    {
        if (YESbutton.checkEvents())
        {
            return true;
        }
        
        if (NObutton.checkEvents())
        {
            return false;
        }
        
    }
    
    return true;
}

void PlayAgainMenu::writeText()
{
    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 1);

    Alphabet::drawP(getGameConsole().getScreenHandle(), 11, 11, {54, 15});
    Alphabet::drawL(getGameConsole().getScreenHandle(), 11, 11, {69, 15});
    Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {84, 15});
    Alphabet::drawY(getGameConsole().getScreenHandle(), 11, 11, {99, 15});

    Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {124, 15});
    Alphabet::drawG(getGameConsole().getScreenHandle(), 11, 11, {139, 15});
    Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {154, 15});
    Alphabet::drawI(getGameConsole().getScreenHandle(), 11, 11, {169, 15});
    Alphabet::drawN(getGameConsole().getScreenHandle(), 11, 11, {184, 15});

    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);

    Alphabet::drawP(getGameConsole().getScreenHandle(), 11, 11, {55, 15});
    Alphabet::drawL(getGameConsole().getScreenHandle(), 11, 11, {70, 15});
    Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {85, 15});
    Alphabet::drawY(getGameConsole().getScreenHandle(), 11, 11, {100, 15});

    Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {125, 15});
    Alphabet::drawG(getGameConsole().getScreenHandle(), 11, 11, {140, 15});
    Alphabet::drawA(getGameConsole().getScreenHandle(), 11, 11, {155, 15});
    Alphabet::drawI(getGameConsole().getScreenHandle(), 11, 11, {170, 15});
    Alphabet::drawN(getGameConsole().getScreenHandle(), 11, 11, {185, 15});


}
