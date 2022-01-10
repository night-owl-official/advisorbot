//
//  TopCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/10/22.
//

#include "TopCommand.hpp"

#include <iostream>

TopCommand::TopCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool TopCommand::run(const OrderBook& orderBook) {
    bool validParams = areParamsValid(orderBook);
    
    // Invalid parameters, return false
    if (!validParams)   return validParams;
    
    // Orderbook with only filtered entries based on the given parameters.
    std::vector<OrderBookEntry> filteredOrders =
        orderBook.getOrders(m_orderType, orderBook.getCurrentTimestamp());
    
    // The top entry in the filtered orderbook.
    OrderBookEntry topEntry = OrderBook::getTopEntry(filteredOrders);
    
    // Display top entry.
    std::cout << "The top " << OrderBookEntry::OrderBookTypeToString(m_orderType) <<
        " is " << topEntry.getPrice() << " for " << topEntry.getProduct() << std::endl;
    
    return validParams;
}

/*
 Verify that the parameters are valid for this command.
 */
bool TopCommand::areParamsValid(const OrderBook& orderBook) {
    // Needs exactly 1 parameter.
    if (m_params.size() != 1)    return false;
    
    // Flag for valid parameter
    bool paramIsValid = false;
    
    // The parameter needs to be a valid order type.
    OrderBookType obt = OrderBookEntry::stringToOrderBookType(m_params[0]);
    switch (obt) {
        case OrderBookType::ask:
        case OrderBookType::bid:
            m_orderType = obt;
            paramIsValid = true;
            break;
        default:
            break;
    }
    
    // If the parameter is valid return true.
    return paramIsValid;
}
