//
//  TimeCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "TimeCommand.hpp"

TimeCommand::TimeCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
void TimeCommand::run() {
    
}

/*
 Verify that the parameters are valid for this command.
 */
bool TimeCommand::areParamsValid() {
    return true;
}
