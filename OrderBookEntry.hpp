//
//  OrderBookEntry.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#ifndef OrderBookEntry_hpp
#define OrderBookEntry_hpp

#include <string>

enum class OrderBookType {
    bid,
    ask,
    unknown
};

class OrderBookEntry {
public:
    OrderBookEntry(double price,
                   double amount,
                   const std::string& timestamp,
                   const std::string& product,
                   OrderBookType orderType);
    
    /*
     Convert a string to an order book type e.g. bid or ask
     */
    static OrderBookType stringToOrderBookType(const std::string& typeString);
    
    /*
     Compare two order books entries by timestamp.
     */
    inline static bool compareByTimestamp(const OrderBookEntry& entry1, const OrderBookEntry& entry2) {
        return entry1.m_timestamp < entry2.m_timestamp;
    }
    
    /*
     Compare two order books entries by price ascending/descending.
     */
    static bool compareByPrice(const OrderBookEntry& entry1, const OrderBookEntry& entry2, bool ascending = true);
    
private:
    double m_price;
    double m_amount;
    std::string m_timestamp;
    std::string m_product;
    OrderBookType m_orderType;
};

#endif /* OrderBookEntry_hpp */
