//
//  Monster.hpp
//  A06_1
//
//  Created by Dmitrii Bacherikov on 22.02.2021.
//

#ifndef Monster_hpp
#define Monster_hpp

#include "GameObject.hpp"

class Monster : public GameObject {
    
private:
    int strength;
    
public:
    Monster();  //Default Ctor
    Monster(char symbol, int strength);  //Another Ctor
    Monster(char symbol, int strength, int x, int y);  //Another Ctor
//    Monster(int x, int y);  //Another Ctor
    //setters and getters
    void setStrength(int);
    int getStrength();
    //void printSelf() override;

    //Dtor
    ~Monster() {
        //cout << "Monster was destructed" << endl;
    };
    
};



#endif /* Monster_hpp */
