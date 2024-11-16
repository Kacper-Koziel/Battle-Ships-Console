#pragma once

#include "PlaceMenu.h"
#include "../Ships/Ships.h"
#include "../Convertions/Convertions.cc"
#include "../Button/Button.cc"
#include "../ButtonsNamespace/Buttons.cc"
#include "../Message/Message.cc"

#include <cmath>

PlaceMenu::PlaceMenu(Board &playerBoard, Console& window) : playerBoard(playerBoard), window(window) {}


PlaceMenu::~PlaceMenu()
{
    
}

void PlaceMenu::drawSet(Base &ship, short amount, short maxAmount)
{
    ship.drawShipW();

    switch (amount)
    {
    case 1:
        Number::drawLower1(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 29, ship.getStart().getY()});
        break;
    
    case 2:
        Number::drawLower2(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 29, ship.getStart().getY()});
        break;

    case 3:
        Number::draw3(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 29, ship.getStart().getY()});
        break;

    case 4:
        Number::drawLower4(getWindow().getScreenHandle(), 5, 6, {ship.getStart().getX() - 29, ship.getStart().getY()});
        break;
    default:
        Console::staticSetFontColor(getWindow().getScreenHandle(), 4);
        Number::drawLower0(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 29, ship.getStart().getY()});
        Console::staticSetFontColor(getWindow().getScreenHandle(), 7);
        break;
    }
    Line::drawLine(getWindow().getScreenHandle(), {{ship.getStart().getX() - 18, ship.getStart().getY() - 3}, {ship.getStart().getX() - 23, ship.getStart().getY() + 2}});

    switch (maxAmount)
    {
    case 1:
        Number::drawLower1(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 14, ship.getStart().getY()});
        break;
    
    case 2:
        Number::drawLower2(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 14, ship.getStart().getY()});
        break;

    case 3:
        Number::draw3(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 14, ship.getStart().getY()});
        break;

    case 4:
        Number::drawLower4(getWindow().getScreenHandle(), 5, 6, {ship.getStart().getX() - 14, ship.getStart().getY()});
        break;
    
    default:
        Console::staticSetFontColor(getWindow().getScreenHandle(), 4);
        Number::drawLower0(getWindow().getScreenHandle(), 5, 5, {ship.getStart().getX() - 14, ship.getStart().getY()});
        Console::staticSetFontColor(getWindow().getScreenHandle(), 7);
        break;
    }
}

bool PlaceMenu::checkEventsForSet(Base &setShip, void (PlaceMenu::*drawSetFunction)(Base &setShip, short, short), short amount, short maxAmount)
{
    POINT cursor;
    GetCursorPos(&cursor);

    POINT consoleCursor;
    Convertions::toCharPosition(window.getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    (this->*drawSetFunction)(setShip, amount, maxAmount);
    

    if (setShip.isHovered(consoleCursor))
    {
        if (setShip.isClicked(consoleCursor))
        {
            return true;
        }
    }

    return false;
    
}

int PlaceMenu::checkEvents()
{
    Quadra newQuadra(getWindow().getScreenHandle(), {176, 10}, {200, 10});
    Tripple newTripple(getWindow().getScreenHandle(), {176, 20}, {192, 20});
    Dual newDual(getWindow().getScreenHandle(), {176, 30}, {186, 30});
    Single newSingle(getWindow().getScreenHandle(), {176, 40}, {176, 40});


    Button clearButton(getWindow().getScreenHandle(), getWindow().getConsoleWindow(), Buttons::clearButton, 8, 20, {150, 53});
    Button nextButton(getWindow().getScreenHandle(), getWindow().getConsoleWindow(), Buttons::nextButton, 8, 40, {190, 53});

    int quadraAmount = 1;
    int trippleAmount = 2;
    int dualAmount = 3;
    int singleAmount = 4;

    int shipsAmount = 0;

    drawMenu(newQuadra, newTripple, newDual, newSingle, clearButton, nextButton);

    bool isUpdated = false;

    while (shipsAmount <= 10)
    {
        
        if (isUpdated = checkEventsForSet(newQuadra, &PlaceMenu::drawSet, quadraAmount, 1))
        {

            if (quadraAmount < 1)
            {
                Message enought(getWindow().getScreenHandle());
                enought.showMessage(2);
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
            }
            else
            {
                quadraAmount--;
                Console::staticClear();
                std::shared_ptr<Base> quadra = placeShip(4);

                Console::staticClear();
                getPlayerBoard().drawBoard();

                if (quadra != nullptr)
                {
                    getPlayerBoard().setShipValue(quadra, shipsAmount);
                    shipsAmount++;
                }
                else
                {
                    quadraAmount++;
                }

                getPlayerBoard().drawShips();
            }
        }

        if (isUpdated = checkEventsForSet(newTripple, &PlaceMenu::drawSet, trippleAmount, 2))
        {

            if (trippleAmount < 1)
            {
                Message enought(getWindow().getScreenHandle());
                enought.showMessage(2);
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
            }
            else
            {
                trippleAmount--;
                Console::staticClear();
                std::shared_ptr<Base> tripple = placeShip(3);

                Console::staticClear();
                getPlayerBoard().drawBoard();

                if (tripple != nullptr)
                {
                    getPlayerBoard().setShipValue(tripple, shipsAmount);
                    shipsAmount++;
                }
                else
                {
                    trippleAmount++;
                }

                getPlayerBoard().drawShips();
            }
        }

        if (isUpdated = checkEventsForSet(newDual, &PlaceMenu::drawSet, dualAmount, 3))
        {
            if (dualAmount < 1)
            {
                Message enought(getWindow().getScreenHandle());
                enought.showMessage(2);
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
            }
            else
            {
                dualAmount--;
                Console::staticClear();
                std::shared_ptr<Base> dual = placeShip(2);

                Console::staticClear();
                getPlayerBoard().drawBoard();

                if (dual != nullptr)
                {
                    getPlayerBoard().setShipValue(dual, shipsAmount);
                    shipsAmount++;
                }
                else
                {
                    dualAmount++;
                }

                getPlayerBoard().drawShips();
            }
        }

        if (isUpdated = checkEventsForSet(newSingle, &PlaceMenu::drawSet, singleAmount, 4))
        {
            if (singleAmount < 1)
            {
                Message enought(getWindow().getScreenHandle());
                enought.showMessage(2);
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
            }
            else
            {
                singleAmount--;
                Console::staticClear();
                getPlayerBoard().drawBoard();
                std::shared_ptr<Base> single = placeShip(1);

                Console::staticClear();
                getPlayerBoard().drawBoard();

                if (single != nullptr)
                {
                    getPlayerBoard().setShipValue(single, shipsAmount);
                    shipsAmount++;
                }
                else
                {
                    singleAmount++;
                }

                getPlayerBoard().drawShips();
            }
        }

        if (clearButton.checkEvents())
        {
            getPlayerBoard().getShips()->clear();
            getPlayerBoard().getShips()->resize(10, nullptr);
            getPlayerBoard().clearHiddenShips();
            Console::staticClear();
            return 1;
        }

        Console::staticSleep(50);

        if (nextButton.checkEvents())
        {
            if (shipsAmount == 10)
            {
                Console::staticClear();
                return 2;
            }
            else
            {
                Message dontHave10(getWindow().getScreenHandle());
                dontHave10.showMessage(3);
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
            }
        }
    }
    
    return 0;
}

bool PlaceMenu::isSafeToPlace(const Point2D& startPosition, const Point2D& endPosition)
{
    int startX = (startPosition.getX() - 26) / 8;
    int startY = (startPosition.getY() - 10) / 5;
    int endX = (endPosition.getX() - 26) / 8;
    int endY = (endPosition.getY() - 10) / 5;

    if (startX < 0 || startX >= 10 || startY < 0 || startY >= 10 ||
        endX < 0 || endX >= 10 || endY < 0 || endY >= 10)
    {
        return false;
    }


    if (getPlayerBoard().getHiddenShips()->at(startY).at(startX) == true || getPlayerBoard().getHiddenShips()->at(endY).at(endX) == true)
    {
        return false;
    }

    
    for (int i = startY - 1; i <= endY + 1; i++)
    {
        for (int j = startX - 1; j <= endX + 1; j++)
        {
            if (j < 0 || j >= 10 || i < 0 || i >= 10) 
            {
                continue;
            }

            
            if (getPlayerBoard().getHiddenShips()->at(i).at(j) == true)
            {
                return false;
            }
        }
    }


    return true;
}




void PlaceMenu::drawMenu(Base &quadraShip, Base &trippleShip, Base &dualShip, Base &singleShip, Button &clearButton, Button &nextButton)
{
    getPlayerBoard().drawBoard();
    getPlayerBoard().drawShips();

    checkEventsForSet(quadraShip, &PlaceMenu::drawSet, 1, 1);
    checkEventsForSet(trippleShip, &PlaceMenu::drawSet, 2, 2);
    checkEventsForSet(dualShip, &PlaceMenu::drawSet, 3, 3);
    checkEventsForSet(singleShip, &PlaceMenu::drawSet, 4, 4);

    clearButton.checkEvents();
    nextButton.checkEvents();
}

void PlaceMenu::drawShadowSingle(int position, const Point2D &start, const Point2D &end, short color)
{
    switch (position)
    {
        case 1:
            Single::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;

        case 2:
            Single::drawGhostE(getWindow().getScreenHandle(), start, end, color);
            break;

        case 3:
            Single::drawGhostS(getWindow().getScreenHandle(), start, end, color);
            break;

        case 4:
            Single::drawGhostW(getWindow().getScreenHandle(), start, end, color);
            break;

        default:
            Single::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;
    }
}

void PlaceMenu::drawShadowDual(int position, const Point2D &start, const Point2D &end, short color)
{
    switch (position)
    {
        case 1:
            Dual::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;

        case 2:
            Dual::drawGhostE(getWindow().getScreenHandle(), start, end, color);
            break;

        case 3:
            Dual::drawGhostS(getWindow().getScreenHandle(), start, end, color);
            break;

        case 4:
            Dual::drawGhostW(getWindow().getScreenHandle(), start, end, color);
            break;

        default:
            Dual::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;
    }
}

void PlaceMenu::changePositionDual(int position, Point2D &start, Point2D &end)
{
    switch (position)
    {
    case 1: 
        start = Point2D(end.getX(), end.getY() - 5);
        break;

    case 2:
        start = end;
        end = Point2D(start.getX() + 8, start.getY()); 
        break;

    case 3:
        end = Point2D(end.getX() - 8, end.getY() + 5);
        break;

    case 4:
        end = Point2D(end.getX(), end.getY() - 5);
        start = Point2D(end.getX() - 8, start.getY()); 
    default:
        break;
    }
}

void PlaceMenu::modifyStartByPositionDual(int position, Point2D &start, Point2D &end)
{
    switch (position)
    {
    case 1:
        start = Point2D(end.getX(), end.getY() - 5);
        break;
    
    case 2:
        start = end;
        end = Point2D(end.getX() + 8, end.getY());
        break;

    case 3:
        start = Point2D(end.getX(), end.getY() - 5);
        break;

    case 4:
        start = Point2D(end.getX() - 8, end.getY());
        break;
    default:
        start = Point2D(end.getX(), end.getY() - 5);
        break;
    }
}

void PlaceMenu::drawShadowTripple(int position, const Point2D &start, const Point2D &end, short color)
{
    switch (position)
    {
        case 1:
            Tripple::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;

        case 2:
            Tripple::drawGhostE(getWindow().getScreenHandle(), start, end, color);
            break;

        case 3:
            Tripple::drawGhostS(getWindow().getScreenHandle(), start, end, color);
            break;

        case 4:
            Tripple::drawGhostW(getWindow().getScreenHandle(), start, end, color);
            break;

        default:
            Tripple::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;
    }
}

void PlaceMenu::changePositionTripple(int position, Point2D &start, Point2D &end)
{
    switch (position)
    {
    case 1: 
        start = Point2D(end.getX(), end.getY() - 10);
        break;

    case 2:
        start = end;
        end = Point2D(start.getX() + 16, start.getY()); 
        break;

    case 3:
        end = Point2D(end.getX() - 16, end.getY() + 10);
        break;

    case 4:
        end = Point2D(end.getX(), end.getY() - 10);
        start = Point2D(end.getX() - 16, start.getY()); 
    default:
        break;
    }
}

void PlaceMenu::modifyStartByPositionTripple(int position, Point2D &start, Point2D &end)
{
    switch (position)
    {
    case 1:
        start = Point2D(end.getX(), end.getY() - 10);
        break;
    
    case 2:
        start = end;
        end = Point2D(end.getX() + 16, end.getY());
        break;

    case 3:
        start = Point2D(end.getX(), end.getY() - 10);
        break;

    case 4:
        start = Point2D(end.getX() - 16, end.getY());
        break;
    default:
        start = Point2D(end.getX(), end.getY() - 10);
        break;
    }
}

void PlaceMenu::drawShadowQuadra(int position, const Point2D &start, const Point2D &end, short color)
{
    switch (position)
    {
        case 1:
            Quadra::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;

        case 2:
            Quadra::drawGhostE(getWindow().getScreenHandle(), start, end, color);
            break;

        case 3:
            Quadra::drawGhostS(getWindow().getScreenHandle(), start, end, color);
            break;

        case 4:
            Quadra::drawGhostW(getWindow().getScreenHandle(), start, end, color);
            break;

        default:
            Quadra::drawGhostN(getWindow().getScreenHandle(), start, end, color);
            break;
    }
}

void PlaceMenu::changePositionQuadra(int position, Point2D &start, Point2D &end)
{
    switch (position)
    {
    case 1: 
        start = Point2D(end.getX(), end.getY() - 15);
        break;

    case 2:
        start = end;
        end = Point2D(start.getX() + 24, start.getY()); 
        break;

    case 3:
        end = Point2D(end.getX() - 24, end.getY() + 15);
        break;

    case 4:
        end = Point2D(end.getX(), end.getY() - 15);
        start = Point2D(end.getX() - 24, start.getY()); 
    default:
        break;
    }
}

void PlaceMenu::modifyStartByPositionQuadra(int position, Point2D &start, Point2D &end)
{
    switch (position)
    {
    case 1:
        start = Point2D(end.getX(), end.getY() - 15);
        break;
    
    case 2:
        start = end;
        end = Point2D(end.getX() + 24, end.getY());
        break;

    case 3:
        start = Point2D(end.getX(), end.getY() - 15);
        break;

    case 4:
        start = Point2D(end.getX() - 24, end.getY());
        break;
    default:
        start = Point2D(end.getX(), end.getY() - 15);
        break;
    }
}

void PlaceMenu::roundCursor(POINT &consoleCursor)
{
    int nearestX = consoleCursor.x;
    int nearestY = consoleCursor.y;
    
    int minDiffX = 100;
    int minDiffY = 100;

    for (int xPoint : getPlayerBoard().getWidthPoints()) 
    {
        int diff = std::abs(xPoint - consoleCursor.x);

        if (diff < minDiffX) 
        {
            minDiffX = diff;
            nearestX = xPoint;
        }
    }


    for (int yPoint : getPlayerBoard().getHeightPoints()) 
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

void PlaceMenu::setHiddens(const Point2D &startPosition, const Point2D &endPosition)
{
    
    int startX = (startPosition.getX() - 26) / 8;
    int startY = (startPosition.getY() - 10) / 5;
    int endX = (endPosition.getX() - 26) / 8;
    int endY = (endPosition.getY() - 10) / 5;

    
    if (startY == endY)
    {    
        for (int j = startX; j <= endX; j++)
        {
            getPlayerBoard().getHiddenShips()->at(startY).at(j) = true;
        }
    }
    else if (startX == endX) 
    {
        
        for (int i = startY; i <= endY; i++)
        {
            getPlayerBoard().getHiddenShips()->at(i).at(startX) = true;
        }
    }
}


std::shared_ptr<Base> PlaceMenu::placeShip(const short size)
{
    switch (size)
    {
    case 1:
    {
        return placeSingle();
        break;
    }    
    
    case 2:
    {
        return placeDual();
        break;
    }

    case 3:
    {
        return placeTripple();
        break;
    }

    case 4:
    {
        return placeQuadra();
        break;
    }

    default:
        break;
    }

    return nullptr;
}

std::shared_ptr<Single> PlaceMenu::placeSingle()
{
    Point2D coordsPosition(26, 10);

    Single::drawGhostN(getWindow().getScreenHandle(), coordsPosition, coordsPosition, 11);

    char positions[4] = {'N', 'E', 'S', 'W'};
    int currentPosition = 1;

    POINT cursor;
    GetCursorPos(&cursor);

    getPlayerBoard().drawShips();

    if (isSafeToPlace(coordsPosition, coordsPosition))
    {
        drawShadowTripple(currentPosition, coordsPosition, coordsPosition, 11);
    }
    else
    {
        drawShadowTripple(currentPosition, coordsPosition, coordsPosition, 4);
    }

    POINT consoleCursor;
    Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    while(true)
    {
        GetCursorPos(&cursor);
        Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

        if (Single::staticIsKeyPressed('X'))
        {

            return nullptr;
        }
        
        if (Single::staticIsKeyPressed('R'))
        {
            currentPosition < 4 ? currentPosition++ : currentPosition = 1;
            
            Console::staticClear();
            getPlayerBoard().drawBoard();
            getPlayerBoard().drawShips();

            if (isSafeToPlace(coordsPosition, coordsPosition))
            {
                drawShadowSingle(currentPosition, coordsPosition, coordsPosition, 11);
            }
            else
            {
                drawShadowSingle(currentPosition, coordsPosition, coordsPosition, 4);
            }
        }
        
        if (Single::staticIsHovered(consoleCursor, {18 + getPlayerBoard().getOffset(), 10}, {88 + getPlayerBoard().getOffset(), 54}))
        {

            if (Single::staticIsClicked(consoleCursor, {18 + getPlayerBoard().getOffset(), 12}, {88 + getPlayerBoard().getOffset(), 53}))
            {
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
                GetCursorPos(&cursor);
                Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

                roundCursor(consoleCursor);
                
                coordsPosition = consoleCursor; //overloading operator = 

                if (isSafeToPlace(coordsPosition, coordsPosition))
                {
                    drawShadowSingle(currentPosition, coordsPosition, coordsPosition, 11);
                }
                else
                {
                    drawShadowSingle(currentPosition, coordsPosition, coordsPosition, 4);
                }
            
            }
            
        }

        if (Single::staticIsKeyPressed('P'))
        {
            if(isSafeToPlace(coordsPosition, coordsPosition))
            {
                getPlayerBoard().getHiddenShips()->at((coordsPosition.getY() - 10) / 5).at((coordsPosition.getX() - 26) / 8) = true;

                std::shared_ptr<Single> newSingle = std::make_shared<Single>(getWindow().getScreenHandle(), coordsPosition, coordsPosition, 1);
                newSingle->setRotation(positions[currentPosition - 1]);

                return newSingle; 
            }
            else
            {
                Message cantMess(getWindow().getScreenHandle());
                cantMess.showMessage(1);
                return nullptr;
            }
        }
    }

    return nullptr;
}

std::shared_ptr<Dual> PlaceMenu::placeDual()
{
    Point2D startPosition(26, 10);
    Point2D endPosition(26, 15);

    char positions[4] = {'N', 'E', 'S', 'W'};
    int currentPosition = 1;

    getPlayerBoard().drawBoard();
    getPlayerBoard().drawShips();

    if (isSafeToPlace(startPosition, endPosition))
    {
        drawShadowDual(currentPosition, startPosition, endPosition, 11);
    }
    else
    {
        drawShadowDual(currentPosition, startPosition, endPosition, 4);
    }

    POINT cursor;
    GetCursorPos(&cursor);

    POINT consoleCursor;
    Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    while(true)
    {
        GetCursorPos(&cursor);
        Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

        if (Dual::staticIsKeyPressed('X'))
        {
            return nullptr;
        }

        if (Dual::staticIsKeyPressed('R'))
        {
            currentPosition < 4 ? currentPosition++ : currentPosition = 1;
            
            Console::staticClear();
            changePositionDual(currentPosition, startPosition, endPosition);
            getPlayerBoard().drawBoard();
            getPlayerBoard().drawShips();

            if (isSafeToPlace(startPosition, endPosition))
            {
                drawShadowDual(currentPosition, startPosition, endPosition, 11);
            }
            else
            {
                drawShadowDual(currentPosition, startPosition, endPosition, 4);
            }
        }

        if (Dual::staticIsHovered(consoleCursor, {18 + getPlayerBoard().getOffset(), 10}, {88 + getPlayerBoard().getOffset(), 54}))
        {

            if (Dual::staticIsClicked(consoleCursor, {18 + getPlayerBoard().getOffset(), 12}, {88 + getPlayerBoard().getOffset(), 53}))
            {
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();

                GetCursorPos(&cursor);
                Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

                roundCursor(consoleCursor);
                
                endPosition = consoleCursor;
                modifyStartByPositionDual(currentPosition, startPosition, endPosition);

                if (isSafeToPlace(startPosition, endPosition))
                {
                    drawShadowDual(currentPosition, startPosition, endPosition, 11);
                }
                else
                {
                    drawShadowDual(currentPosition, startPosition, endPosition, 4);
                }
            
            }
            
        }

        if (Dual::staticIsKeyPressed('P'))
        {
            if (isSafeToPlace(startPosition, endPosition))
            {
                setHiddens(startPosition, endPosition);
                std::shared_ptr<Dual> newDual = std::make_shared<Dual>(getWindow().getScreenHandle(), startPosition, endPosition, 2);
                newDual->setRotation(positions[currentPosition - 1]);
                return newDual;
            }
            else
            {
                Message cantMess(getWindow().getScreenHandle());
                cantMess.showMessage(1);
                return nullptr;
            }
        }
    }

    return nullptr;
}

std::shared_ptr<Tripple> PlaceMenu::placeTripple()
{
    Point2D startPosition(26, 10);
    Point2D endPosition(26, 20);

    char positions[4] = {'N', 'E', 'S', 'W'};
    int currentPosition = 1;

    getPlayerBoard().drawBoard();
    getPlayerBoard().drawShips();

    if (isSafeToPlace(startPosition, endPosition))
    {
        drawShadowTripple(currentPosition, startPosition, endPosition, 11);
    }
    else
    {
        drawShadowTripple(currentPosition, startPosition, endPosition, 4);
    }


    POINT cursor;
    GetCursorPos(&cursor);

    POINT consoleCursor;
    Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    while(true)
    {
        GetCursorPos(&cursor);
        Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

        if (Tripple::staticIsKeyPressed('X'))
        {
            return nullptr;
        }

        if (Tripple::staticIsKeyPressed('R'))
        {
            currentPosition < 4 ? currentPosition++ : currentPosition = 1;
            
            Console::staticClear();
            changePositionTripple(currentPosition, startPosition, endPosition);
            getPlayerBoard().drawBoard();
            getPlayerBoard().drawShips();

            if (isSafeToPlace(startPosition, endPosition))
            {
                drawShadowTripple(currentPosition, startPosition, endPosition, 11);
            }
            else
            {
                drawShadowTripple(currentPosition, startPosition, endPosition, 4);
            }
        }

        if (Tripple::staticIsHovered(consoleCursor, {18 + getPlayerBoard().getOffset(), 10}, {88 + getPlayerBoard().getOffset(), 54}))
        {

            if (Tripple::staticIsClicked(consoleCursor, {18 + getPlayerBoard().getOffset(), 12}, {88 + getPlayerBoard().getOffset(), 53}))
            {
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
                GetCursorPos(&cursor);
                Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

                roundCursor(consoleCursor);
                
                endPosition = consoleCursor;
                modifyStartByPositionTripple(currentPosition, startPosition, endPosition);

                if (isSafeToPlace(startPosition, endPosition))
                {
                    drawShadowTripple(currentPosition, startPosition, endPosition, 11);
                }
                else
                {
                    drawShadowTripple(currentPosition, startPosition, endPosition, 4);
                }
            
            }
            
        }

        if (Tripple::staticIsKeyPressed('P'))
        {
            if(isSafeToPlace(startPosition, endPosition))
            {
                setHiddens(startPosition, endPosition);

                std::shared_ptr<Tripple> newTripple = std::make_shared<Tripple>(getWindow().getScreenHandle(), startPosition, endPosition, 2);
                newTripple->setRotation(positions[currentPosition - 1]);
                return newTripple; 
            }
            else
            {
                Message cantMess(getWindow().getScreenHandle());
                cantMess.showMessage(1);
                return nullptr;
            }
        }
    }

    return nullptr;
}

std::shared_ptr<Quadra> PlaceMenu::placeQuadra()
{
    Point2D startPosition(26, 10);
    Point2D endPosition(26, 25);

    char positions[4] = {'N', 'E', 'S', 'W'};
    int currentPosition = 1;

    getPlayerBoard().drawBoard();
    getPlayerBoard().drawShips();
    
    if (isSafeToPlace(startPosition, endPosition))
    {
        drawShadowQuadra(currentPosition, startPosition, endPosition, 11);
    }
    else
    {
        drawShadowQuadra(currentPosition, startPosition, endPosition, 4);
    }

    POINT cursor;
    GetCursorPos(&cursor);

    POINT consoleCursor;
    Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    while(true)
    {
        GetCursorPos(&cursor);
        Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

        if (Quadra::staticIsKeyPressed('X'))
        {
            return nullptr;
        }

        if (Quadra::staticIsKeyPressed('R'))
        {
            currentPosition < 4 ? currentPosition++ : currentPosition = 1;
            
            Console::staticClear();
            changePositionQuadra(currentPosition, startPosition, endPosition);
            getPlayerBoard().drawBoard();
            getPlayerBoard().drawShips();

            if (isSafeToPlace(startPosition, endPosition))
            {
                drawShadowQuadra(currentPosition, startPosition, endPosition, 11);
            }
            else
            {
                drawShadowQuadra(currentPosition, startPosition, endPosition, 4);
            }
        }

        if (Quadra::staticIsHovered(consoleCursor, {18 + getPlayerBoard().getOffset(), 10}, {88 + getPlayerBoard().getOffset(), 54}))
        {

            if (Quadra::staticIsClicked(consoleCursor, {18 + getPlayerBoard().getOffset(), 12}, {88 + getPlayerBoard().getOffset(), 53}))
            {
                Console::staticClear();
                getPlayerBoard().drawBoard();
                getPlayerBoard().drawShips();
                GetCursorPos(&cursor);
                Convertions::toCharPosition(getWindow().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

                roundCursor(consoleCursor);
                
                endPosition = consoleCursor;
                modifyStartByPositionQuadra(currentPosition, startPosition, endPosition);

                if (isSafeToPlace(startPosition, endPosition))
                {
                    drawShadowTripple(currentPosition, startPosition, endPosition, 11);
                }
                else
                {
                    drawShadowTripple(currentPosition, startPosition, endPosition, 4);
                }
            
            }
            
        }

        if (Quadra::staticIsKeyPressed('P'))
        {
            if(isSafeToPlace(startPosition, endPosition))
            {
                setHiddens(startPosition, endPosition);

                std::shared_ptr<Quadra> newQuadra = std::make_shared<Quadra>(getWindow().getScreenHandle(), startPosition, endPosition, 2);
                newQuadra->setRotation(positions[currentPosition - 1]);
                return newQuadra; 
            }
            else
            {
                Message cantMess(getWindow().getScreenHandle());
                cantMess.showMessage(1);
                return nullptr;
            }
        }
    }

    return nullptr;
}
