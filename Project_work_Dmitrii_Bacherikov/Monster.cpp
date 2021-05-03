//
//  Monster.cpp
//  A06_1
//
//  Created by Dmitrii Bacherikov on 22.02.2021.
//

#include "Monster.hpp"
#include <iostream>
using namespace std;

void Monster::setStrength(int strength) {
    this->strength = strength;
}

int Monster::getStrength() {
    return this->strength;
}

//Defaulf Ctor
Monster::Monster() : GameObject() {
    this->strength = 15;
}

//Custom Ctor
Monster::Monster(char symbol, int strength) : GameObject(symbol) {
    this->strength = strength;
}

//Custom Ctor
Monster::Monster(char symbol, int strength, int x, int y) : GameObject(symbol, x, y) {
    this->strength = strength;
}

//Custom Ctor
//Monster::Monster(int x, int y) : GameObject(x, y) {
//    this->strength = 50;
//}

//void Monster::printSelf() {
//    cout << "Monster is at: (" << this->position.getX() << ", " << this->position.getY() << ")" <<endl;
//}

//ObjectType Monster::getType() {
//    return MonsterType;
//};
