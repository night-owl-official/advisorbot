//
//  PredictCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef PredictCommand_hpp
#define PredictCommand_hpp

#include "Command.hpp"

class PredictCommand : public Command {
public:
    PredictCommand(const std::vector<std::string>& cmdParams);
    
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

#endif /* PredictCommand_hpp */
