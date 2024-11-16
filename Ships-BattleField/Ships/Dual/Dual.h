#ifndef DUAL_H
#define DUAL_H
    #include "../Base/Base.h"


    class Dual : public Base
    {
    private:
        
    public:
        Dual(const HANDLE& screenHandle ,const Point2D& start, const Point2D& end, int blocksLeft = 2);
        ~Dual();

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