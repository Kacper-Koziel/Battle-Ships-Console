#pragma once
#include "Intro.h"

#include "../Alphabet/Alphabet.cc"
#include "../Numbers/Number.cc"
#include "../ButtonsNamespace/Buttons.cc"
#include "../Button/Button.cc"


Intro::Intro()
{

}

Intro::Intro(Console &window) : window(window) {}

Intro::~Intro()
{
    
}

void Intro::drawTitle()
{
    this->window.setFontColor(1);
    Alphabet::drawS(window.getScreenHandle(), 11, 11, {{87}, {8}});
    this->window.setFontColor(7);
    Alphabet::drawS(window.getScreenHandle(), 11, 11, {{88}, {8}});
    Alphabet::drawS(window.getScreenHandle(), 11, 11, {{89}, {8}});

    this->window.setFontColor(1);
    Alphabet::drawH(window.getScreenHandle(), 11, 11, {{106}, {8}});
    this->window.setFontColor(7);
    Alphabet::drawH(window.getScreenHandle(), 11, 11, {{107}, {8}});
    Alphabet::drawH(window.getScreenHandle(), 11, 11, {{108}, {8}});


    this->window.setFontColor(1);
    Alphabet::drawI(window.getScreenHandle(), 11, 11, {{123}, {8}});
    this->window.setFontColor(7);  
    Alphabet::drawI(window.getScreenHandle(), 11, 11, {{124}, {8}});
    Alphabet::drawI(window.getScreenHandle(), 11, 11, {{125}, {8}});

    this->window.setFontColor(1);
    Alphabet::drawP(window.getScreenHandle(), 11, 11, {{138}, {8}});
    this->window.setFontColor(7);
    Alphabet::drawP(window.getScreenHandle(), 11, 11, {{139}, {8}});
    Alphabet::drawP(window.getScreenHandle(), 11, 11, {{140}, {8}});

    this->window.setFontColor(1);
    Alphabet::drawS(window.getScreenHandle(), 11, 11, {{155}, {8}});
    this->window.setFontColor(7);
    Alphabet::drawS(window.getScreenHandle(), 11, 11, {{156}, {8}});
    Alphabet::drawS(window.getScreenHandle(), 11, 11, {{157}, {8}});
}

int Intro::collectButtonsData(Console &window)
{
    Intro* copy = new Intro(window);
    
    Button* pvpButton = new Button(this->window.getScreenHandle(), this->window.getConsoleWindow(), &Buttons::PvPButton, 10, 78, {117, 24});
    Button* pvAiButton = new Button(this->window.getScreenHandle(), this->window.getConsoleWindow(), &Buttons::PvAiButton, 10, 78, {117, 38});
    Button* creditsButton = new Button(this->window.getScreenHandle(), this->window.getConsoleWindow(), &Buttons::CreditsButton, 10, 78, {117, 52});

    // Button pvpButton(this->window.getScreenHandle(), this->window.getConsoleWindow(), &Buttons::PvPButton, 10, 78, {117, 24});
    // Button pvAiButton(this->window.getScreenHandle(), this->window.getConsoleWindow(), &Buttons::PvAiButton, 10, 78, {117, 38});
    // Button creditsButton(this->window.getScreenHandle(), this->window.getConsoleWindow(), &Buttons::CreditsButton, 10, 78, {117, 52});

    std::pair<Button*, int> pvpPair(pvpButton, 1);
    std::pair<Button*, int> pvAiPair(pvAiButton, 2);
    std::pair<Button*, int> creditsPair(creditsButton, 3);

    while(true)
    {

        if (pvpPair.first->checkEvents(copy, pvAiButton, creditsButton))
        {
            return pvpPair.second;
        }

        if (pvAiPair.first->checkEvents(copy, pvpButton, creditsButton))
        {
            return pvAiPair.second;
        }

        if (creditsPair.first->checkEvents(copy, pvpButton, pvAiButton))
        {
            return creditsPair.second;
        }
    }

    delete copy;
    delete pvpButton;
    delete pvAiButton;
    delete creditsButton;

    copy = nullptr;
    pvpButton = nullptr;
    pvAiButton = nullptr;
    creditsButton = nullptr;

    return 0;
}

int Intro::playIntro()
{
    this->window.setTitle(L"Ships-menu");


    while (this->window.isOpen())
    {
        int data = collectButtonsData(this->window);

        if (data != 0)
        {
            return data;
        }
        
    }
    

    return 0;
}
