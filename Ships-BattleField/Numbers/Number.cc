#pragma once

#include "Number.h"

void Number::draw1(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 4, middlePoint.getY() - (height - 1) / 2}, {middlePoint.getX() - width / 4, middlePoint.getY() - (height - 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
}

void Number::draw2(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
}

void Number::draw3(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height - 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height - 1) / 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 3}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 3}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - height / 4}, {middlePoint.getX(), middlePoint.getY() - height / 4}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + (width - 2) / 2, middlePoint.getY()}, {middlePoint.getX(), middlePoint.getY()}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() + height / 2}});
}

void Number::draw4(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 4, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - (width + 1) / 2, middlePoint.getY() + height / 4}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 3}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
}

void Number::draw5(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - 1}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - 1}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - 1}});
    
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - 1}, {middlePoint.getX() + width / 2, middlePoint.getY() - 1}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
}

void Number::draw6(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY()}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() + height / 2}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}, {middlePoint.getX() + width / 2, middlePoint.getY()}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 3, middlePoint.getY() - 1}, {middlePoint.getX(), middlePoint.getY() - 1}});
}

void Number::draw7(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});
}

void Number::draw8(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 3}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 3}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 3}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 3}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - height / 3}, {middlePoint.getX() + width / 3, middlePoint.getY() - height / 3}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY()}, {middlePoint.getX() + width / 3, middlePoint.getY()}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 3}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 3}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() - width / 2, middlePoint.getY()}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height  / 3}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() + height / 2}});

}

void Number::draw9(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 3}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY()}, {middlePoint.getX() + width / 3, middlePoint.getY()}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() + height / 2}});

}

void Number::draw0(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 3}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() + height / 2}});
}

void Number::drawLower1(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 4, middlePoint.getY() - (height - 1) / 2}, {middlePoint.getX() - width / 4, middlePoint.getY() - (height - 1) / 2}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});

}

void Number::drawLower2(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2 + 1, middlePoint.getY() - height / 2 - 1}, {middlePoint.getX() + width / 2 - 1, middlePoint.getY() - height / 2 - 1}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}});
}   

void Number::drawLower3(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{   
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - 1, middlePoint.getY() + height / 2}, {middlePoint.getX() + 1, middlePoint.getY() + height / 2}});
    
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY()}, {middlePoint.getX() + 1, middlePoint.getY()}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - 1, middlePoint.getY() - height / 2 - 1}, {middlePoint.getX() + 1, middlePoint.getY() - height / 2 - 1}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}});
}

void Number::drawLower4(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY() + height / 2}, {middlePoint.getX() + 1, middlePoint.getY() - height / 2 - 1}});

    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() - height / 2 - 1}, {middlePoint.getX() - width / 2, middlePoint.getY()}});
}

void Number::drawLower5(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    // Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    // Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - 1}});
    // Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - 1}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - 1}});
    
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - 1}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - 1}, {middlePoint.getX() - width / 2 + 1, middlePoint.getY() - 1}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});

}

void Number::drawLower6(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2 + 1, middlePoint.getY() - height / 2 - 1}, {middlePoint.getX() + width / 2 - 1, middlePoint.getY() - height / 2 - 1}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2 - 1}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 2 - 1}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2 - 1}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2 - 1}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() + height / 2}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2 - 1, middlePoint.getY() + height / 3}, {middlePoint.getX() + width / 2, middlePoint.getY()}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 3, middlePoint.getY() - 1}, {middlePoint.getX() - 1, middlePoint.getY() - 1}});

}

void Number::drawLower7(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2 + 1, middlePoint.getY() + height / 2}});

}

void Number::drawLower8(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - 1, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + 1, middlePoint.getY() - (height + 1) / 2}});
    
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - 1, middlePoint.getY() - 1}, {middlePoint.getX() + 1, middlePoint.getY() - 1}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - 1, middlePoint.getY()}, {middlePoint.getX() + 1, middlePoint.getY()}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() - width / 2, middlePoint.getY()}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY() + height / 2}, {middlePoint.getX() - 1, middlePoint.getY() + height / 2}});

}

void Number::drawLower9(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - height / 3}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});
    
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY()}, {middlePoint.getX() + width / 3, middlePoint.getY()}});
    
    // Line::drawLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() + height / 2}});

}

void Number::drawLower0(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 3, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 3, middlePoint.getY() - (height + 1) / 2}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + 1}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + 1}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY() + height / 2}, {middlePoint.getX() - 1, middlePoint.getY() + height / 2}});


}
