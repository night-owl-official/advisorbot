//
//  TopCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/10/22.
//

#ifndef TopCommand_hpp
#define TopCommand_hpp

#include "Command.hpp"

class TopCommand : public Command {
public:
    TopCommand(const std::vector<std::string>& cmdParams);
    
    /*
     Run the command.
     */
    bool run(const OrderBook& orderBook) override;
    
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid(const OrderBook& orderBook) override;
    
private:
    OrderBookType m_orderType;  // Type of order e.g. ask or bid
};

#endif /* TopCommand_hpp */
