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
	
	protected:
		int red;
		int green;
		int blue;
};

class Maze
{
	public:
		Maze(int x, int y);
		Maze(const char* imagePath);
		~Maze();
		bool loadFromFile();
		void paint();
		void display() const;

	protected:
		int x;
		int y;
		Pixel** pixelMatrix;

};
