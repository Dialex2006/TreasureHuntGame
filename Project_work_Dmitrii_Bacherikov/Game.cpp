//
//  Game.cpp
//  Project_work_Dmitrii_Bacherikov
//
//  Created by Dmitrii Bacherikov on 02.04.2021.
//

#include "Game.hpp"
#include "Constants.hpp"
#include <cstdlib>



using namespace std;


//main game loop
void Game::gameLoop() {
    
    string input;  // for player's input
    
    do {
        
        //moving to the next level
        newLevel();
    
        //printing out current game info (Level, Energy, Points) before move
        printMoveInfo();
        
        //print the map
        this->map->print();
        
        cout << "Please enter movement (wasd) or q to escape > ";
        getline(cin, input);  //capturing player's input
        
        //processing the input. If it's legal then we change its position
        if (processInput(input) == 1 && input.length() == 1) {
            moveProcessing(input[0]);
        } //otherwise asking the User to enter again
        else cout << "Invalid input: " << "\"" << input << "\". Try again." << endl;
        
    }
    while (!(input =="q" || endOfGame)) ; //until we want to quit or out of energy
    
    for (int i=0; i<Monst_arr.size(); i++) {
        delete Monst_arr[i];
    }
    for (int i=0; i<Apple_arr.size(); i++) {
        delete Apple_arr[i];
    }
    for (int i=0; i<Gem_arr.size(); i++) {
        delete Gem_arr[i];
    }
    delete this->map;
    
    this->log.addLog("Sadly you lost :-/ The game is over.", true);
    //cout << "Sadly you lost :-/ The game is over." << endl;
    this->log.addLog("You reached level " + to_string(levelNumber) + " and got " + to_string(player.getPoints()) + " points.", true);
    
    //printing log
    cout << "\nLogs:" << endl;
    log.printAll();
    log.saveLogs();

};



//checking if input is valid or not
int Game::processInput (string line) {
    switch (line[0]) {
        default:
            //This means invalid input
            return 0;
        case 'a':
        case 's':
        case 'd':
        case 'w':
        case 'q':
            return 1;  //This is correct input
    }
};


void Game::newLevel() {
    int rand1=0, rand2=0;
    
    if (levelUP) {
        for (int i=0; i<levelNumber; i++) {
            delete Monst_arr[i];
        }
        Monst_arr.clear();
        
        for (int i=0; i<levelNumber; i++) {
            delete Apple_arr[i];
        }
        Apple_arr.clear();
        
        if (gemPlaced) {  //probably can remove this condition - Gem is created every time
            for (int i=0; i<numOfGems; i++) {
                delete Gem_arr[i];
            }
            Gem_arr.clear();
        }
        
        delete this->map;
        
        numOfGems = 0;
        levelNumber++;
        this->map = new Map(Constants::getWIDTH()+levelNumber, Constants::getHEIGHT()+levelNumber);
        this->log.addLog("Congratulations! Now you are on the level No."+to_string(levelNumber), 1);
        levelUP = false;
        playerOnMap = false;
        monstersOnMap = false;
        applesOnMap = false;
        gemPlaced = false;
    }
    
    //placing the Player
    while (!playerOnMap) {
        srand ((unsigned)time(NULL));
        rand1 = rand() % (Constants::getHEIGHT()+levelNumber-2) + 1; // rows-1
        rand2 = rand() % (Constants::getWIDTH()+levelNumber-2) + 1; // columns-1
        
        if (this->map->getElementAt(rand1, rand2) == Constants::getMapDot() && !(locked(rand1, rand2))) {
            playerOnMap = true;
            this->player.setPosition(rand1, rand2);
            this->map->setElementAt(rand1, rand2, Constants::getPlayerSymbol());
        }
    }
    
    
    //placing Monsters - running every new level
    if (!monstersOnMap) {
        for (int i=0; i<levelNumber; i++) {
            MonsterPlaced = false;
            while (!MonsterPlaced) {
                rand1 = rand() % (Constants::getHEIGHT()+levelNumber-2) + 1; // rows-1
                rand2 = rand() % (Constants::getWIDTH()+levelNumber-2) + 1; // columns-1
                
                if (this->map->getElementAt(rand1, rand2) == Constants::getMapDot()) {
                    
                    int rand_strength = rand() % (Constants::getMonsterStrengthMax()-Constants::getMonsterStrengthMin()+1) + Constants::getMonsterStrengthMin(); // random strength from Min to Max values
                    Monst_arr.push_back(new Monster(Constants::getMonsterSymbol(), rand_strength, rand1, rand2));
                    //(Constants::getMonsterSymbol(), 10, rand1, rand2);     //  .setPosition(rand1, rand2);
                    MonsterPlaced = true;
                    this->map->setElementAt(rand1, rand2, Constants::getMonsterSymbol());
                }
            }
        }
        
        monstersOnMap = true;
    }
    
    
    //placing Apples - running every new level
    if (!applesOnMap) {
        for (int i=0; i<levelNumber; i++) {
            applesPlaced = false;
            while (!applesPlaced) {
                rand1 = rand() % (Constants::getHEIGHT()+levelNumber-2) + 1; // rows-1
                rand2 = rand() % (Constants::getWIDTH()+levelNumber-2) + 1; // columns-1
                
                if (this->map->getElementAt(rand1, rand2) == Constants::getMapDot()) {
                    Apple_arr.push_back(new MagicApple(Constants::getAppleEnergy(), rand1, rand2));
                    applesPlaced = true;
                    this->map->setElementAt(rand1, rand2, Constants::getAppleSymbol());
                }
            }
        }
        applesOnMap = true;
    }
    
};


bool Game::locked(int x, int y) {
    if (this->map->getElementAt(x-1, y) == Constants::getMapDot() || this->map->getElementAt(x, y-1) == Constants::getMapDot() || this->map->getElementAt(x+1, y) == Constants::getMapDot() || this->map->getElementAt(x, y+1) == Constants::getMapDot() )
    return false;
    else return true;
};



//changing Player's position in each direction
void Game::moveProcessing(char direction) {
    switch (direction) {
        case 'a':
            //checking if there is a wall. If not then change player's position (same for each direction)
            if (!this->map->isWall(player.getPosition().getX()-1, player.getPosition().getY())) {
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), Constants::getMapDot());
                this->player.changePosition(-1, 0);
                removeEnergy(Constants::getMoveEnergyWaste());
                this->log.addLog("Moving left. Energy left: " + to_string(player.getEnergy()), true);
                if (player.getEnergy() >0) this->interaction();
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), 'P');
            } else
                cout << "Wall on the way!" << endl;
            break;
        case 's':
            if (!this->map->isWall(player.getPosition().getX(), player.getPosition().getY()+1)) {
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), Constants::getMapDot());
                this->player.changePosition(0, 1);
                removeEnergy(Constants::getMoveEnergyWaste());
                this->log.addLog("Moving down. Energy left: " + to_string(player.getEnergy()), true);
                if (player.getEnergy() >0) this->interaction();
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), 'P');
            } else
                cout << "Wall on the way!" << endl;
            break;
        case 'd':
            if (!this->map->isWall(player.getPosition().getX()+1, player.getPosition().getY())) {
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), Constants::getMapDot());
                this->player.changePosition(1, 0);
                removeEnergy(Constants::getMoveEnergyWaste());
                this->log.addLog("Moving right. Energy left: " + to_string(player.getEnergy()), true);
                
                if (player.getEnergy() >0) this->interaction();
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), 'P');
            } else
                cout << "Wall on the way!" << endl;
            break;
        case 'w':
            if (!this->map->isWall(player.getPosition().getX(), player.getPosition().getY()-1)) {
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), Constants::getMapDot());
                this->player.changePosition(0, -1);
                removeEnergy(Constants::getMoveEnergyWaste());
                this->log.addLog("Moving up. Energy left: " + to_string(player.getEnergy()), true);
                
                if (player.getEnergy() >0) this->interaction();
                this->map->setElementAt(player.getPosition().getX(), player.getPosition().getY(), 'P');
                
            } else
                cout << "Wall on the way!" << endl;
            break;
    }
};


void Game::interaction () {
    
    //if the Player finds a Gem
    if (this->map->getElementAt(player.getPosition().getX(), player.getPosition().getY()) == Constants::getGemSymbol()) {
        
        //for all Gems on the map
        for (int i=0; i<numOfGems; i++) {
            if (player.getPosition() == Gem_arr.at(i)->getPosition()) {
                Gem_arr.at(i)->setPosition(0, 0); //removing the Gem from the Map
                openSecretDoor();
                this->player.setEnergy(this->player.getEnergy()+10);
                player.addPoints(Constants::getGemPoints());
                this->log.addLog("You opened the Secret Door, received 30 points and restored 10% of Energy!", true);
                
            }
        }
    } //if the Player meets the Secret Door
    else if (this->map->getElementAt(player.getPosition().getX(), player.getPosition().getY()) == Constants::getDoorSymbol()) {

                levelUP=true;
                this->player.setEnergy(this->player.getEnergy()+20);
                this->log.addLog("You entered the Secret Door to the next Level and restored 20% Energy!", true);
                
    }
    //if the Player meets a Monster
    else if (this->map->getElementAt(player.getPosition().getX(), player.getPosition().getY()) == Constants::getMonsterSymbol()) {
        
        for (int i=0; i< this->levelNumber; i++) {
            //if the Player meets a Monster
            if (this->player.getPosition() == this->Monst_arr.at(i)->getPosition()) {
                this->Monst_arr.at(i)->setPosition(0, 0);  //removing the Monster from the Map
                    if (this->player.getEnergy() == 0)  //if out of energy after the move
                        this->log.addLog("You don't have energy to fight with Monster!", true);
                    else {
                        removeEnergy(this->Monst_arr.at(i)->getStrength());
                        if (player.getEnergy() == 0) {
                            this->log.addLog("You met a Monster and LOST!", true);
                        }
                        else
                            player.addPoints(Constants::getMonsterPoints());
                            this->log.addLog("You met a Monster (" + to_string(this->Monst_arr.at(i)->getStrength()) + ") and WON! You earned " + to_string (Constants::getMonsterPoints()) + " points and can see location of Gem.", true);
                            placeGem();
                            cout << "Energy left: " << this->player.getEnergy() << endl << endl;
                    }
            }
        }
        
    }
    else if (this->map->getElementAt(player.getPosition().getX(), player.getPosition().getY()) == Constants::getAppleSymbol()) {
        
        for (int i=0; i< this->levelNumber; i++) {

            //if the Player find an Apple
            if (this->player.getPosition() == this->Apple_arr.at(i)->getPosition()) {
                
                this->Apple_arr.at(i)->setPosition(0,0); //removing the Apple from the Map
                if (this->player.getEnergy() == 0)  //if out of energy after the move
                    this->log.addLog("You don't have energy to reach the apple!", true);
                   
                else {
                    //cout << "Energy: " << this->player.getEnergy() << endl << endl;
                    removeEnergy(-this->Apple_arr.at(i)->getEnergy());
                    this->log.addLog("You ate an Apple and restored the energy by " + to_string(Constants::getAppleEnergy()) + "%!", true);
                    cout << "Energy left: " << this->player.getEnergy() << endl << endl;
                }
            }
        }
    }
        

    
}



void Game::placeGem() {
    int random1, random2 = 0;
    bool gemPlacedlocal;
    //placing a Gem - after defeating a Monster
        if (!gemPlaced) {  //check this condition - maybe remove it????
        }
            gemPlacedlocal = false;
            while (!gemPlacedlocal) {
                random1 = rand() % (Constants::getHEIGHT()+levelNumber-2) + 1; // rows-1
                random2 = rand() % (Constants::getWIDTH()+levelNumber-2) + 1; // columns-1
                
                if (this->map->getElementAt(random1, random2) == Constants::getMapDot()) {
                    Gem_arr.push_back(new Gem(random1, random2));
                    this->numOfGems++;
                    gemPlacedlocal = true;
                    gemPlaced = true;
                    this->map->setElementAt(random1, random2, Constants::getGemSymbol());

                }
            }
}



void Game::openSecretDoor() {
    int random1, random2 = 0;
    bool doorPlaced = false;
    
    while (!doorPlaced) {
        random1 = rand() % (Constants::getHEIGHT()+levelNumber-2) + 1; // rows-1
        random2 = rand() % (Constants::getWIDTH()+levelNumber-2) + 1; // columns-1
        
        if (this->map->getElementAt(random1, random2) == Constants::getMapDot()) {
            doorPlaced = true;
            this->map->setElementAt(random1, random2, Constants::getDoorSymbol());

        }
    }
    
    
}






void Game::removeEnergy(int removeQuantity) {
    if (this->player.getEnergy() < removeQuantity+1)  //if amount of coins is less than to be removed
    {
        player.setEnergy(0);
        endOfGame = true;
    }
    else{
        this->player.setEnergy(this->player.getEnergy()-removeQuantity);
    }
}


void Game::printMoveInfo() {
    cout << "Level: " << levelNumber << "; Player energy: " << player.getEnergy() << "; Points: " << player.getPoints() << endl;
}
