#ifndef TRIPPLE_H
#define TRIPPLE_H
    #include "../Base/Base.h"

    class Tripple : public Base
    {
    private:
        
    public:
        Tripple(const HANDLE &screenHandle, const Point2D &start, const Point2D &end, int blocksLeft = 3);
        ~Tripple();

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