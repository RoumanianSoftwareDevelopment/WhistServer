#include "ProcessingCommand.h"
#include "../parser/parser.h"
#include <map>

using namespace std;
using namespace WhistGame;

namespace WhistGame {

ProcessingCommand::ProcessingCommand() : database(h, c, p, n)
{
}

ProcessingCommand::~ProcessingCommand()
{

}

Players& ProcessingCommand::GetPlayers()
{
    return players;
}

Tables& ProcessingCommand::GetTables()
{
    return tables;
}

void ProcessingCommand::RemovePlayer(Player *player)
{
    players.RemovePlayer(player);
}

string ProcessingCommand::Processing(string input, Player *player)
{
    static map<string, Command*> functions =
        {{"Login", new LoginCommand(database)},
         {"SendFriendRequest", new SendFriendRequestCommand(database)},
         {"AcceptFriendRequest", new AcceptFriendRequestCommand(database)},
         {"RefuseFriendRequest", new RefuseFriendRequestCommand(database)},
         {"ChangePassword", new ChangePasswordCommand(database)},
         {"DeleteFriend", new DeleteFriendCommand(database)},
         {"DeleteAvatar", new DeleteAvatarCommand(database)},
         {"ChangeAvatar", new ChangeAvatarCommand(database)},
         {"BlockPrivMessages", new BlockPrivMessagesCommand(database)},
         {"DeblockPrivMessages", new DeblockPrivMessagesCommand(database)},
         {"BanPlayer", new BanPlayerCommand(database)},
         {"ChangeRank", new ChangeRankCommand(database)},
         {"LostPassword", new LostPasswordCommand(database)},
         {"IsActivated", new IsActivatedCommand(database)},
         {"Logout", new LogoutCommand(database)},
         {"Exit", new ExitCommand(database)},
//         {},
//         {},
//         {},
         {"Register", new RegisterCommand(database)}};

    vector<string> parameters = ParseCommand(input);
    if (functions.count(parameters[0]) > 0)
        return functions[parameters[0]]->Execute(parameters, &players,
                                                 player, &tables);
    else
        return "The command doesn't exist\n";
}

}

