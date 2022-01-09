//
//  HelpCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef HelpCommand_hpp
#define HelpCommand_hpp

#include "Command.hpp"

#include <map>

class HelpCommand : public Command {
public:
    HelpCommand(const std::vector<std::string>& cmdParams);
    
    /*
     Run the command.
     */
    bool run(const OrderBook& orderBook) override;
    
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid() override;
    
private:
    /*
     Display all the available commands.
     */
    void runBasicHelp() const;
    
    /*
     Initialize the commands help map.
     */
    void initCommandsHelpMap();
    
private:
    static const std::string AVAILABLE_COMMANDS[9]; // List of available commands.
    
private:
    std::map<std::string, std::string> m_commandsHelpMap;   // Maps command to help description.
    std::string m_currentValidParameter;                    // The command the user needs help with.
};

#endif /* HelpCommand_hpp */
