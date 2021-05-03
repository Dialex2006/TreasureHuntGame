//
//  Player.hpp
//  A05_4
//
//  Created by Dmitrii Bacherikov on 15.02.2021.
//

#ifndef Player_hpp
#define Player_hpp
#include "GameObject.hpp"

#include "Position.hpp"

class Player : public GameObject {
    
private:
    int energy;
    int points;
public:
    //Default Ctor
    Player();
    
    //Other Ctors
    Player(int, int, int, char);
    
    
    //member functions
    void changePosition(int, int);
    void setEnergy(int);
    Position getPosition();
    int getEnergy();
    int getPoints();
    void addPoints (int);
    
};





#include <stdio.h>

#endif /* Player_hpp */
