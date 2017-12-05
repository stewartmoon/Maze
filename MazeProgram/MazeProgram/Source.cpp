#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

class Maze
{
public:
	void ReadFile();
	//Create 2 dimensional Array
	void Search();
	char MazeArray[35][35];
};


int main()
{
	//Declare variables
	double numbers;

	Maze Maze;

	//Read file and store into Array
	Maze.ReadFile();

	//Recursion Method
	Maze.Search();
	
	//Close inStream
	return 0;
}

void Maze::ReadFile()
{
	//Read from text 
	ifstream inStream;
	inStream.open("Maze.txt");

	//Store into Array 
	for (int i = 0; i <= 34; i++)
	{
		for (int j = 0; j <= 34; j++)
		{
			inStream >> MazeArray[j][i];
			cout << MazeArray[j][i];
		}
	}
	inStream.close();

}

void Maze:: Search()
{

	

}