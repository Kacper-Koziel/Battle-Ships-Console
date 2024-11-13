#ifndef BUTTON_H
#define BUTTON_H

#include "Windows.h"
#include "../Structures/Structures.h"
#include "../Intro/Intro.cc"

    class Button
    {
    private:
        HWND consoleWindow;
        HANDLE screenHandle;
        void (*creationFunct)(const HANDLE&, int, int, const Point2D&, short);
        int height;
        int width;
        Point2D middlePoint;
    public:
        Button(const HANDLE& screenHandle, const HWND& consoleWindow ,void (*creationFunct)(const HANDLE&, int, int, const Point2D& ,short), int height, int width, const Point2D& middlePoint);
        ~Button();

        HANDLE getScreenHandle() const { return this->screenHandle; }
        HWND getConsoleWindow() const { return this->consoleWindow; }
        int getHeight() const { return this->height; }
        int getWidth() const { return this->width; }
        Point2D getMiddlePoint() const { return this->middlePoint; }

        bool isHovered(POINT cursor);
        bool isClicked(POINT cursor);

        bool checkEvents();
        bool checkEvents(Intro* introTitle, Button* otherButton1, Button* otherButton2);

        void drawButton(short offset);
        static void staticDrawButton(const HANDLE& screenHandle, short offset,  void (*creationFunct)(const HANDLE&, short));
    };
    
#endif