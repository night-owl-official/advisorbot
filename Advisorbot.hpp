//
//  Advisorbot.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/4/22.
//

#ifndef Advisorbot_hpp
#define Advisorbot_hpp

#include "OrderBook.hpp"

#include <string>

class AdvisorBot {
public:
    // Constructor, initializing the orderbook with a filepath to the csv file
    // Also set the current time to the earliest time.
    AdvisorBot(const std::string& csvFilepath);
    
private:
    OrderBook m_orderBook;      // Instance of an orderbook.
    std::string m_currentTime;  // The current timestamp for the simulation.
};

#endif /* Advisorbot_hpp */
