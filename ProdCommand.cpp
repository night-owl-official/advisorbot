//
//  ProdCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "ProdCommand.hpp"

ProdCommand::ProdCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
void ProdCommand::run() {
    
}

/*
 Verify that the parameters are valid for this command.
 */
bool ProdCommand::areParamsValid() {
    return true;
}
