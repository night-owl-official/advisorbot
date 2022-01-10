//
//  CommandParser.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/4/22.
//

#include "CommandParser.hpp"

#include "HelpCommand.hpp"
#include "ProdCommand.hpp"
#include "MinCommand.hpp"
#include "MaxCommand.hpp"
#include "AvgCommand.hpp"
#include "PredictCommand.hpp"
#include "TimeCommand.hpp"
#include "StepCommand.hpp"
#include "TopCommand.hpp"

/*
 Get a Command from a command string.
 */
Command* CommandParser::getCommand(const std::string& commandString) {
    Command* nop_command = nullptr;
    // Tokenize the command string
    std::vector<std::string> commandBits = CommandParser::tokenize(commandString, ' ');
    
    // Extract the command parameters from the tokenized string
    // Start counting from one because we don't want the command name
    std::vector<std::string> commandParameters;
    for (int i = 1; i < commandBits.size(); ++i)
        commandParameters.push_back(commandBits[i]);
    
    // Instantiate a command on the heap based on the command name entered by the user
    if (commandBits[0] == "help")           nop_command = new HelpCommand{commandParameters};
    else if (commandBits[0] == "prod")      nop_command = new ProdCommand{commandParameters};
    else if (commandBits[0] == "min")       nop_command = new MinCommand{commandParameters};
    else if (commandBits[0] == "max")       nop_command = new MaxCommand{commandParameters};
    else if (commandBits[0] == "avg")       nop_command = new AvgCommand{commandParameters};
    else if (commandBits[0] == "predict")   nop_command = new PredictCommand{commandParameters};
    else if (commandBits[0] == "time")      nop_command = new TimeCommand{commandParameters};
    else if (commandBits[0] == "step")      nop_command = new StepCommand{commandParameters};
    else if (commandBits[0] == "top")       nop_command = new TopCommand{commandParameters};
    
    // There's a chance that a nullpointer could be returned
    // In that case it simply means the given command is not correct
    return nop_command;
}

/*
 Tokenize a command string.
 */
std::vector<std::string> CommandParser::tokenize(const std::string& command, char separator) {
    std::vector<std::string> tokens;
    int start, end;
    std::string token;
    
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
