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
    std::vector<std::string> temp{};
    return temp;
}

/*
 Turn tokens for one order into an OrderBookEntry.
 */
OrderBookEntry CSVParser::tokensToOBE(const std::vector<std::string>& tokens) {
    return OrderBookEntry{0.0, 0.0, "", "", OrderBookType::unknown};
}
