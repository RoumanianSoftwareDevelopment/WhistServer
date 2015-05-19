#ifndef _TABLES_H_
#define _TABLES_H_

#include "Table.h"
#include <list>

namespace WhistGame
{

class Tables
{
    public:
        Tables();
        virtual~ Tables();
        void AddTable(WhistGame::Table*);
        WhistGame::Table* GetTable(unsigned int id);
        void RemoveTable(WhistGame::Table*);
    private:
        std::list<WhistGame::Table*> tables;
};

}

#endif

