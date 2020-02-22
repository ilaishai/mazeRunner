#include "mazeInfo.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void paint();
void loadFromFile();


int main()
{
	//char temp[100];
	Maze maze1("doesn't do anything yet");


	//cout << "The number of path pixels: " << maze1.countPathPixels() << endl;
	cout << "\n\n\n" << endl;
	maze1.display();

	maze1.findExits();
	maze1.paint();
	
	return 0;
}

