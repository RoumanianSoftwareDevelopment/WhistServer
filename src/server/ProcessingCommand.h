#ifndef _PROCESSINGCOMMAND_H__
#define _PROCESSINGCOMMAND_H__

#include "Players.h"
#include "Tables.h"
#include "Commands.h"
#include "../database/date.h"

namespace WhistGame {

class ProcessingCommand
{
    public:
        ProcessingCommand();
        virtual~ ProcessingCommand();
        std::string Processing(std::string, Player*);
        Players& GetPlayers();
        Tables& GetTables();
    private:
        std::string h = host, n = nume, c = client, p = parola;
        WhistGame::Players players;
        WhistGame::Tables tables;
        WhistGame::Database database;
};

}

#endif

