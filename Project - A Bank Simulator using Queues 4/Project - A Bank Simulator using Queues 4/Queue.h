#pragma once
#include<iostream>

// implementation queue using an linkedlist 

class Node {
public:
	int value;
	Node* next;
};
class Queue {
	Node* front = NULL;
	Node* rear = NULL;
public:
	bool ISempty();
	void Add(int);
	int back_();
	int front_();
	void pop_front();
	int len();

};
inline bool Queue::ISempty()
{
	return front == NULL;
}
void Queue::Add(int num)
{
	Node* newnode = new Node();
	newnode->value = num;
	if (ISempty())
	{
		newnode->next = NULL;
		front = newnode;
		rear = front;

	}
	else
	{
		if (rear->next == NULL)
		{
			rear->next = newnode;
			rear = newnode;
		}
		else                                        /// the code never enter in else  iff program is crash  
		{
			while (rear->next != NULL)
			{
				rear = rear->next;
			}
		}

	}
}
inline int Queue::back_()
{
	return rear->value;
}
inline int Queue::front_()
{
	return front->value;
}
int Queue::len()
{
	int len = 1;
	if (ISempty()) {
		Node* temp = front;
		while (temp != rear)
		{
			len++;
		}

		return len;
	}
	else return 0;
}
void Queue::pop_front()
{

	Node* temp = front;
	front = front->next;
	delete temp;

}