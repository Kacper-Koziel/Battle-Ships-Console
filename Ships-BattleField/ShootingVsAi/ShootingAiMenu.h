#ifndef SHOOTINGAIMENU_H
#define SHOOTINGAIMENU_H

    #include "../Player/Player.cc"
    #include "../AI/Ai.cc"

    class ShootingAiMenu
    {
    private:
        Console& gameConsole;
        Player& player;
        Ai& ai;

        Board* boardTemplate = new Board(getGameConsole().getScreenHandle(), 130);
    public:
        ShootingAiMenu(Console& gameConsole, Player& player, Ai& ai);
        ~ShootingAiMenu();

        Board* getBoardTemplate() { return this->boardTemplate; }
        Console& getGameConsole() { return this->gameConsole; }
        Player& getPlayer() { return this->player; }
        Ai& getAi() { return this->ai; }

        void drawMenu();
        void checkEvents();
        void makePlayersTurn(POINT& cursor, POINT& consoleCursor, int& aiShipsAmount, bool& isPlayersTurn, bool& isUpdated);

        bool playerShoot(POINT& consoleCursor);

        bool playerIsSinked(POINT& consoleCursor);
        bool playerIsSinkedNS(int startY, int endY, int startX);
        bool playerIsSinkedEW(int startX, int endX, int startY);

        void fillTheSpace(POINT &consoleCursor);
        void fillTheSpaceNS(int startX, int startY, int endX, int endY);
        void fillTheSpaceEW(int startY, int endX, int startX);

        
        int findShipIndex(POINT& consoleCursor);
        void roundCursor(POINT& cursor);

        void makeAiTurn(Point2D& lastHit, Point2D& solidHit, int& playerShipsAmount, bool& isPlayersTurn, bool& isUpdated);

        bool isHittedAi(Point2D& hit);

        bool isSinkedAi(Point2D& consoleCursor);
        bool isSinkedNSAi(int startY, int endY, int startX);
        bool isSinkedEWAi(int startX, int endX, int startY);

        void fillTheSpaceAi(Point2D &consoleCursor);
        void fillTheSpaceNSAi(int startX, int startY, int endX, int endY);
        void fillTheSpaceEWAi(int startY, int endX, int startX);

        Point2D calculateNewHit(Point2D& lastHit, Point2D& solidHit);
        Point2D getHit(Point2D& lastHit, Point2D& solidHit);

        std::vector<char> unSetDirections(Point2D &lastHit);
        Point2D getHitBasedOnDirection(Point2D &lastHit, char direction);
        char getHitDirection(Point2D& lastHit, Point2D& solidHit);

        int findShipIndexAi(Point2D& coords);

    };
    

#endif