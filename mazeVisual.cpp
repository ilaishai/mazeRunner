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
	ofstream image("picture.ppm");
	image << "P3" << endl;
	image << x << " " << y << endl;
	image << "255" << endl;

	for (int i = 0; i < y; ++i)
	{
		for (int k = 0; k < x; ++k)
		{
			int r = rand() % 255;
			int g = rand() % 255;
			int b = rand() % 255;
			//int r = i % 255;
			//int g = k % 255;
			//int b = (i * k) % 255;

			image << r << " " <<  g << " " << b << endl;
		}
	}
	system("feh -Z picture.bmp");
}



bool Maze::loadFromFile()
{
	char* temp = new char[100];
	char* magicNumber;
	int count = 0;
	int rgb[3];
	ifstream dataFile;
	dataFile.open("image2.ppm");


	dataFile >> temp;
	magicNumber = new char[strlen(temp) + 1];
	strcpy(magicNumber, temp);


	dataFile >> x;
	dataFile >> y;
	dataFile >> temp;

	cout << "magic: " << magicNumber << endl;
	cout << "x " << x << endl;
	cout << "y " << y << endl;

	pixelMatrix = new Pixel*[y];

	for (int i = 0; i < y; ++i)
		pixelMatrix[i] = new Pixel[x];

	while (!dataFile.eof() && dataFile)
	{
		temp[0] = '\0';

		dataFile >> rgb[count%3];

		if ((count + 1) %3 == 0)
		{
			cout << "\n" << (count/3)+1 << " | ";
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
	cout << "(" << red << ", " << green << ", " << blue << ")";
}


void Pixel::setColor(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}



void Pixel::setToGreen()
{
	green = 255;
}



void Pixel::setToRed()
{
	red = 255;
}


bool Pixel::isWhite() const
{
	if (red == 255 && green == 255 && blue == 255)
		return true;
	return false;
}
