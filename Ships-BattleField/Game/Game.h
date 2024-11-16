#ifndef GAME_H
#define GAME_H
    #include "../Console/Console.cc"
    #include "../Intro/Intro.cc"
    #include "../Board/Board.cc"
    #include "../Player/Player.cc"
    #include "../AI/Ai.cc"

    class Game
    {
    private:
        Console gameConsole;
        Intro* intro;
        
    public:
        Game(const Console& gameConsole);
        ~Game();

        Intro* getIntro() { return this->intro; }
        Console& getGameConsole() { return this->gameConsole; }

        void playMode(short mode);

        void PvPMode();
        void PvAiMode();

        void playPvpMode(Board& firstPlayerBoard, Board& secondPlayerBoard, Player& firstPlayer, Player& secondPlayer);
        void playPvAiMode(Board& playerBoard, Board& aiBoard, Player& player, Ai& ai);

        void showCredits();

        void play();

        void clearData(Player& player1, Player& player2);
        void clearDataAi(Player& player, Ai& ai);
    };
    
#endif