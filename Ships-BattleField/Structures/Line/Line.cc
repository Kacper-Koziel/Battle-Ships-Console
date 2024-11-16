#pragma once

#include "Line.h"
#include <iostream>
#include <locale>

Line::Line() : start({0, 0}), end({0, 0}) {}

Line::Line(const Point2D& start, const Point2D& end) : start(start), end(end) {}

void Line::drawLine(const HANDLE &screenHandle, const Line &line)
{
    int startX = line.getStart().getX();
    int startY = line.getStart().getY();
    int endX = line.getEnd().getX();
    int endY = line.getEnd().getY();

    int delX = abs(endX - startX);
    int delY = abs(endY - startY);

    int stepX = startX < endX ? 1 : -1;
    int stepY = startY < endY ? 1 : -1;
    int error = delX - delY; 

    SetConsoleOutputCP(CP_UTF8);

    while (true)
    {
        SetConsoleCursorPosition(screenHandle, { static_cast<short>(startX), static_cast<short>(startY) });
        std::cout << "\u2588"; //Day 1. VsCode dont wanna work with me so i use cout (insted of wcout); i feel bullied by my own code

        if (startX == endX && startY == endY) break;

        int doubError = 2 * error;

        if (doubError > -delY)
        {
            error = error - delY;
            startX = startX + stepX;
        }

        if (doubError < delX)
        {
            error = error + delX;
            startY = startY + stepY;
        }
    }
}

void Line::drawTopBlockLine(const HANDLE &screenHandle, const Line &line)
{
    int startX = line.getStart().getX();
    int startY = line.getStart().getY();
    int endX = line.getEnd().getX();
    int endY = line.getEnd().getY();

    int delX = abs(endX - startX);
    int delY = abs(endY - startY);

    int stepX = startX < endX ? 1 : -1;
    int stepY = startY < endY ? 1 : -1;
    int error = delX - delY; 

    SetConsoleOutputCP(CP_UTF8);

    while (true)
    {
        SetConsoleCursorPosition(screenHandle, { static_cast<short>(startX), static_cast<short>(startY) });
        std::cout << "\u2580";

        if (startX == endX && startY == endY) break;

        int doubError = 2 * error;

        if (doubError > -delY)
        {
            error = error - delY;
            startX = startX + stepX;
        }

        if (doubError < delX)
        {
            error = error + delX;
            startY = startY + stepY;
        }
    }
}

void Line::drawBottomBlockLine(const HANDLE &screenHandle, const Line &line)
{
    int startX = line.getStart().getX();
    int startY = line.getStart().getY();
    int endX = line.getEnd().getX();
    int endY = line.getEnd().getY();

    int delX = abs(endX - startX);
    int delY = abs(endY - startY);

    int stepX = startX < endX ? 1 : -1;
    int stepY = startY < endY ? 1 : -1;
    int error = delX - delY; 

    SetConsoleOutputCP(CP_UTF8);

    while (true)
    {
        SetConsoleCursorPosition(screenHandle, { static_cast<short>(startX), static_cast<short>(startY) });
        std::cout << "\u2584";

        if (startX == endX && startY == endY) break;

        int doubError = 2 * error;

        if (doubError > -delY)
        {
            error = error - delY;
            startX = startX + stepX;
        }

        if (doubError < delX)
        {
            error = error + delX;
            startY = startY + stepY;
        }
    }
}

