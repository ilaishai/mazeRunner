
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
		bool notVisited() const;
		bool isValid() const;
		void markVisited();
	
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
		
		int* findExits();
		int countPathPixels();
		bool BFS(int startX, int startY, int destX, int destY);
		bool DFS(int startX, int startY, int destX, int destY);

	protected:
		int x;
		int y;
		Pixel** pixelMatrix;

};
#endif
