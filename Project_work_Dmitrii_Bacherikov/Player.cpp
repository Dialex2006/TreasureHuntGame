//
//  Player.cpp
//  A05_4
//
//  Created by Dmitrii Bacherikov on 15.02.2021.
//

#include "Player.hpp"
#include "Position.hpp"

Player::Player() {
//    this->position.setX(1);
//    this->position.setY(1);
    this->energy = 100;
    this->points = 0;
};

//Other Ctors
Player::Player(int x, int y, int energy, char symbol) : GameObject(symbol, x, y) {
    this->energy = energy;
};


void Player::changePosition(int x, int y) {
    this->setPosition(this->getPosition().getX()+x, this->getPosition().getY()+y);
};

void Player::setEnergy(int energy) {
    this->energy = energy;
    if (this->energy > 100) this->energy = 100;
};

Position Player::getPosition() {
    return this->position;
};

int Player::getEnergy() {
    return this->energy;
};

int Player::getPoints() {
    return this->points;
};


void Player::addPoints (int points) {
    this->points += points;
};
