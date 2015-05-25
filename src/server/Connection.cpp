#include "Connection.h"
#include <cstdlib>
#include "../parser/parser.h"

using namespace boost::asio::ip;
using namespace std;
using namespace WhistGame;

namespace WhistGame {

Connection::Connection(tcp::socket sock, Players* _players, Tables* _tables) :
    playerSocket(std::move(sock)),
    player(&playerSocket),
    processingCommand(_players, &player, _tables, &writeBuffer)
{
    players = _players;
    tables = _tables;
    readBuffer = (char*) malloc(1024 * sizeof(char));
    memset(readBuffer, 0, 1024);
    players->AddPlayer(&player);
}

Connection::~Connection()
{
    free(readBuffer);
}

void Connection::Start()
{
    Read();
}

void Connection::Read()
{
    int len = strlen(readBuffer);
    auto self(shared_from_this());
    playerSocket.async_read_some(
        boost::asio::buffer((void*)(readBuffer + len), 1023 - len),
        MakeCustomAllocHandler(allocator,
            [this, self, len](boost::system::error_code ec, std::size_t length)
            {
                if (!ec)
                {
                    readBuffer[length + len] = '\0';

                    while (IsThereAnyCommand(readBuffer))
                    {
                        string command = ParseMessage(readBuffer);
                        processingCommand.Processing(command);
                        Write(length);
                    }

                    Read();
                }
                else
                {
                    players->RemovePlayer(&player);
                }
            }
        )
    );
}

void Connection::Write(size_t length)
{
    auto self(shared_from_this());
    boost::asio::async_write(
        playerSocket,
        boost::asio::buffer(writeBuffer.c_str(), writeBuffer.size()),
        MakeCustomAllocHandler(allocator,
            [this, self](boost::system::error_code ec, std::size_t)
            {
                if (!ec)
                {
                    writeBuffer = "";
                }
                else
                {
                    players->RemovePlayer(&player);
                }
            }
        )
    );
}

bool Connection::IsThereAnyCommand(char* message)
{
    unsigned int size = strlen(message);
    for (unsigned int i = 0; i < size; i++)
        if (message[i] == '\n')
            return true;

    return false;
}

}

