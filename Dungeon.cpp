#include "Dungeon.h"
#include <iostream>
#include <fstream>


using namespace std;

void catcher(string message)
{
	cout << endl << message << " Exiting the program." << endl;
	terminate();
}

Dungeon::Dungeon()
{

}

Dungeon::Dungeon(unsigned int rows, unsigned int col)
{
	worldRows = rows;
	worldColumns = col;
	maze = new char *[worldRows];
	for(unsigned int i = 0; i < worldRows; i++)
		maze[i] = new char[worldColumns];
}


Dungeon::Dungeon(string fileName)
{
	readInMaze(fileName);
}

Dungeon::~Dungeon()
{
	for(unsigned int i = 0; i < worldRows; i++)
		delete [] maze[i];
	delete [] maze;
}

char Dungeon::getMazeSquare(unsigned int row, unsigned int col) const
{
	try
	{
		if (row > worldRows || row < 0 || col > worldColumns || col < 0)
		{
			throw ("rocks");
		}
	}
	catch (...)
	{
		catcher("Invalid cell in dungeon.");
	}

	return maze[row][col];
}

unsigned int Dungeon::getWorldRows() const
{
	return worldRows;
}

void Dungeon::setWorldRows(unsigned int r)
{
	worldRows = r;
}

unsigned int Dungeon::getWorldColumns() const
{
	return worldColumns;
}

void Dungeon::setWorldColumns(unsigned int c)
{
	worldColumns = c;
}

void Dungeon::readInMaze(string fileName)
{
	ifstream mazeFile;

	try
	{
		mazeFile.open("mazeExample.txt", ifstream::in);
		if (!mazeFile.good())
			throw("stones");
	}
	catch (...)
	{
		catcher("The file does not exist.");
	}

	mazeFile >> worldRows >> worldColumns;

	maze = new char *[worldRows];
	for (unsigned int i = 0; i < worldRows; i++)
	{
		maze[i] = new char[worldColumns];
		for(int j = 0; j < worldColumns; j++)
		{
			maze[i][j] = mazeFile.get();
		}
	}


}