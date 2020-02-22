#include "mazeInfo.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


Maze::Maze(const char* filepath)
{
	loadFromFile();
}



Maze::Maze(int x, int y)
{
	x = x;
	y = y;
	pixelMatrix = new Pixel*[y];
	for (int i = 0; i < y; ++i)
		pixelMatrix[i] = new Pixel[x];
}


Maze::~Maze()
{
	for (int i = 0; i < y; ++i)
		delete[] pixelMatrix[i];
	delete[] pixelMatrix;
}



void Maze::display() const
{
	for (int i = 0; i < y; ++i)
	{
		for (int k = 0; k < x; ++k)
		{
			if (pixelMatrix[i][k].isWhite())
				cout << "  ";
			else
				cout << "|#";
		}
		cout << "\n";
	}
}


void Maze::paint()
{
	ifstream tryname("produced.ppm");
	if (tryname)
		cout << "File exists" << endl;
	else
	{
		ofstream image("produced.ppm");
		image << "P3" << endl;
		image << x << " " << y << endl;
		image << "255" << endl;

		for (int i = 0; i < y; ++i)
		{
			for (int k = 0; k < x; ++k)
			{
				int* pixelData = pixelMatrix[i][k].getPixel();
				
				int r = pixelData[0];
				int g = pixelData[1];
				int b = pixelData[2];

				image << r << " " <<  g << " " << b << endl;

				delete[] pixelData;
			}
		}
		//system("feh -Z produced.ppm");
	}
}



bool Maze::loadFromFile()
{
	char* temp = new char[100];
	char* magicNumber;
	int count = 0;
	int rgb[3];
	ifstream dataFile;
	dataFile.open("image.ppm");


	dataFile >> temp;
	magicNumber = new char[strlen(temp) + 1];
	strcpy(magicNumber, temp);


	dataFile >> x;
	dataFile >> y;
	dataFile >> temp;

	/*
	cout << "magic: " << magicNumber << endl;
	cout << "x " << x << endl;
	cout << "y " << y << endl;
	*/


	pixelMatrix = new Pixel*[y];

	for (int i = 0; i < y; ++i)
		pixelMatrix[i] = new Pixel[x];

	while (!dataFile.eof() && dataFile)
	{
		temp[0] = '\0';

		dataFile >> rgb[count%3];

		if ((count + 1) %3 == 0)
		{
			//cout << "\n" << (count/3)+1 << " | ";
			pixelMatrix[(count/3)/x][(count/3)%x] = Pixel(rgb[0], rgb[1], rgb[2]);
			pixelMatrix[(count/3)/x][(count/3)%x].display();
		}
		++count;
	}

	dataFile.close();
	dataFile.clear();
	delete[] magicNumber;
	delete[] temp;

	return true;
}


Pixel::Pixel()
{
	red = 0;
	green = 0;
	blue = 0;
}



Pixel::Pixel(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}



Pixel::~Pixel()
{
	red = 0;
	green = 0;
	blue = 0;
}


void Pixel::display() const
{
	//cout << "(" << red << ", " << green << ", " << blue << ")";
}


void Pixel::setColor(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}



void Pixel::setToGreen()
{
	red = 0;
	green = 255;
	blue = 0;
}



void Pixel::setToRed()
{
	red = 255;
	green = 0;
	blue = 0;
}


bool Pixel::isWhite() const
{
	if (red == 255 && green == 255 && blue == 255)
		return true;
	return false;
}



int* Pixel::getPixel() const
{
	int* pixelData = new int[3];
	pixelData[0] = red;
	pixelData[1] = green;
	pixelData[2] = blue;

	return pixelData;
}
