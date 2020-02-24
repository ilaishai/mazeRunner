
#ifndef PIXEL
#define PIXEL
class Pixel
{
	public:
		Pixel();
		Pixel(int r, int g, int b);
		~Pixel();
		void display() const;
		void setColor(int r, int g, int b);
		void setToGreen();
		void setToRed();
		bool isWhite() const;
		int* getPixel() const;
	
	protected:
		int red;
		int green;
		int blue;
		bool visited;
};

#endif

#ifndef MAZE
#define MAZE
class Maze
{
	public:
		Maze(int x, int y);
		Maze(const char* imagePath);
		~Maze();
		
		//visual functions
		bool loadFromFile();
		void paint();
		void display() const;
		
		bool findExits();
		int countPathPixels();

	protected:
		int x;
		int y;
		Pixel** pixelMatrix;

};
#endif
