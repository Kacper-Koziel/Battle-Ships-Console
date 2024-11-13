#include "Console/Console.cc"
#include "Game/Game.cc"

int main()
{
    Console newWindow;
    newWindow.setConsoleSize();

    Game newGame(newWindow);

    newGame.play();

    // Message newMessage(newWindow.getScreenHandle());

    // newMessage.showMessage(8);
    Console::staticSleep(500000);

}