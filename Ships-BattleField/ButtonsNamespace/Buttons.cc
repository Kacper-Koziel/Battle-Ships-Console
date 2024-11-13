#pragma once

#include "Buttons.h"
#include "../Alphabet/Alphabet.cc"
#include "../Structures/Structures.h"

void Buttons::PvPButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset = 0)
{
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() - height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() - height / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() + height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() + height / 2)}});

    Alphabet::drawP(screenHandle, height / 2, width / 10, {(middlePoint.getX() - width / 8) + offset, middlePoint.getY()});
    Alphabet::drawV(screenHandle, height / 3, width / 15, {middlePoint.getX() + offset, middlePoint.getY() + height / 10});
    Alphabet::drawP(screenHandle, height / 2, width / 10, {(middlePoint.getX() + width / 8) + offset, middlePoint.getY()});
}

void Buttons::PvAiButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset = 0)
{

    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() - height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() - height / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() + height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() + height / 2)}});

    Alphabet::drawP(screenHandle, height / 2, width / 10, {(middlePoint.getX() - width / 6) + offset, middlePoint.getY()});
    Alphabet::drawV(screenHandle, height / 3, width / 15, {middlePoint.getX() + offset, middlePoint.getY() + height / 10});
    Alphabet::drawA(screenHandle, height / 2, width / 10, {(middlePoint.getX() + width / 6) + offset, middlePoint.getY()});
    Alphabet::drawI(screenHandle, height / 2, width / 10, {(middlePoint.getX() + width / 4) + offset, middlePoint.getY()});

}

void Buttons::CreditsButton(const HANDLE& screenHandle, int height, int width, const Point2D& middlePoint, short offset = 0)
{
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() - height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() - height / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() + height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() + height / 2)}});

    Alphabet::drawC(screenHandle, height / 2, width / 10, {(middlePoint.getX() - (width + 3) / 3) + offset, middlePoint.getY()});
    Alphabet::drawR(screenHandle, height / 2, width / 10, {(middlePoint.getX() - width / 4) + offset, middlePoint.getY()});
    Alphabet::drawE(screenHandle, height / 2, width / 10, {(middlePoint.getX() - width / 8) + offset, middlePoint.getY()});
    Alphabet::drawD(screenHandle, height / 2, width / 10, {(middlePoint.getX()) + offset, middlePoint.getY()});
    Alphabet::drawI(screenHandle, height / 2, width / 10, {(middlePoint.getX() + width / 8) + offset, middlePoint.getY()});
    Alphabet::drawT(screenHandle, height / 2, width / 10, {(middlePoint.getX() + width / 4) + offset, middlePoint.getY()});
    Alphabet::drawS(screenHandle, height / 2, width / 10, {(middlePoint.getX() + (width + 3) / 3) + offset, middlePoint.getY()});
}

void Buttons::nextButton(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint, short offset)
{
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() - height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() - height / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() + height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() + height / 2)}});

    Alphabet::drawN(screenHandle, height / 2, width / 10, {(middlePoint.getX() - width / 5) + offset, middlePoint.getY()});
    Alphabet::drawE(screenHandle, height / 2, width / 10, {middlePoint.getX() - width / 18 + offset, middlePoint.getY() + height / 10});
    Alphabet::drawX(screenHandle, height / 2, width / 10, {(middlePoint.getX() + width / 10) + offset, middlePoint.getY()});
    Alphabet::drawT(screenHandle, height / 2, width / 10, {(middlePoint.getX() + width / 4) + offset, middlePoint.getY()});

}

void Buttons::clearButton(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint, short offset)
{
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() - height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() - height / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() + height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() + height / 2)}});


    Alphabet::drawLowerC(screenHandle, height / 2, width / 5,  middlePoint);
}

void Buttons::YESButton(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint, short offset)
{
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() - height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() - height / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() + height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() + height / 2)}});

    Alphabet::drawY(screenHandle, height / 2, width / 5,  {middlePoint.getX() - width / 3, middlePoint.getY()});
    Alphabet::drawE(screenHandle, height / 2, width / 5,  {middlePoint.getX(), middlePoint.getY()});
    Alphabet::drawS(screenHandle, height / 2, width / 5,  {middlePoint.getX() + width / 3, middlePoint.getY()});

}

void Buttons::NOButton(const HANDLE &screenHandle, int height, int width, const Point2D &middlePoint, short offset)
{
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() - height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() - height / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() - width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() - (height - 1) / 2)}, {(middlePoint.getX() + width / 2) + offset, (middlePoint.getY() + (height - 1) / 2)}});
    Line::drawLine(screenHandle, {{(middlePoint.getX() - (width - 1) / 2) + offset, (middlePoint.getY() + height / 2)}, {middlePoint.getX() + (width - 2) / 2 + offset, (middlePoint.getY() + height / 2)}});

    Alphabet::drawN(screenHandle, height / 2, width / 5,  {middlePoint.getX() - width / 6, middlePoint.getY()});
    Alphabet::drawO(screenHandle, height / 2, width / 5,  {middlePoint.getX() + width / 6, middlePoint.getY()});
}
