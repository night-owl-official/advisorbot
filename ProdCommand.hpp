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
    void run() override;
protected:
    /*
     Verify that the parameters are valid for this command.
     */
    bool areParamsValid() override;
};

#endif /* ProdCommand_hpp */