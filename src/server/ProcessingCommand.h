#ifndef _PROCESSINGCOMMAND_H__
#define _PROCESSINGCOMMAND_H__

#include "Players.h"
#include "Tables.h"

namespace WhistGame {

class ProcessingCommand
{
    public:
        ProcessingCommand(WhistGame::Players*, WhistGame::Player*,
                          WhistGame::Tables*, std::string*);
        virtual~ ProcessingCommand();
        void Processing(std::string);
    private:
        WhistGame::Players *players;
        WhistGame::Player *player;
        WhistGame::Tables *tables;
        std::string *writeBuffer;
};

}

#endif

