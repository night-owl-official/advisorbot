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
    bool run(const OrderBook& orderBook) override;
    
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid(const OrderBook& orderBook) override;
    
private:
    std::string m_orderPriceValue;  // Max or Min for ask/bid
    std::string m_product;          // Product name e.g. ETH/BTC
    OrderBookType m_orderType;      // Type of order e.g. ask or bid
};

#endif /* PredictCommand_hpp */
