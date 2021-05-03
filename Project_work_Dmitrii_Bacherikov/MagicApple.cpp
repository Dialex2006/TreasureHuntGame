//
//  MagicApple.cpp
//  A07_5
//
//  Created by Dmitrii Bacherikov on 07.03.2021.
//

#include "MagicApple.hpp"
#include <iostream>
using namespace std;


void MagicApple::setEnergy(int energy) {
    this->energy = energy;
}

int MagicApple::getEnergy() {
    return this->energy;
}

//Defaulf Ctor
MagicApple::MagicApple() : GameObject() {
    this->energy = Constants::getAppleEnergy();
}

//Custom Ctor
MagicApple::MagicApple(int energy) {
    this->energy = energy;
}

//Custom Ctor
MagicApple::MagicApple(int energy, int x, int y) : GameObject(Constants::getAppleSymbol(), x, y) {
    this->energy = energy;
}

//Custom Ctor
MagicApple::MagicApple(int x, int y) : GameObject(Constants::getAppleSymbol(), x, y) {
    this->energy = 30;
}

//void MagicApple::printSelf() {
//    cout << "Magic Apple is at: (" << this->position.getX() << ", " << this->position.getY() << ")" <<endl;
//}

