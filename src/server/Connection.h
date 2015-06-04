#ifndef _CONNECTION_H__
#define _CONNECTION_H__

#include "ProcessingCommand.h"
#include <iostream>

namespace WhistGame {

class Connection : public std::enable_shared_from_this<Connection>
{
    public:
        Connection(boost::asio::ip::tcp::socket, ProcessingCommand*);
        virtual~ Connection();
        void Start();
    private:
        void Read();
        void Write(std::size_t);
        bool IsThereAnyCommand(char*);

        boost::asio::ip::tcp::socket playerSocket;
        std::string writeBuffer;
        Player player;
        ProcessingCommand *processingCommand;
        char *readBuffer;
};

}

#endif

