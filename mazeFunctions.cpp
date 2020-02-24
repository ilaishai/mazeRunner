#include "mazeInfo.hpp"
#include "nodeQueue.hpp"
#include <iostream>

using namespace std;


int* Maze::findExits()
{
	int* locationsArray = new int[4];
	int count = 0;
	for (int i = 0; i < y; ++i)
	{
		if (count < 2)
		{
			if (pixelMatrix[i][0].isWhite())
			{
				//pixelMatrix[i][0].setToGreen();

				locationsArray[count*2] = 0;
				locationsArray[count*2 + 1] = i;

				cout << "FOUND ONE AT (1, " << i+1 << ")" << endl;

				++count;
			}
			if (pixelMatrix[i][x - 1].isWhite())
			{
				//pixelMatrix[i][x - 1].setToGreen();

				locationsArray[count*2] = x-1;
				locationsArray[count*2 + 1] = i;

				cout << "FOUND ONE AT (" << i+1 << ", " << x << ")" << endl;
				++count;
			}
		}
	}
	for (int i = 0; i < x; ++i)
	{
		if (count < 2)
		{
			if (pixelMatrix[0][i].isWhite())
			{
				//pixelMatrix[0][i].setToGreen();

				locationsArray[count*2] = i;
				locationsArray[count*2 + 1] = 0;

				cout << "FOUND ONE AT (" << i+1 << ", 1)" << endl;
				
				++count;
			}
			if (pixelMatrix[y - 1][i].isWhite())
			{
				//pixelMatrix[y - 1][i].setToGreen();

				locationsArray[count*2] = i;
				locationsArray[count*2 + 1] = y-1;

				cout << "FOUND ONE AT (" << i+1 << ", " << y << ")" << endl;

				++count;
			}
		}
	}
	return locationsArray;
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


bool Maze::BFS(int startX, int startY, int destX, int destY)
{
	Queue traversalQueue;

	if (startX == destX && startY == destY)
		return true;

	while (traversalQueue.hasItems())
	{
		Pixel North = pixelMatrix[startY - 1][startX];
		Pixel South = pixelMatrix[startY + 1][startX];
		Pixel East = pixelMatrix[startY][startX + 1];
		Pixel West = pixelMatrix[startY][startX - 1];


		if (North.isValid())
			traversalQueue.enqueue(&North);
		if (South.isValid())
			traversalQueue.enqueue(&South);
		if (East.isValid())
			traversalQueue.enqueue(&East);
		if (West.isValid())
			traversalQueue.enqueue(&West);

		pixelMatrix[startY][startX].markVisited();
	}
	return false;
}


bool Maze::DFS(int startX, int startY, int destX, int destY)
{
	cout << "\nSTART: (" << startX << ", " << startY << ") ";
	cout << "END: (" << destX << ", " << destY << ") ";
	if (startX == destX && startY == destY)
	{
		pixelMatrix[startY][startX].setToGreen();
		return true;
	}

	bool locationSuccess = false;
	pixelMatrix[startY][startX].markVisited();

	if (startY != 0)
	{
		Pixel North = pixelMatrix[startY - 1][startX];
		if (North.isValid())
			locationSuccess = locationSuccess || DFS(startX, startY - 1, destX, destY);
	}
	if (startY != y-1)
	{
		Pixel South = pixelMatrix[startY + 1][startX];
		if (South.isValid() && !locationSuccess)
			locationSuccess = locationSuccess || DFS(startX, startY + 1, destX, destY);
	}
	if (startX != x-1)
	{
		Pixel East = pixelMatrix[startY][startX + 1];
		if (East.isValid() && !locationSuccess)
			locationSuccess = locationSuccess || DFS(startX + 1, startY, destX, destY);
	}

	if (startX != 0)
	{
		Pixel West = pixelMatrix[startY][startX - 1];
		if (West.isValid() && !locationSuccess)
			locationSuccess = locationSuccess || DFS(startX - 1, startY, destX, destY);
	}


	if (locationSuccess)
		pixelMatrix[startY][startX].setToGreen();


	return locationSuccess;
}
