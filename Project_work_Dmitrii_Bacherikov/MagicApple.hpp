//
//  MagicApple.hpp
//  A07_5
//
//  Created by Dmitrii Bacherikov on 07.03.2021.
//

#ifndef MagicApple_hpp
#define MagicApple_hpp
#include "iostream"
#include <stdio.h>
#include "GameObject.hpp"
#include "Constants.hpp"


class MagicApple : public GameObject {
    
private:
    int energy;
    
public:
    MagicApple();  //Default Ctor
    MagicApple(int energy);  //Another Ctor
    MagicApple(int energy, int x, int y);  //Another Ctor
    MagicApple(int x, int y);  //Another Ctor
    //setters and getters
    void setEnergy(int);
    int getEnergy();
    ~MagicApple() {};
    
};


#endif /* MagicApple_hpp */
