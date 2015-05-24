#include "parser.h"
#include <cstring>

using namespace std;

namespace WhistGame {

string ParseMessage(char* message, char delimiter)
{
    string command;
    unsigned int i;
    for (i = 0; message[i] != delimiter; i++)
        command.push_back(message[i]);

    i = command.size() + 1;
    int  k = 0;
    for (; i <= strlen(message); i++)
        message[k++] = message[i];
    
    return command;
}

vector<string> ParseCommand(string& command, char delimiter)
{
    vector<string> parameters;

    size_t found = command.find(delimiter);
    while (found != string::npos)
    {
        parameters.push_back(command.substr(0, found));
        command.erase(command.begin(), command.begin() + found + 1);
        found = command.find(delimiter);
    }

    if (command.size() > 0)
    {
        parameters.push_back(command);
        command = "";
    }

    return parameters;
}

} //end namespace

