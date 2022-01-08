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

HelpCommand::HelpCommand(const std::vector<std::string>& cmdParams) : Command(cmdParams) {
    // Initialize commands' help map.
    initCommandsHelpMap();
}

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
    // Basic help when no parameters and help <cmd> for one parameter.
    if (m_params.size() == 0)       runBasicHelp();
    else if (m_params.size() == 1)  std::cout << m_commandsHelpMap.at(m_currentValidParameter) << std::endl;
    
    return paramsValid;
}

/*
 Verify that the parameters are valid for this command.
 */
bool HelpCommand::areParamsValid() {
    // More than one parameter is incorrect.
    if (m_params.size() > 1)    return false;
    
    // One parameter only needs to be checked.
    if (m_params.size() == 1) {
        // Check for the given parameter in the list of valid parameters/commands.
        int validParametersArraySize = sizeof(AVAILABLE_COMMANDS) / sizeof(AVAILABLE_COMMANDS[0]);
        for (int i = 0; i < validParametersArraySize; ++i) {
            // Discard the first two commands which are just there for displaying purposes.
            if (i < 2) continue;
            
            // Check whether the parameter is valid or not.
            if (m_params[0] == AVAILABLE_COMMANDS[i]) {
                // Store the current valid parameter.
                m_currentValidParameter = m_params[0];
                return true;
            }
        }
        
        // When we get here it means that we had one parameter to the function and it was wrong.
        return false;
    }
    
    // No parameters is valid.
    return true;
}

/*
 Display all the available commands.
 */
void HelpCommand::runBasicHelp() const {
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
}

/*
 Initialize the commands help map.
 */
void HelpCommand::initCommandsHelpMap() {
    m_commandsHelpMap[AVAILABLE_COMMANDS[2]] = "prod -> List the available products";
    m_commandsHelpMap[AVAILABLE_COMMANDS[3]] = "min ETH/BTC ask -> minimum ETH/BTC ask in the current timestep";
    m_commandsHelpMap[AVAILABLE_COMMANDS[4]] = "max ETH/BTC bid -> maximum ETH/BTC bid in the current timestep";
    m_commandsHelpMap[AVAILABLE_COMMANDS[5]] = "avg ETH/BTC ask 10 -> average ETH/BTC ask price over the last 10 timesteps";
    m_commandsHelpMap[AVAILABLE_COMMANDS[6]] = "predict max ETH/BTC bid -> predict the max ETH/BTC bid price in the next timestep";
    m_commandsHelpMap[AVAILABLE_COMMANDS[7]] = "time -> state the current time in the dataset e.g. 2020/03/17 17:01:24";
    m_commandsHelpMap[AVAILABLE_COMMANDS[8]] = "step -> move to the next timestep";
}
