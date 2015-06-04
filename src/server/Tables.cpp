#include "Tables.h"
#include <iostream>

using namespace std;

namespace WhistGame
{

Tables::Tables()
{
    for (unsigned short int i = 0; i < MAX_TABLES; i++)
        tables[i] = NULL;
}

bool Tables::AddTable(WhistGame::Table* table)
{
    unsigned short int id = table->GetId();
    if (id < 0 || id > 99)
        return false;
    if (tables[id] != NULL)
        return false;

    tables[id] = table;
    tablesNo++;

    return true;
}

bool Tables::RemoveTable(unsigned short int id)
{
    for (unsigned short int i = 0; i < MAX_TABLES; i++)
        if (tables[i] != NULL)
            if (tables[i]->GetId() == id)
            {
                delete tables[i];
                tables[i] = NULL;
                tablesNo--;
                return true;
            }

    return false;
}

WhistGame::Table* Tables::GetTable(unsigned short int id) const
{
    for(unsigned short int i = 0; i < MAX_TABLES; i++)
    {
        if(tables[i]->GetId() == id)
            return tables[i];
    }

    return NULL;
}

Tables::~Tables()
{

}

unsigned short int Tables::GetTablesNo() const
{
    return tablesNo;
}

short int Tables::GeneratesId() const
{
    if (tablesNo == MAX_TABLES)
        return -1;

    for (unsigned short int i = 0; i < MAX_TABLES; i++)
        if (tables[i] == NULL)
            return i;

    return -1;
}

void Tables::PrintTables() const
{
    if (tablesNo == 0)
    {
        cout << "Doesn't exist tables.\n";
        return;
    }

    for (int i = 0; i < MAX_TABLES; i++)
        if (tables[i] != NULL)
            tables[i]->PrintTable();
}

}
