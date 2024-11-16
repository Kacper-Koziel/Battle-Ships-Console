#pragma once

#include "ShootMenu.h"
#include "../Ships/Ships.h"
#include "../Message/Message.cc"

ShootMenu::ShootMenu(Console& gameConsole, std::vector<Player>& players) : gameConsole(gameConsole), players(players)
{
    this->boardTemplate = new Board(getGameConsole().getScreenHandle(), 130);
}

ShootMenu::~ShootMenu()
{
    delete this->boardTemplate;

    this->boardTemplate = nullptr;
}

int ShootMenu::checkEvents()
{
    POINT cursor;
    GetCursorPos(&cursor);

    POINT consoleCursor;

    Convertions::toCharPosition(getGameConsole().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    bool isUpdated = true;

    Player* shooter = &getPlayers().at(0);
    Player* defender = &getPlayers().at(1);

    Message newMessage(getGameConsole().getScreenHandle());

    int firstPshipsAmount = 10;
    int secondPshipsAmount = 10;

    while (firstPshipsAmount > 0 && secondPshipsAmount > 0)
    {

        GetCursorPos(&cursor);
        Convertions::toCharPosition(getGameConsole().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

        if (isUpdated)
        {
            newMessage.showMessage(3 + shooter->getID());
            while(true)
            {
                if (Base::staticIsKeyPressed(VK_SPACE)) break;
            }
            Console::staticClear();
            drawMenu(*shooter, *defender);
            isUpdated = false;
        }

        if (Base::staticIsHovered(consoleCursor, {144, 9}, {220, 55}))
        {
            if (Base::staticIsClicked(consoleCursor, {144, 9}, {220, 55}))
            {
                if(!shoot(*defender, consoleCursor))
                {
                    defender->getBoard().drawSigns();
                    Console::staticSleep(500);
                    std::swap(shooter, defender);
                    isUpdated = true;
                }
                else
                {
                    defender->getBoard().drawSigns();
                    drawMenu(*shooter, *defender);
                    if (isSinked(*defender, consoleCursor))
                    {
                        fillTheSpace(*defender, consoleCursor);
                        defender->getBoard().drawDefeatedShips();
                        defender->getBoard().drawSigns();

                        if (defender->getID() == 1)
                        {
                            firstPshipsAmount--;
                        }
                        else
                        {
                            secondPshipsAmount--;
                        }
                        
                    }
                    
                    
                }
            }   
        }
        
        
        
    }

    return firstPshipsAmount > secondPshipsAmount ? 1 : 2;
}

void ShootMenu::drawMenu(Player& shooter, Player& defender)
{
    shooter.getBoard().setOffset(10);
    shooter.getBoard().synchronizeShips();
    shooter.getBoard().drawBoard();
    shooter.getBoard().drawShips();
    shooter.getBoard().drawOwnSigns();
    
    if (shooter.getID() == 1)
    {
        Console::staticSetFontColor(getGameConsole().getScreenHandle(), 8);

        Alphabet::drawP(getGameConsole().getScreenHandle(), 13, 13, {121, 15});
        Number::draw1(getGameConsole().getScreenHandle(), 13, 13, {121, 40});

        Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);

        Alphabet::drawP(getGameConsole().getScreenHandle(), 13, 13, {120, 15});
        Number::draw1(getGameConsole().getScreenHandle(), 13, 13, {120, 40});
    }
    else
    {
        Console::staticSetFontColor(getGameConsole().getScreenHandle(), 8);

        Alphabet::drawP(getGameConsole().getScreenHandle(), 13, 13, {121, 15});
        Number::draw2(getGameConsole().getScreenHandle(), 13, 13, {121, 40});

        Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);

        Alphabet::drawP(getGameConsole().getScreenHandle(), 13, 13, {120, 15});
        Number::draw2(getGameConsole().getScreenHandle(), 13, 13, {120, 40});
    }

    defender.getBoard().setOffset(130);
    defender.getBoard().synchronizeShips();
    defender.getBoard().drawBoard();
    defender.getBoard().drawDefeatedShips();
    defender.getBoard().drawSigns();
}

bool ShootMenu::shoot(Player& defender, POINT& consoleCursor)
{
    roundCursor(consoleCursor);

    int shootX = (consoleCursor.x - 144) / 8;
    int shootY = (consoleCursor.y - 9) / 5;

    if (defender.getBoard().getShoots()->at(shootY).at(shootX) == false)
    {
        defender.getBoard().getShoots()->at(shootY).at(shootX) = true;

        if (defender.getBoard().getHiddenShips()->at(shootY).at(shootX) == true)
        {
            defender.getBoard().getSigns()->push_back([this, consoleCursor](){
                Console::staticSetFontColor(getGameConsole().getScreenHandle(), 4);
                Alphabet::drawX(getGameConsole().getScreenHandle(), 4, 4, {consoleCursor.x, consoleCursor.y});
                Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);
            });

            defender.getBoard().getOwnBoardSigns()->push_back([this, consoleCursor](){
                Console::staticSetFontColor(getGameConsole().getScreenHandle(), 4);
                Alphabet::drawX(getGameConsole().getScreenHandle(), 4, 4, {consoleCursor.x - 120, consoleCursor.y});
                Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);
            });

            return true;
        }
        else
        {
            defender.getBoard().getSigns()->push_back([this, consoleCursor](){
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {consoleCursor.x, consoleCursor.y});
            }); 

            defender.getBoard().getOwnBoardSigns()->push_back([this, consoleCursor](){
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {consoleCursor.x - 120, consoleCursor.y});
            }); 

            return false;
        }

    }
    else
    {
        Message newMessage(getGameConsole().getScreenHandle());

        newMessage.showMessage(6);
        Console::staticClear();
    }

    return true;
}

bool ShootMenu::isSinked(Player &defender, POINT &consoleCursor)
{
    int shipIndex = findShipIndex(defender, consoleCursor);
    bool isSinked = false;

    if (shipIndex == -1)
    {
        return false;
    }
    
    std::shared_ptr<Base> ship = defender.getBoard().getShips()->at(shipIndex);

    int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
    int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
    int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
    int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

    if (ship->getDirection() == 'N' || ship->getDirection() == 'S')
    {
        if (isSinked = isSinkedNS(defender, startY, endY, startX))
        {
            defender.getBoard().getDefeatedShips()->push_back(ship);
        }

        return isSinked;
    }
    else
    {
        if (isSinked = isSinkedEW(defender, startX, endX, startY))
        {
            defender.getBoard().getDefeatedShips()->push_back(ship);
        }

        return isSinked;
    }
    
}

bool ShootMenu::isSinkedNS(Player &defender, int startY, int endY, int startX)
{
    int updatedEndY = (endY - 9) / 5;
    int updatedStartY = (startY - 9) / 5;
    int updatedStartX = (startX - 144) / 8;

    for (int i = updatedEndY; i <= updatedStartY; i++)
    {
        if (defender.getBoard().getHiddenShips()->at(i).at(updatedStartX) == false || defender.getBoard().getShoots()->at(i).at(updatedStartX) == false)
        {
            return false;
        }
        
    }
    
    return true;
}

bool ShootMenu::isSinkedEW(Player &defender, int startX, int endX, int startY)
{
    int updatedStartX = (startX - 144) / 8;
    int updatedEndX = (endX - 144) / 8;
    int updatedStartY = (startY - 9) / 5;

    for (int i = updatedEndX; i <= updatedStartX; i++)
    {
        if (defender.getBoard().getHiddenShips()->at(updatedStartY).at(i) == false || defender.getBoard().getShoots()->at(updatedStartY).at(i) == false)
        {
            return false;
        }
        
    }
    
    return true;
}

void ShootMenu::fillTheSpace(Player &defender, POINT &consoleCursor)
{
    int shipIndex = findShipIndex(defender, consoleCursor);
    std::shared_ptr<Base> ship = defender.getBoard().getShips()->at(shipIndex);

    int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
    int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
    int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
    int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

    if (ship->getDirection() == 'N' || ship->getDirection() == 'S')
    {
        fillTheSpaceNS(defender, startX, startY, endX, endY);
    }
    else
    {
        fillTheSpaceEW(defender, startY, startX, endX);
    }
    
}

void ShootMenu::fillTheSpaceNS(Player &defender, int startX, int startY, int endX, int endY)
{
    for (int y = endY - 5; y <= startY + 5; y += 5)
    {
        for (int x = endX - 8; x <= startX + 8; x += 8)
        {
            if (x < 144 || x > 220 || y < 9 || y > 55 || (x >= endX && x <= startX && y >= endY && y <= startY))
            {
                continue;
            }

            defender.getBoard().getSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x, y});
            });

            defender.getBoard().getOwnBoardSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x - 120, y});
            });
            
            int indexX = (x - 144) / 8;
            int indexY = (y - 9) / 5;

            if (indexX >= 0 && indexX < 10 && indexY >= 0 && indexY < 10)
            {
                defender.getBoard().getShoots()->at(indexY).at(indexX) = true;
            }
            
        }
    }
}


void ShootMenu::fillTheSpaceEW(Player &defender, int startY, int startX, int endX)
{
    for (int y = startY - 5; y <= startY + 5; y += 5)
    {
        for (int x = endX - 8; x <= startX + 8; x += 8)
        {
            if (x < 144 || x > 220 || y < 9 || y > 55 || (x >= endX && x <= startX && y == startY))
            {
                continue;
            }

            defender.getBoard().getSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x, y});
            });

            defender.getBoard().getOwnBoardSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x - 120, y});
            });

            int indexX = (x - 144) / 8;
            int indexY = (y - 9) / 5;

            if (indexX >= 0 && indexX < 10 && indexY >= 0 && indexY < 10)
            {
                defender.getBoard().getShoots()->at(indexY).at(indexX) = true;
            }
        }
    }
}

int ShootMenu::findShipIndex(Player &defender, POINT &consoleCursor)
{
    roundCursor(consoleCursor);

    for (int i = 0; i < 10; i++)
    {
        std::shared_ptr<Base> ship = defender.getBoard().getShips()->at(i);

        int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
        int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
        int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
        int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

        if (consoleCursor.x >= endX && consoleCursor.x <= startX && consoleCursor.y >= endY && consoleCursor.y <= startY)
        {
            return i;
        }
        
    }
    

    return -1;
}

void ShootMenu::roundCursor(POINT &consoleCursor)
{
    int nearestX = consoleCursor.x;
    int nearestY = consoleCursor.y;
    
    int minDiffX = 100;
    int minDiffY = 100;

    for (int xPoint : getBoardTemplate()->getWidthPoints()) 
    {
        int diff = std::abs(xPoint - consoleCursor.x);

        if (diff < minDiffX) 
        {
            minDiffX = diff;
            nearestX = xPoint;
        }
    }


    for (int yPoint : getBoardTemplate()->getHeightPoints()) 
    {
        int diff = std::abs(yPoint - consoleCursor.y);

        if (diff < minDiffY) 
        {
            minDiffY = diff;
            nearestY = yPoint;
        }
    }

    consoleCursor.x = nearestX;
    consoleCursor.y = nearestY;
}
