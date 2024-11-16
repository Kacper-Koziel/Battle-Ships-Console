#pragma once

#include "Board.h"
#include "../Console/Console.cc"

Board::Board(HANDLE& screenHandle, short offset) : screenHandle(screenHandle), offset(offset) 
{
    this->hiddenShips->resize(10);

    for(std::vector<bool>& hidden : *this->hiddenShips)
    {
        hidden.resize(10, false);
    }

    this->widthPoints.resize(10);

    for (short i = 0; i < 10; i++)
    {
        this->widthPoints.at(i) = 16 + getOffset() + (i * 8);
    }
    
    this->heightPoints.resize(10);

    for (short i = 0; i < 10; i++)
    {
        this->heightPoints.at(i) = static_cast<int>(10 + (i * 5));
    }

    this->ships->resize(10);

    this->hasBeenShoot->resize(10);
    
    for(std::vector<bool>& shoot : *this->hasBeenShoot)
    {
        shoot.resize(10, false);
    }
}

Board::~Board()
{
    delete this->hiddenShips;
    delete this->ships;
    delete this->hasBeenShoot;

    hasBeenShoot = nullptr;
    hiddenShips = nullptr;
    ships = nullptr;
}

void Board::clearHiddenShips()
{
    this->hiddenShips->clear();
    this->hiddenShips->resize(10);

    for(std::vector<bool>& hidden : *this->hiddenShips)
    {
        hidden.resize(10, false);
    }
}

void Board::setShipValue(std::shared_ptr<Base> value, int index)
{
    (*this->ships)[index] = value;
}

void Board::synchronizePoints()
{
    this->widthPoints.clear();
    this->widthPoints.resize(10);

    for (short i = 0; i < 10; i++)
    {
        this->widthPoints.at(i) = 16 + getOffset() + (i * 8);
    }
}

void Board::synchronizeShips()
{
    for(std::shared_ptr<Base> ship : *getShips())
    {
        ship->setStart({ship->getConstStart().getX() +  getOffset() - 10, ship->getStart().getY()});
        ship->setEnd({ship->getConstEnd().getX() + getOffset() - 10, ship->getEnd().getY()});
    }
}

void Board::synchronizeSigns()
{

}

void Board::drawBoard()
{
    short offset = getOffset();

    Alphabet::drawA(getScreenHandle(), 3, 4, {16 + offset, 4});
    Alphabet::drawLowerB(getScreenHandle(), 3, 4, {24 + offset, 4});
    Alphabet::drawLowerC(getScreenHandle(), 3, 4, {32 + offset, 4});
    Alphabet::drawD(getScreenHandle(), 3, 4, {40 + offset, 4});
    Alphabet::drawE(getScreenHandle(), 3, 4, {48 + offset, 4});
    Alphabet::drawF(getScreenHandle(), 3, 4, {56 + offset, 4});
    Alphabet::drawLowerG(getScreenHandle(), 3, 4, {64 + offset, 4});
    Alphabet::drawH(getScreenHandle(), 3, 4, {72 + offset, 4});
    Alphabet::drawI(getScreenHandle(), 3, 4, {80 + offset, 4});
    Alphabet::drawLowerJ(getScreenHandle(), 3, 4, {88 + offset, 4});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawTopBlockLine(getScreenHandle(), {{13 + offset, 7}, {92 + offset, 7}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower1(getScreenHandle(), 3, 4, {8 + offset, 10});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 12}, {92 + offset, 12}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower2(getScreenHandle(), 3, 4, {8 + offset, 15});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 17}, {92 + offset, 17}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower3(getScreenHandle(), 3, 4, {8 + offset, 20});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 22}, {92 + offset, 22}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower4(getScreenHandle(), 3, 4, {8 + offset, 25});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 27}, {92 + offset, 27}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower5(getScreenHandle(), 3, 4, {8 + offset, 30});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 32}, {92 + offset, 32}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower6(getScreenHandle(), 3, 4, {8 + offset, 35});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 37}, {92 + offset, 37}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower7(getScreenHandle(), 3, 4, {8 + offset, 40});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 42}, {92 + offset, 42}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower8(getScreenHandle(), 3, 4, {8 + offset, 45});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 47}, {92 + offset, 47}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower9(getScreenHandle(), 3, 4, {8 + offset, 50});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 52}, {92 + offset, 52}});
    Console::staticSetFontColor(getScreenHandle(), 7);

    Number::drawLower1(getScreenHandle(), 3, 4, {4 + offset, 56});
    Number::drawLower0(getScreenHandle(), 3, 4, {8 + offset, 56});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawBottomBlockLine(getScreenHandle(), {{13 + offset, 57}, {92 + offset, 57}});
    Console::staticSetFontColor(getScreenHandle(), 7);


    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawLine(getScreenHandle(), {{12 + offset, 7}, {12 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{20 + offset, 7}, {20 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{28 + offset, 7}, {28 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{36 + offset, 7}, {36 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{44 + offset, 7}, {44 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{52 + offset, 7}, {52 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{60 + offset, 7}, {60 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{68 + offset, 7}, {68 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{76 + offset, 7}, {76 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{84 + offset, 7}, {84 + offset, 57}});
    Line::drawLine(getScreenHandle(), {{92 + offset, 7}, {92 + offset, 57}});
    Console::staticSetFontColor(getScreenHandle(), 7);
}

void Board::drawPoints()
{
    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            Line::drawLine(getScreenHandle(), {{getWidthPoints().at(j), getHeightPoints().at(i)}, {getWidthPoints().at(j), getHeightPoints().at(i)}});
        }
        
    }
    
}

void Board::drawShips()
{
    for(int i = 0; i < this->ships->size(); i++)
    {
        if ((*this->ships)[i] != nullptr)
        {
            drawShipDirection(this->ships->at(i));
        }
    }
}

void Board::drawDefeatedShips()
{
    for(int i = 0; i < getDefeatedShips()->size(); i++)
    {
        drawShipDirection(getDefeatedShips()->at(i));
    }
}

void Board::drawShipDirection(std::shared_ptr<Base> ship)
{
    switch (ship->getDirection())
    {
    case 'N':
        ship->drawShipN();
        break;
    
    case 'E':
        ship->drawShipE();
        break;

    case 'S':
        ship->drawShipS();
        break;

    case 'W':
        ship->drawShipW();
        break;
    default:
        ship->drawShipN();
        break;
    }
}

void Board::drawSigns()
{
    for(auto& draw : *getSigns())
    {
        draw();
    }
}

void Board::drawOwnSigns()
{
    for(auto& draw : *getOwnBoardSigns())
    {
        draw();
    }
}

void Board::clearData()
{
    clearHiddenShips();
    getShips()->clear();
    getShips()->resize(10);
    
    for (int i = 0; i < getShoots()->size(); i++)
    {
        getShoots()->at(i).clear();
        getShoots()->at(i).resize(10);
    }

    getSigns()->clear();
    
    
}
