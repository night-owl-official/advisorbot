//
//  MaxCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef MaxCommand_hpp
#define MaxCommand_hpp

#include "Command.hpp"

class MaxCommand : public Command {
public:
    MaxCommand(const std::vector<std::string>& cmdParams);
    
    /*
     Run the command.
     */
    void run() override;
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid() override;
};

#endif /* MaxCommand_hpp */
