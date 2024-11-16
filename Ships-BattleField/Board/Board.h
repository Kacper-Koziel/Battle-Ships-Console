#ifndef BOARD_H
#define BOARD_H

#include "../Alphabet/Alphabet.cc"
#include "../Numbers/Number.cc"
#include "../Button/Button.cc"
#include "../Ships/Ships.h"
#include <vector>
#include <memory>
#include <functional>

class Board
{
private:
    HANDLE screenHandle;
    
    short offset;
    std::vector<int> heightPoints;
    std::vector<int> widthPoints;

    std::vector<std::vector<bool>>* hiddenShips = new std::vector<std::vector<bool>>();
    std::vector<std::shared_ptr<Base>>* ships = new std::vector<std::shared_ptr<Base>>();
    std::vector<std::shared_ptr<Base>>* defeatedShips = new std::vector<std::shared_ptr<Base>>();
    std::shared_ptr<std::vector<std::function<void()>>> signs = std::make_shared<std::vector<std::function<void()>>>(); //In this line more happends than in my whole life. Im terrified
    std::shared_ptr<std::vector<std::function<void()>>> ownBoardSigns = std::make_shared<std::vector<std::function<void()>>>();
    std::vector<std::vector<bool>>* hasBeenShoot = new std::vector<std::vector<bool>>();
    
public:
    Board() {}
    Board(HANDLE& screenHandle, short offset);
    ~Board();

    HANDLE& getScreenHandle() { return this->screenHandle; }
    short getOffset() const { return this->offset; }
    
    void setOffset(int newOffset) { this->offset = newOffset; }

    std::vector<int>& getHeightPoints() { return this->heightPoints; }
    std::vector<int>& getWidthPoints() { return this->widthPoints; }
    std::vector<std::vector<bool>>* getHiddenShips() { return this->hiddenShips; }
    
    std::vector<std::vector<bool>>* getShoots() { return this->hasBeenShoot; }
    std::vector<std::shared_ptr<Base>>* getShips() { return this->ships; }
    std::vector<std::shared_ptr<Base>>* getDefeatedShips() { return this->defeatedShips; }
    std::shared_ptr<std::vector<std::function<void()>>> getSigns() { return this->signs; }
    std::shared_ptr<std::vector<std::function<void()>>> getOwnBoardSigns() { return this->ownBoardSigns; }

    void clearHiddenShips();

    void setShipValue(std::shared_ptr<Base> value, int index);
    void synchronizePoints();
    void synchronizeShips();
    void synchronizeSigns();

    void drawBoard();
    void drawPoints();
    void drawShips();
    void drawDefeatedShips();
    void drawShipDirection(std::shared_ptr<Base> ship);
    void drawSigns();
    void drawOwnSigns();

    void clearData();
};


#endif
