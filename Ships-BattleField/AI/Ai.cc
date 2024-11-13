#pragma once

#include "Ai.h"

#include <random>

Ai::Ai(Console& gameConsole, Board &aiBoard) : gameConsole(gameConsole), aiBoard(aiBoard)
{
}

Ai::~Ai()
{
}

void Ai::randomizeBoard()
{
    getAiBoard().clearData();
    getAiBoard().synchronizePoints();

    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<> XYdistributor(0, 9);
    std::uniform_int_distribution<> RotationDistributor(0, 3);

    int currentType = 4;

    for (int i = 0; i < 10; i++)
    {
        changeType(currentType, i);

        while (true)
        {
            Point2D end(XYdistributor(generator), XYdistributor(generator));
            char rotation = setRotation(RotationDistributor(generator));

            Point2D start = getStart(end, currentType, rotation);

            modifyStartBasedOnPosition(start, end, currentType, rotation);

            if (isSafeToPlace(start, end))
            {
                placeShip(start, end, rotation, currentType, i);
                break;
            }
        }
        
    }
}

void Ai::drawBoard()
{
    Console::staticClear();
    getAiBoard().synchronizePoints();
    getAiBoard().synchronizeShips();

    getAiBoard().drawBoard();
    getAiBoard().drawShips();

    Console::staticSleep(10000);
}

bool Ai::isSafeToPlace(Point2D &start, Point2D& end)
{
    if (start.getX() < 0 || start.getY() < 0 || start.getX() >= 10 || start.getY() >= 10)
    {
        return false;
    }
    
    if (end.getX() < 0 || end.getY() < 0 || end.getX() >= 10 || end.getY() >= 10)
    {
        return false;
    }

    if (getAiBoard().getHiddenShips()->at(end.getY()).at(end.getX()) || getAiBoard().getHiddenShips()->at(start.getY()).at(start.getX()))
    {
        return false;
    }
    

    for (int i = start.getY() - 1; i <= end.getY() + 1; i++)
    {
        for (int j = start.getX() - 1; j <= end.getX() + 1; j++)
        {
            if (j < 0 || j >= 10 || i < 0 || i >= 10) 
            {
                continue;
            }

            
            if (getAiBoard().getHiddenShips()->at(i).at(j) == true)
            {
                return false;
            }
        }
    }

    return true;
}

void Ai::placeShip(Point2D &start, Point2D& end, char rotation, int size, int shipsAmount)
{
    int startX = start.getX() * 8 + 26;
    int startY = start.getY() * 5 + 10;
    int endX = end.getX() * 8 + 26;
    int endY = end.getY() * 5 + 10;

    setUpHiddenShips(start, end); 

    addShipType({startX, startY}, {endX, endY}, rotation, size, shipsAmount);
}

void Ai::changeType(int &currentType, int amountOfShips)
{
    if (amountOfShips == 1)
    {
        currentType = 3;
    }
    else if (amountOfShips == 3)
    {
        currentType = 2;
    }
    else if (amountOfShips == 6)
    {
        currentType = 1;
    }   
}

void Ai::addShipType(Point2D start, Point2D end, char rotation, int size, int shipsAmount)
{
    switch (size)
    {
    case 1:
        getAiBoard().getShips()->at(shipsAmount) = std::make_shared<Single>(getGameConsole().getScreenHandle(), start, end);
        getAiBoard().getShips()->at(shipsAmount)->setRotation(rotation);
        break;
    
    case 2:
        getAiBoard().getShips()->at(shipsAmount) = std::make_shared<Dual>(getGameConsole().getScreenHandle(), start, end);
        getAiBoard().getShips()->at(shipsAmount)->setRotation(rotation);
        break;

    case 3:
        getAiBoard().getShips()->at(shipsAmount) = std::make_shared<Tripple>(getGameConsole().getScreenHandle(), start, end);
        getAiBoard().getShips()->at(shipsAmount)->setRotation(rotation);
        break;

    case 4:
        getAiBoard().getShips()->at(shipsAmount) = std::make_shared<Quadra>(getGameConsole().getScreenHandle(), start, end);
        getAiBoard().getShips()->at(shipsAmount)->setRotation(rotation);
        break;
    default:
        break;
    }
}

void Ai::setUpHiddenShips(Point2D &start, Point2D& end)
{
    if (start.getY() == end.getY())
    {    
        for (int j = start.getX(); j <= end.getX(); j++)
        {
            getAiBoard().getHiddenShips()->at(start.getY()).at(j) = true;
        }
    }
    else if (start.getX() == end.getX()) 
    {
        
        for (int i = start.getY(); i <= end.getY(); i++)
        {
            getAiBoard().getHiddenShips()->at(i).at(start.getX()) = true;
        }
    }
}

void Ai::modifyStartBasedOnPosition(Point2D &start, Point2D &end, int size, char rotation)
{
    size--;

    switch (rotation)
    {
    case 'N':
        start = Point2D(end.getX(), end.getY() - size);
        break;
    
    case 'E':
        start = end;
        end = Point2D(end.getX() + size, end.getY());
        break;

    case 'S':
        start = Point2D(end.getX(), end.getY() - size);
        break;

    case 'W':
        start = Point2D(end.getX() - size, end.getY());
        break;
    default:
        
        break;
    }
}

Point2D Ai::getStart(Point2D &end, int size, char rotation)
{
    switch (rotation)
    {
    case 'N':
        return Point2D(end.getX(), end.getY() - size);
        break;
    
    case 'E':
        return Point2D(end.getX() + size, end.getY());
        break;

    case 'S':
        return Point2D(end.getX(), end.getY() + size);
        break;

    case 'W':
        return Point2D(end.getX() - size, end.getY());
        break;
    default:
        return Point2D(end.getX(), end.getY() - size);
        break;
    }
}

char Ai::setRotation(int rotation)
{
    switch (rotation)
    {
    case 0:
        return 'N';
        break;
    
    case 1:
        return 'E';
        break;

    case 2:
        return 'S';
        break;

    case 3:
        return 'W';
        break;
    default:
        return 'N';
        break;
    }
}

void Ai::roundCursor(Point2D &consoleCursor)
{
    int nearestX = consoleCursor.getX();
    int nearestY = consoleCursor.getY();
    
    int minDiffX = 100;
    int minDiffY = 100;

    for (int xPoint : getAiBoard().getWidthPoints()) 
    {
        int diff = std::abs(xPoint - consoleCursor.getX());

        if (diff < minDiffX) 
        {
            minDiffX = diff;
            nearestX = xPoint;
        }
    }


    for (int yPoint : getAiBoard().getHeightPoints()) 
    {
        int diff = std::abs(yPoint - consoleCursor.getY());

        if (diff < minDiffY) 
        {
            minDiffY = diff;
            nearestY = yPoint;
        }
    }

    consoleCursor.setX(nearestX);
    consoleCursor.setY(nearestY);
}

Point2D Ai::getRandomShoot(Player& player)
{
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<> XYdistributor(0, 9);

    int newX;
    int newY;

    do
    {
        newX = XYdistributor(generator);
        newY = XYdistributor(generator);

    } while (player.getBoard().getShoots()->at(newY).at(newX));

    return Point2D(newX, newY);
}

void Ai::shoot()
{

}
