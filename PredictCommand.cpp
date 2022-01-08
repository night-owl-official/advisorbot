//
//  PredictCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "PredictCommand.hpp"

PredictCommand::PredictCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool PredictCommand::run() {
    return true;
}

/*
 Verify that the parameters are valid for this command.
 */
bool PredictCommand::areParamsValid() {
    return true;
}
