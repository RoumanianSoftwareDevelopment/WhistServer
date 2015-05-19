#include "Table.h"

namespace WhistGame
{

Table::Table(WhistGame::Player *player, short int type, unsigned int id)
{
    this->id = id;
    this->type = type;
    players[0] = player;

    for (int i = 1; i < 6; i++)
        players[i] = NULL;
}

Table::~Table()
{

}

}

