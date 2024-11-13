bool ShootingAiMenu::playerIsSinkedAi(POINT &consoleCursor)
{
    int shipIndex = findShipIndex(consoleCursor);

    if (shipIndex == -1)
    {
        return false;
    }

    std::shared_ptr<Base> ship = getAi().getAiBoard().getShips()->at(shipIndex);

    int startX = Convertions::MAX(ship->getStart().getX(), ship->getEnd().getX());
    int startY = Convertions::MAX(ship->getStart().getY(), ship->getEnd().getY());
    int endX = Convertions::MIN(ship->getStart().getX(), ship->getEnd().getX());
    int endY = Convertions::MIN(ship->getStart().getY(), ship->getEnd().getY());

    if (ship->getDirection() == 'N' || ship->getDirection() == 'S')
    {
        return playerIsSinkedNSAi(startY, endY, startX);
    }
    else
    {
        return playerIsSinkedEWAi(startX, endX, startY);
    }
}

bool ShootingAiMenu::playerIsSinkedNSAi(int startY, int endY, int startX)
{

    for (int i = updatedEndY; i <= updatedStartY; i++)
    {
        if (getAi().getAiBoard().getHiddenShips()->at(i).at(startX) == false || getAi().getAiBoard().getShoots()->at(i).at(updatedStartX) == false)
        {
            return false;
        }
        
    }
    
    return true;
}

bool ShootingAiMenu::playerIsSinkedEWAi(int startX, int endX, int startY)
{
    int updatedStartX = (startX - 144) / 8;
    int updatedEndX = (endX - 144) / 8;
    int updatedStartY = (startY - 9) / 5;

    for (int i = updatedEndX; i <= updatedStartX; i++)
    {
        if (getAi().getAiBoard().getHiddenShips()->at(updatedStartY).at(i) == false || getAi().getAiBoard().getShoots()->at(updatedStartY).at(i) == false)
        {
            return false;
        }
        
    }
    
    return true;
}