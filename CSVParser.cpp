//
//  CSVParser.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/7/22.
//

#include "CSVParser.hpp"

#include <vector>
#include <fstream>
#include <iostream>

/*
 Read CSV file while parsing all its lines into OrderBookEntries.
 */
std::vector<OrderBookEntry> CSVParser::readCSV(const std::string& csvFilename) {
    std::vector<OrderBookEntry> entries;

    // Open an input file stream using the given filename.
     std::ifstream csvFile{csvFilename};
     std::string line;
    
    // Make sure the file was opened before reading.
     if (csvFile.is_open()) {
         // Keep reading the file until the end of the file
         // and store every newly read line into the string line.
         while(std::getline(csvFile, line)) {
             try {
                 // Try to convert a csv line into an order book an entry.
                entries.push_back(tokensToOBE(tokenize(line)));
             } catch(const std::exception& e) {
                 // Something went wrong while trying to convert a line into an OBE.
                 std::cout << "CSVParser::readCSV Bad data!"  << std::endl;
             }
         }
     }

     return entries;
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
    double price;
    double amount;
    
    // A well formed line from the exchange csv would contain 5 tokens
    // if we have less or more than that then it's not a good line.
    if (tokens.size() != 5) {
        std::cout << "CSVParser::tokensToOBE Bad line!" << std::endl;
        throw std::exception{};
    }
    
    // We have 5 tokens.
    try {
        // Try to convert price and amount tokens to double.
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    } catch(const std::exception& e) {
        // Failed to convert token string to double
        std::cout << "CSVReader::stringsToOBE Bad float! " << tokens[3]<< std::endl;
        std::cout << "CSVReader::stringsToOBE Bad float! " << tokens[4]<< std::endl;
        throw;
    }

    // Construct an Order Book Entry and return it.
    return OrderBookEntry {price, amount,
                        tokens[0], tokens[1],
                        OrderBookEntry::stringToOrderBookType(tokens[2])};
}
