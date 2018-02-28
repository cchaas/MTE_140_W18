#include "SequentialList.hpp"
#include <iostream>
using namespace std;
SequentialList::SequentialList(unsigned int cap)
{
	capacity_ = cap;
	size_ = 0;
	data_ = new DataType[cap];
	for (int i=0; i < cap; i++){
		*(data_+i) = 0;
	}
}

SequentialList::~SequentialList()
{
	delete[] data_;
	data_= NULL;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	if (size_ == 0)
		return true;
	return false;
}

bool SequentialList::full() const
{
	if (size_ == capacity_)
		return true;
	return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if (empty()) return 0;
	if (index < size_){
		return *(data_+index);
	}
	return *(data_+size_-1);
}

unsigned int SequentialList::search(DataType val) const
{
	for (int i=0; i< size_; i++){
		if (*(data_+i)==val)
			return i;
	}
	return size_;
}

void SequentialList::print() const
{
	for (int i=0; i< size_; i++){
		cout<<*(data_+i)<<" ";
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if (full()) return false;
	if (index > size_) return false;
	DataType temp1 = *(data_+index);
	*(data_+index) = val;
	for (int i=index; i<size_; i++){
			//Push the next value after inserting
			DataType temp2 = *(data_+i+1);
			*(data_+i+1) = temp1;
			temp1 = temp2;
	}
	size_++;
	return true;
}

bool SequentialList::insert_front(DataType val)
{
	if (!full()){
		DataType temp1 = *(data_);
		for (int i=0; i<size_; i++){
			DataType temp2 = *(data_+i+1);
			//set next value to be the previous value
			*(data_+i+1) = temp1;
			temp1 = temp2;
		}
		*data_ = val;
		size_++;

		return true;
	}
	return false;
}

bool SequentialList::insert_back(DataType val)
{
	if (!full()){
		//since the last value is pushed out we do not have to consider it
		*(data_+size_) = val;
		size_++;
		return true;
	}
	return false;
}

bool SequentialList::remove(unsigned int index)
{
	if (empty()) return false;
	if (index >= size_) return false;
	if (index < size_-1){
		for (int i=index; i< size_-1; i++){
			*(data_+i)=*(data_+i+1);
		}
	}
	*(data_+size_-1) = 0;
	size_--;
	return true;

}

bool SequentialList::remove_front()
{
	//check if the list is empty
	if (empty()) return false;

	for (int i=0; i< size_-1; i++){
		*(data_+i)=*(data_+i+1);
	}
	*(data_+size_-1) = 0;
	size_--;
	return true;
}

bool SequentialList::remove_back()
{
	if (empty()) return false;
	size_--;
	return true;
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if (index >= size_)
		return false;
	*(data_+index) = val;

	return true;
}

