#include "mazeInfo.hpp"

struct QueueNode
{
	Pixel* contents;
	QueueNode* next;
	int data;
};

class Queue
{
	public:
		Queue();
		~Queue();
		//void enqueue(int toAdd);	//for testing purposes
		void enqueue(Pixel* contents);
		QueueNode* dequeue();
		void display();
		bool hasItems() const;
	protected:
		QueueNode* front;
		QueueNode* rear;
};
