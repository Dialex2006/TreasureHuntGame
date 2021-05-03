//
//  GameObject.cpp
//  A06_1
//
//  Created by Dmitrii Bacherikov on 22.02.2021.
//

#include "GameObject.hpp"


GameObject::GameObject () {
    this->position.setX(0);
    this->position.setY(0);
    this->symbol = '#';
};

GameObject::GameObject(char symbol) {
    this->position.setX(0);
    this->position.setY(0);
    this->symbol = symbol;
};

GameObject::GameObject(char symbol, int x, int y) {
    this->position.setX(x);
    this->position.setY(y);
    this->symbol = symbol;
};


void GameObject::setSymbol (char symbol) {
    this->symbol = symbol;
};

char GameObject::getSymbol () {
    return this->symbol;
};

void GameObject::setPosition(int x, int y) {
    this->position.setPosition(x, y);
};


Position GameObject::getPosition () {
    return this->position;
};

//Destructor
GameObject::~GameObject() {
}
