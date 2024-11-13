#ifndef AI_H
#define AI_H

    #include "../Board/Board.cc"

    class Ai
    {
    private:
        Board& aiBoard;
        Console& gameConsole;
    public:
        Ai(Console& gameConsole, Board& aiBoard);
        ~Ai();

        Board& getAiBoard() { return this->aiBoard; }
        Console& getGameConsole() { return this->gameConsole; }

        //Place Menu methods
        void randomizeBoard();
        void drawBoard();

        bool isSafeToPlace(Point2D &start, Point2D& end);
        void placeShip(Point2D &start, Point2D& end, char rotation, int size, int shipsAmount);
        void changeType(int& currentType, int amountOfShips);

        void addShipType(Point2D start, Point2D end, char rotation, int size, int shipsAmount);

        void setUpHiddenShips(Point2D &start, Point2D& end);
        void modifyStartBasedOnPosition(Point2D &start, Point2D& end, int size, char rotation);

        Point2D getStart(Point2D &end, int size, char rotation);
        char setRotation(int rotation);

        void roundCursor(Point2D &consoleCursor);

        // Shooting

        Point2D getRandomShoot(Player& player);

        void shoot();
    };
    
#endif