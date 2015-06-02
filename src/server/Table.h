#ifndef _TABLE_H_
#define _TABLE_H_

#include "Player.h"
#include <array>
#include <list>

namespace WhistGame
{

class Table
{
    public:
        Table(WhistGame::Player *player, short int type, unsigned int id);
        virtual~ Table();
        bool AddPlayer(WhistGame::Player*, int);
        bool RemovePlayer(WhistGame::Player*);
        bool AddSpectator(WhistGame::Player*);
        bool RemoveSpectator(WhistGame::Player*);
        unsigned int GetId();
        short int GetType();
    private:
        unsigned int id;
        short int type, playersNumber = 0;
        std::array<WhistGame::Player*, 6> players;
        std::list<WhistGame::Player*> spectators;
};

}

#endif
