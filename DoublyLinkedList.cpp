#include "DoublyLinkedList.hpp"
#include <cstddef>
#include <iostream>

using namespace std;

//Node data constructor
DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	next = NULL;
	prev = NULL;
}

//default constructor
DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* last = head_;
	//if there is something in the list
	if (head_!= NULL) {
		while (last->next != NULL) {
			last = last->next;
			last->prev->next = NULL;
			delete last->prev;
			last->prev = NULL;
		}
		delete tail_;
	}
}

bool DoublyLinkedList::empty() const
{
	if (head_==NULL)
		return true;
	return false;
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

void DoublyLinkedList::print() const
{
	Node* toPrint = head_;

	while (toPrint->next != NULL)
	{
		cout << toPrint->value << endl;
		toPrint = toPrint->next;
	}
	cout << tail_->value << endl;
	return;
}

bool DoublyLinkedList::insert_front(DataType value)
{

	if (size_ >= CAPACITY-1)
	{
		cout << "the list is full" << endl;
		return false;
	}

	Node* theNode= new Node(value);
	theNode->next = head_;
	theNode->prev = NULL;
	head_ = theNode;
	if (size_ == 0)
		tail_ = theNode;
	size_++;
	return true;
}

bool DoublyLinkedList::remove_front()
{
	if (size_ == 0)
	{
		cout << "the list is empty" << endl;
		return false;
	}

	//if there is one node in the list
	if (tail_ == head_){
		delete tail_;
		tail_ = NULL;
		head_ = NULL;
		size_--;
		return true;
	}

	Node* tempNode = head_->next;
	delete head_;
	head_ = tempNode;
	size_--;
	if (size_ == 0)
		tail_ = NULL;
	return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
	if (size_ >= CAPACITY)
	{
		cout << "the list is full" << endl;
		return false;
	}

	Node* newNode = new Node(value);
	if (size_ == 0) {
		tail_ = newNode;
		head_ = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		size_++;
		return true;
	}

	if (tail_ == NULL)
		cout << "NULL";

	newNode->prev = tail_;
	tail_->next = newNode;
	tail_ = newNode;
	newNode->next = NULL;

	size_++;

	return true;
}

bool DoublyLinkedList::remove_back()
{
	if (size_ == 0)
	{
		cout << "the list is empty" << endl;
		return false;
	}

	//if there is one node in the list
	if (tail_ == head_){
		delete tail_;
		tail_ = NULL;
		head_ = NULL;
		size_--;
		return true;
	}

	Node* tempNode = tail_->prev;
	delete tail_;
	tail_ = tempNode;
	tail_->next = NULL;
	tail_->prev = tempNode->prev;
	size_--;
	if (size_ == 0)
			head_ = NULL;
	return true;

}

//first node at index 0
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if (size_ >= CAPACITY || index > size_)
	{
		cout << "the list is full" << endl;
		return false;
	}

	Node* newNode = new Node(value);
	Node* trackNode = head_;

	if (index == 0)
		return insert_front(value);
	if (index == size_)
		return insert_back(value);

	for (unsigned int i=0;i<index;i++)
		trackNode = trackNode->next;

	newNode->next = trackNode->next;
	trackNode->next->prev = newNode;
	trackNode->next = newNode;
	newNode->prev = trackNode;

	size_++;

	return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if (size_ == 0 || index > size_-1)
		{
			cout << "error removing node at: " << index << endl;
			return false;
		}

	else if (index == size_-1)
		return remove_back();


	else if (index == 0)
		return remove_front();

	Node *trackNode = head_;
	for (unsigned int i=0;i<index;i++)
		trackNode = trackNode->next;

	trackNode->prev->next = trackNode->next;
	trackNode->next->prev = trackNode->prev;
	delete trackNode;

	return true;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	Node *trackNode = head_;
	for (unsigned int i=0;i<size_;i++) {
		if (trackNode->value == value)
			return i;
		trackNode = trackNode->next;
	}
	return size_;

}

//gets node at an index
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* wanted = head_;
	for (unsigned int i=0;i<index;i++)
		wanted = wanted->next;

	return wanted;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if (head_== NULL)
	{
		cout << "The list is empty." << endl;
		return getNode(size_)->value;
	}

	if (index >= size_) {
		cout << "could not successfully select the value at index" << index << endl;
		return getNode(size_)->value;

	}
	return getNode(index)->value;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if (index >= size_){
		cout << "could not successfully change index " << index << "to " << value << endl;
		return false;
	}

	getNode(index)->value = value;
	return true;

}

bool DoublyLinkedList::full() const
{
	if (size_ == CAPACITY)
		return true;
	return false;
}

