//
//  Position.hpp
//  A04_3
//
//  Created by Dmitrii Bacherikov on 08.02.2021.
//

#ifndef Position_hpp
#define Position_hpp



class Position {
    private:
        int x;
        int y;
    public:
        Position();
        Position(int);
        Position(int, int);
        bool operator== (const Position&);
        bool operator!= (const Position&);
        void setPosition(int, int);
        void setX(int);
        void setY(int);
        int getX();
        int getY();
        bool equals(Position);
};

#endif /* Position_hpp */
