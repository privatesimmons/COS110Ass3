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

}


Dungeon::Dungeon(string fileName)
{

}

Dungeon::~Dungeon()
{

}

char Dungeon::getMazeSquare(unsigned int row, unsigned int col) const
{
	try
	{
		if (row > worldRows || row < 0 || col > worldColumns || col < 0)
		{
			throw ("Invalid cell in dungeon.");
		}
	}
	catch (string message)
	{
		catcher(message);
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
	fstream mazeFile;

	try
	{
		mazeFile.open(fileName, ios::in);
		if (mazeFile.fail())
			throw("The file does not exist.");
	}
	catch (string message)
	{
		catcher(message);
	}

	mazeFile >> worldRows >> worldColumns;

	maze = new char *[worldRows];
	for (int i = 0; i < worldRows; i++)
	{
		maze[i] = new char[worldColumns + 1];
		mazeFile.getline(maze[i], worldColumns + 1);
	}


}