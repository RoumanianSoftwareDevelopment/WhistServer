#include "Tables.h"

namespace WhistGame
{

Tables::Tables()
{

}

void Tables::AddTable(WhistGame::Table* table)
{
    tables.push_back(table);
}

void Tables::RemoveTable(WhistGame::Table* table)
{
    tables.remove(table);
}

WhistGame::Table* Tables::GetTable(unsigned int id)
{
    for(auto it = tables.begin(); it != tables.end(); it++)
    {
        if((*it)->GetId() == id)
            return *it;
    }

    return NULL;
}

Tables::~Tables()
{

}

}
