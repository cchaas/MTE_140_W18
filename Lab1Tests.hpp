#ifndef LAB1_TESTS_HPP
#define LAB1_TESTS_HPP

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

#include "DoublyLinkedList.hpp"
#include "SequentialList.hpp"

class SequentialListTest
{
public:
    bool test1() //size(), capacity(), empty(), full()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);

        ASSERT_TRUE(list.size() == 0)
        ASSERT_TRUE(list.capacity() == capacity)
        ASSERT_TRUE(list.empty() == true)
        ASSERT_TRUE(list.full() == false)
        return true;
    }

    bool test2() //insert_front(), insert_back()
    {
        unsigned int capacity = 5;
        SequentialList list1(capacity);
        SequentialList list2(capacity);
        ASSERT_TRUE(list1.insert_front(100))
        ASSERT_TRUE(list2.insert_back(100))

        ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
        ASSERT_TRUE(list1.data_ != NULL)
        ASSERT_TRUE(list2.data_ != NULL)
        ASSERT_TRUE(list1.data_[0] == list2.data_[0] && list1.data_[0] == 100)
        return true;
    }

    bool test3() //remove_front(), remove_back(), search(), select()
    {
        unsigned int capacity = 5;
        SequentialList list(capacity);

        ASSERT_TRUE(list.insert_front(100))
        ASSERT_TRUE(list.insert_front(101))
        ASSERT_TRUE(list.remove_front())
        ASSERT_TRUE(list.remove_back())
        ASSERT_TRUE(list.search(100) == list.size_)


        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.insert_back(i*100))
        }

        unsigned int idx = 3;
        ASSERT_TRUE(list.search(list.select(idx)) == idx)
        ASSERT_TRUE(list.select(capacity + 1) == list.select(capacity))
        ASSERT_TRUE(list.search(1000) == list.size())

        for (unsigned int i = 0; i < capacity; i++) {
            ASSERT_TRUE(list.select(i) == i*100 && list.data_[i] == i*100)
        }
        return true;
    }

    bool test4() //print(), insert()
    {
    	unsigned int capacity = 10;
    	SequentialList list(capacity);

    	for (unsigned int i = 0; i < 5; i++) {
    		ASSERT_TRUE(list.insert_back(i*100))
    	}

    	for (unsigned int i = 0; i < 4; i++) {
    		ASSERT_TRUE(list.insert(i,3));
    	}

    	ASSERT_TRUE(list.size() == 9);

    	cout << endl;

    	list.print();

    	cout << endl;

    	return true;
    }

    bool test5() // select()
    {
    	unsigned int capacity = 10;
    		SequentialList list(capacity);

    	for (unsigned int i = 0; i < capacity; i++) {
    	    ASSERT_TRUE(list.insert_back(i*100))
    	}

    	for (unsigned int i = 0; i < capacity; i++) {
    		ASSERT_TRUE(list.search(i*100) == i && list.select(i) == i*100)
    	}

    	return true;

    }

    bool test6() // replace()
    {
    	unsigned int capacity = 10;
    	SequentialList list(capacity);

        for (int i = 0; i < capacity; i++) {
        	ASSERT_TRUE(list.insert(i,i))
        	ASSERT_TRUE(list.replace(i,i+1))
        	ASSERT_TRUE(list.select(i) == i+1);
        }

        ASSERT_TRUE(!list.replace(10,1));
        ASSERT_TRUE(list.search(12)==list.size())

        return true;
    }

    bool test7() //tests upper limit of list capacity
        {
        	unsigned int capacity = 10;
        	SequentialList list(capacity);

            for (int i = 0; i <= capacity; i++) {
            	if (i == (capacity)) {
            		ASSERT_TRUE(!list.insert(i,i))
            	}
            	else {
            		ASSERT_TRUE(list.insert(i,i))
            	    ASSERT_TRUE(list.select(i) == i);
            	}
            }

            ASSERT_TRUE(!list.replace(10,1));
            ASSERT_TRUE(list.search(12)==list.size())

            return true;
        }

};

class DoublyLinkedListTest
{
public:
    bool test1() //size(), empty(), full()
    {
        DoublyLinkedList list;
        ASSERT_TRUE(list.size() == 0)
        ASSERT_TRUE(list.empty() == true)
        ASSERT_TRUE(list.full() == false)
        ASSERT_TRUE(list.head_ == NULL)
        ASSERT_TRUE(list.tail_ == NULL)
        return true;
    }

    bool test2() //insert_front(), insert_back()
    {
        DoublyLinkedList list1, list2;
        list1.insert_front(100);
        list2.insert_back(100);

        ASSERT_TRUE(list1.size() == list2.size() && list1.size() == 1)
        ASSERT_TRUE(list1.head_ != NULL && list1.head_ == list1.tail_)
        ASSERT_TRUE(list2.head_ != NULL && list2.head_ == list2.tail_)
        ASSERT_TRUE(list1.head_->prev == NULL && list1.tail_->next == NULL)
        ASSERT_TRUE(list2.head_->prev == NULL && list2.tail_->next == NULL)
        ASSERT_TRUE(list1.head_->value == list2.head_->value && list1.head_->value == 100)
        return true;
    }

    bool test3() //remove_front(), remove_back(), search(), select()
    {
        DoublyLinkedList list;

        ASSERT_TRUE(list.insert_front(100))
        ASSERT_TRUE(list.insert_front(101))

        ASSERT_TRUE(list.remove_front())
        ASSERT_TRUE(list.remove_back())
		ASSERT_TRUE(list.size()==0) //added
        ASSERT_TRUE(list.search(100) == list.size_)
        ASSERT_TRUE(list.head_ == NULL && list.tail_ == NULL)

        // List is [0, 100, ..., 400]
        const int num_elems = 5;
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.insert_back(i*100))
        }

        ASSERT_TRUE(list.search(300)==3); //added

        unsigned int idx = 3;
        ASSERT_TRUE(list.search(list.select(idx)) == idx)
        ASSERT_TRUE(list.search(1000) == list.size_)


        // Check that the list has the right values
        for (int i = 0; i < num_elems; i++) {
            ASSERT_TRUE(list.select(i) == i*100)
        }

        ASSERT_TRUE(list.head_->prev == NULL && list.tail_->next == NULL)

        return true;
    }

    bool test4() // insert(), remove()
    {
    	DoublyLinkedList list;

    	cout << list.size() << endl;

    	const int num_elems = 5;
        for (int i = 0; i < num_elems; i++) {
        	ASSERT_TRUE(list.insert(i*100,i))
        	ASSERT_TRUE(list.select(i) == i*100);
        }
        list.remove(0);
        list.remove(list.size()-1);
		list.remove(list.size()); //should be an error since size 3, nodes 0,1,2

        return true;
    }

    bool test5() //tests upper bound of list capacity
    {
    	DoublyLinkedList list;

    	const int num_elems = 65537;
        for (int i = 0; i < num_elems; i++) {
        	if (i == (num_elems-1)) {
        		ASSERT_TRUE(!list.insert(i,i))
        	}
        	else {
        		ASSERT_TRUE(list.insert(i,i))
        		ASSERT_TRUE(list.select(i) == i);
        	}
        }

        ASSERT_TRUE(list.search(543)==543)
        ASSERT_TRUE(list.full())

        return true;
    }

    bool test6() //replace()
    {
    	DoublyLinkedList list;

    	const int num_elems = 10;
        for (int i = 0; i < num_elems; i++) {
        	ASSERT_TRUE(list.insert(i,i))
        	ASSERT_TRUE(list.replace(i,i+1))
        	ASSERT_TRUE(list.select(i) == i+1);
        }

        ASSERT_TRUE(!list.replace(10,1));
        ASSERT_TRUE(list.search(12)==list.size())

        return true;
    }

};


#endif



