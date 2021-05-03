//
//  Utilities.hpp
//  Project_work_Dmitrii_Bacherikov
//
//  Created by Dmitrii Bacherikov on 13.04.2021.
//
#ifndef Utilities_hpp
#define Utilities_hpp
#pragma warning(disable : 4996)

std::string getCurrentTime () {

    time_t t_time = time(0);   //current time
    struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&t_time);
        strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);
        
    return buf;
};


#endif /* Utilities_hpp */
