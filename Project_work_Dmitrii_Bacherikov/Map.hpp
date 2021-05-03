//
//  Map.hpp
//  A02_2
//
//  Created by Dmitrii Bacherikov on 24.01.2021.
//

#ifndef Map_hpp
#define Map_hpp

#include "Position.hpp"
#include "iostream"
using namespace std;

class Map {
private:
    int width;
    int height;
    char *ch;
    static int mapsCounter;
    
    
public:
    void print();
    
    //Default constructor
    Map ();
    
    //Constructor
    Map (int, int);
    
    //Destructor
    ~Map ();
    
    char getElementAt(int x, int y);
    char getElementAt(Position p);
    bool isWall(int x, int y);
    int getMapsCount() const;
    void setElementAt(int x, int y, char symb);
    
};

#endif /* Map_hpp */
