#ifndef SHOOTMENU_H
#define SHOOTMENU_H
    #include "../Player/Player.cc"

    class ShootMenu
    {
    private:    
        std::vector<Player>& players;
        Console gameConsole;

        Board* boardTemplate;
    public:
        ShootMenu(Console& gameConsole, std::vector<Player>& players);
        ~ShootMenu();

        Console& getGameConsole() { return this->gameConsole; }
        Board* getBoardTemplate() { return this->boardTemplate; }
        std::vector<Player>& getPlayers() { return this->players; }

        int checkEvents();
        void drawMenu(Player& shooter, Player& defender);

        bool shoot(Player& defender, POINT& consoleCursor);
        bool isSinked(Player& defender, POINT& consoleCursor);
        bool isSinkedNS(Player &defender, int startY, int endY, int startX);
        bool isSinkedEW(Player &defender, int startX, int endX, int startY);

        void fillTheSpace(Player &defender, POINT &consoleCursor);
        void fillTheSpaceNS(Player &defender, int startX, int startY, int endX, int endY);
        void fillTheSpaceEW(Player &defender, int startY, int endX, int startX);

        int findShipIndex(Player& defender, POINT& consoleCursor);
        void roundCursor(POINT& cursor);
    };
    
#endif