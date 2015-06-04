#ifndef _COMMANDS_H__
#define _COMMANDS_H__

#include "../database/Database.h"
#include "Player.h"

namespace WhistGame {

#define constructor(x) x(WhistGame::Database &database) \
                        { \
                            _database = &database; \
                        }

#define if_wrong_command(x, message) if (parameters.size() != x) \
                                        return message

#define EXECUTE virtual std::string Execute(std::vector<std::string>& parameters, \
                                            Players *players, Player *player, \
                                            Tables *tables)

class Command
{
    public:
        virtual std::string Execute(std::vector<std::string>& parameters,
                                    Players *players, Player *player,
                                    Tables *tables) = 0;
};

class LoginCommand : public Command
{
    public:
        constructor(LoginCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (players->GetPlayer(parameters[1]) != NULL)
                return "Login:the account is connected\n";
            if (player->GetName() != "")
                return "Login:you already are connected\n";

            std::string result = _database->Login(parameters[1], parameters[2]);
            if (result == "Login:successfully\n");
            {
                players->AddPlayer(player);
                player->SetName(parameters[1]);
            }

            return result;
        }

    private:
        WhistGame::Database *_database;
};

class LogoutCommand : public Command
{
    public:
        constructor(LogoutCommand)

        EXECUTE
        {
            if_wrong_command(1, "Wrong command\n");
            if (player->GetName() == "")
                return "Logout:you are not connected\n";

            players->RemovePlayer(player);
            player->SetName("");
            return "Logout:successfully\n";
        }

    private:
        WhistGame::Database *_database;
};

class ExitCommand : public Command
{
    public:
        constructor(ExitCommand)

        EXECUTE
        {
            if_wrong_command(1, "Wrong command\n");
            player->GetSocket()->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
            return "";
        }

    private:
        WhistGame::Database *_database;
};

class RegisterCommand : public Command
{
    public:
        constructor(RegisterCommand)

        EXECUTE
        {
            if_wrong_command(4, "Wrong command\n");
            return _database->Register(parameters[1], parameters[2],
                                       parameters[3]);
        }
        
    private:
        WhistGame::Database *_database;
};

class SendFriendRequestCommand : public Command
{
    public:
        constructor(SendFriendRequestCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->SendFriendRequest(parameters[1], parameters[2]);
        }

    private:
        WhistGame::Database *_database;
};

class AcceptFriendRequestCommand : public Command
{
    public:
        constructor(AcceptFriendRequestCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->AcceptFriendRequest(parameters[1], parameters[2]);
        }

    private:
        WhistGame::Database *_database;
};

class RefuseFriendRequestCommand : public Command
{
    public:
        constructor(RefuseFriendRequestCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->RefuseFriendRequest(parameters[1], parameters[2]);
        }
        
    private:
        WhistGame::Database *_database;
};

class ChangePasswordCommand : public Command
{
    public:
        constructor(ChangePasswordCommand)

        EXECUTE
        {
            if_wrong_command(4, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->ChangePassword(parameters[1], parameters[2],
                                             parameters[3]);
        }
        
    private:
        WhistGame::Database *_database;
};

class DeleteFriendCommand : public Command
{
    public:
        constructor(DeleteFriendCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->DeleteFriend(parameters[1], parameters[2]);
        }

    private:
        WhistGame::Database *_database;
};

class DeleteAvatarCommand : public Command
{
    public:
        constructor(DeleteAvatarCommand)

        EXECUTE
        {
            if_wrong_command(2, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->DeleteAvatar(parameters[1]);
        }

    private:
        WhistGame::Database *_database;
};

class ChangeAvatarCommand : public Command
{
    public:
        constructor(ChangeAvatarCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->ChangeAvatar(parameters[1], parameters[2]);
        }

    private:
        WhistGame::Database *_database;
};

class BlockPrivMessagesCommand : public Command
{
    public:
        constructor(BlockPrivMessagesCommand)

        EXECUTE
        {
            if_wrong_command(2, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->BlockPrivMessages(parameters[1]);
        }

    private:
        WhistGame::Database *_database;
};

class DeblockPrivMessagesCommand : public Command
{
    public:
        constructor(DeblockPrivMessagesCommand)

        EXECUTE
        {
            if_wrong_command(2, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->DeblockPrivMessages(parameters[1]);
        }

    private:
        WhistGame::Database *_database;
};

class BanPlayerCommand : public Command
{
    public:
        constructor(BanPlayerCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->BanPlayer(parameters[1], parameters[2]);
        }

    private:
        WhistGame::Database *_database;
};

class ChangeRankCommand : public Command
{
    public:
        constructor(ChangeRankCommand)

        EXECUTE
        {
            if_wrong_command(4, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->ChangeRank(parameters[2], parameters[3]);
        }

    private:
        WhistGame::Database *_database;
};

class LostPasswordCommand : public Command
{
    public:
        constructor(LostPasswordCommand)

        EXECUTE
        {
            if_wrong_command(3, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            return _database->LostPassword(parameters[1], parameters[2]);
        }

    private:
        WhistGame::Database *_database;
};

class IsActivatedCommand : public Command
{
    public:
        constructor(IsActivatedCommand)

        EXECUTE
        {
            if_wrong_command(2, "Wrong command\n");
            return _database->IsActivated(parameters[1]);
        }

    private:
        WhistGame::Database *_database;
};

class JoinToTableCommand : public Command
{
    public:
        constructor(JoinToTableCommand)

        EXECUTE
        {
            if_wrong_command(2, "Wrong command\n");
            if (player->GetName() == "")
                return "You must be connected\n";
            if (!isNumber(parameters[1]))
                return "Wrong command\n";
            int id = stoi(parameters[1]);
            if (id < 0 || id > 99)
                return "Wrong command\n";

            Table *t = tables->GetTable(id);
            if (t == NULL)
                return "Table doesn't exist\n";

            if (t->AddSpectator(player))
                return "JoinToTable:successfully\n";
            else
                return "JoinToTable:failed\n";
        }

    private:
        WhistGame::Database *_database;

        bool isNumber(std::string& str) const
        {
            int size = str.size();
            for (int i = 0; i < size; i++)
                if (str[i] < '0' || str[i] > '9')
                    return false;

            return true;
        }

};

}; // end namespace

#endif

