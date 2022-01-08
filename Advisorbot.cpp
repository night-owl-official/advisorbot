//
//  Advisorbot.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/4/22.
//

#include "Advisorbot.hpp"

#include "CSVParser.hpp"
#include "CommandParser.hpp"

AdvisorBot::AdvisorBot(const std::string& csvFilepath):
    m_orderBook{csvFilepath} {
        // Set the starting time as the current time.
        m_currentTime = m_orderBook.getEarliestTime();
    }
