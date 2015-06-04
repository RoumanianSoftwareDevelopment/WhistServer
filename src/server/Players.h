#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include "Player.h"
#include <list>

namespace WhistGame {

class Players
{
    public:
        Players();
        virtual~ Players();
        void AddPlayer(Player*);
        Player* GetPlayer(std::string&) const;
        void RemovePlayer(Player*);
        void PrintPlayers() const;
    private:
        std::list<Player*> players;
};

}

#endif

