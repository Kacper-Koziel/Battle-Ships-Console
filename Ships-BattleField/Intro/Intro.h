#ifndef INTRO_H
#define INTRO_H
    #include "../Console/Console.cc"

    class Intro
    {
    private:
        Console window;
    public:
        Intro();
        Intro(Console& window);
        ~Intro();
        int playIntro();

        void drawTitle();
        int collectButtonsData(Console &window);

    };
    
#endif