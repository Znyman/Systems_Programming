#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

LinkedList::LinkedList()
{
	head = NULL;
}
void LinkedList::InsertAtHead(int v)
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

void LinkedList::PrintList()
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

void LinkedList::freeList()
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