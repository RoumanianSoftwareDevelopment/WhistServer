#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <boost/asio.hpp>
#include <string>

namespace WhistGame {

class Player
{
    public:
        Player(boost::asio::ip::tcp::socket*);
        virtual~ Player();
        void SetName(std::string);
        std::string GetName();
        boost::asio::ip::tcp::socket* GetSocket();
    private:
        std::string name;
        boost::asio::ip::tcp::socket *socketPlayer;
};

};

#endif

