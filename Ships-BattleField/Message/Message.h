#ifndef MESSAGE_H
#define MESSAGE_H
    #include <Windows.h>
    #include <string>
            
    class Message
    {
    private:
        HANDLE screenHandle;
    public:
        Message(const HANDLE& screenHandle);
        ~Message();

        HANDLE getScreenHandle() const { return this->screenHandle; }

        void errorText();
        void dontHaveEnough();
        void cantPlaceText();
        void dontHave10Ships();
        void player1Select();
        void player2Select();
        void cantShootHere();
        void aiWins();
        void playerWins();

        void showMessage(short code);
    };
    
#endif