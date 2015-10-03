#include "RolePlayingGame.h"

using namespace std;

RolePlayingGame::RolePlayingGame(unsigned int seed, unsigned int nrMon, unsigned int nrKits, unsigned int nrPotions, unsigned int boost, unsigned int mhealth)
{
    //initialize the dungeon to be empty
    this->dungeon.readInMaze("mazeExample.txt");
          
    initializeCreatures();
    
    initializeHero(seed);
    
    initializeMonsters(seed, nrMon);
    
    initializeFirstAidKits(seed, nrKits, boost);  
 
    initializePotions(seed, nrPotions);
   
    this->maxHealth = mhealth;
}

RolePlayingGame::~RolePlayingGame()
{
    
}
    
bool RolePlayingGame::moveHero(const char direction)
{
    
}
    
void RolePlayingGame::printBoard()
{
    
}
    
bool RolePlayingGame::heroIsDead()
{
    
}
    
bool RolePlayingGame::allMonstersDead()
{
    
}
    
void RolePlayingGame::removeDeadMonsters()
{
    
}
    
unsigned int RolePlayingGame::getNrMonsters() const
{
    
}
    
void RolePlayingGame::setNrMonsters(unsigned int n)
{
    
}
    
unsigned int RolePlayingGame::getNrFirstAidKits() const
{
    
}
    
void RolePlayingGame::setNrFirstAidKits(unsigned int f)
{
    
}
    
unsigned int RolePlayingGame::getNrPotions() const
{
    
}

void RolePlayingGame::setNrPotions(unsigned int p)
{
    
}

void RolePlayingGame::initializeCreatures()
{
    
}

void RolePlayingGame::initializeMonsters(unsigned int seed, unsigned int numMon)
{
    
}
    
void RolePlayingGame::initializeFirstAidKits(unsigned int seed, unsigned int numKits, unsigned int boost)
{
    
}
    
void RolePlayingGame::initializePotions(unsigned int seed, unsigned int numPotions)
{
    
}
    
void RolePlayingGame::initializeHero(unsigned int seed)
{
    
}
        
vector<int> RolePlayingGame::locateCreature(Creature* creature)
{
    
}