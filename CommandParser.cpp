//
//  CommandParser.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/4/22.
//

#include "CommandParser.hpp"

/*
 parse function
 */
std::vector<std::string> CommandParser::parse(const std::string& command) {
    std::vector<std::string> tokens;
    int start, end;
    std::string token;
    char separator = ' ';
    
    // Set the starting index to the first character that is not the separator
     start = (int) command.find_first_not_of(separator, 0);
    
    // Keep looping until the end of the command string
     do {
         // Set the ending index to the first separator found starting
         // from the starting index
         end = (int) command.find_first_of(separator, start);
         
         // Stop the tokenization when we get to the end of the command string
         if (start == command.length() || start == end) break;
         
         // When there's a separator it will take the substring from the starting index
         // up to the next separator, otherwise it takes the whole string since it would be
         // a unique and singular string
         if (end >= 0) token = command.substr(start, end - start);
         else token = command.substr(start, command.length() - start);
         
         // Add the token to the list
         tokens.push_back(token);
         
         // Move the starting index to the next token after the separator
         start = end + 1;
     } while(end > 0);

    return tokens;
}
