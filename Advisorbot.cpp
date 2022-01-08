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
        
        // Quit input is processed immediately w/o
        // the help of the command parser
        if (userInput == "quit") {
            std::cout << "advisorbot> Bye! Thanks for using advisorbot!" << std::endl;
            break;
        }
        
        // Process the user input.
        processUserInput(userInput);
    }
}

/*
 Process the user input and responds accordingly.
 */
void AdvisorBot::processUserInput(const std::string& input) {
    
}
