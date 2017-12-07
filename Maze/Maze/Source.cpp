#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

class Maze
{
public:
	int height, width;
	void ReadFile();
	void Maze::PrintMaze(char** pointer, int height, int width);
	int Maze::MazeMove(char** pointer, int width, int height, int xLocation, int yLocation);
	int getXStart();
	int getYStart();
	//Create 2 dimensional Array
	char** MazeArray;
	char** point;
private:
	int yStart = 0;
	int xStart = 0;

};

int main()
{
	//Declare variables
	double numbers;
	int finish = 0, success = 0;

	Maze Maze;

	//Read file and store into Array
	Maze.ReadFile();
	Maze.PrintMaze(Maze.point,Maze.height,Maze.width);
	//cout << Maze.getXStart() << " " << Maze.getYStart();
	//Recursion Method
	success = Maze.MazeMove(Maze.point,Maze.width,Maze.height, Maze.getXStart(), Maze.getYStart());

	if (success == 1)
	{
		cout << "Congratulations, you have solved the Maze." << endl;
	}
	else
	{
		cout << "Unfortunatly, the maze has not been solved correctly!" << endl;
	}

	return 0;
}

int Maze::getXStart() {
	return xStart;
}

int Maze::getYStart() {
	return yStart;
}

void Maze::ReadFile()
{
	//Read from text 
	ifstream inStream;
	inStream.open("Maze.txt");
	string temp = "", temp2;
	getline(inStream, temp);

	height = stoi(temp);
	getline(inStream, temp);
	width = stoi(temp);

	getline(inStream, temp);
	xStart = stoi(temp);
	getline(inStream, temp);
	yStart = stoi(temp);

	MazeArray = new char*[height];

	for (int g = 0; g < height; ++g)
		MazeArray[g] = new char[width];

	//Store into Array 
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			inStream >> MazeArray[j][i];
		}
	}

	//Close inStream
	point = MazeArray;
	inStream.close();
}

void Maze::PrintMaze(char** pointer, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << pointer[j][i];
		}
		cout << endl;
	}


	//Prompt user so program can freeze on move
	cout << "Hit return to see next move\n";
	system("pause");
}

int Maze::MazeMove(char** pointer, int width, int height, int xLocation, int yLocation)
{
	int success = 0;

	PrintMaze(pointer, width, height);


	while (success == 0) //Execute while success =0
	{
		//Check above for a valid move
		if (pointer[xLocation + 1][yLocation] == 'O')
		{
			cout << "YOMIKE";

			if (pointer[xLocation + 1][yLocation] == 'O')
			{
				pointer[xLocation + 1][yLocation] == 'P';//Change 'O' to 'P'
				success = MazeMove(pointer, width, height,xLocation + 1, yLocation); //Move Down
			}
			else if (pointer[xLocation + 1][yLocation] == 'P')
			{
				pointer[xLocation + 1][yLocation] == 'P';//Change 'O' to 'P'
				success = MazeMove(pointer, width,height,xLocation + 1, yLocation); //Move Down
			}
			else
			{
				pointer[xLocation + 1][yLocation] == 'E';
				success = 1;
				break;
			}
		}

		/*else if (pointer[xLocation - 1][yLocation] == 'O')
		{
			pointer[xLocation - 1][yLocation] == 'P'; //Change 'O' to 'P'
			success = MazeMove(pointer, xLocation - 1, yLocation); //Move up
		}



		//Check square right for valid move
		else if (pointer[xLocation][yLocation + 1] == 'O')
		{
			pointer[xLocation][yLocation + 1] == 'P';//Change 'O' to 'P'
			success = MazeMove(pointer, xLocation, yLocation + 1); //Move Right
		}



		//Check square below for valid move

		//Check to the left for valid move
		else if (pointer[xLocation][yLocation - 1] == 'O')
		{
			pointer[xLocation][yLocation - 1] == 'P';//Change 'O' to 'P'
			success = MazeMove(pointer, xLocation, yLocation - 1); //Move to the left
		}
		else //If go no where
		{
			success = 0;
			return success;
		}*/

	} //end -while loop
	return success;
}