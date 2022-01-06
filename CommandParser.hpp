//
//  CommandParser.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/4/22.
//

#ifndef CommandParser_hpp
#define CommandParser_hpp

#include <vector>
#include <string>

#include "Command.hpp"

class CommandParser {
public:
    // Static class
    CommandParser() = delete;
    ~CommandParser() = delete;
    
    /*
     Get a Command from a command string.
     */
    static Command* getCommand(const std::string& commandString);
    
private:
    /*
     Tokenize a command string.
     */
    static std::vector<std::string> tokenize(const std::string& command, char separator);
};

#endif /* CommandParser_hpp */
