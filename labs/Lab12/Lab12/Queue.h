#pragma once
#include "List.h"

template <class T>
class Queue : private List<T> 
{

public:
	//Queue();
	void enqueue(T newData);
	T dequeue();
	void printq();
};

template <class T>
void Queue<T>::enqueue(T newData) 
{
	this->insertAtFront(newData);
}

template <class T>
T Queue<T>::dequeue() 
{
	return this->RemoveFromEnd();
}

template <class T>
void Queue<T>::printq()
{

}