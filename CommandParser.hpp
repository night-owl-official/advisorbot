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

class CommandParser {
public:
    // Default constructor
    CommandParser() = default;
    
private:
    /*
     Tokenize a command string.
     */
    static std::vector<std::string> tokenize(const std::string& command, char separator);
};

#endif /* CommandParser_hpp */
