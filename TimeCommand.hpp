//
//  TimeCommand.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef TimeCommand_hpp
#define TimeCommand_hpp

#include "Command.hpp"

class TimeCommand : public Command {
public:
    TimeCommand(const std::vector<std::string>& cmdParams);
    
    /*
     Run the command.
     */
    bool run(const OrderBook& orderBook) override;
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid() override;
};

#endif /* TimeCommand_hpp */
