//
//  Map.cpp
//  A02_2
//
//  Created by Dmitrii Bacherikov on 24.01.2021.
//

#include <ctime>
#include "Map.hpp"
#include "Constants.hpp"

#include <cstdlib>

//Default Constructor
Map::Map() : Map (1,1) {
    mapsCounter++;
}

//Constructor
Map::Map (int width, int height) {
    srand (time(NULL));
    this->width = width;
    this->height = height;
    ch = new char [(width)*(height)];  //dynamically allocated
    
    //filling the whole map with symbols
    for (int i=0; i<(width)*(height); i++) {
        //defining walls - first and last rows + sides
        if (i<width || i%(width) == 0 || (i+1)%(width) == 0 || i>(width)*(height) - width-2 )
            ch[i] = Constants::getMapWall();
        else {
            int randNum = rand() % 100 + 1; // in less than 10% cases
            if (randNum < 10)
                ch[i] = Constants::getInsideMapWall(); //placing random "rooms"
            else
                ch[i] = Constants::getMapDot();  //dots at other positions - mapping
        }
    }
    mapsCounter++;
}

//print the whole map
void Map::print() {
    for (int i=0; i<(width)*(height); i++) {
        cout << ch[i];
        if ((i+1)%(width)==0) //end of each row
            cout << endl;
    }
}

//returning symbol at a certain position
char Map::getElementAt(int x, int y) {
    return this->ch[x-1 + this->width * (y-1)];
}

//returning symbol at a certain position (Position class)
char Map::getElementAt(Position p) {
    return this->ch[p.getX()-1 + this->width * (p.getY()-1)];
}

bool Map::isWall(int x, int y) {
    if (this->getElementAt(x, y) == Constants::getMapWall() || this->getElementAt(x, y) == Constants::getInsideMapWall())
        return true;
    else return false;
}

//Destructor
Map::~Map () {
    delete [] ch;
}

int Map::mapsCounter = 0;

int Map::getMapsCount() const {
    return mapsCounter;
}

void Map::setElementAt(int x, int y, char symb) {
    this->ch[x-1 + this->width * (y-1)] = symb;
}
