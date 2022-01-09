//
//  AvgCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef AvgCommand_hpp
#define AvgCommand_hpp

#include "Command.hpp"

class AvgCommand : public Command {
public:
    AvgCommand(const std::vector<std::string>& cmdParams);
    
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

#endif /* AvgCommand_hpp */
