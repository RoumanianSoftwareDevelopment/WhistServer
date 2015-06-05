#include "server/Server.hpp"
#include <functional>
#include <thread>

using namespace std;
using namespace WhistGame;

void ReadCommandsFromKeyboard(Server& server)
{
    string command;
    while (true)
    {
        cin >> command;
        if (command == "quit")
        {
            server.Stop();
            break;
        }
        if (command == "PrintPlayers")
        {
            server.PrintPlayers();
            continue;
        }
        if (command == "PrintTables")
        {
            server.PrintTables();
            continue;
        }
    }
}

int main(void)
{
    system("clear");

    Server server(12345);
    thread t(ReadCommandsFromKeyboard, std::ref(server));
    server.Start();
    t.join();

    return 0;
}

