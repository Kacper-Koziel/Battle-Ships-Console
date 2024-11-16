#pragma once

#include "Button.h"
#include "../Console/Console.cc"
#include "../Convertions/Convertions.cc"
#include <atomic>
#include <thread>

Button::Button(const HANDLE& screenHandle, const HWND& consoleWindow, void (*creationFunct)(const HANDLE&, int, int, const Point2D& ,short), int height, int width, const Point2D& middlePoint) : 
screenHandle(screenHandle), consoleWindow(consoleWindow) ,creationFunct(creationFunct), height(height), width(width), middlePoint(middlePoint) {}

Button::~Button()
{
    
}

bool Button::isHovered(POINT cursor)
{
    return cursor.x >= (getMiddlePoint().getX() - getWidth() / 2) && cursor.x <= (getMiddlePoint().getX() + getWidth() / 2) && cursor.y >= (getMiddlePoint().getY() - getHeight() / 2) && cursor.y <= (getMiddlePoint().getY() + getHeight() / 2);
}

bool Button::isClicked(POINT cursor)
{
    if (isHovered(cursor))
    {
        return GetAsyncKeyState(VK_LBUTTON) != 0;
    }
    
    return false;
}

bool Button::checkEvents() 
{
    POINT cursor;
    GetCursorPos(&cursor);

    POINT consoleCursor;
    Convertions::toCharPosition(getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    if (isHovered(consoleCursor)) {
        
        std::atomic<bool> isAnimated{true}; //Safer for multi-thread
        std::atomic<bool> clicked{false};
        
        std::thread clickThread([&]() {
            while (isAnimated.load()) {
                GetCursorPos(&cursor);
                Convertions::toCharPosition(getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

                if (isClicked(consoleCursor)) {
                    
                    isAnimated.store(false);
                    clicked.store(true);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
            }
        });

        
        Console::staticSetFontColor(getScreenHandle(), 1);
        drawButton(-1);
        Console::staticSetFontColor(getScreenHandle(), 7);
        drawButton(0);

        clickThread.detach();

        return clicked.load();
    }

    Console::staticSetFontColor(getScreenHandle(), 0);
    drawButton(-1);
    Console::staticSetFontColor(getScreenHandle(), 7);
    drawButton(0);

    return false;
}

bool Button::checkEvents(Intro* introTitle, Button *otherButton1, Button *otherButton2)
{
    POINT cursor;
    GetCursorPos(&cursor);

    POINT consoleCursor;
    Convertions::toCharPosition(getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

    if (isHovered(consoleCursor)) {
        
        std::atomic<bool> isAnimated{true}; //Safer for multi-thread
        std::atomic<bool> clicked{false};
        
        std::thread clickThread([&]() {
            while (isAnimated.load()) {
                GetCursorPos(&cursor);
                Convertions::toCharPosition(getConsoleWindow(), cursor, consoleCursor.x, consoleCursor.y);

                if (isClicked(consoleCursor)) {
                    
                    isAnimated.store(false);
                    clicked.store(true);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
            }
        });

        Console::staticSetFontColor(getScreenHandle(), 1);
        drawButton(-1);
        Console::staticSetFontColor(getScreenHandle(), 7);
        drawButton(0);


        clickThread.detach();

        return clicked.load();
    }

    Console::staticSetFontColor(getScreenHandle(), 0);
    drawButton(-1);
    Console::staticSetFontColor(getScreenHandle(), 7);
    drawButton(0);

    introTitle->drawTitle();
    otherButton1->drawButton(0);
    otherButton2->drawButton(0);
    drawButton(0);

    return false;
}

void Button::drawButton(short offset)
{
    (*this->creationFunct)(getScreenHandle(), getHeight(), getWidth(), getMiddlePoint(), offset);
}

void Button::staticDrawButton(const HANDLE &screenHandle, short offset, void (*creationFunct)(const HANDLE &, short))
{
    (*creationFunct)(screenHandle, offset);
}
