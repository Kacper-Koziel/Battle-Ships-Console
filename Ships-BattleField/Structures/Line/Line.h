#ifndef LINE_H
#define LINE_H
    #include "../Points/Point2D.h"
    #include <Windows.h>

    struct Line
    {
        private:
            Point2D start;
            Point2D end;
        public:
            Line();
            Line(const Point2D& start, const Point2D& end);

            Point2D getStart() const { return this->start; }
            Point2D getEnd() const { return this->end; }

            static void drawLine(const HANDLE& screenHandle, const Line& line);
            static void drawTopBlockLine(const HANDLE &screenHandle, const Line &line);
            static void drawBottomBlockLine(const HANDLE &screenHandle, const Line &line);
    };

#endif