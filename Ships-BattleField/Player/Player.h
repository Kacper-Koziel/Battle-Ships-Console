#ifndef PLAYER_H
#define PLATER_H
    #include "../Board/Board.cc"
    #include "../Ships/Ships.h"

    class Player
    {
    private:
        int id;

        Board& myBoard;

        int wins = 0;
        int gamesPlayed = 0;
        float KD = 0;
    public:
        Player(Board& myBoard, int id);
        ~Player();

        Board& getBoard() { return this->myBoard; }
        int getID() { return this->id; }
        int getWins() { return this->wins; }
        int getGamesPlayed() { return this->gamesPlayed; }

        void setWins(int newWins) { this->wins = newWins; }
        void setGamesPlayed(int newGames) { this->gamesPlayed = newGames; }

        void calculateKD() { this->KD = getWins() / getGamesPlayed(); }
    };
    
#endif