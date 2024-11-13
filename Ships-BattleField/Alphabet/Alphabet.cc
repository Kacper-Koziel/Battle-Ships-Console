#pragma once

#include "Alphabet.h"

void Alphabet::drawA(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - (height - 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height - 1) / 2}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
}

void Alphabet::drawB(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2},{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2},{middlePoint.getX() + width / 2, middlePoint.getY() - 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - 1}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - 1}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawC(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height - 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}});
}

void Alphabet::drawD(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + 1, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + 1, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}});
}

void Alphabet::drawE(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - 1}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - 1}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY()}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY()}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawF(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});
}

void Alphabet::drawG(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY()}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 3, middlePoint.getY()}, {middlePoint.getX() + width / 3, middlePoint.getY()}});
}

void Alphabet::drawH(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY()}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY()}});
}

void Alphabet::drawI(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() - (height - 2) / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX(), middlePoint.getY() - (height + 1) / 2}});
}

void Alphabet::drawJ(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 3}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 3}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 3}});
}

void Alphabet::drawK(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + 1}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
}

void Alphabet::drawL(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawM(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, middlePoint});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, middlePoint});
}

void Alphabet::drawN(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawO(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawP(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2},{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2},{middlePoint.getX() + width / 2, middlePoint.getY() - 1}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY()}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY()}});

}

void Alphabet::drawR(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2},{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2},{middlePoint.getX() + (width - 2) / 2, middlePoint.getY()}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY()}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY()}});

    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY()}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawS(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - 1}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - 1}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - 1}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY()}});


    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY()}, {middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawT(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() - height / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});
}

void Alphabet::drawU(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});

}

void Alphabet::drawW(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}, middlePoint});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, middlePoint});
}

void Alphabet::drawY(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() + height / 2}, middlePoint});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, middlePoint});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, middlePoint});
}

void Alphabet::drawZ(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawX(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawV(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint) //Guess who forgot about V in PvP
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});
}
//From this point, i cant even put in words how much i hate this program. whole Alphabet has to be reprogrammed cuz it
//does not work for font size < 5. Kys C++

//New data. only some of letters has to be reprogrammed. Still hating on Alphabet

//Fonts specially for board size 3:

void Alphabet::drawLowerB(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() - 1, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX(), middlePoint.getY() - (height + 1) / 2}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY() - 2}, {middlePoint.getX() + 1, middlePoint.getY() - 2}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY() - 1}, {middlePoint.getX() + 1, middlePoint.getY() - 1}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX(), middlePoint.getY() - 1}, {middlePoint.getX(), middlePoint.getY() - 1}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint}, {middlePoint}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY()}, {middlePoint.getX() + 1, middlePoint.getY()}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY() + 1}, {middlePoint.getX() + 1, middlePoint.getY() + 1}});

    Line::drawBottomBlockLine(screenHandle, {{middlePoint.getX() - 1, middlePoint.getY() + height / 2}, {middlePoint.getX(), middlePoint.getY() + height / 2}});
}

void Alphabet::drawLowerC(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height - 1) / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});
}

void Alphabet::drawLowerG(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() - width / 2, middlePoint.getY() + (height - 2) / 2}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() - (height + 1) / 2}});
   
    Line::drawLine(screenHandle, {{middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() + (height - 2) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY()}});
    Line::drawTopBlockLine(screenHandle, {{middlePoint.getX() + 1, middlePoint.getY() + (height - 2) / 2}, {middlePoint.getX() + 1, middlePoint.getY()}});

}


void Alphabet::drawLowerJ(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint)
{
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY() - (height + 1) / 2}, {middlePoint.getX() + width / 2, middlePoint.getY() - (height + 1) / 2}});

    Line::drawLine(screenHandle, {{middlePoint.getX() + width / 2, middlePoint.getY() - height / 2}, {middlePoint.getX() + width / 2, middlePoint.getY()}});
    Line::drawLine(screenHandle, {{middlePoint.getX() + (width - 2) / 2, middlePoint.getY() + height / 2}, {middlePoint.getX() - (width - 2) / 2, middlePoint.getY() + height / 2}});
    
    Line::drawLine(screenHandle, {{middlePoint.getX() - width / 2, middlePoint.getY()}, {middlePoint.getX() - width / 2, middlePoint.getY()}});
}