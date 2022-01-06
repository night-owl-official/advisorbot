//
//  Command.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/6/22.
//

#ifndef Command_h
#define Command_h

#include <vector>
#include <string>

class Command {
public:
    Command(const std::vector<std::string>& params)
    : m_params{params} {}
    
    virtual ~Command() {}
    
    /*
     Run the command.
     */
    virtual void run() = 0;

protected:
    /*
     Verify that the parameters are valid for this command.
     */
    virtual bool areParamsValid() = 0;
    
protected:
    std::vector<std::string> m_params; // Command parameters
};

#endif /* Command_h */
