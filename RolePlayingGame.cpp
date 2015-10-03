#include <iostream>
#include "RolePlayingGame.h"
#include "RandomNumberGenerator.h"

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
    creatures = new Creature **[dungeon.getWorldRows()];
    for(int i = 0; i < dungeon.getWorldRows(); i++)
    {
        creatures[i] = new Creature *[dungeon.getWorldColumns()];
        for(int j = 0; j < dungeon.getWorldColumns(); j++)
        {
            creatures[i][j] = 0;
        }
    }
}

void RolePlayingGame::initializeMonsters(unsigned int seed, unsigned int numMon)
{
    do
    {
        try
        {
            if(numMon >= 11)
                throw "cake";
        }
        catch (...)
        {
            //sorry
            int temp = numMon;


                cout << endl << "Too many monsters requested. Maximum 10 allowed." << endl;
                cout << "How many monsters should be added:" << endl;
            do{
                cin >> temp;
                if (temp == numMon)
                {
                    cout <<  endl << "Enter an integer from 1 to 10. How many monsters should be added: " << endl;
                }
            } while(temp == numMon);
            numMon = temp;
        }

    } while(numMon >= 11);

    monsters = new Creature[numMon];
    nrMonsters = numMon;

    unsigned int row, col;

    for(int i = 0; i < numMon; i++)
    {
        RandomNumberGenerator ran(seed, this->dungeon.getWorldRows() - 2);
        RandomNumberGenerator ran2(seed, this->dungeon.getWorldColumns() - 2);

        do
        {
            row = ran.nextInt();
            col = ran2.nextInt();
        }
        while (dungeon.getMazeSquare(row, col) != ' ' && creatures[row][col] != 0);


        // The seg faults happen here
        creatures[row][col] = &monsters[i];

    }
}
    
void RolePlayingGame::initializeFirstAidKits(unsigned int seed, unsigned int numKits, unsigned int boost)
{
    
}
    
void RolePlayingGame::initializePotions(unsigned int seed, unsigned int numPotions)
{
    
}
    
void RolePlayingGame::initializeHero(unsigned int seed)
{
    unsigned int row, col;
    RandomNumberGenerator ran(seed, this->dungeon.getWorldRows() - 2);
    RandomNumberGenerator ran2(seed, this->dungeon.getWorldColumns() - 2);

    do
    {
        row = ran.nextInt();
        col = ran2.nextInt();
    }
    while(dungeon.getMazeSquare(row, col) != ' ' && creatures[row][col] != 0);
// Why we no use dungeon to store hero >_<
    creatures[row][col] = &hero;
}
        
vector<int> RolePlayingGame::locateCreature(Creature* creature)
{
    
}