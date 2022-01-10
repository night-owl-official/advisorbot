//
//  MinCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "MinCommand.hpp"

#include <iostream>

MinCommand::MinCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool MinCommand::run(const OrderBook& orderBook) {
    bool validParams = areParamsValid(orderBook);
    
    // Invalid parameters, return false
    if (!validParams)   return validParams;
    
    // Orderbook with only filtered entries based on the given parameters.
    std::vector<OrderBookEntry> filteredOrders =
        orderBook.getOrders(m_orderType, m_product, orderBook.getCurrentTimestamp());
    
    // The min price in the filtered orderbook.
    double minPrice = OrderBook::getLowestPrice(filteredOrders);
    
    // Display min price.
    std::cout << "The min " << OrderBookEntry::OrderBookTypeToString(m_orderType) <<
        " price for " << m_product << " is " << minPrice << std::endl;
    
    return validParams;
}

/*
 Verify that the parameters are valid for this command.
 */
bool MinCommand::areParamsValid(const OrderBook& orderBook) {
    // Needs exactly 2 parameters.
    if (m_params.size() != 2)    return false;
    
    // Flags to set decide whether both params are valid
    bool firstParamIsValid = false;
    bool secondParamIsValid = false;
    
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
    
    // Both params are valid, return true.
    return firstParamIsValid && secondParamIsValid;
}
