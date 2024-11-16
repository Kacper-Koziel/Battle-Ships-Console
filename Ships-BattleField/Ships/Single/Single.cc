#pragma once

#include "Single.h"
#include "../../Console/Console.cc"

Single::Single(const HANDLE& screenHandle ,const Point2D& start, const Point2D& end, int blocksLeft)
{
    this->screenHandle = screenHandle;
    this->start = start;
    this->end = end;
    this->blocksLeft = blocksLeft;
    this->constStart = start;
    this->constEnd = end;
}

Single::~Single()
{

}

void Single::drawShipN()
{
    // Line::drawLine(getScreenHandle(), {getStart(), getEnd()});
    Line::drawTopBlockLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY() + 1}, {getEnd().getX() - 2, getEnd().getY() + 1}});
    
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY()}, {getEnd().getX() - 2, getEnd().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY()}, {getEnd().getX() + 2, getEnd().getY()}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY()}, {getEnd().getX(), getEnd().getY() - 2}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY()}, {getEnd().getX(), getEnd().getY() - 2}});

    Console::staticSetFontColor(getScreenHandle(), 8);

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY()}, {getEnd().getX() + 1, getEnd().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 1, getEnd().getY()}, {getEnd().getX() - 1, getEnd().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY()}, {getEnd().getX(), getEnd().getY() - 1}});

    Console::staticSetFontColor(getScreenHandle(), 7);
}   

void Single::drawShipE()
{
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() - 1}, {getEnd().getX() - 2, getEnd().getY()}});

    Line::drawBottomBlockLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() - 2}, {getEnd().getX() + 2, getEnd().getY() - 2}});
    Line::drawTopBlockLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() + 1}, {getEnd().getX() + 2, getEnd().getY() + 1}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY() - 1}, {getEnd().getX() + 2, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY()}, {getEnd().getX() + 2, getEnd().getY()}});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 1, getEnd().getY() - 1}, {getEnd().getX() - 1, getEnd().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY() - 1}, {getEnd().getX(), getEnd().getY()}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY() - 1}, {getEnd().getX() + 1, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY()}, {getEnd().getX() + 1, getEnd().getY()}});

    Console::staticSetFontColor(getScreenHandle(), 7);
}

void Single::drawShipS()
{
    Line::drawBottomBlockLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY() - 2}, {getEnd().getX() - 2, getEnd().getY() - 2}});
    
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() - 1}, {getEnd().getX() - 2, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY() - 1}, {getEnd().getX() + 2, getEnd().getY() - 1}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 1, getEnd().getY()}, {getEnd().getX(), getEnd().getY() + 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY()}, {getEnd().getX(), getEnd().getY() + 1}});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 1, getEnd().getY() - 1}, {getEnd().getX() + 1, getEnd().getY() - 1}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY()}, {getEnd().getX(), getEnd().getY() - 1}});

    Console::staticSetFontColor(getScreenHandle(), 7);
}

void Single::drawShipW()
{
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() - 1}, {getEnd().getX() - 2, getEnd().getY()}});

    Line::drawBottomBlockLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() - 2}, {getEnd().getX() + 2, getEnd().getY() - 2}});
    Line::drawTopBlockLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() + 1}, {getEnd().getX() + 2, getEnd().getY() + 1}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY() - 1}, {getEnd().getX() + 2, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY()}, {getEnd().getX() + 2, getEnd().getY()}});

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 1, getEnd().getY() - 1}, {getEnd().getX() - 1, getEnd().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY() - 1}, {getEnd().getX(), getEnd().getY()}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY() - 1}, {getEnd().getX() + 1, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY()}, {getEnd().getX() + 1, getEnd().getY()}});

    Console::staticSetFontColor(getScreenHandle(), 7);
}

void Single::drawGhostN(const HANDLE& screenHandle, const Point2D& start, const Point2D& end, short color)
{
    Console::staticSetFontColor(screenHandle, color);

    Line::drawTopBlockLine(screenHandle, {{end.getX() + 2, end.getY() + 1}, {end.getX() - 2, end.getY() + 1}});
    
    Line::drawLine(screenHandle, {{end.getX() - 2, end.getY()}, {end.getX() - 2, end.getY()}});
    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY()}, {end.getX() + 2, end.getY()}});

    Line::drawLine(screenHandle, {{end.getX() - 2, end.getY()}, {end.getX(), end.getY() - 2}});
    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY()}, {end.getX(), end.getY() - 2}});

    Console::staticSetFontColor(screenHandle, 7);
}

void Single::drawGhostE(const HANDLE& screenHandle ,const Point2D& start, const Point2D& end, short color)
{
    Console::staticSetFontColor(screenHandle, color);

    Line::drawLine(screenHandle, {{end.getX() - 2, end.getY() - 1}, {end.getX() - 2, end.getY()}});

    Line::drawBottomBlockLine(screenHandle, {{end.getX() - 2, end.getY() - 2}, {end.getX() + 2, end.getY() - 2}});
    Line::drawTopBlockLine(screenHandle, {{end.getX() - 2, end.getY() + 1}, {end.getX() + 2, end.getY() + 1}});

    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY() - 1}, {end.getX() + 2, end.getY() - 1}});
    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY()}, {end.getX() + 2, end.getY()}});

    Console::staticSetFontColor(screenHandle, 7);
}

void Single::drawGhostS(const HANDLE& screenHandle ,const Point2D& start, const Point2D& end, short color)
{
    Console::staticSetFontColor(screenHandle, color);
    
    Line::drawBottomBlockLine(screenHandle, {{end.getX() + 2, end.getY() - 2}, {end.getX() - 2, end.getY() - 2}});
    
    Line::drawLine(screenHandle, {{end.getX() - 2, end.getY() - 1}, {end.getX() - 2, end.getY() - 1}});
    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY() - 1}, {end.getX() + 2, end.getY() - 1}});

    Line::drawLine(screenHandle, {{end.getX() - 1, end.getY()}, {end.getX(), end.getY() + 1}});
    Line::drawLine(screenHandle, {{end.getX() + 1, end.getY()}, {end.getX(), end.getY() + 1}});

    Console::staticSetFontColor(screenHandle, 7);
}

void Single::drawGhostW(const HANDLE& screenHandle ,const Point2D& start, const Point2D& end, short color)
{
    Console::staticSetFontColor(screenHandle, color);
    
    Line::drawLine(screenHandle, {{end.getX() - 2, end.getY() - 1}, {end.getX() - 2, end.getY()}});

    Line::drawBottomBlockLine(screenHandle, {{end.getX() - 2, end.getY() - 2}, {end.getX() + 2, end.getY() - 2}});
    Line::drawTopBlockLine(screenHandle, {{end.getX() - 2, end.getY() + 1}, {end.getX() + 2, end.getY() + 1}});

    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY() - 1}, {end.getX() + 2, end.getY() - 1}});
    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY()}, {end.getX() + 2, end.getY()}});

    Console::staticSetFontColor(screenHandle, 7);
}
