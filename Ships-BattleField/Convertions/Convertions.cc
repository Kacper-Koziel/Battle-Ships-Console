#pragma once

#include "Convertions.h"

void Convertions::toCharPosition(const HWND &consoleWindow, POINT &cursor, int &column, int &row)
{
    GetCursorPos(&cursor);

    ScreenToClient(consoleWindow, &cursor);

    column = cursor.x / 8;
    row = cursor.y / 16;

    column = column < 240 ? column : 239;
    row = row < 63 ? row : 62;
}

void Convertions::toCharPosition(const HWND &consoleWindow, POINT &cursor, long &column, long &row)
{
    GetCursorPos(&cursor);

    ScreenToClient(consoleWindow, &cursor);

    column = cursor.x / 8;
    row = cursor.y / 16;

    column = column < 240 ? column : 239;
    row = row < 63 ? row : 62;
}