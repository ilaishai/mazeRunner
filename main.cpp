#include "mazeInfo.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void paint();
void loadFromFile();


int main()
{
	char temp[100];
	Maze maze1("doesn't do anything yet");
	cout << "\n";
	cin >> temp;
	cin.ignore(100, '\n');
	cout << "\n\n\n";
	maze1.display();
	cout << "\n\n\n\n";
	//paint();
	//loadFromFile();
	return 0;
}





