#ifndef PLACEMENU_H
#define PLACEMENU_H
    #include "../Console/Console.cc"
    #include "../Board/Board.cc"
    #include "../Ships/Ships.h"
    #include <memory>

    class PlaceMenu
    {
    private:
        Board& playerBoard;
        Console window;
        static Board boardTemplate;
    public:
        PlaceMenu(Board& playerBoard, Console& window);
        ~PlaceMenu();

        Board& getPlayerBoard() { return this->playerBoard; }
        Console& getWindow() { return this->window; }

        void drawSet(Base& ship, short amount, short maxAmount);

        bool checkEventsForSet(Base& setShip, void (PlaceMenu::*drawSetFunction)(Base& setShip, short, short), short amount, short maxAmount);
        int checkEvents();

        bool isSafeToPlace(const Point2D& startPosition, const Point2D& endPosition);
        
        void drawMenu(Base& quadraShip, Base& trippleShip, Base& dualShip, Base& singleShip, Button& clearButton, Button& nextButton);
        void drawShadowSingle(int position, const Point2D& start, const Point2D& end, short color);


        void drawShadowDual(int position, const Point2D& start, const Point2D& end, short color);
        void changePositionDual(int position, Point2D& start, Point2D& end);
        void modifyStartByPositionDual(int position, Point2D& start, Point2D& end);

        void drawShadowTripple(int position, const Point2D& start, const Point2D& end, short color);
        void changePositionTripple(int position, Point2D& start, Point2D& end);
        void modifyStartByPositionTripple(int position, Point2D& start, Point2D& end);

        void drawShadowQuadra(int position, const Point2D& start, const Point2D& end, short color);
        void changePositionQuadra(int position, Point2D& start, Point2D& end);
        void modifyStartByPositionQuadra(int position, Point2D& start, Point2D& end);

        void roundCursor(POINT& consoleCursor);
        void setHiddens(const Point2D& startPosition, const Point2D& endPosition);

        std::shared_ptr<Base> placeShip(const short size);
        std::shared_ptr<Single> placeSingle();
        std::shared_ptr<Dual> placeDual();
        std::shared_ptr<Tripple> placeTripple();
        std::shared_ptr<Quadra> placeQuadra();
    };
    
#endif