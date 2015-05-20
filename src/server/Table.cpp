#include "Table.h"

namespace WhistGame
{

Table::Table(WhistGame::Player *player, short int type, unsigned int id)
{
    this->id = id;
    this->type = type;
    players[0] = player;

    for (int i = 0; i < 6; i++)
        players[i] = NULL;
}

void Table::AddPlayer(WhistGame::Player* player, int position)
{
    if(players[position] != NULL)
    {
        players[position] = player;
        playersNumber++;
    }
}

void Table::RemovePlayer(WhistGame::Player* player)
{
    for(int i = 0; i < 6; i++)
    {
        if(player == players[i])
        {
            players[i] = NULL;
            playersNumber--;
            return;
        }
    }
}

unsigned int Table::GetId()
{
    return id;
}

short int Table::GetType()
{
    return type;    
}

Table::~Table()
{
}

}
