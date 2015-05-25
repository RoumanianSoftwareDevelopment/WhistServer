#ifndef _TABLE_H_
#define _TABLE_H_

#include "Player.h"
#include <array>

namespace WhistGame
{

class Table
{
    public:
        Table(WhistGame::Player *player, short int type, unsigned int id);
        virtual~ Table();
        bool AddPlayer(WhistGame::Player*, int);
        bool RemovePlayer(WhistGame::Player*);
        unsigned int GetId();
        short int GetType();
    private:
        unsigned int id;
        short int type, playersNumber = 0;
        std::array<WhistGame::Player*, 6> players;
};

}

#endif
