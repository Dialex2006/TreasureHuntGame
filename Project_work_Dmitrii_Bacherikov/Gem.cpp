//
//  Gem.cpp
//  A06_1
//
//  Created by Dmitrii Bacherikov on 22.02.2021.
//

#include "Gem.hpp"
#include <iostream>
using namespace std;



void Gem::setValue(int value) {
    this->value = value;
}

int Gem::getValue() {
    return this->value;
}

//Default Ctor
Gem::Gem() : GameObject() {
    this->value = Constants::getGemPoints();
}

//Custom Ctor
Gem::Gem(char symbol, int value) : GameObject(symbol) {
    this->value = value;
    //std::cout << "Gem Ctor" << std::endl;
}

//Custom Ctor
Gem::Gem(int x, int y) : GameObject(Constants::getGemSymbol(), x, y) {
    this->value = Constants::getGemPoints();
}

//Custom Ctor
Gem::Gem(char symbol, int value, int x, int y) : GameObject(symbol, x, y) {
    this->value = value;
    //std::cout << "Gem Ctor" << std::endl;
}

void Gem::print()  {
    cout << "A gem looking like " << this->getSymbol() << ", with value=" << this->value << " and position=(" << this->getPosition().getX() << ", " << this->getPosition().getY() << ")" << endl;
}

//Destructor
Gem::~Gem() {
    //std::cout << "Gem Dtor" << std::endl;
}
