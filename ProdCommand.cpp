//
//  ProdCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "ProdCommand.hpp"

#include <iostream>

ProdCommand::ProdCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool ProdCommand::run(const OrderBook& orderBook) {
    bool validParams = areParamsValid();
    
    // Invalid parameters
    if (!validParams)   return validParams;
    
    // Parameters are valid. Display a list
    // of available products.
    std::vector<std::string> knownProds = orderBook.getProducts();
    for (int i = 0; i < knownProds.size(); ++i) {
        std::cout << knownProds[i];
        
        // No comma on the last known product
        if (i < knownProds.size() - 1)  std::cout << ", ";
    }
    
    // New line at the end of the list
    std::cout << std::endl;
    
    return validParams;
}

/*
 Verify that the parameters are valid for this command.
 */
bool ProdCommand::areParamsValid() {
    // No parameters allowed for this command
    return m_params.size() == 0;
}
