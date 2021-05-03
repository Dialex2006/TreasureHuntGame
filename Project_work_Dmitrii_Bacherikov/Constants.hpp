//
//  Constants.hpp
//  A04_2
//
//  Created by Dmitrii Bacherikov on 08.02.2021.
//

#ifndef Constants_hpp
#define Constants_hpp



class Constants {
    private:
        static const char SYMBOL_GEM;
        static const char SYMBOL_PLAYER;
        static const char SYMBOL_MONSTER;
        static const char SYMBOL_MAP_WALL;
        static const char SYMBOL_INSIDE_MAP_WALL;
        static const char SYMBOL_MAP_DOT;
        static const char SYMBOL_APPLE;
        static const char SYMBOL_DOOR;
        static const int WIDTH;
        static const int HEIGHT;
        static const int APPLE_ENERGY;
        static const int DEFEAT_MOSTER_POINTS;
        static const int GEM_POINTS;
        static const int MONSTER_STRENGTH_MIN;
        static const int MONSTER_STRENGTH_MAX;
        static const int MOVE_ENERGY_WASTE;
    public:
        //Definition of static member function
        static int getGemSymbol() {
            return SYMBOL_GEM;
        };
    
        static int getMonsterSymbol() {
            return SYMBOL_MONSTER;
        };
    
        static char getMapWall() {
            return SYMBOL_MAP_WALL;
        };
    
        static char getInsideMapWall() {
            return SYMBOL_INSIDE_MAP_WALL;
        };
    
        static char getMapDot() {
            return SYMBOL_MAP_DOT;
        };
    
        static char getAppleSymbol() {
            return SYMBOL_APPLE;
        };
    
        static char getWIDTH() {
            return WIDTH;
        };
    
        static char getHEIGHT() {
            return HEIGHT;
        };
    
        static char getMoveEnergyWaste() {
            return MOVE_ENERGY_WASTE;
        };
    
        static int getAppleEnergy() {
            return APPLE_ENERGY;
        };
    
        static char getPlayerSymbol() {
            return SYMBOL_PLAYER;
        };
    
        static char getMonsterStrengthMin() {
            return MONSTER_STRENGTH_MIN;
        };
    
        static char getMonsterStrengthMax() {
            return MONSTER_STRENGTH_MAX;
        };
    
        static int getMonsterPoints() {
            return DEFEAT_MOSTER_POINTS;
        };
    
        static char getGemPoints() {
            return GEM_POINTS;
        };
    
        static char getDoorSymbol() {
            return SYMBOL_DOOR;
        };
};


#endif /* Constants_hpp */
