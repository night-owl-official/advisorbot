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
    
    /*
     Parse a command string into multiple separate strings making up the entire command.
     */
    static std::vector<std::string> parse(const std::string& command);
private:
    
};

#endif /* CommandParser_hpp */
