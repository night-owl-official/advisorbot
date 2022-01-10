//
//  OrderBook.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#ifndef OrderBook_hpp
#define OrderBook_hpp

#include <vector>

#include "OrderBookEntry.hpp"

class OrderBook {
public:
    /*
     Initialize order book from a csv file.
     */
    OrderBook(const std::string& filename);
    
    /*
     Getters
     */
    inline std::string getCurrentTimestamp() const { return m_currentTimestamp; }
    
    inline std::vector<std::string> getProducts() const { return m_knownProducts; }
    
    /*
     Setters
     */
    inline void setCurrentTimestamp(const std::string& timestamp) { m_currentTimestamp = timestamp; }
    
    /*
     Return vector of Orders according to the sent filters.
     */
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          const std::string& product,
                                          const std::string& timestamp) const;
    
    /*
     Return vector of Orders according to the sent filters.
     */
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          const std::string& timestamp) const;
    
    /*
     Return the earliest time in the orderbook.
     */
    std::string getEarliestTime() const;
    
    /*
     Return the next time after the
     sent time in the orderbook.
     If there is no next timestamp, wraps around to the start.
     */
    std::string getNextTime(const std::string& timestamp) const;
    
    /*
     Return the last time before the
     sent time in the orderbook.
     If there is no last timestamp, wraps around to the end.
     */
    std::string getLastTime(const std::string& timestamp) const;
    
public:
    /*
     Return the highest price in the given order book.
     */
    static double getHighestPrice(const std::vector<OrderBookEntry>& orders);
    
    /*
     Return the lowest price in the given order book.
     */
    static double getLowestPrice(const std::vector<OrderBookEntry>& orders);
    
    /*
     Return the average price in the given order book.
     */
    static double getAveragePrice(const std::vector<OrderBookEntry>& orders);
    
private:
    /*
     Return a vector of all known products in the dataset.
     */
    void setKnownProducts();

private:
    std::vector<OrderBookEntry> m_orders;       // Store all the orderbook entries
    std::string m_currentTimestamp;             // The current timestamp in the orderbook.
    std::vector<std::string> m_knownProducts;   // List of all known products.
};

#endif /* OrderBook_hpp */
