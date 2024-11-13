#pragma once

#include "Game.h"
#include "../Player/Player.cc"
#include "../PlaceMenu/PlaceMenu.cc"
#include "../ShootingMenu/ShootMenu.cc"
#include "../PlayAgainMenu/PlayAgain.cc"
#include "../WinMenu/DataMenu.cc"
#include "../Credits/Credits.cc"
#include "../ShootingVsAi/ShootingAiMenu.cc"

Game::Game(const Console &gameConsole) : gameConsole(gameConsole)
{
    this->intro = new Intro(this->gameConsole);
}

Game::~Game()
{
    delete this->intro;
}

void Game::playMode(short mode)
{
    switch (mode)
    {
    case 1:
        PvPMode();
        break;
    
    case 2:
        PvAiMode();
        break;
    
    case 3:
        showCredits();
        break;
    default:
        break;
    }
}

void Game::PvPMode()
{
    Console::staticClear();

    Board firstPlayerBoard(getGameConsole().getScreenHandle(), 10);
    Board secondPlayerBoard(getGameConsole().getScreenHandle(), 10);

    Player firstPlayer(firstPlayerBoard, 1);
    Player secondPlayer(secondPlayerBoard, 2);

    PlayAgainMenu againMenu(getGameConsole());


    bool playAgain = true;
    
    while(playAgain)
    {
        playPvpMode(firstPlayerBoard, secondPlayerBoard, firstPlayer, secondPlayer);

        playAgain = againMenu.wannaPlayAgain();

        Console::staticClear();

        if (playAgain)
        {
            clearData(firstPlayer, secondPlayer);
        }
    }

    Console::staticSleep(1000);
}

void Game::PvAiMode()
{
    Board playerBoard(getGameConsole().getScreenHandle(), 10);
    Board aiBoard(getGameConsole().getScreenHandle(), 10);

    Player player(playerBoard, 1);
    Ai newAi(getGameConsole(), aiBoard);

    PlayAgainMenu againMenu(getGameConsole());

    bool playAgain = true;

    while (playAgain)
    {
        playPvAiMode(playerBoard, aiBoard, player, newAi);

        playAgain = againMenu.wannaPlayAgain();

        Console::staticClear();

        if (playAgain)
        {
            clearDataAi(player, newAi);
        }
        
    }
    
}

void Game::playPvpMode(Board& firstPlayerBoard, Board& secondPlayerBoard, Player& firstPlayer, Player& secondPlayer)
{
    PlaceMenu firstPlayerPlaces(firstPlayerBoard, getGameConsole());
    PlaceMenu secondPlayerPlaces(secondPlayerBoard, getGameConsole());

    std::vector<Player> players = { firstPlayer, secondPlayer };

    Message newMessage(getGameConsole().getScreenHandle());

    int temporaryData = 0;

    do
    {
        if (temporaryData == 0)
        {
            newMessage.showMessage(4);
            Console::staticClear();
        }

    } while((temporaryData = firstPlayerPlaces.checkEvents()) != 2);

    temporaryData = 0;

    do
    {
        if (temporaryData == 0)
        {
            newMessage.showMessage(5);
            Console::staticClear();
        }

    } while((temporaryData = secondPlayerPlaces.checkEvents()) != 2);

    ShootMenu newShoot(getGameConsole(), players);
    
    temporaryData = newShoot.checkEvents();
    Console::staticClear();

    if (temporaryData == 1)
    {
        firstPlayer.setWins(firstPlayer.getWins() + 1);
        DataMenu newData(getGameConsole(), firstPlayer);
        newData.drawResults();
    }
    else
    {
        secondPlayer.setWins(secondPlayer.getWins() + 1);
        DataMenu newData(getGameConsole(), secondPlayer);
        newData.drawResults();
    }

    Console::staticSleep(3000);
    Console::staticClear();

    firstPlayer.setGamesPlayed(firstPlayer.getGamesPlayed() + 1);
    secondPlayer.setGamesPlayed(secondPlayer.getGamesPlayed() + 1);

    firstPlayer.calculateKD();
    secondPlayer.calculateKD();
}

void Game::playPvAiMode(Board &playerBoard, Board &aiBoard, Player &player, Ai &ai)
{
    PlaceMenu playerPlaces(playerBoard, getGameConsole());

    Message newMessage(getGameConsole().getScreenHandle());

    int temporaryData = 0;

    ai.randomizeBoard();

    do
    {
        if (temporaryData == 0)
        {
            newMessage.showMessage(4);
            Console::staticClear();
        }

    } while((temporaryData = playerPlaces.checkEvents()) != 2);

    ShootingAiMenu newShooting(getGameConsole(), player, ai);

    newShooting.checkEvents();

    Console::staticSleep(3000);
    Console::staticClear();
}

void Game::showCredits()
{
    Credits newCredits(getGameConsole());

    Console::staticClear();

    newCredits.drawCredits();
}

void Game::play()
{
    int temporaryData = 0;

    while (getGameConsole().isOpen())
    {   
        temporaryData = getIntro()->playIntro();

        playMode(static_cast<short>(temporaryData));
    }
    
}

void Game::clearData(Player& player1, Player& player2)
{
    player1.getBoard().clearData();
    player2.getBoard().clearData();
    
    player1.getBoard().setOffset(10);
    player2.getBoard().setOffset(10);
}

void Game::clearDataAi(Player &player, Ai &ai)
{
    player.getBoard().clearData();
    player.getBoard().setOffset(10);

    ai.getAiBoard().clearData();
}
