//
//  StepCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "StepCommand.hpp"

#include <iostream>

StepCommand::StepCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool StepCommand::run(const OrderBook& orderBook) {
    bool validParams = areParamsValid(orderBook);
    
    // Invalid parameters, return false.
    if (!validParams)   return validParams;
    
    // Display the next timestamp.
    std::cout << "Now at " << orderBook.getNextTime(orderBook.getCurrentTimestamp()) << std::endl;
    
    return validParams;
}

/*
 Verify that the parameters are valid for this command.
 */
bool StepCommand::areParamsValid(const OrderBook& orderBook) {
    // No parameters allowed for this command.
    return m_params.size() == 0;
}
