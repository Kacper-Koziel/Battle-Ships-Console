#ifndef BUTTONS_H
#define BUTTONS_H

#include "../Structures/Structures.h"
#include <Windows.h>

    namespace Buttons
    {
        void PvPButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint,  short offset);
        void PvAiButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset);
        void CreditsButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset);
        void nextButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset);
        void clearButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset);
        void YESButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset);
        void NOButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset);
    }
    
#endif