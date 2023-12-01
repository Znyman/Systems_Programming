#pragma once
#ifndef LinkedList_h
#define LinkedList_h
#include <cassert>
#include <string>
#include <stdint.h>

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	bool isEmpty();
	void InsertAtHead(T v);
	T PeekHead();
	T RemoveHead();
	void Print();
private:
	struct Node
	{
	public:
		Node(T v = NULL, Node* n = NULL) :value(v), nextNode(n) {}
		void SetValue(T v)
		{
			value = v;
		}
		void SetNext(Node* n)
		{
			nextNode = n;
		}
		T GetValue() const
		{
			return value;
		}
		Node* GetNext() const
		{
			return nextNode;
		}
		void PrintNode()
		{
			std::cout << "(" << value << ")";
		}

	private:
		T value;
		Node* nextNode;
	};
	Node * head;
};

#endif /*LinkedList_h*/

using std::cout;
using std::endl;

template<typename T>
inline LinkedList<T>::LinkedList()
{
	head = NULL;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	Node * next;
	while (head != NULL)
	{
		next = head->GetNext();
		delete[] head;
		head = next;
	}
	head = NULL;
}

template<typename T>
inline bool LinkedList<T>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	return false;
}

template<typename T>
inline void LinkedList<T>::InsertAtHead(T v)
{
	Node * newNode = new Node(v);
	if (head == NULL)
	{
		newNode->SetNext(NULL);
		head = newNode;
		return;
	}
	newNode->SetNext(head);
	head = newNode;
}

template<typename T>
inline T LinkedList<T>::PeekHead()
{
	assert(head != NULL);
	return head->GetValue();
}

template<typename T>
inline T LinkedList<T>::RemoveHead()
{
	assert(head != NULL);
	T deletedValue = (*head).GetValue();
	Node* next = (*head).GetNext();
	delete head;
	head = next;
	return deletedValue;
}

template<typename T>
inline void LinkedList<T>::Print()
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	Node * temp = head;
	while (temp != NULL)
	{
		temp->PrintNode();
		temp = temp->GetNext();
	}
	cout << endl;
}