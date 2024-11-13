#ifndef ALPHABET_H
#define ALPHABET_H

    #include "../Structures/Structures.h"
    #include <Windows.h>

    namespace Alphabet //Board l. stats: 5 x 5, mid(6, y);
    {
        void drawA(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawB(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawC(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawD(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawE(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawF(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawG(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawH(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawI(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawJ(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawK(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawL(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawM(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawN(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawO(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawP(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawR(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawS(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawT(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawU(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawW(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawY(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawZ(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawX(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawV(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);

        //I hate you microsoft for not adding font sizes >:(
        void drawLowerB(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint);
        void drawLowerC(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint);
        void drawLowerG(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint);
        void drawLowerJ(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint);
    };
    
#endif