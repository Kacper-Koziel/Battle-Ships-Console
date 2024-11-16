#pragma once

#include "Message.h"
#include "../Console/Console.cc"
#include "../Structures/Structures.h"
#include "../Alphabet/Alphabet.cc"

Message::Message(const HANDLE& screenHandle) : screenHandle(screenHandle) {}

Message::~Message()
{

}

void Message::cantPlaceText()
{
    Console::staticSetFontColor(getScreenHandle(), 8);
    Alphabet::drawY(getScreenHandle(), 7, 7, {47, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {55, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {63, 24});

    Alphabet::drawC(getScreenHandle(), 7, 7, {75, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {83, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {91, 24});
    Alphabet::drawT(getScreenHandle(), 7, 7, {99, 24});

    Alphabet::drawP(getScreenHandle(), 7, 7, {111, 24});
    Alphabet::drawL(getScreenHandle(), 7, 7, {119, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {127, 24});
    Alphabet::drawC(getScreenHandle(), 7, 7, {135, 24});
    Alphabet::drawE(getScreenHandle(), 7, 7, {143, 24});

    Alphabet::drawY(getScreenHandle(), 7, 7, {155, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {163, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {171, 24});
    Alphabet::drawR(getScreenHandle(), 7, 7, {179, 24});

    Alphabet::drawS(getScreenHandle(), 7, 7, {80, 38});
    Alphabet::drawH(getScreenHandle(), 7, 7, {88, 38});
    Alphabet::drawI(getScreenHandle(), 7, 7, {96, 38});
    Alphabet::drawP(getScreenHandle(), 7, 7, {104, 38});

    Alphabet::drawH(getScreenHandle(), 7, 7, {120, 38});
    Alphabet::drawE(getScreenHandle(), 7, 7, {128, 38});
    Alphabet::drawR(getScreenHandle(), 7, 7, {136, 38});
    Alphabet::drawE(getScreenHandle(), 7, 7, {144, 38});


    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawY(getScreenHandle(), 7, 7, {48, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {56, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {64, 24});

    Alphabet::drawC(getScreenHandle(), 7, 7, {76, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {84, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {92, 24});
    Alphabet::drawT(getScreenHandle(), 7, 7, {100, 24});

    Alphabet::drawP(getScreenHandle(), 7, 7, {112, 24});
    Alphabet::drawL(getScreenHandle(), 7, 7, {120, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {128, 24});
    Alphabet::drawC(getScreenHandle(), 7, 7, {136, 24});
    Alphabet::drawE(getScreenHandle(), 7, 7, {144, 24});

    Alphabet::drawY(getScreenHandle(), 7, 7, {156, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {164, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {172, 24});
    Alphabet::drawR(getScreenHandle(), 7, 7, {180, 24});

    Alphabet::drawS(getScreenHandle(), 7, 7, {81, 38});
    Alphabet::drawH(getScreenHandle(), 7, 7, {89, 38});
    Alphabet::drawI(getScreenHandle(), 7, 7, {97, 38});
    Alphabet::drawP(getScreenHandle(), 7, 7, {105, 38});

    Alphabet::drawH(getScreenHandle(), 7, 7, {121, 38});
    Alphabet::drawE(getScreenHandle(), 7, 7, {129, 38});
    Alphabet::drawR(getScreenHandle(), 7, 7, {137, 38});
    Alphabet::drawE(getScreenHandle(), 7, 7, {145, 38});



}

void Message::dontHave10Ships()
{
    Console::staticSetFontColor(getScreenHandle(), 8);
    Alphabet::drawY(getScreenHandle(), 7, 7, {37, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {45, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {53, 24});

    Alphabet::drawD(getScreenHandle(), 7, 7, {65, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {73, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {81, 24});
    Alphabet::drawT(getScreenHandle(), 7, 7, {89, 24});

    Alphabet::drawH(getScreenHandle(), 7, 7, {101, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {109, 24});
    Alphabet::drawV(getScreenHandle(), 7, 7, {117, 24});
    Alphabet::drawE(getScreenHandle(), 7, 7, {125, 24});

    Number::draw1(getScreenHandle(), 7, 7, {137, 24});
    Number::draw0(getScreenHandle(), 7, 7, {145, 24});

    Alphabet::drawS(getScreenHandle(), 7, 7, {157, 24});
    Alphabet::drawH(getScreenHandle(), 7, 7, {165, 24});
    Alphabet::drawI(getScreenHandle(), 7, 7, {173, 24});
    Alphabet::drawP(getScreenHandle(), 7, 7, {181, 24});
    Alphabet::drawS(getScreenHandle(), 7, 7, {189, 24});

    Alphabet::drawP(getScreenHandle(), 7, 7, {90, 38});
    Alphabet::drawL(getScreenHandle(), 7, 7, {98, 38});
    Alphabet::drawA(getScreenHandle(), 7, 7, {106, 38});
    Alphabet::drawC(getScreenHandle(), 7, 7, {114, 38});
    Alphabet::drawE(getScreenHandle(), 7, 7, {122, 38});
    Alphabet::drawD(getScreenHandle(), 7, 7, {130, 38});

    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawY(getScreenHandle(), 7, 7, {38, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {46, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {54, 24});

    Alphabet::drawD(getScreenHandle(), 7, 7, {66, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {74, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {82, 24});
    Alphabet::drawT(getScreenHandle(), 7, 7, {90, 24});

    Alphabet::drawH(getScreenHandle(), 7, 7, {102, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {110, 24});
    Alphabet::drawV(getScreenHandle(), 7, 7, {118, 24});
    Alphabet::drawE(getScreenHandle(), 7, 7, {126, 24});

    Number::draw1(getScreenHandle(), 7, 7, {138, 24});
    Number::draw0(getScreenHandle(), 7, 7, {146, 24});

    Alphabet::drawS(getScreenHandle(), 7, 7, {158, 24});
    Alphabet::drawH(getScreenHandle(), 7, 7, {166, 24});
    Alphabet::drawI(getScreenHandle(), 7, 7, {174, 24});
    Alphabet::drawP(getScreenHandle(), 7, 7, {182, 24});
    Alphabet::drawS(getScreenHandle(), 7, 7, {190, 24});

    Alphabet::drawP(getScreenHandle(), 7, 7, {91, 38});
    Alphabet::drawL(getScreenHandle(), 7, 7, {99, 38});
    Alphabet::drawA(getScreenHandle(), 7, 7, {107, 38});
    Alphabet::drawC(getScreenHandle(), 7, 7, {115, 38});
    Alphabet::drawE(getScreenHandle(), 7, 7, {123, 38});
    Alphabet::drawD(getScreenHandle(), 7, 7, {131, 38});

}

void Message::player1Select()
{
    Console::staticSetFontColor(getScreenHandle(), 8);

    Alphabet::drawP(getScreenHandle(), 9, 9, {84, 30});
    Alphabet::drawL(getScreenHandle(), 9, 9, {96, 30});
    Alphabet::drawA(getScreenHandle(), 9, 9, {108, 30});
    Alphabet::drawY(getScreenHandle(), 9, 9, {120, 30});
    Alphabet::drawE(getScreenHandle(), 9, 9, {132, 30});
    Alphabet::drawR(getScreenHandle(), 9, 9, {144, 30});

    Number::draw1(getScreenHandle(), 9, 9, {159, 30});

    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawP(getScreenHandle(), 9, 9, {85, 30});
    Alphabet::drawL(getScreenHandle(), 9, 9, {97, 30});
    Alphabet::drawA(getScreenHandle(), 9, 9, {109, 30});
    Alphabet::drawY(getScreenHandle(), 9, 9, {121, 30});
    Alphabet::drawE(getScreenHandle(), 9, 9, {133, 30});
    Alphabet::drawR(getScreenHandle(), 9, 9, {145, 30});

    Number::draw1(getScreenHandle(), 9, 9, {160, 30});
}

void Message::player2Select()
{
    Console::staticSetFontColor(getScreenHandle(), 8);

    Alphabet::drawP(getScreenHandle(), 9, 9, {84, 30});
    Alphabet::drawL(getScreenHandle(), 9, 9, {96, 30});
    Alphabet::drawA(getScreenHandle(), 9, 9, {108, 30});
    Alphabet::drawY(getScreenHandle(), 9, 9, {120, 30});
    Alphabet::drawE(getScreenHandle(), 9, 9, {132, 30});
    Alphabet::drawR(getScreenHandle(), 9, 9, {144, 30});

    Number::draw2(getScreenHandle(), 9, 9, {159, 30});

    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawP(getScreenHandle(), 9, 9, {85, 30});
    Alphabet::drawL(getScreenHandle(), 9, 9, {97, 30});
    Alphabet::drawA(getScreenHandle(), 9, 9, {109, 30});
    Alphabet::drawY(getScreenHandle(), 9, 9, {121, 30});
    Alphabet::drawE(getScreenHandle(), 9, 9, {133, 30});
    Alphabet::drawR(getScreenHandle(), 9, 9, {145, 30});

    Number::draw2(getScreenHandle(), 9, 9, {160, 30});
}

void Message::cantShootHere()
{
    Console::staticSetFontColor(getScreenHandle(), 8);

    Alphabet::drawY(getScreenHandle(), 7, 7, {42, 30});
    Alphabet::drawO(getScreenHandle(), 7, 7, {50, 30});
    Alphabet::drawU(getScreenHandle(), 7, 7, {58, 30});

    Alphabet::drawC(getScreenHandle(), 7, 7, {70, 30});
    Alphabet::drawA(getScreenHandle(), 7, 7, {78, 30});
    Alphabet::drawN(getScreenHandle(), 7, 7, {86, 30});
    Alphabet::drawT(getScreenHandle(), 7, 7, {94, 30});

    Alphabet::drawS(getScreenHandle(), 7, 7, {106, 30});
    Alphabet::drawH(getScreenHandle(), 7, 7, {114, 30});
    Alphabet::drawO(getScreenHandle(), 7, 7, {122, 30});
    Alphabet::drawO(getScreenHandle(), 7, 7, {130, 30});
    Alphabet::drawT(getScreenHandle(), 7, 7, {138, 30});

    Alphabet::drawH(getScreenHandle(), 7, 7, {152, 30});
    Alphabet::drawE(getScreenHandle(), 7, 7, {160, 30});
    Alphabet::drawR(getScreenHandle(), 7, 7, {168, 30});
    Alphabet::drawE(getScreenHandle(), 7, 7, {176, 30});


    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawY(getScreenHandle(), 7, 7, {43, 30});
    Alphabet::drawO(getScreenHandle(), 7, 7, {51, 30});
    Alphabet::drawU(getScreenHandle(), 7, 7, {59, 30});

    Alphabet::drawC(getScreenHandle(), 7, 7, {71, 30});
    Alphabet::drawA(getScreenHandle(), 7, 7, {79, 30});
    Alphabet::drawN(getScreenHandle(), 7, 7, {87, 30});
    Alphabet::drawT(getScreenHandle(), 7, 7, {95, 30});

    Alphabet::drawS(getScreenHandle(), 7, 7, {107, 30});
    Alphabet::drawH(getScreenHandle(), 7, 7, {115, 30});
    Alphabet::drawO(getScreenHandle(), 7, 7, {123, 30});
    Alphabet::drawO(getScreenHandle(), 7, 7, {131, 30});
    Alphabet::drawT(getScreenHandle(), 7, 7, {139, 30});

    Alphabet::drawH(getScreenHandle(), 7, 7, {153, 30});
    Alphabet::drawE(getScreenHandle(), 7, 7, {161, 30});
    Alphabet::drawR(getScreenHandle(), 7, 7, {169, 30});
    Alphabet::drawE(getScreenHandle(), 7, 7, {177, 30});

}

void Message::aiWins()
{
    Console::staticSetFontColor(getScreenHandle(), 8);
    
    Alphabet::drawA(getScreenHandle(), 9, 9, {89, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {101, 30});

    Alphabet::drawW(getScreenHandle(), 9, 9, {116, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {128, 30});
    Alphabet::drawN(getScreenHandle(), 9, 9, {140, 30});
    Alphabet::drawS(getScreenHandle(), 9, 9, {152, 30});

    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawA(getScreenHandle(), 9, 9, {90, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {102, 30});

    Alphabet::drawW(getScreenHandle(), 9, 9, {117, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {129, 30});
    Alphabet::drawN(getScreenHandle(), 9, 9, {141, 30});
    Alphabet::drawS(getScreenHandle(), 9, 9, {153, 30});

    Alphabet::drawA(getScreenHandle(), 9, 9, {91, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {102, 30});

    Alphabet::drawW(getScreenHandle(), 9, 9, {118, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {130, 30});
    Alphabet::drawN(getScreenHandle(), 9, 9, {142, 30});
    Alphabet::drawS(getScreenHandle(), 9, 9, {154, 30});
}

void Message::playerWins()
{
    Console::staticSetFontColor(getScreenHandle(), 8);

    Alphabet::drawP(getScreenHandle(), 9, 9, {65, 30});
    Alphabet::drawL(getScreenHandle(), 9, 9, {76, 30});
    Alphabet::drawA(getScreenHandle(), 9, 9, {87, 30});
    Alphabet::drawY(getScreenHandle(), 9, 9, {98, 30});
    Alphabet::drawE(getScreenHandle(), 9, 9, {109, 30});
    Alphabet::drawR(getScreenHandle(), 9, 9, {120, 30});

    Alphabet::drawW(getScreenHandle(), 9, 9, {144, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {155, 30});
    Alphabet::drawN(getScreenHandle(), 9, 9, {166, 30});
    Alphabet::drawS(getScreenHandle(), 9, 9, {177, 30});

    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawP(getScreenHandle(), 9, 9, {66, 30});
    Alphabet::drawL(getScreenHandle(), 9, 9, {77, 30});
    Alphabet::drawA(getScreenHandle(), 9, 9, {88, 30});
    Alphabet::drawY(getScreenHandle(), 9, 9, {99, 30});
    Alphabet::drawE(getScreenHandle(), 9, 9, {110, 30});
    Alphabet::drawR(getScreenHandle(), 9, 9, {121, 30});

    Alphabet::drawW(getScreenHandle(), 9, 9, {145, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {156, 30});
    Alphabet::drawN(getScreenHandle(), 9, 9, {167, 30});
    Alphabet::drawS(getScreenHandle(), 9, 9, {178, 30});

    Alphabet::drawP(getScreenHandle(), 9, 9, {67, 30});
    Alphabet::drawL(getScreenHandle(), 9, 9, {78, 30});
    Alphabet::drawA(getScreenHandle(), 9, 9, {89, 30});
    Alphabet::drawY(getScreenHandle(), 9, 9, {100, 30});
    Alphabet::drawE(getScreenHandle(), 9, 9, {111, 30});
    Alphabet::drawR(getScreenHandle(), 9, 9, {122, 30});

    Alphabet::drawW(getScreenHandle(), 9, 9, {146, 30});
    Alphabet::drawI(getScreenHandle(), 9, 9, {157, 30});
    Alphabet::drawN(getScreenHandle(), 9, 9, {168, 30});
    Alphabet::drawS(getScreenHandle(), 9, 9, {179, 30});

}

void Message::errorText()
{
    Console::staticSetFontColor(getScreenHandle(), 8);
    Alphabet::drawE(getScreenHandle(), 11, 11, {93, 30});
    Alphabet::drawR(getScreenHandle(), 11, 11, {106, 30});
    Alphabet::drawR(getScreenHandle(), 11, 11, {119, 30});
    Alphabet::drawO(getScreenHandle(), 11, 11, {133, 30});
    Alphabet::drawR(getScreenHandle(), 11, 11, {146, 30});

    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawE(getScreenHandle(), 11, 11, {94, 30});
    Alphabet::drawR(getScreenHandle(), 11, 11, {107, 30});
    Alphabet::drawR(getScreenHandle(), 11, 11, {120, 30});
    Alphabet::drawO(getScreenHandle(), 11, 11, {134, 30});
    Alphabet::drawR(getScreenHandle(), 11, 11, {147, 30});
}

void Message::dontHaveEnough()
{
    Console::staticSetFontColor(getScreenHandle(), 8);

    Alphabet::drawY(getScreenHandle(), 7, 7, {45, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {53, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {61, 24});

    Alphabet::drawD(getScreenHandle(), 7, 7, {73, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {81, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {89, 24});
    Alphabet::drawT(getScreenHandle(), 7, 7, {97, 24});

    Alphabet::drawH(getScreenHandle(), 7, 7, {109, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {117, 24});
    Alphabet::drawV(getScreenHandle(), 7, 7, {125, 24});
    Alphabet::drawE(getScreenHandle(), 7, 7, {133, 24});

    Alphabet::drawE(getScreenHandle(), 7, 7, {145, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {153, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {161, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {169, 24});
    Alphabet::drawG(getScreenHandle(), 7, 7, {177, 24});
    Alphabet::drawH(getScreenHandle(), 7, 7, {185, 24});

    Alphabet::drawS(getScreenHandle(), 7, 7, {99, 38});
    Alphabet::drawH(getScreenHandle(), 7, 7, {107, 38});
    Alphabet::drawI(getScreenHandle(), 7, 7, {115, 38});
    Alphabet::drawP(getScreenHandle(), 7, 7, {123, 38});
    Alphabet::drawS(getScreenHandle(), 7, 7, {131, 38});

    Console::staticSetFontColor(getScreenHandle(), 7);

    Alphabet::drawY(getScreenHandle(), 7, 7, {46, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {54, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {62, 24});

    Alphabet::drawD(getScreenHandle(), 7, 7, {74, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {82, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {90, 24});
    Alphabet::drawT(getScreenHandle(), 7, 7, {98, 24});

    Alphabet::drawH(getScreenHandle(), 7, 7, {110, 24});
    Alphabet::drawA(getScreenHandle(), 7, 7, {118, 24});
    Alphabet::drawV(getScreenHandle(), 7, 7, {126, 24});
    Alphabet::drawE(getScreenHandle(), 7, 7, {134, 24});

    Alphabet::drawE(getScreenHandle(), 7, 7, {146, 24});
    Alphabet::drawN(getScreenHandle(), 7, 7, {154, 24});
    Alphabet::drawO(getScreenHandle(), 7, 7, {162, 24});
    Alphabet::drawU(getScreenHandle(), 7, 7, {170, 24});
    Alphabet::drawG(getScreenHandle(), 7, 7, {178, 24});
    Alphabet::drawH(getScreenHandle(), 7, 7, {186, 24});

    Alphabet::drawS(getScreenHandle(), 7, 7, {100, 38});
    Alphabet::drawH(getScreenHandle(), 7, 7, {108, 38});
    Alphabet::drawI(getScreenHandle(), 7, 7, {116, 38});
    Alphabet::drawP(getScreenHandle(), 7, 7, {124, 38});
    Alphabet::drawS(getScreenHandle(), 7, 7, {132, 38});

}

void Message::showMessage(short code)
{
    Console::staticClear();

    Console::staticSetFontColor(getScreenHandle(), 8);
    Line::drawLine(getScreenHandle(), {{0, 10}, {239, 10}});
    Line::drawLine(getScreenHandle(), {{0, 53}, {239, 53}});

    Line::drawLine(getScreenHandle(), {{0, 12}, {239, 12}});
    Line::drawLine(getScreenHandle(), {{0, 51}, {239, 51}});

    Console::staticSetFontColor(getScreenHandle(), 7);
    Line::drawLine(getScreenHandle(), {{0, 11}, {239, 11}});
    Line::drawLine(getScreenHandle(), {{0, 52}, {239, 52}});

    switch (code)
    {
    case 1:
        cantPlaceText();
        break;
    
    case 2:
        dontHaveEnough();
        break;

    case 3:
        dontHave10Ships();
        break;

    case 4:
        player1Select();
        break;

    case 5:
        player2Select();
        break;

    case 6:
        cantShootHere();
        break;

    case 7:
        aiWins();
        break;

    case 8:
        playerWins();
        break;

    default:
        errorText();
        break;
    }

    Console::staticSleep(1000);
}

