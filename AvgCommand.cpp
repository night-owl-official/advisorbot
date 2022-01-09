//
//  AvgCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "AvgCommand.hpp"

#include <iostream>

AvgCommand::AvgCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool AvgCommand::run(const OrderBook& orderBook) {
    return true;
}

/*
 Verify that the parameters are valid for this command.
 */
bool AvgCommand::areParamsValid(const OrderBook& orderBook) {
    // Needs exactly 3 parameters.
    if (m_params.size() < 3)    return false;
    
    // Flags to set decide whether all params are valid
    bool firstParamIsValid = false;
    bool secondParamIsValid = false;
    bool thirdParamIsValid = false;
    
    // First parameter needs to be a valid known product.
    for (const std::string& prod : orderBook.getProducts()) {
        if (m_params[0] == prod) {
            // Store the valid product
            m_product = m_params[0];
            firstParamIsValid = true;
        }
    }
    
    // Second parameter needs to be a valid order type.
    OrderBookType obt = OrderBookEntry::stringToOrderBookType(m_params[1]);
    switch (obt) {
        case OrderBookType::ask:
        case OrderBookType::bid:
            m_orderType = obt;
            secondParamIsValid = true;
            break;
        default:
            break;
    }
    
    // Third parameter needs to be a valid integer.
    try {
        // Try converting a string to an integer.
        m_timesteps = std::stoi(m_params[2]);
        
        // If the timestep is an integer that's not 0 then the conversion was successful
        if (m_timesteps > 0)    thirdParamIsValid = true;
    } catch (const std::exception& e) {
        // Conversion went wrong.
    }
    
    // All params are valid, return true.
    return firstParamIsValid && secondParamIsValid && thirdParamIsValid;
}
