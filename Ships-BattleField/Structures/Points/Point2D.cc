#pragma once

#include "Point2D.h"

Point2D::Point2D() : x(0), y(0) {}

Point2D::Point2D(int x, int y) : x(x), y(y) {}

Point2D Point2D::operator=(const POINT &consoleCursor)
{
    setX(consoleCursor.x);
    setY(consoleCursor.y);

    return *this;
}
