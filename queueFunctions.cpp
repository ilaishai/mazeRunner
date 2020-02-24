#include "nodeQueue.hpp"
#include <iostream>

using namespace std;

Queue::Queue()
{
	front = NULL;
	rear = NULL;
}


Queue::~Queue()
{
	if (front)
		front -> next = NULL;

	while (rear)
	{
		QueueNode* temp = rear -> next;
		rear -> data = 0;
		rear -> contents = NULL;
		delete rear;
		rear = temp;
	}
}

void Queue::enqueue(int toAdd)
{
	QueueNode* temp = new QueueNode;
	temp -> data = toAdd;
	temp -> contents = NULL;

	if (front)
	{
		front -> next = temp;
		temp -> next = rear;
		front = temp;
	}
	else
	{
		rear = temp;
		front = rear;
		front -> next = rear;
	}
}


QueueNode* Queue::dequeue()
{
	if (rear)
	{
		QueueNode* toReturn = new QueueNode();
		toReturn -> data = rear -> data;
		toReturn -> contents = rear -> contents;

		front -> next = rear -> next;

		rear -> data = 0;
		rear -> contents = NULL;
		delete rear;
		rear = front -> next;


		return toReturn;
	}
	return NULL;
}


void Queue::display()
{
	QueueNode* current = rear;
	if (current)
	{
		do
		{
			cout << "current: " << current -> data << endl;
			current = current -> next;
		} while (current != rear);
	}
}
