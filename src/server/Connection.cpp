#include "Connection.h"
#include <cstdlib>
#include "../parser/parser.h"

using namespace boost::asio::ip;
using namespace std;
using namespace WhistGame;

namespace WhistGame {

Connection::Connection(tcp::socket sock, ProcessingCommand *procCom) :
    playerSocket(std::move(sock)),
    player(&playerSocket)
{
    readBuffer = (char*) malloc(1024 * sizeof(char));
    memset(readBuffer, 0, 1024);
    processingCommand = procCom;
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
        [this, self, len](boost::system::error_code ec, std::size_t length)
        {
            if (!ec)
            {
                readBuffer[length + len] = '\0';

                while (IsThereAnyCommand(readBuffer))
                {
                    string command = ParseMessage(readBuffer);
                    writeBuffer = processingCommand->Processing(command,
                                                                &player);
                    Write(length);
                }

                Read();
            }
            else
            {
                if (player.GetName() != "")
                    processingCommand->RemovePlayer(&player);
            //    playerSocket.shutdown(tcp::socket::shutdown_both, ec);
                playerSocket.close();
            }
        }
    );
}

void Connection::Write(size_t length)
{
    auto self(shared_from_this());
    boost::asio::async_write(
        playerSocket,
        boost::asio::buffer(writeBuffer.c_str(), writeBuffer.size()),
        [this, self](boost::system::error_code ec, std::size_t)
        {
            if (!ec)
            {
                writeBuffer = "";
            }
            else
            {
                if (player.GetName() != "")
                    processingCommand->RemovePlayer(&player);
                playerSocket.close();
            }
        }
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

