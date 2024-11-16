#ifndef BASE_H
#define BASE_H

#include "../../Structures/Structures.h"
#include <Windows.h>

    class Base
    {
    protected:
        HANDLE screenHandle;
        int blocksLeft = 0;
        Point2D constStart = {0, 0};
        Point2D constEnd = {0, 0};
        Point2D start = {0, 0};
        Point2D end = {0, 0};
        char rotation = 'N';
    public:
        virtual ~Base() {};
        virtual void drawShipN() = 0;
        virtual void drawShipE() = 0;
        virtual void drawShipS() = 0;
        virtual void drawShipW() = 0;

        HANDLE& getScreenHandle() { return this->screenHandle; }
        Point2D& getStart() { return this->start; }
        Point2D& getEnd() { return this->end; }
        char getDirection() const { return this->rotation; }
        Point2D& getConstStart() { return this->constStart; }
        Point2D& getConstEnd() { return this->constEnd; }

        void setStart(Point2D newStart) { this->start = newStart; }
        void setEnd(Point2D newEnd) { this->end = newEnd; }
        void setRotation(char newRotation) { this->rotation = newRotation; }

        bool isHovered(POINT cursor) { return cursor.x >= (getStart().getX() - 2) && cursor.x <= (getEnd().getX() + 1) && cursor.y >= (getStart().getY() - 2) && cursor.y <= (getEnd().getY() + 2); }
        static bool staticIsHovered(POINT cursor, Point2D start, Point2D end) { return cursor.x >= (start.getX() - 2) && cursor.x <= (end.getX() + 1) && cursor.y >= (start.getY() - 2) && cursor.y <= (end.getY() + 2); }

        bool isClicked(POINT cursor) { return isHovered(cursor) ? (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0 : false; }
        static bool staticIsClicked(POINT cursor, Point2D start, Point2D end) { return Base::staticIsHovered(cursor, start, end) ? (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0 : false; }

        bool isKeyPressed(char key) const {return GetAsyncKeyState(key) & 0x8000; }
        static bool staticIsKeyPressed(char key) {return GetAsyncKeyState(key) & 0x8000; }
    };
    
#endif