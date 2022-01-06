//
//  StepCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "StepCommand.hpp"

StepCommand::StepCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
void StepCommand::run() {
    
}

/*
 Verify that the parameters are valid for this command.
 */
bool StepCommand::areParamsValid() {
    return true;
}