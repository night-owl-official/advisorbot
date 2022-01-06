//
//  AvgCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "AvgCommand.hpp"

AvgCommand::AvgCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
void AvgCommand::run() {
    
}

/*
 Verify that the parameters are valid for this command.
 */
bool AvgCommand::areParamsValid() {
    return true;
}
