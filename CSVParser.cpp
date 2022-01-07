//
//  CSVParser.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#include "CSVParser.hpp"

#include <vector>

/*
 Read CSV file while parsing all its lines into OrderBookEntries.
 */
std::vector<OrderBookEntry> CSVParser::readCSV(const std::string& csvFilename) {
    std::vector<OrderBookEntry> temp{};
    return temp;
}

/*
 Take a csv line and turns it into bits where separator happens.
 */
std::vector<std::string> CSVParser::tokenize(const std::string& csvLine, char separator) {
    std::vector<std::string> tokens;
    int start, end;
    std::string token;
    
    // Set the starting index to the first character that is not the separator
     start = (int) csvLine.find_first_not_of(separator, 0);
    
    // Keep looping until the end of the command string
     do {
         // Set the ending index to the first separator found starting
         // from the starting index
         end = (int) csvLine.find_first_of(separator, start);
         
         // Stop the tokenization when we get to the end of the command string
         if (start == csvLine.length() || start == end) break;
         
         // When there's a separator it will take the substring from the starting index
         // up to the next separator, otherwise it takes the whole string since it would be
         // a unique and singular string
         if (end >= 0) token = csvLine.substr(start, end - start);
         else token = csvLine.substr(start, csvLine.length() - start);
         
         // Add the token to the list
         tokens.push_back(token);
         
         // Move the starting index to the next token after the separator
         start = end + 1;
     } while(end > 0);

    return tokens;
}

/*
 Turn tokens for one order into an OrderBookEntry.
 */
OrderBookEntry CSVParser::tokensToOBE(const std::vector<std::string>& tokens) {
    return OrderBookEntry{0.0, 0.0, "", "", OrderBookType::unknown};
}
