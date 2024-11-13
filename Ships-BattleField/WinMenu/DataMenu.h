#ifndef DATAMENU_H
#define DATAMENU_H

    #include "../Console/Console.cc"
    #include "../Player/Player.cc"

    class DataMenu
    {
    private:
        Console& gameConsole;
        Player& winner;
    public:
        DataMenu(Console& gameConsole, Player &winner);
        ~DataMenu();

        Player& getWinner() { return this->winner; }
        Console& getGameConsole() { return this->gameConsole; }

        void drawResults();

        void drawTotal(int total);
    };

    
#endif