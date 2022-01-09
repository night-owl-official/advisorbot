//
//  StepCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef StepCommand_hpp
#define StepCommand_hpp

#include "Command.hpp"

class StepCommand : public Command {
public:
    StepCommand(const std::vector<std::string>& cmdParams);
    
    /*
     Run the command.
     */
    bool run(const OrderBook& orderBook) override;
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid(const OrderBook& orderBook) override;
};

#endif /* StepCommand_hpp */
