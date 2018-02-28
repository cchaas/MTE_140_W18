#include <iostream>
#include <string>
using namespace std;

#include "Lab1Tests.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    SequentialListTest seq_test;
    DoublyLinkedListTest linked_test;

    bool seq_test1_passed = seq_test.test1();
    bool seq_test2_passed = seq_test.test2();
    bool seq_test3_passed = seq_test.test3();
    bool seq_test4_passed = seq_test.test4(); //added
    bool seq_test5_passed = seq_test.test5(); //added
    bool seq_test6_passed = seq_test.test6(); //added
    bool seq_test7_passed = seq_test.test7(); //added

    bool linked_test1_passed = linked_test.test1();
    bool linked_test2_passed = linked_test.test2();
    bool linked_test3_passed = linked_test.test3();
    bool linked_test4_passed = linked_test.test4(); //added
    bool linked_test5_passed = linked_test.test5(); //added
    bool linked_test6_passed = linked_test.test6(); //added

    cout << "---Sequential List Tests---" << endl;
    cout << "Test1: " << get_status_str(seq_test1_passed) << endl;
    cout << "Test2: " << get_status_str(seq_test2_passed) << endl;
    cout << "Test3: " << get_status_str(seq_test3_passed) << endl;
    cout << "Test4: " << get_status_str(seq_test4_passed) << endl;
    cout << "Test5: " << get_status_str(seq_test5_passed) << endl;
    cout << "Test6: " << get_status_str(seq_test6_passed) << endl;
    cout << "Test7: " << get_status_str(seq_test7_passed) << endl;
    cout << endl;

    cout << "---Linked List Tests---" << endl;
    cout << "Test1: " << get_status_str(linked_test1_passed) << endl;
    cout << "Test2: " << get_status_str(linked_test2_passed) << endl;
    cout << "Test3: " << get_status_str(linked_test3_passed) << endl;
    cout << "Test4: " << get_status_str(linked_test4_passed) << endl;
    cout << "Test5: " << get_status_str(linked_test5_passed) << endl;
    cout << "Test6: " << get_status_str(linked_test6_passed) << endl;

    system("pause");
}

