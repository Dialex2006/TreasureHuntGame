//
//  Game.hpp
//  Project_work_Dmitrii_Bacherikov
//
//  Created by Dmitrii Bacherikov on 02.04.2021.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
using namespace std;

#include <stdio.h>
#include "Player.hpp"
#include "Map.hpp"
#include "Monster.hpp"
#include "MagicApple.hpp"
#include "Gem.hpp"
#include "Logger.hpp"
#include <sstream>


class Game {
private:
    int levelNumber;
    bool levelUP;
    Player player;
    Map* map;
    vector<Monster*> Monst_arr;
    vector<MagicApple*> Apple_arr;
    vector<Gem*> Gem_arr;
    int numOfGems;
    bool endOfGame;
    Logger log;
public:
    Game() {
        levelNumber=1;
        levelUP=false;
        this->map = new Map(Constants::getWIDTH()+levelNumber,Constants::getHEIGHT()+levelNumber);
        endOfGame = false;
        numOfGems = 0;
    }
    bool playerOnMap = false;
    bool monstersOnMap = false;
    bool MonsterPlaced = false;
    bool applesOnMap = false;
    bool applesPlaced = false;
    bool gemPlaced = false;
    
    
    
    void gameLoop();
    void newLevel();
    int processInput(string line);
    void moveProcessing(char direction);
    void interaction();
    void removeEnergy (int removeQuantity);
    void printMoveInfo();
    void placeGem();
    void openSecretDoor();
    bool locked(int, int);
};

#endif /* Game_hpp */
