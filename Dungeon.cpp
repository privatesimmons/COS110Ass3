#include "Dungeon.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


Dungeon::Dungeon()
{
	worldRows = 0;
	worldColumns = 0;
	maze = 0;
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
		if (row > worldRows  || col > worldColumns )
		{
			throw ("rocks");
		}
	}
	catch (...)
	{
		cout << endl << "Invalid cell in dungeon." << " Exiting the game." << endl;
		exit(EXIT_FAILURE);
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
		mazeFile.open(fileName.c_str(), ios::in);
		if (!mazeFile)
			throw("stones");
	}
	catch (...)
	{
		cout << endl << "The file does not exist." << " Exiting the program." << endl;
		exit(EXIT_FAILURE);
	}

	mazeFile >> worldRows >> worldColumns;
	while(mazeFile.get() != '\n');
	maze = new char *[worldRows];
	for (unsigned int i = 0; i < worldRows; i++)
	{
		maze[i] = new char[worldColumns + 1];
		char temp = 0;
		unsigned int j = 0;
		while(true)
		{
			mazeFile.get(temp);
			if(temp == '\n')
				break;

			maze[i][j++] = temp;
		}
		while(j < worldColumns)
		{
			maze[i][j++] = ' ';
		}

	}


}