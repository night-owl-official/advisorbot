//
//  Advisorbot.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/4/22.
//

#include "Advisorbot.hpp"

#include "CSVParser.hpp"
#include "CommandParser.hpp"

#include <iostream>

AdvisorBot::AdvisorBot(const std::string& csvFilepath):
    m_orderBook{csvFilepath} {}

/*
 Call to start advisorbot.
 */
void AdvisorBot::init() {
    // Initialize the timestamp to the earliest in the order book.
    m_currentTime = m_orderBook.getEarliestTime();
    
    // User input
    std::string userInput = "";
    
    // Inform the user on how to make it work.
    std::cout << "advisorbot> Please enter a command, or help for a list of commands" << std::endl;
    
    // Main loop
    while (true) {
        // Waits for some user input.
        std::cout << "user> ";
        std::getline(std::cin, userInput);
        
        // Process the user input here.
    }
}
