//
//  Position.cpp
//  A04_3
//
//  Created by Dmitrii Bacherikov on 08.02.2021.
//

#include "Position.hpp"

//==Constructors==
Position::Position() {
    this->x = 0;
    this->y = 0;
};

Position::Position(int x) {
    this->x = x;
    this->y = 0;
};

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
};
//==================

// '==' operator overload
bool Position::operator== (const Position& rhsObj) {
    if ((this->x == rhsObj.x) && (this->y == rhsObj.y))
        return true;
    else return false;
};

// '!=' operator overload
bool Position::operator!= (const Position& rhsObj) {
    if ((this->x != rhsObj.x) || (this->y != rhsObj.y))
        return true;
    else return false;
};

//Other class members
void Position::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
};

void Position::setX(int x) {
    this->x = x;
};

void Position::setY(int y) {
    this->y = y;
};

int Position::getX() {
    return this->x;
};

int Position::getY() {
    return this->y;
};

bool Position::equals(Position p) {
    if (this->x == p.x && this->y == p.y)
        return true;
    else return false;
};
