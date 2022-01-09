//
//  MaxCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "MaxCommand.hpp"

MaxCommand::MaxCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool MaxCommand::run(const OrderBook& orderBook) {
    return true;
}

/*
 Verify that the parameters are valid for this command.
 */
bool MaxCommand::areParamsValid() {
    return true;
}
