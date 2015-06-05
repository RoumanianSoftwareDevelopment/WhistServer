#ifndef _TABLE_H_
#define _TABLE_H_

#include "Player.h"
#include <array>
#include <list>

namespace WhistGame
{

#define MAX_PLAYERS_AT_TABLE 6

class Table
{
    public:
        Table(WhistGame::Player *player, short int _type, unsigned int _id);
        virtual~ Table();
        bool AddPlayer(WhistGame::Player*, int);
        bool RemovePlayer(WhistGame::Player*);
        bool AddSpectator(WhistGame::Player*);
        bool RemoveSpectator(WhistGame::Player*);
        bool SearchSpectator(WhistGame::Player*);
        unsigned int GetId() const;
        short int GetType() const;
        void PrintTable() const;
    private:
        unsigned int id;
        short int type, playersNumber = 0;
        std::array<WhistGame::Player*, MAX_PLAYERS_AT_TABLE> players;
        std::list<WhistGame::Player*> spectators;
};

}

#endif
