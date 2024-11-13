#ifndef CREDITS_H
#define CREDITS_H

    #include "../Console/Console.cc"

    class Credits
    {
    private:
        Console& gameConsole;
    public:
        Credits(Console& gameConsole);
        ~Credits();

        Console& getGameConsole() { return this->gameConsole; }

        void drawCredits();

        void drawName();

        void drawSurname();

        void drawClass();
    };
    
    
#endif