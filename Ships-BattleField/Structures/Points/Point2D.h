#ifndef POINT2D_H
#define POINT2D_H
    struct Point2D
    {
        private:
            int x;
            int y;
        
        public:
            Point2D();
            Point2D(int x, int y);

            int getX() const { return this->x; }
            int getY() const { return this->y; }

            void setX(int newX) { this->x = newX; }
            void setY(int newY) { this->y = newY; }

            Point2D operator=(const POINT& consoleCursor);
    };
    
#endif