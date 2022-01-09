//
//  TimeCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "TimeCommand.hpp"

#include <iostream>

TimeCommand::TimeCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool TimeCommand::run(const OrderBook& orderBook) {
    bool validParams = areParamsValid(orderBook);
    
    // Invalid parameters, return false.
    if (!validParams)   return validParams;
    
    // Display the current timestamp.
    std::cout << orderBook.getCurrentTimestamp() << std::endl;
    
    return validParams;
}

/*
 Verify that the parameters are valid for this command.
 */
bool TimeCommand::areParamsValid(const OrderBook& orderBook) {
    // No parameters allowed for this command.
    return m_params.size() == 0;
}
