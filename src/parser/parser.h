#ifndef _PARSER_H__
#define _PARSER_H__

#include <string>
#include <vector>

namespace WhistGame {

std::string ParseMessage(char*, char = '\n');
std::vector<std::string> ParseCommand(std::string&, char = ' ');

} // end namespace

#endif

