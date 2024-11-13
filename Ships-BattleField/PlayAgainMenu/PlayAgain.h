#ifndef PLAYAGAIN_H
#define PLAYAGAIN_H
    #include "../Console/Console.cc"

    class PlayAgainMenu
    {
    private:
        Console& gameConsole;
    public:
        PlayAgainMenu(Console& gameConsole);
        ~PlayAgainMenu();

        Console& getGameConsole() { return this->gameConsole; }

        bool wannaPlayAgain();

        void writeText();
    };
    
#endif