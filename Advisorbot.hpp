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
    AdvisorBot(const std::string& csvFilepath);
    
    /*
     Call to start advisorbot.
     */
    void init();
    
private:
    /*
     Process the user input and responds accordingly.
     */
    void processUserInput(const std::string& input);
    
private:
    OrderBook m_orderBook;      // Instance of an orderbook.
    std::string m_currentTime;  // The current timestamp for the simulation.
};

#endif /* Advisorbot_hpp */
