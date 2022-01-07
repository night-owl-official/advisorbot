//
//  CSVParser.hpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#ifndef CSVParser_hpp
#define CSVParser_hpp

#include "OrderBookEntry.hpp"

class CSVParser {
public:
    // Static class, no constructor or destructor
    CSVParser() = delete;
    ~CSVParser() = delete;
    
    /*
     Read CSV file while parsing all its lines into OrderBookEntries.
     */
    static std::vector<OrderBookEntry> readCSV(const std::string& csvFilename);

   private:
    /*
     Take a csv line and turns it into bits where separator happens.
     */
    static std::vector<std::string> tokenize(const std::string& csvLine, char separator = ' ');
    
    /*
     Turn tokens for one order into an OrderBookEntry.
     */
    static OrderBookEntry tokensToOBE(const std::vector<std::string>& tokens);
};

#endif /* CSVParser_hpp */
