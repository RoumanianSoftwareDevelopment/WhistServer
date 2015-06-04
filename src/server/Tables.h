#ifndef _TABLES_H_
#define _TABLES_H_

#include "Table.h"

#define MAX_TABLES 100

namespace WhistGame
{

class Tables
{
    public:
        Tables();
        virtual~ Tables();
        bool AddTable(WhistGame::Table*);
        WhistGame::Table* GetTable(unsigned short int id) const;
        bool RemoveTable(unsigned short int id);
        unsigned short int GetTablesNo() const;
        short int GeneratesId() const;
        void PrintTables() const;
    private:
        WhistGame::Table* tables[MAX_TABLES];
        unsigned short int tablesNo = 0;
};

}

#endif

