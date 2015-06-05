#include "Player.h"
#include <iostream>

using namespace std;

namespace WhistGame
{

Player::Player(boost::asio::ip::tcp::socket *sock)
{
    socketPlayer = sock;
}

Player::~Player()
{

}

void Player::SetName(std::string newName)
{
    name = newName;
}

void Player::Write(string& message)
{
    boost::asio::write(*socketPlayer,
                       boost::asio::buffer(message.c_str(), message.size()));
}

std::string Player::GetName() const
{
    return name;
}

boost::asio::ip::tcp::socket* Player::GetSocket() const
{
    return socketPlayer;
}

void Player::PrintPlayer() const
{
    cout << name << "\n";
}

}

