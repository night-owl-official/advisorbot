//
//  HelpCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "HelpCommand.hpp"

HelpCommand::HelpCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
void HelpCommand::run() {
    
}

/*
 Verify that the parameters are valid for this command.
 */
bool HelpCommand::areParamsValid() {
    return true;
}