#pragma once

#include "Tripple.h"
#include "../../Console/Console.cc"

Tripple::Tripple(const HANDLE &screenHandle, const Point2D &start, const Point2D &end, int blocksLeft)
{
    this->screenHandle = screenHandle;
    this->start = start;
    this->end = end;
    this->blocksLeft = blocksLeft;
    this->constStart = start;
    this->constEnd = end;
}

Tripple::~Tripple()
{
    
}

void Tripple::drawShipN()
{
    Line::drawLine(getScreenHandle(), {{getStart().getX(), getStart().getY() - 2}, {getStart().getX() - 2, getStart().getY()}});
    Line::drawLine(getScreenHandle(), {{getStart().getX(), getStart().getY() - 2}, {getStart().getX() + 2, getStart().getY()}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY() + 1}, {getStart().getX() + 2, getStart().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() + 1}, {getStart().getX() - 2, getStart().getY()}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY() + 1}, {getEnd().getX() - 2, getEnd().getY() + 1}});

    Console::staticSetFontColor(getScreenHandle(), 8);

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY()}, {getStart().getX() + 1, getStart().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 1, getEnd().getY()}, {getStart().getX() - 1, getStart().getY()}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY()}, {getStart().getX(), getStart().getY() - 1}});

    Console::staticSetFontColor(getScreenHandle(), 7);

}

void Tripple::drawShipE()
{
    Line::drawLine(getScreenHandle(), {{getStart().getX() - 2, getStart().getY()}, {getStart().getX() - 2, getStart().getY() - 1}});

    Line::drawBottomBlockLine(getScreenHandle(), {{getStart().getX() - 2, getStart().getY() - 2}, {getEnd().getX() - 1, getEnd().getY() - 2}});
    Line::drawTopBlockLine(getScreenHandle(), {{getStart().getX() - 2, getStart().getY() + 1}, {getEnd().getX() - 1, getEnd().getY() + 1}});

    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY()}, {getEnd().getX(), getEnd().getY() - 1}});
    Line::drawBottomBlockLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY() - 1}, {getEnd().getX() + 1, getEnd().getY() - 1}});
    Line::drawTopBlockLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY()}, {getEnd().getX() + 1, getEnd().getY()}});

    Console::staticSetFontColor(getScreenHandle(), 8);

    Line::drawLine(getScreenHandle(), {{getStart().getX() - 1, getStart().getY() - 1}, {getEnd().getX() - 1, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getStart().getX() - 1, getStart().getY()}, {getEnd().getX() - 1, getEnd().getY()}});


    Console::staticSetFontColor(getScreenHandle(), 7);
}

void Tripple::drawShipS()
{
    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY() + 1}, {getEnd().getX() - 2, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY() + 1}, {getEnd().getX() + 2, getEnd().getY() - 1}});

    Line::drawLine(getScreenHandle(), {{getStart().getX() + 2, getStart().getY() - 2}, {getEnd().getX() + 2, getEnd().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 2, getEnd().getY() - 1}, {getStart().getX() - 2, getStart().getY() - 2}});

    Line::drawLine(getScreenHandle(), {{getStart().getX() + 2, getStart().getY() - 2}, {getStart().getX() - 2, getStart().getY() - 2}});

    Console::staticSetFontColor(getScreenHandle(), 8);

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY() - 1}, {getStart().getX() + 1, getStart().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() - 1, getEnd().getY() - 1}, {getStart().getX() - 1, getStart().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX(), getEnd().getY()}, {getStart().getX(), getStart().getY() - 1}});


    Console::staticSetFontColor(getScreenHandle(), 7);

}

void Tripple::drawShipW()
{
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 2, getEnd().getY()}, {getEnd().getX() + 2, getEnd().getY() - 1}});

    Line::drawBottomBlockLine(getScreenHandle(), {{getStart().getX() + 1, getStart().getY() - 2}, {getEnd().getX() + 2, getStart().getY() - 2}});
    Line::drawTopBlockLine(getScreenHandle(), {{getStart().getX() + 1, getStart().getY() + 1}, {getEnd().getX() + 2, getStart().getY() + 1}});

    Line::drawLine(getScreenHandle(), {{getStart().getX(), getStart().getY()}, {getStart().getX(), getStart().getY() - 1}});

    Line::drawBottomBlockLine(getScreenHandle(), {{getStart().getX() - 1, getStart().getY() - 1}, {getStart().getX() - 1, getStart().getY() - 1}});
    Line::drawTopBlockLine(getScreenHandle(), {{getStart().getX() - 1, getStart().getY()}, {getStart().getX() - 1, getStart().getY()}});

    Console::staticSetFontColor(getScreenHandle(), 8);

    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY() - 1}, {getStart().getX() + 1, getStart().getY() - 1}});
    Line::drawLine(getScreenHandle(), {{getEnd().getX() + 1, getEnd().getY()}, {getStart().getX() + 1, getStart().getY()}});

    Console::staticSetFontColor(getScreenHandle(), 7);
}

void Tripple::drawGhostN(const HANDLE &screenHandle, const Point2D &start, const Point2D &end, short color)
{
    Console::staticSetFontColor(screenHandle, color);
    
    Line::drawLine(screenHandle, {{start.getX(), start.getY() - 2}, {start.getX() - 2, start.getY()}});
    Line::drawLine(screenHandle, {{start.getX(), start.getY() - 2}, {start.getX() + 2, start.getY()}});

    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY() + 1}, {start.getX() + 2, start.getY()}});
    Line::drawLine(screenHandle, {{end.getX() - 2, end.getY() + 1}, {start.getX() - 2, start.getY()}});

    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY() + 1}, {end.getX() - 2, end.getY() + 1}});

    Console::staticSetFontColor(screenHandle, 7);
}

void Tripple::drawGhostE(const HANDLE &screenHandle, const Point2D &start, const Point2D &end, short color)
{
    Console::staticSetFontColor(screenHandle, color);
    
    Line::drawLine(screenHandle, {{start.getX() - 2, start.getY()}, {start.getX() - 2, start.getY() - 1}});

    Line::drawBottomBlockLine(screenHandle, {{start.getX() - 2, start.getY() - 2}, {end.getX() - 1, end.getY() - 2}});
    Line::drawTopBlockLine(screenHandle, {{start.getX() - 2, start.getY() + 1}, {end.getX() - 1, end.getY() + 1}});

    Line::drawLine(screenHandle, {{end.getX(), end.getY()}, {end.getX(), end.getY() - 1}});
    Line::drawBottomBlockLine(screenHandle, {{end.getX() + 1, end.getY() - 1}, {end.getX() + 1, end.getY() - 1}});
    Line::drawTopBlockLine(screenHandle, {{end.getX() + 1, end.getY()}, {end.getX() + 1, end.getY()}});

    Console::staticSetFontColor(screenHandle, 7);
}

void Tripple::drawGhostS(const HANDLE &screenHandle, const Point2D &start, const Point2D &end, short color)
{
   Console::staticSetFontColor(screenHandle, color);
   
    Line::drawLine(screenHandle, {{end.getX(), end.getY() + 1}, {end.getX() - 2, end.getY() - 1}});
    Line::drawLine(screenHandle, {{end.getX(), end.getY() + 1}, {end.getX() + 2, end.getY() - 1}});

    Line::drawLine(screenHandle, {{start.getX() + 2, start.getY() - 2}, {end.getX() + 2, end.getY() - 1}});
    Line::drawLine(screenHandle, {{end.getX() - 2, end.getY() - 1}, {start.getX() - 2, start.getY() - 2}});

    Line::drawLine(screenHandle, {{start.getX() + 2, start.getY() - 2}, {start.getX() - 2, start.getY() - 2}});

    Console::staticSetFontColor(screenHandle, 7);
}

void Tripple::drawGhostW(const HANDLE &screenHandle, const Point2D &start, const Point2D &end, short color)
{
    Console::staticSetFontColor(screenHandle, color);
    
    Line::drawLine(screenHandle, {{end.getX() + 2, end.getY()}, {end.getX() + 2, end.getY() - 1}});

    Line::drawBottomBlockLine(screenHandle, {{start.getX() + 1, start.getY() - 2}, {end.getX() + 2, start.getY() - 2}});
    Line::drawTopBlockLine(screenHandle, {{start.getX() + 1, start.getY() + 1}, {end.getX() + 2, start.getY() + 1}});

    Line::drawLine(screenHandle, {{start.getX(), start.getY()}, {start.getX(), start.getY() - 1}});

    Line::drawBottomBlockLine(screenHandle, {{start.getX() - 1, start.getY() - 1}, {start.getX() - 1, start.getY() - 1}});
    Line::drawTopBlockLine(screenHandle, {{start.getX() - 1, start.getY()}, {start.getX() - 1, start.getY()}});

    Console::staticSetFontColor(screenHandle, 7);
}
