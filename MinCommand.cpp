//
//  MinCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "MinCommand.hpp"

MinCommand::MinCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
void MinCommand::run() {
    
}

/*
 Verify that the parameters are valid for this command.
 */
bool MinCommand::areParamsValid() {
    return true;
}