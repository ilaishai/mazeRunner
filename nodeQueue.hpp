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
		void enqueue(int toAdd);
		QueueNode* dequeue();
		void display();
	protected:
		QueueNode* front;
		QueueNode* rear;
};
