#include <iostream>
#include <limits.h>
#include "RolePlayingGame.h"
#include "RandomNumberGenerator.h"

#define NORMAL 1
#define CURE 2

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
	return nrMonsters;
}
    
void RolePlayingGame::setNrMonsters(unsigned int n)
{
    nrMonsters = n;
}
    
unsigned int RolePlayingGame::getNrFirstAidKits() const
{
	return nrFirstAidKits;
}
    
void RolePlayingGame::setNrFirstAidKits(unsigned int f)
{
    nrFirstAidKits = f;
}
    
unsigned int RolePlayingGame::getNrPotions() const
{
	return nrPotions;
}

void RolePlayingGame::setNrPotions(unsigned int p)
{
	nrPotions = p;
}

void RolePlayingGame::initializeCreatures()
{
    creatures = new Creature **[dungeon.getWorldRows()];
    for(unsigned int i = 0; i < dungeon.getWorldRows(); i++)
    {
        creatures[i] = new Creature *[dungeon.getWorldColumns()];
        for(unsigned int j = 0; j < dungeon.getWorldColumns(); j++)
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
	        unsigned int temp = numMon;


                cout << endl << "Too many monsters requested. Maximum 10 allowed." << endl;
                cout << "How many monsters should be added:" << endl;
            do{
                cin >> temp;
                if (!temp)
                {
                    cout <<  endl << "Enter an integer from 1 to 10. How many monsters should be added: " << endl;
	                cin.clear();
	                cin.ignore(INT_MAX, '\n');
                }
            } while(!temp);
            numMon = temp;
        }

    } while(numMon >= 11);

    monsters = new Creature[numMon];
    nrMonsters = numMon;

    unsigned int row, col;
	RandomNumberGenerator ran(seed, (this->dungeon.getWorldRows() - 2)*1000);
	RandomNumberGenerator ran2(seed, (this->dungeon.getWorldColumns() - 2) * 1000);

    for(unsigned int i = 0; i < numMon; i++)
    {

        do
        {
            row = ran.nextInt() / 1000;
            col = ran2.nextInt() / 1000;
        }
        while (dungeon.getMazeSquare(row, col) != ' ' || creatures[row][col] != 0);


        // The seg faults happen here
        creatures[row][col] = &monsters[i];

    }
}
    
void RolePlayingGame::initializeFirstAidKits(unsigned int seed, unsigned int numKits, unsigned int boost)
{

	do
	{
		try
		{
			if (numKits > (nrMonsters / 2))
				throw "cake";
		}
		catch (...)
		{
			//sorry
			unsigned int temp = numKits;


			cout << endl << "Too many first aid kits requested. Maximum " << nrMonsters / 2 << " is allowed." << endl;
			cout << "How many kits should be added:" << endl;
			do
			{
				cin >> temp;
				if (!temp)
				{
					cout << endl << "Enter an integer from 1 to " << nrMonsters / 2
					<< ". How many first aid kits should be added: " << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (!temp);
			numKits = temp;
		}

	} while (numKits > (nrMonsters / 2));

	firstAidKits = new Creature[numKits];
	nrFirstAidKits = numKits;

	unsigned int row, col;
	RandomNumberGenerator ran(seed, (this->dungeon.getWorldRows() - 2) * 1000);
	RandomNumberGenerator ran2(seed, (this->dungeon.getWorldColumns() - 2) * 1000);

	for (unsigned int i = 0; i < numKits; i++)
	{

		do
		{
			row = ran.nextInt() / 1000;
			col = ran2.nextInt() / 1000;
		}
		while (dungeon.getMazeSquare(row, col) != ' ' || creatures[row][col] != 0);

		creatures[row][col] = &firstAidKits[i];
	}
}
void RolePlayingGame::initializePotions(unsigned int seed, unsigned int numPotions)
{

	do
	{
		try
		{
			if (numPotions > (nrMonsters / 2))
				throw "cake";
		}
		catch (...)
		{
			//sorry
			unsigned int temp = numPotions;

			cout << endl << "Too many potions requested. Maximum " << nrMonsters / 2 << " is allowed." << endl;
			cout << "How many potions should be added:" << endl;
			do
			{
				cin >> temp;
				if (!temp)
				{
					cout << endl << "Enter an integer from 1 to " << nrMonsters / 2
					<< ". How many potions should be added: " << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (!temp);
			numPotions = temp;
		}

	} while (numPotions > (nrMonsters / 2));

	potions = new Creature[numPotions * 2];
	nrPotions = numPotions;

	unsigned int row, col;
	RandomNumberGenerator ran(seed, (this->dungeon.getWorldRows() - 2) * 1000);
	RandomNumberGenerator ran2(seed, (this->dungeon.getWorldColumns() - 2) * 1000);

	for (unsigned int i = 0; i < numPotions * 2; i++)
	{
		if(i % 2 == 0)
			potions[i].setHealth(NORMAL);
		else
			potions[i].setHealth(CURE);

		do
		{
			row = ran.nextInt() / 1000;
			col = ran2.nextInt() / 1000;
		}
		while (dungeon.getMazeSquare(row, col) != ' ' || creatures[row][col] != 0);

		creatures[row][col] = &potions[i];
	}
}
    
void RolePlayingGame::initializeHero(unsigned int seed)
{
    unsigned int row, col;
    RandomNumberGenerator ran(seed, (this->dungeon.getWorldRows() - 2)*1000);
    RandomNumberGenerator ran2(seed, (this->dungeon.getWorldColumns() - 2) * 1000);

    do
    {
        row = ran.nextInt() / 1000;
        col = ran2.nextInt() / 1000;
	    if(dungeon.getMazeSquare(row, col) == ' ' && creatures[row][col] == 0)
		    break;
    }
    while(true);
// Why we no use dungeon to store hero >_<
    creatures[row][col] = &hero;
}

//vector<int> RolePlayingGame::locateCreature(Creature* creature)
//{
//
//}