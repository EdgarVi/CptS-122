#pragma once
#include <iostream>

template <class T> class List;

template <class T>
class ListNode
{
	friend class List<T>;
public:
	ListNode(T newdata);
	ListNode(const ListNode<T> &copy);
	T getData() const;

private:
	T data;
	ListNode<T> *pNext;
};

template <class T>
class List
{
public:
	List();
	~List();
	void insertAtFront(T data);
	void insertAtEnd(T data);
	T RemoveFromFront();
	T RemoveFromEnd();
	bool isEmpty();
	void print();

private:
	ListNode<T> *Front;
	ListNode<T> *End;
};

template <class T>
ListNode<T>::ListNode(T newdata)
{
	this->data = newdata;
	this->pNext = nullptr;
}

template <class T>
ListNode<T>::ListNode(const ListNode<T> &copy)
{
	this->data = copy.data;
	this->pNext = nullptr;
}

template <class T>
T ListNode<T>::getData() const
{
	return data;
}


template <class T>
List<T>::List()
{
	Front = End = nullptr;
}

template <class T>
bool List<T>::isEmpty()
{
	return (!Front);
}

// Assuming that T has overloaded stream extraction operator
template <class T>
void List<T>::print()
{
	ListNode<T> *temp = Front;
	while (temp)
	{
		std::cout << temp->data << std::endl;
		temp = temp->pNext;
	}
}

template <class T>
T List<T>::RemoveFromEnd()
{
	ListNode<T> *temp = Front;
	while (temp && temp->pNext && temp->pNext != End)
	{
		temp = temp->pNext;
	}
	if (!temp) return 0;
	T retval = End->data;
	if (Front == End)
	{
		delete End;
		Front = End = nullptr;
		return retval;
	}
	delete End;
	End = temp;
	End->pNext = nullptr;
	return retval;
}

template <class T>
T List<T>::RemoveFromFront()
{
	ListNode<T> *temp;
	T retval;
	if (Front)
		temp = Front->pNext;
	else
		return 0;
	retval = Front->data;
	if (Front == End)
	{
		delete Front;
		Front = End = nullptr;
	}
	else
	{
		delete Front;
		Front = temp;
	}

	return retval;
}

template <class T>
void List<T>::insertAtEnd(T data)
{
	ListNode<T> *pmem = new ListNode<T>(data);
	if (!End)
	{
		Front = End = pmem;
		return;
	}
	End->pNext = pmem;
	End = pmem;
}


template <class T>
void List<T>::insertAtFront(T data)
{
	ListNode<T> *pmem = new ListNode<T>(data);
	if (!Front)
	{
		Front = End = pmem;
		return;
	}
	pmem->pNext = Front;
	Front = pmem;
}


template <class T>
List<T>::~List()
{
	ListNode<T> *temp, *next;
	temp = Front;
	while (temp)
	{
		next = temp->pNext;
		delete temp;
		temp = next;
	}
}