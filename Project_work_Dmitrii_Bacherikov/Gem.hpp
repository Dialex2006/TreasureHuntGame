//
//  Gem.hpp
//  A06_1
//
//  Created by Dmitrii Bacherikov on 22.02.2021.
//

#ifndef Gem_hpp
#define Gem_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Constants.hpp"

class Gem : public GameObject {
    
private:
    int value;
    
public:
    Gem();  //Default Ctor
    Gem(char symbol, int value);  //Another Ctor
    Gem(int x, int y);  //Another Ctor
    Gem(char symbol, int value, int x, int y);  //Another Ctor
    //setter and getter
    void setValue (int);
    int getValue ();
    //print function
    void print();
    //Dustructor
    ~Gem();
    
    
};

#endif /* Gem_hpp */
