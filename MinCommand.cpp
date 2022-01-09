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
bool MinCommand::run(const OrderBook& orderBook) {
    return true;
}

/*
 Verify that the parameters are valid for this command.
 */
bool MinCommand::areParamsValid(const OrderBook& orderBook) {
    // Needs exactly 2 parameters.
    if (m_params.size() < 2)    return false;
    
    // First parameter needs to be a valid known product.
    // Second parameter needs to be a valid order type.
    return true;
}
