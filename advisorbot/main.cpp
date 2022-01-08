//
//  main.cpp
//  advisorbot
//
//  Created by Daniel Grieco on 1/4/22.

#include "AdvisorBot.hpp"

int main(int argc, const char * argv[]) {
    AdvisorBot advisorbot{"/Users/danielgrieco/Desktop/merklerex_end_topic_5/src/20200601.csv"};
    advisorbot.init();
    
    return 0;
}
