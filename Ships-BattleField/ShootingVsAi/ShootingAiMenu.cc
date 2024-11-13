#pragma once

#include "ShootingAiMenu.h"
#include "../Message/Message.cc"

ShootingAiMenu::ShootingAiMenu(Console& gameConsole, Player &player, Ai &ai) : gameConsole(gameConsole), player(player), ai(ai) 
{
    
}

ShootingAiMenu::~ShootingAiMenu()
{
    delete this->boardTemplate;

    this->boardTemplate = nullptr;
}

void ShootingAiMenu::drawMenu()
{
    getPlayer().getBoard().setOffset(10);
    getPlayer().getBoard().synchronizeShips();
    getPlayer().getBoard().drawBoard();
    getPlayer().getBoard().drawShips();
    getPlayer().getBoard().drawSigns();
    
    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 8);

    Alphabet::drawP(getGameConsole().getScreenHandle(), 13, 13, {121, 15});
    Number::draw1(getGameConsole().getScreenHandle(), 13, 13, {121, 40});

    Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);

    Alphabet::drawP(getGameConsole().getScreenHandle(), 13, 13, {120, 15});
    Number::draw1(getGameConsole().getScreenHandle(), 13, 13, {120, 40});

    getAi().getAiBoard().setOffset(130);
    getAi().getAiBoard().synchronizeShips();
    getAi().getAiBoard().drawBoard();
    getAi().getAiBoard().drawSigns();
}

void ShootingAiMenu::checkEvents()
{
    POINT cursor;

    GetCursorPos(&cursor);
    
    POINT consoleCursor;

    Convertions::toCharPosition(getGameConsole().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    bool isUpdated = true;
    bool isPlayersTurn = true;
    Point2D lastHit = {-1, -1};
    int aiShipsAmount = 10;
    int playerShipsAmount = 10;
    int targettedShipIndex = 0;

    while(aiShipsAmount > 0 && playerShipsAmount > 0)
    {
        if (isUpdated)
        {
            drawMenu();
            isUpdated = false;
        } 

        if (isPlayersTurn)
        {   
            makePlayersTurn(cursor, consoleCursor, aiShipsAmount, isPlayersTurn, isUpdated);
        }   
        else
        {
            makeAiTurn(lastHit, playerShipsAmount, targettedShipIndex, isPlayersTurn, isUpdated);
        }

    }

    Message winMessage(getGameConsole().getScreenHandle());

    if (playerShipsAmount > aiShipsAmount)
    {
        winMessage.showMessage(8);
    }
    else
    {
        winMessage.showMessage(7);
    }
    
}

void ShootingAiMenu::makePlayersTurn(POINT& cursor, POINT& consoleCursor, int& aiShipsAmount, bool& isPlayersTurn, bool& isUpdated)
{
    GetCursorPos(&cursor);
    Convertions::toCharPosition(getGameConsole().getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    if (Base::staticIsHovered(consoleCursor, {144, 9}, {220, 55}))
    {
        if (Base::staticIsClicked(consoleCursor, {144, 9}, {220, 55}))
        {
            if (!playerShoot(consoleCursor))
            {
                getAi().getAiBoard().drawSigns();
                Console::staticSleep(500);
                isPlayersTurn = false;
                isUpdated = true;
            }
            else
            {
                getAi().getAiBoard().drawSigns();
                drawMenu();

                if (playerIsSinked(consoleCursor))
                {
                    fillTheSpace(consoleCursor);
                    getAi().getAiBoard().drawSigns();

                    aiShipsAmount--;
                }
                
            }
            
        }
        
    }
}

bool ShootingAiMenu::playerShoot(POINT& consoleCursor)
{
    roundCursor(consoleCursor);

    int shootX = (consoleCursor.x - 144) / 8;
    int shootY = (consoleCursor.y - 9) / 5;

    if (getAi().getAiBoard().getShoots()->at(shootY).at(shootX) == false)
    {
        getAi().getAiBoard().getShoots()->at(shootY).at(shootX) = true;

        if (getAi().getAiBoard().getHiddenShips()->at(shootY).at(shootX) == true)
        {
            getAi().getAiBoard().getSigns()->push_back([this, consoleCursor](){
                Console::staticSetFontColor(getGameConsole().getScreenHandle(), 4);
                Alphabet::drawX(getGameConsole().getScreenHandle(), 4, 4, {consoleCursor.x, consoleCursor.y});
                Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);
            });

            return true;
        }
        else
        {
            getAi().getAiBoard().getSigns()->push_back([this, consoleCursor](){
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {consoleCursor.x, consoleCursor.y});
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

bool ShootingAiMenu::playerIsSinked(POINT &consoleCursor)
{
    int shipIndex = findShipIndex(consoleCursor);

    if (shipIndex == -1)
    {
        return false;
    }

    std::shared_ptr<Base> ship = getAi().getAiBoard().getShips()->at(shipIndex);

    int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
    int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
    int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
    int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

    if (ship->getDirection() == 'N' || ship->getDirection() == 'S')
    {
        return playerIsSinkedNS(startY, endY, startX);
    }
    else
    {
        return playerIsSinkedEW(startX, endX, startY);
    }
}

bool ShootingAiMenu::playerIsSinkedNS(int startY, int endY, int startX)
{
    int updatedEndY = (endY - 9) / 5;
    int updatedStartY = (startY - 9) / 5;
    int updatedStartX = (startX - 144) / 8;

    for (int i = updatedEndY; i <= updatedStartY; i++)
    {
        if (getAi().getAiBoard().getHiddenShips()->at(i).at(updatedStartX) == false || getAi().getAiBoard().getShoots()->at(i).at(updatedStartX) == false)
        {
            return false;
        }
        
    }
    
    return true;
}

bool ShootingAiMenu::playerIsSinkedEW(int startX, int endX, int startY)
{
    int updatedStartX = (startX - 144) / 8;
    int updatedEndX = (endX - 144) / 8;
    int updatedStartY = (startY - 9) / 5;

    for (int i = updatedEndX; i <= updatedStartX; i++)
    {
        if (getAi().getAiBoard().getHiddenShips()->at(updatedStartY).at(i) == false || getAi().getAiBoard().getShoots()->at(updatedStartY).at(i) == false)
        {
            return false;
        }
        
    }
    
    return true;
}

void ShootingAiMenu::fillTheSpace(POINT &consoleCursor)
{
    int shipIndex = findShipIndex(consoleCursor);
    std::shared_ptr<Base> ship = getAi().getAiBoard().getShips()->at(shipIndex);

    int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
    int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
    int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
    int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

    if (ship->getDirection() == 'N' || ship->getDirection() == 'S')
    {
        fillTheSpaceNS(startX, startY, endX, endY);
    }
    else
    {
        fillTheSpaceEW(startY, endX, startX);
    }
}

void ShootingAiMenu::fillTheSpaceNS(int startX, int startY, int endX, int endY)
{
    for (int y = endY - 5; y <= startY + 5; y += 5)
    {
        for (int x = endX - 8; x <= startX + 8; x += 8)
        {
            if (x < 144 || x > 220 || y < 9 || y > 55 || (x >= endX && x <= startX && y >= endY && y <= startY))
            {
                continue;
            }

            getAi().getAiBoard().getSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x, y});
            });
            
            int indexX = (x - 144) / 8;
            int indexY = (y - 9) / 5;

            if (indexX >= 0 && indexX < 10 && indexY >= 0 && indexY < 10)
            {
                getAi().getAiBoard().getShoots()->at(indexY).at(indexX) = true;
            }
            
        }
    }
}

void ShootingAiMenu::fillTheSpaceEW(int startY, int endX, int startX)
{
    for (int y = startY - 5; y <= startY + 5; y += 5)
    {
        for (int x = endX - 8; x <= startX + 8; x += 8)
        {
            if (x < 144 || x > 220 || y < 9 || y > 55 || (x >= endX && x <= startX && y == startY))
            {
                continue;
            }

            getAi().getAiBoard().getSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x, y});
            });

            int indexX = (x - 144) / 8;
            int indexY = (y - 9) / 5;

            if (indexX >= 0 && indexX < 10 && indexY >= 0 && indexY < 10)
            {
                getAi().getAiBoard().getShoots()->at(indexY).at(indexX) = true;
            }
        }
    }
}

int ShootingAiMenu::findShipIndex(POINT &consoleCursor)
{
    roundCursor(consoleCursor);

    for (int i = 0; i < 10; i++)
    {
        std::shared_ptr<Base> ship = getAi().getAiBoard().getShips()->at(i);

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

void ShootingAiMenu::roundCursor(POINT &consoleCursor)
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

void ShootingAiMenu::makeAiTurn(Point2D& lastHit, int& playerShipsAmount, int& targettedShipIndex, bool& isPlayersTurn, bool& isUpdated)
{
    isUpdated = true;
    Point2D hit = {0, 0};

    bool isHitted = false;

    if (targettedShipIndex < 0 || lastHit.getX() < 0 || lastHit.getY() < 0)
    {
        hit = getAi().getRandomShoot(getPlayer());
    }
    else
    {
        hit = calculateNewHit(targettedShipIndex, lastHit);
    }

    Console::staticSleep(300);
    
    if (isHitted = isHittedAi(hit))
    {
        targettedShipIndex = findShipIndexAi(hit);
        lastHit = hit;
        
        if (isSinkedAi(hit))
        {
            playerShipsAmount--;
            fillTheSpaceAi(hit);
            targettedShipIndex = -1;
        }
    }
    else
    {
        isPlayersTurn = true;
    }
    
}

bool ShootingAiMenu::isHittedAi(Point2D& hit)
{
    int newX = hit.getX() * 8 + 26;
    int newY = hit.getY() * 5 + 10;

    getPlayer().getBoard().getShoots()->at(hit.getY()).at(hit.getX()) = true;

    if (getPlayer().getBoard().getHiddenShips()->at(hit.getY()).at(hit.getX()) == true)
    {
        getPlayer().getBoard().getSigns()->push_back([this, newX, newY](){
            Console::staticSetFontColor(getGameConsole().getScreenHandle(), 4);
            Alphabet::drawX(getGameConsole().getScreenHandle(), 4, 4, {newX, newY});
            Console::staticSetFontColor(getGameConsole().getScreenHandle(), 7);
        });

        return true;
    }
    else
    {
        getPlayer().getBoard().getSigns()->push_back([this, newX, newY](){
            Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {newX, newY});
        });
    }

    return false;
}

Point2D ShootingAiMenu::calculateNewHit(int& targettedShipIndex, Point2D& lastHit)
{
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<> perfectProcentage(0, 2);

    Point2D newHit = {-1, -1};

    while (true)
    {
        newHit = (perfectProcentage(generator) % 2 == 0) ? getPerfectHit(targettedShipIndex, lastHit) : getBadHit(lastHit);


        if (!getPlayer().getBoard().getShoots()->at(newHit.getY()).at(newHit.getX()))
        {
            return newHit;
        }
        
    }
    
}

Point2D ShootingAiMenu::getPerfectHit(int& targettedShipIndex, Point2D& lastHit)
{
    char direction = getPlayer().getBoard().getShips()->at(targettedShipIndex)->getDirection();

    Point2D start = getPlayer().getBoard().getShips()->at(targettedShipIndex)->getStart();
    Point2D end = getPlayer().getBoard().getShips()->at(targettedShipIndex)->getEnd();

    start.setX((start.getX() - 26) / 8);
    start.setY((start.getY() - 10) / 5);

    end.setX((end.getX() - 26) / 8);
    end.setY((end.getY() - 10) / 5);

    int startX = Convertions::MAX(start.getX(), end.getX());
    int startY = Convertions::MAX(start.getY(), end.getY());
    int endX = Convertions::MIN(start.getX(), end.getX());
    int endY = Convertions::MIN(start.getY(), end.getY());
    
    std::vector<Point2D> freePoints;

    for (int i = endY; i <= startY; i++)
    {
        for (int j = endX; j <= startX; j++)
        {
            if (getPlayer().getBoard().getShoots()->at(i).at(j) == false)
            {
                freePoints.push_back({j, i});
            }
        }
    }

    if (!freePoints.empty())
    {
        std::random_device seed;
        std::mt19937 generator(seed());
        std::uniform_int_distribution<> randomDistributor(0, freePoints.size() - 1);

        return freePoints.at(randomDistributor(generator));
    }

    targettedShipIndex = -1;
    
    return getAi().getRandomShoot(getPlayer());
}

Point2D ShootingAiMenu::getBadHit(Point2D& lastHit)
{
    char direction = getBadHitDirection(lastHit);
    
    return getHitBasedOnDirection(lastHit, direction);
}

std::vector<char> ShootingAiMenu::unSetDirections(std::vector<char> &options, Point2D &lastHit)
{
    std::vector<char> validOptions;


    if (lastHit.getX() > 0 && !getPlayer().getBoard().getShoots()->at(lastHit.getY()).at(lastHit.getX() - 1))
    {
        validOptions.push_back('W');
    }

    if (lastHit.getX() < 9 && !getPlayer().getBoard().getShoots()->at(lastHit.getY()).at(lastHit.getX() + 1))
    {
        validOptions.push_back('E');
    }

    if (lastHit.getY() > 0 && !getPlayer().getBoard().getShoots()->at(lastHit.getY() - 1).at(lastHit.getX()))
    {
        validOptions.push_back('N');
    }

    if (lastHit.getY() < 9 && !getPlayer().getBoard().getShoots()->at(lastHit.getY() + 1).at(lastHit.getX()))
    {
        validOptions.push_back('S');
    }

    return validOptions;
}

Point2D ShootingAiMenu::getHitBasedOnDirection(Point2D &lastHit, char direction)
{
    switch (direction)
    {
    case 'N':
        return Point2D(lastHit.getX(), lastHit.getY() - 1);
        break;
    
    case 'E':
        return Point2D(lastHit.getX() + 1, lastHit.getY());
        break;

    case 'S':
        return Point2D(lastHit.getX(), lastHit.getY() + 1);
        break;

    case 'W':
        return Point2D(lastHit.getX() - 1, lastHit.getY());
        break;
    default:
        return getAi().getRandomShoot(getPlayer());
        break;
    }
}
char ShootingAiMenu::getBadHitDirection(Point2D &lastHit)
{
    std::vector<char> options = {'N', 'E', 'S', 'W'};

    options = unSetDirections(options, lastHit);

    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<> randomDirection(0, options.size() - 1);

    char random = options.at(randomDirection(generator));
    return random;
}


bool ShootingAiMenu::isSinkedAi(Point2D &consoleCursor)
{
    int shipIndex = findShipIndexAi(consoleCursor);

    if (shipIndex == -1)
    {
        return false;
    }

    std::shared_ptr<Base> ship = getPlayer().getBoard().getShips()->at(shipIndex);

    int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
    int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
    int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
    int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

    if (ship->getDirection() == 'N' || ship->getDirection() == 'S')
    {
        return isSinkedNSAi(startY, endY, startX);
    }
    else
    {
        return isSinkedEWAi(startX, endX, startY);
    }
}

bool ShootingAiMenu::isSinkedNSAi(int startY, int endY, int startX)
{
    int newStartX = (startX - 26) / 8;
    int newStartY = (startY - 10) / 5;
    int newEndY = (endY - 10) / 5;


    for (int i = newEndY; i <= newStartY; i++)
    {
        if (!getPlayer().getBoard().getHiddenShips()->at(i).at(newStartX) || !getPlayer().getBoard().getShoots()->at(i).at(newStartX))
        {
            return false;
        }
    }
    
    return true;
}

bool ShootingAiMenu::isSinkedEWAi(int startX, int endX, int startY)
{
    int newStartX = (startX - 26) / 8;
    int newStartY = (startY - 10) / 5;
    int newEndX = (endX - 26) / 8;


    for (int i = newEndX; i <= newStartX; i++)
    {
        if (!getPlayer().getBoard().getHiddenShips()->at(newStartY).at(i) || !getPlayer().getBoard().getShoots()->at(newStartY).at(i))
        {
            return false;
        }
    }
    
    return true;
}

void ShootingAiMenu::fillTheSpaceAi(Point2D &consoleCursor)
{

    int shipIndex = findShipIndexAi(consoleCursor);
    std::shared_ptr<Base> ship = getPlayer().getBoard().getShips()->at(shipIndex);

    int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
    int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
    int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
    int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

    if (ship->getDirection() == 'N' || ship->getDirection() == 'S')
    {
        fillTheSpaceNSAi(startX, startY, endX, endY);
    }
    else
    {
        fillTheSpaceEWAi(startY, endX, startX);
    }
}

void ShootingAiMenu::fillTheSpaceNSAi(int startX, int startY, int endX, int endY)
{

    for (int y = endY - 5; y <= startY + 5; y += 5)
    {
        for (int x = endX - 8; x <= startX + 8; x += 8)
        {
            if (x < 26 || x > 102 || y < 10 || y > 56 || (x >= endX && x <= startX && y >= endY && y <= startY))
            {
                continue;
            }

            getPlayer().getBoard().getSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x, y});
            });
            
            int indexX = (x - 26) / 8;
            int indexY = (y - 10) / 5;

            if (indexX >= 0 && indexX < 10 && indexY >= 0 && indexY < 10)
            {
                getPlayer().getBoard().getShoots()->at(indexY).at(indexX) = true;
            }
            
        }
    } 
}

void ShootingAiMenu::fillTheSpaceEWAi(int startY, int endX, int startX)
{

    for (int y = startY - 5; y <= startY + 5; y += 5)
    {
        for (int x = endX - 8; x <= startX + 8; x += 8)
        {
            if (x < 26 || x > 102 || y < 10 || y > 56 || (x >= endX && x <= startX && y == startY))
            {
                continue;
            }

            getPlayer().getBoard().getSigns()->push_back([this, x, y]() {
                Number::drawLower0(getGameConsole().getScreenHandle(), 3, 4, {x, y});
            });

            int indexX = (x - 26) / 8;
            int indexY = (y - 10) / 5;

            if (indexX >= 0 && indexX < 10 && indexY >= 0 && indexY < 10)
            {
                getPlayer().getBoard().getShoots()->at(indexY).at(indexX) = true;
            }
        }
    }   
}

int ShootingAiMenu::findShipIndexAi(Point2D &coords)
{
    int newCoordsX = coords.getX() * 8 + 26;
    int newCoordsY = coords.getY() * 5 + 10;

    for (int i = 0; i < 10; i++)
    {
        std::shared_ptr<Base> ship = getPlayer().getBoard().getShips()->at(i);

        int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
        int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
        int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
        int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

        if (newCoordsX >= endX && newCoordsX <= startX && newCoordsY >= endY && newCoordsY <= startY)
        {
            return i;
        }
        
    }

    return -1;
}
