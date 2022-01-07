//
//  OrderBookEntry.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#include "OrderBookEntry.hpp"

OrderBookEntry::OrderBookEntry(double price,
               double amount,
               const std::string& timestamp,
               const std::string& product,
               OrderBookType orderType) :
    m_price{price},
    m_amount{amount},
    m_timestamp{timestamp},
    m_product{product},
    m_orderType{orderType} {}


/*
 Convert a string to an order book type e.g. bid or ask
 */
OrderBookType OrderBookEntry::stringToOrderBookType(const std::string& typeString) {
    if (typeString == "bid")        return OrderBookType::bid;
    else if (typeString == "ask")   return OrderBookType::ask;
    
    return OrderBookType::unknown;
}
