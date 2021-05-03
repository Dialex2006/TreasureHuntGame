//
//  Logger.cpp
//  A04_5
//
//  Created by Dmitrii Bacherikov on 09.02.2021.
//

#include "Logger.hpp"
#include <fstream>
#include <sstream>
#include "Utilities.hpp"


Logger::Logger () {
    logRecords = {};
};


void Logger::addLog (string line, bool echo=true) {
    logRecords.push_back(getCurrentTime ()+" "+line);
    if (echo)
        cout << line << endl;
};

void Logger::printAll () {
    for (int i=0; i < this->logRecords.size(); i++) {
        cout << this->logRecords[i] << endl;
    }
};



void  Logger::saveLogs () {
    ofstream file;
    file.open("Logs.txt");
    for (int i=0; i < this->logRecords.size(); i++) {
        file << this->logRecords[i] << endl;
    }
    file.close();
}
