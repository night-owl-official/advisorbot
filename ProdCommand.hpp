//
//  ProdCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef ProdCommand_hpp
#define ProdCommand_hpp

#include "Command.hpp"

class ProdCommand : public Command {
public:
    ProdCommand(const std::vector<std::string>& cmdParams);
    
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

#endif /* ProdCommand_hpp */
