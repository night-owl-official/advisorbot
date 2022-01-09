//
//  OrderBook.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#include "OrderBook.hpp"

#include "CSVParser.hpp"

#include <map>

/*
 Initialize order book from a csv file.
 */
OrderBook::OrderBook(const std::string& filename) {
    // Read in orders from the CSV file.
    m_orders = CSVParser::readCSV(filename);
    
    // Store the known products from the dataset.
    setKnownProducts();
}

/*
 Return vector of Orders according to the sent filters.
 */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                 const std::string& product,
                                                 const std::string& timestamp) const {
    std::vector<OrderBookEntry> filtered_orders;
    
    // Go through the orders and only select orders
    // that match the given filters.
    for (const OrderBookEntry& obe : m_orders) {
        
        if (obe.getOrderBookType() == type &&
            obe.getProduct() == product &&
            obe.getTimestamp() == timestamp ) {
                filtered_orders.push_back(obe);
            }
    }
    
    return filtered_orders;
}

/*
 Return the earliest time in the orderbook.
 */
std::string OrderBook::getEarliestTime() const {
    return m_orders[0].getTimestamp();
}

/*
 Return the next time after the
 sent time in the orderbook.
 If there is no next timestamp, wraps around to the start.
 */
std::string OrderBook::getNextTime(const std::string& timestamp) const {
    std::string nextTimestamp = "";
    std::string currentTimestamp = "";
    
    // Find the first timestamp greater than the given timestamp
    for (const OrderBookEntry& obe : m_orders) {
        currentTimestamp = obe.getTimestamp();
        if (currentTimestamp > timestamp) {
            nextTimestamp = currentTimestamp;
            break;
        }
    }
    
    // No timestamp is greater than the given timestamp, loop back to the beginning
    // of the dataset as the given timestamp was the last timestamp.
    if (nextTimestamp == "")   nextTimestamp = m_orders[0].getTimestamp();
    
    return nextTimestamp;
}

/*
 Return the highest price in the given order book.
 */
double OrderBook::getHighestPrice(const std::vector<OrderBookEntry>& orders) {
    // First max price is the first order in the orderbook.
    double max = orders[0].getPrice();
    
    // Look into all the orders and find the max price in the orderbook.
    for (const OrderBookEntry& obe : orders) {
        if (obe.getPrice() > max)   max = obe.getPrice();
    }
    
    return max;
}

/*
 Return the lowest price in the given order book.
 */
double OrderBook::getLowestPrice(const std::vector<OrderBookEntry>& orders) {
    // First min price is the first order in the orderbook.
    double min = orders[0].getPrice();
    
    // Look into all the orders and find the min price in the orderbook.
    for (const OrderBookEntry& obe : orders) {
        if (obe.getPrice() < min)   min = obe.getPrice();
    }
    
    return min;
}

/*
 Return the average price in the given order book.
 */
double OrderBook::getAveragePrice(const std::vector<OrderBookEntry>& orders) {
    double avg = 0.0;
    
    // Keep adding prices to the average.
    for (const OrderBookEntry& obe : orders)    avg += obe.getPrice();
    
    // Divide by the total entries
    avg /= orders.size();
    
    return avg;
}

/*
 Return a vector of all known products in the dataset.
 */
void OrderBook::setKnownProducts() {
    std::map<std::string, bool> prodMap;

    // Use a map with the product as key to avoid duplicates.
    for (const OrderBookEntry& obe : m_orders)  prodMap[obe.getProduct()] = true;
    
    // Now flatten the map to a vector of strings
    for (const auto& e : prodMap)   m_knownProducts.push_back(e.first);
}
