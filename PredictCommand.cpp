//
//  PredictCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "PredictCommand.hpp"

#include <iostream>

PredictCommand::PredictCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool PredictCommand::run(const OrderBook& orderBook) {
    bool validParams = areParamsValid(orderBook);
    
    // Invalid parameters, return false
    if (!validParams)   return validParams;
    
    // Start looking at the current timestamp
    std::string currentTimestamp = orderBook.getCurrentTimestamp();
    double totalMaxMinPrice = 0.0;
    
    // Go back 5 timesteps to check the last max or min prices.
    for (int i = 0; i < 5; ++i) {
        // Get the highest or lowest price based on user input
        // Add up the highest/lowest prices of orders from the filtered orderbook together for the last 5 timesteps
        if (m_orderPriceValue == "min") {
            totalMaxMinPrice += orderBook.getLowestPrice(orderBook.getOrders(m_orderType, m_product, currentTimestamp));
        } else if (m_orderPriceValue == "max") {
            totalMaxMinPrice += orderBook.getHighestPrice(orderBook.getOrders(m_orderType, m_product, currentTimestamp));
        }
        
        // Update the current timestep to the last timestamp
        currentTimestamp = orderBook.getLastTime(currentTimestamp);
    }
    
    // Divide the total by the amount of timesteps
    totalMaxMinPrice /= 5;
    
    std::cout << "The predicted " << m_product << " " << m_orderPriceValue <<
        " " << OrderBookEntry::OrderBookTypeToString(m_orderType) <<
        " price for the next timestep is " << totalMaxMinPrice << std::endl;
    
    return validParams;
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
            m_product = m_params[1];
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
