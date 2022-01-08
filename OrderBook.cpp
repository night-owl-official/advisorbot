//
//  OrderBook.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#include "OrderBook.hpp"

#include "CSVParser.hpp"

/*
 Initialize order book from a csv file.
 */
OrderBook::OrderBook(const std::string& filename) {
    // Read in orders from the CSV file.
    m_orders = CSVParser::readCSV(filename);
}

/*
 Return a vector of all known products in the dataset.
 */
std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> temp{};
    return temp;
}

/*
 Return vector of Orders according to the sent filters.
 */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                 const std::string& product,
                                                 const std::string& timestamp) {
    std::vector<OrderBookEntry> temp{};
    return temp;
}

/*
 Return the earliest time in the orderbook.
 */
std::string OrderBook::getEarliestTime() {
    return "";
}

/*
 Return the next time after the
 sent time in the orderbook.
 If there is no next timestamp, wraps around to the start.
 */
std::string OrderBook::getNextTime(const std::string& timestamp) {
    return "";
}

/*
 Return the highest price in the order book.
 */
double OrderBook::getHighestPrice(const std::vector<OrderBookEntry>& orders) {
    return 0.0;
}

/*
 Return the lowest price in the order book.
 */
double OrderBook::getLowestPrice(const std::vector<OrderBookEntry>& orders) {
    return 0.0;
}
