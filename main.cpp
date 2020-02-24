#include "mazeInfo.hpp"
#include "nodeQueue.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void paint();
void loadFromFile();


int main()
{
	//char temp[100];
	/*
	Maze maze1("doesn't do anything yet");


	//cout << "The number of path pixels: " << maze1.countPathPixels() << endl;
	cout << "\n\n\n" << endl;
	maze1.display();

	maze1.findExits();
	maze1.paint();
	*/

	
	Queue newQueue;
	while (true)
	{
		int num;
		QueueNode* tempnode;
		cout << "Enter a number and 0 to quit: ";
		cin >> num;
		cin.ignore(100, '\n');

		switch (num)
		{
			case 0:
				newQueue.display();
				return 0;

			case -1:
				//cout << "HU" << endl;
				tempnode = newQueue.dequeue();
				if (tempnode)
					cout << "DROPPED: " << tempnode -> data << endl;
				newQueue.display();
				delete tempnode;
				break;

			default:
				newQueue.enqueue(num);
				break;
		}
	}
	return 0;
}
