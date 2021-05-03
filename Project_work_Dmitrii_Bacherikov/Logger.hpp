//
//  Logger.hpp
//  A04_5
//
//  Created by Dmitrii Bacherikov on 09.02.2021.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <iostream>
#include <vector>
using namespace std;


class Logger {
private:
    vector<string> logRecords;
public:
    Logger ();
    void addLog (string line, bool echo);

    void putRecords();
    void printAll();
    void saveLogs();
};

#endif /* Logger_hpp */
