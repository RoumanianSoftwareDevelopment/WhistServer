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
        Table(WhistGame::Player *player, short int _type, unsigned int _id);
        virtual~ Table();
        bool AddPlayer(WhistGame::Player*, int);
        bool RemovePlayer(WhistGame::Player*);
        bool AddSpectator(WhistGame::Player*);
        bool RemoveSpectator(WhistGame::Player*);
        unsigned int GetId() const;
        short int GetType() const;
    private:
        const unsigned int id;
        const short int type;
        short int playersNumber = 0;
        std::array<WhistGame::Player*, 6> players;
        std::list<WhistGame::Player*> spectators;
};

}

#endif
