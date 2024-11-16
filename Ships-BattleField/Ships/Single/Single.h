#ifndef SINGLE_H
#define SINGLE_H

    #include "../Base/Base.h"

    class Single : public Base
    {
    private:
        
    public: 
        Single(const HANDLE& screenHandle ,const Point2D& start, const Point2D& end, int blocksLeft = 1);
        ~Single();

        void drawShipN() override;
        void drawShipE() override;
        void drawShipS() override;
        void drawShipW() override;

        static void drawGhostN(const HANDLE& screenHandle, const Point2D& start, const Point2D& end, short color);
        static void drawGhostE(const HANDLE& screenHandle, const Point2D& start, const Point2D& end, short color);
        static void drawGhostS(const HANDLE& screenHandle, const Point2D& start, const Point2D& end, short color);
        static void drawGhostW(const HANDLE& screenHandle, const Point2D& start, const Point2D& end, short color);
    };

    
#endif