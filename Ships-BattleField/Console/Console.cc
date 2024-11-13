#pragma once

#include "Console.h"
#include <iostream>
#include <thread>
#include <chrono>

Console::Console()
{
    this->screenHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    this->mouseInput = GetStdHandle(STD_INPUT_HANDLE);
    this->consoleWindow = GetConsoleWindow();
    SetConsoleTitleW(L"Ships-BattleField");
    disableQuickMode();
}

Console::~Console()
{

}

void Console::disableQuickMode()
{
    DWORD mode;
    
    if (!GetConsoleMode(getInputHandle(), &mode))
    {
        std::cerr << "Cant reach current mode" << std::endl;
        SetConsoleTitleW(L"Ships-BattleField-ERROR");
        return;
    }

    //Sht is going crazy on here.. bit operations 
    mode &= ~ENABLE_QUICK_EDIT_MODE;
    mode |= ENABLE_EXTENDED_FLAGS;
    mode |= ENABLE_MOUSE_INPUT;

    if (!SetConsoleMode(getInputHandle(), mode))
    {
        SetConsoleTitleW(L"Ships-BattleField-ERROR");
        return;
    }
    
}

void Console::setConsoleSize(int height, int width)
{
    if(this->screenHandle == NULL)
    {
        std::cerr << "Cant reach screen handle" << std::endl;
        SetConsoleTitleW(L"Ships-BattleField-ERROR");
        return;
    }

    COORD newBufferSize{static_cast<short>(width), static_cast<short>(height)}; //Same as ()

    if (!SetConsoleScreenBufferSize(this->screenHandle, newBufferSize))
    {
        std::cerr << "Cant set new buffer size" << std::endl;
        SetConsoleTitleW(L"Ships-BattleField-ERROR");
        return;
    }

    SMALL_RECT windowSize{0, 0, static_cast<short>(width - 1), static_cast<short>(height - 1)}; //Phisical console space

    if (!SetConsoleWindowInfo(this->screenHandle, TRUE, &windowSize))
    {
        std::cerr << "Cant set new phisical window size" << std::endl;
        SetConsoleTitleW(L"Ships-BattleField-ERROR");
        return;
    }
    
    SetWindowPos(this->consoleWindow, 0, -8, 0, 0, 0, SWP_NOSIZE);
}

void Console::setTitle(const std::wstring &title)
{
    this->title = title;
    SetConsoleTitleW(title.c_str());
}

void Console::setFontColor(short textColor)
{
    SetConsoleTextAttribute(getScreenHandle(), textColor);
}

void Console::clear()
{
    system("cls");
}

void Console::sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Console::staticClear()
{
    system("cls");
}

void Console::staticSleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void Console::staticSetFontColor(const HANDLE &screenHandle, short textColor)
{
    SetConsoleTextAttribute(screenHandle, textColor);
}

bool Console::isHovered()
{
    return false;
}

bool Console::isOpen()
{
    return IsWindow(this->consoleWindow);
}
