//
//  HelpCommand.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#include "HelpCommand.hpp"

#include <iostream>

// Available commands.
const std::string HelpCommand::AVAILABLE_COMMANDS[9] = {
    "help",
    "help <cmd>",
    "prod",
    "min",
    "max",
    "avg",
    "predict",
    "time",
    "step"
};

HelpCommand::HelpCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {}

/*
 Run the command.
 */
bool HelpCommand::run() {
    // Check the validity of the parameters.
    bool paramsValid = areParamsValid();
    
    // Invalid parameters.
    // Don't continue execution.
    if (!paramsValid)   return paramsValid;
    
    // Valid parameters.
    if (m_params.size() < 1) {
        // Regular help command.
        std::cout << "The available commands are ";
        
        // Calculate the size of the available commands array.
        int availableCommandsArraySize = sizeof(AVAILABLE_COMMANDS) / sizeof(AVAILABLE_COMMANDS[0]);
        // Write out all the commands to the console.
        for (int i = 0; i < availableCommandsArraySize; ++i) {
            std::cout << AVAILABLE_COMMANDS[i];
            
            // Don't add a comma and space for the last command in the list.
            if (i < availableCommandsArraySize - 1) {
                std::cout << ", ";
            }
        }
        
        // Newline at the end of the list.
        std::cout << std::endl;
    } else if (m_params.size() == 1) {
        // Process help <cmd> command.
    }
    
    return paramsValid;
}

/*
 Verify that the parameters are valid for this command.
 */
bool HelpCommand::areParamsValid() {
    return true;
}
