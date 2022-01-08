//
//  MinCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef MinCommand_hpp
#define MinCommand_hpp

#include "Command.hpp"

class MinCommand : public Command {
public:
    MinCommand(const std::vector<std::string>& cmdParams);
    
    /*
     Run the command.
     */
    bool run() override;
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid() override;
};

#endif /* MinCommand_hpp */
