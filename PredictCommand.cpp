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
bool PredictCommand::run(const OrderBook& orderBook) {
    return true;
}

/*
 Verify that the parameters are valid for this command.
 */
bool PredictCommand::areParamsValid(const OrderBook& orderBook) {
    // Needs exactly 3 parameters.
    if (m_params.size() < 3)    return false;
    
    // Flags to set decide whether all params are valid
    bool firstParamIsValid = false;
    bool secondParamIsValid = false;
    bool thirdParamIsValid = false;
    
    // First parameter needs to be a valid string (max or min).
    if (m_params[0] == "min" || m_params[0] == "max") {
        // Store the valid min/max string
        m_orderPriceValue = m_params[0];
        firstParamIsValid = true;
    }
    
    // Second parameter needs to be a valid known product.
    for (const std::string& prod : orderBook.getProducts()) {
        if (m_params[1] == prod) {
            // Store the valid product
            m_product = m_params[0];
            secondParamIsValid = true;
        }
    }
    
    // Third parameter needs to be a valid order type.
    OrderBookType obt = OrderBookEntry::stringToOrderBookType(m_params[2]);
    switch (obt) {
        case OrderBookType::ask:
        case OrderBookType::bid:
            m_orderType = obt;
            thirdParamIsValid = true;
            break;
        default:
            break;
    }
    
    
    // All params are valid, return true.
    return firstParamIsValid && secondParamIsValid && thirdParamIsValid;
}
