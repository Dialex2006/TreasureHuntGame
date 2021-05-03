//
//  GameObject.hpp
//  A06_1
//
//  Created by Dmitrii Bacherikov on 22.02.2021.
//

#ifndef GameObject_hpp
#define GameObject_hpp
#include "Position.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;


class GameObject {
    
private:
    char symbol;
    
protected:
    Position position;
    
public:
    GameObject();  //Default Ctor
    GameObject(char); //Custom Ctor
    GameObject(char, int, int); //Custom Ctor
    
    //setters and getters
    void setSymbol (char);
    char getSymbol ();
    void setPosition (int, int);
    //virtual void printSelf() = 0;
    Position getPosition ();
    
    //Destructor
    virtual ~GameObject();
    
};







#endif /* GameObject_hpp */
