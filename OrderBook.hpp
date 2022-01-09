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
    
    /*
     Setters
     */
    inline void setCurrentTimestamp(const std::string& timestamp) { m_currentTimestamp = timestamp; }
    
    /*
     Return a vector of all known products in the dataset.
     */
    std::vector<std::string> getKnownProducts() const;
    
    /*
     Return vector of Orders according to the sent filters.
     */
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          const std::string& product,
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
     Return the highest price in the order book.
     */
    double getHighestPrice() const;
    
    /*
     Return the lowest price in the order book.
     */
    double getLowestPrice() const;

private:
    std::vector<OrderBookEntry> m_orders;   // Store all the orderbook entries
    std::string m_currentTimestamp;         // The current timestamp in the orderbook.
};

#endif /* OrderBook_hpp */
