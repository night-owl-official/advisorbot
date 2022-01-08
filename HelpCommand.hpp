//
//  HelpCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef HelpCommand_hpp
#define HelpCommand_hpp

#include "Command.hpp"

#include <string>

class HelpCommand : public Command {
public:
    HelpCommand(const std::vector<std::string>& cmdParams);
    
    /*
     Run the command.
     */
    bool run() override;
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid() override;
    
private:
    static const std::string AVAILABLE_COMMANDS[9]; // List of available commands.
};

#endif /* HelpCommand_hpp */
