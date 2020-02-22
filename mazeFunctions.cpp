#include "mazeInfo.hpp"
#include <iostream>

using namespace std;

bool Maze::findExits()
{
	cout << "HERE" << endl;
	int count;
	for (int i = 0; i < y; ++i)
	{
		if (pixelMatrix[i][0].isWhite())
		{
			pixelMatrix[i][0].setToGreen();
			++count;
			cout << "FOUND ONE AT (1, " << i+1 << ")" << endl;
		}
		if (pixelMatrix[i][x - 1].isWhite())
		{
			pixelMatrix[i][x - 1].setToGreen();
			++count;
			cout << "FOUND ONE AT (" << i+1 << ", " << x << ")" << endl;
		}
	}
	for (int i = 0; i < x; ++i)
	{
		if (pixelMatrix[0][i].isWhite())
		{
			pixelMatrix[0][i].setToGreen();
			++count;
			cout << "FOUND ONE AT (" << i+1 << ", 1)" << endl;
		}
		if (pixelMatrix[y - 1][i].isWhite())
		{
			pixelMatrix[y - 1][i].setToGreen();
			++count;
			cout << "FOUND ONE AT (" << i+1 << ", " << y << ")" << endl;
		}
	}

	if (count == 2)
		return true;
	return false;
}


int Maze::countPathPixels()
{
	int count = 0;;
	for (int i = 0; i < y; ++i)
		for (int k = 0; k < x; ++k)
			if (pixelMatrix[i][k].isWhite())
				++count;
	return count;
}
