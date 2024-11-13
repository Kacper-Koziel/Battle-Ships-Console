#ifndef CONVERTIONS_H
#define CONVERTIONS_H
    #include <Windows.h>

    namespace Convertions
    {
        static void toCharPosition(const HWND& consoleWindow, POINT& cursor, int &row, int &column);
        static void toCharPosition(const HWND &consoleWindow, POINT &cursor, long &column, long &row);


        //Nah this pc is ducking with me.. I cant even use std::max and std::min
        template <typename T>
        T MAX(T a, T b)
        {
            return a > b ? a : b;
        }

        template <typename T>
        T MIN(T a, T b)
        {
            return a > b ? b : a;
        }
    }
    
#endif