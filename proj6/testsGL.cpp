#include "DoubleLinkedList.h"
#include<string>
#include <iostream>
using namespace std;

bool findExists() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
	//cout << "push_front 4,3,2,1 in that order" << endl;
	//cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

	if (*position == 3) {
		//test more stuff
	//	cout << "Find returned the correct position!" << endl;
		return true;
	}

	else {
	//	cout << "Find did not return the correct position" << endl;

		return false;
	}
}

bool findBeginning() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 1" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 1);

	if (*position == 1) {
		//test more stuff
//		cout << "Find returned the correct position!" << endl;
		return true;
	}

	else {
//		cout << "Find did not return the correct position for 1" << endl;

		return false;
	}
}

bool findEnd() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 4" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

	if (*position == 4) {
		//test more stuff
//		cout << "Find returned the correct position!" << endl;
		return true;
	}

	else {
//		cout << "Find did not return the correct position for 4" << endl;

		return false;
	}
}

bool findSecond() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(4);
	myList.push_front(1);
//	cout << "push_front 4,3,2,4,1 in that order" << endl;
//	cout << "find 4" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

	if (*position == 4) {
		//test more stuff
//		cout << "Find returned the correct position of first 4!" << endl;
		position = myList.find(++position, myList.end(), 4);
		if (position != NULL) {
	//		cout << "found correct position of 2nd 4" << endl;
			return true;
		}
		else {
	//		cout << "did not find correct position of 2nd 4" << endl;
			return false;
		}
	}

	else {
	//	cout << "Find did not return the correct position for first 4" << endl;

		return false;
	}
}

bool findDoesntExist() {
	DoubleLinkedList<int> myList;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 5" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

	if (position != NULL) {
		//test more stuff
//		cout << "Find didn't return a null!" << endl;
		return false;
	}

	else {
//		cout << myList.toString() << endl;
//		cout << "Find returned a null since 5 was not in the list, list not affected" << endl;

		return true;
	}
}

bool insertBefore() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

//	cout << "Return iterator to node containing 3" << endl;

	if (*position == 3) {
		//test more stuff
	//	cout << "Insert 5 before the node containing 3" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.insert_before(position, 5);
		result = myList.toString();
//		cout << result << endl;
		if (result.substr(4, 3).compare("5 3") == 0) {
//			cout << "5 was correctly inserted before 3" << endl;
			return true;
		}
		else {
//			cout << "5 was not inserted before 3 correctly" << endl;
			return false;
		}
	}

	else {
//		cout << "Find did not return the correct position" << endl;

		return false;
	}
}

bool insertBeforeList() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 1" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 1);

//	cout << "Return iterator to node containing 1" << endl;

	if (*position == 1) {
		//test more stuff
//		cout << "Insert 0 before the node containing 1" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.insert_before(position, 0);
		result = myList.toString();
//		cout << result << endl;
		if (result.substr(0, 3).compare("0 1") == 0) {
//			cout << "0 was correctly inserted before 1" << endl;
			return true;
		}
		else {
//			cout << "0 was not inserted before 1 correctly" << endl;
			return false;
		}
	}

	else {
//		cout << "Find did not return the correct position" << endl;

		return false;
	}
}

bool insertBeforeDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

//	cout << "Return iterator to node containing 5, there is not 5 should return null" << endl;

	if (position != NULL) {
//		cout << "Returned a non-null iterator for the node containing 5" << endl;
		return false;
	}

	else {
//		cout << "Try to insert a 8 before the node containing 5 (which is null, but this should not crash)" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.insert_before(position, 8);
		if (pos != NULL) {
//			cout << "Returned a non-null iterator when trying to insert an 8 before a null" << endl;
			return false;
		}
		else {
//			cout << myList.toString() << endl;
//			cout << "Null was correctly returned from trying to insert_before a null, list not affected" << endl;
			return true;
		}
	}
}

bool insertAfter() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

//	cout << "Return iterator to node containing 3" << endl;

	if (*position == 3) {
		//test more stuff
//		cout << "Insert 5 after the node containing 3" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.insert_after(position, 5);
		result = myList.toString();
//		cout << result << endl;
		if (result.substr(4, 3).compare("3 5") == 0) {
	//		cout << "5 was correctly inserted after 3" << endl;
			return true;
		}
		else {
	//		cout << "5 was not inserted after 3 correctly" << endl;
			return false;
		}
	}

	else {
//		cout << "Find did not return the correct position" << endl;
//
		return false;
	}
}

bool insertAfterEndOfList() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 4" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

//	cout << "Return iterator to node containing 3" << endl;

	if (*position == 4) {
		//test more stuff
//		cout << "Insert 5 after the node containing 4" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.insert_after(position, 5);
		result = myList.toString();
	//	cout << result << endl;
		if (result.substr(0, 9).compare("1 2 3 4 5") == 0) {
	//		cout << result << " 5 was correctly inserted after 4" << endl;
			return true;
		}
		else {
//			cout << result << " 5 was not inserted after 3 correctly" << endl;
			return false;
		}
	}

	else {
//		cout << "Find did not return the correct position for 4" << endl;

		return false;
	}
}

bool insertAfterDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

//	cout << "Return iterator to node containing 5, there is not 5 should return null" << endl;

	if (position != NULL) {
//		cout << "Returned a non-null iterator for the node containing 5" << endl;
		return false;
	}

	else {
//		cout << "Try to insert a 8 after the node containing 5 (which is null, but this should not crash)" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.insert_after(position, 8);
		if (pos != NULL) {
//			cout << "Returned a non-null iterator when trying to insert an 8 after a null" << endl;
			return false;
		}
		else {
//			cout << myList.toString() << endl;
//			cout << "Null was correctly returned from trying to insert_after a null, list not affected" << endl;
			return true;
		}
	}
}

bool remove() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

//	cout << "Return iterator to node containing 3" << endl;
	if (*position == 3) {
		//test more stuff
//		cout << "Remove the node containing 3" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.remove(position);
		result = myList.toString();
//		cout << result << endl;
		if (result.substr(2, 3).compare("2 4") == 0) {
//			cout << "3 has been deleted correctly" << endl;
			return true;
		}
		else {
//			cout << "3 was not deleted correctly" << endl;
			return false;
		}
	}

	else {
//		cout << "Find did not return the correct position" << endl;

		return false;
	}
}

bool removeEnd() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 4" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

//	cout << "Return iterator to node containing 4" << endl;
	if (*position == 4) {
		//test more stuff
//		cout << "Remove the node containing 4" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.remove(position);
		result = myList.toString();
//		cout << result << endl;
		if (result.substr(0, 5).compare("1 2 3") == 0) {
//			cout << "4 has been deleted correctly" << endl;
			return true;
		}
		else {
//			cout << "4 was not deleted correctly" << endl;
			return false;
		}
	}

	else {
	//	cout << "Find did not return the correct position for 4" << endl;

		return false;
	}
}

bool removeDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

//	cout << "Return iterator to node containing 5, there is not 5 should return null" << endl;

	if (position != NULL) {
//		cout << "Returned a non-null iterator for the node containing 5" << endl;
		return false;
	}

	else {
//		cout << "Try to remove a node with an iterator of null (but this should not crash)" << endl;
		DoubleLinkedList<int>::Iterator pos = myList.remove(position);
		if (pos != NULL) {
//			cout << "Returned a non-null iterator when trying to remove a node with null as the interator" << endl;
			return false;
		}
		else {
	//		cout << myList.toString() << endl;
	//		cout << "Null was correctly returned from trying to remove with a null iterator, list not affected" << endl;
			return true;
		}
	}
}

bool reverseStringPartial() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 3" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

//	cout << "Return iterator to node containing 3" << endl;
	if (*position == 3) {
		//test more stuff
	//	cout << "Reverse string from the node containing 3 to the beginning" << endl;
		result = myList.reverseString(position);
		if (result.substr(0, 5).compare("3 2 1") == 0) {
//			cout << result << endl;
//			cout << "reverseString working correctly" << endl;
			return true;
		}
		else {
//			cout << "reverseString not working correctly. Should have returned 3 2 1, yours returned " << result << endl;
			return false;
		}
	}

	else {
//		cout << "Find did not return the correct position of 3" << endl;

		return false;
	}
}

bool reverseStringEntireList() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 4" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 4);

//	cout << "Return iterator to node containing 4" << endl;
	if (*position == 4) {
		//test more stuff
//		cout << "Reverse string from the node containing 4 to the beginning" << endl;
		result = myList.reverseString(position);
		if (result.substr(0, 7).compare("4 3 2 1") == 0) {
//			cout << result << endl;
//			cout << "reverseString working correctly" << endl;
			return true;
		}
		else {
	//		cout << "reverseString not working correctly. Should have returned 4 3 2 1, yours returned " << result << endl;
			return false;
		}
	}

	else {
//		cout << "Find did not return the correct position of 4" << endl;
//
		return false;
	}
}

bool reverseStringDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//	cout << "find 5" << endl;

	DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 5);

//	cout << "Return iterator to node containing 5, there is no 5 should return null" << endl;

	if (position != NULL) {
//		cout << "Returned a non-null iterator for the node containing 5" << endl;
		return false;
	}

	else {
//		cout << "Try to reverseString with an iterator of null (but this should not crash)" << endl;
		result = myList.reverseString(position);
		if (result.compare("") != 0) {
//			cout << "Returned a non-empty string when trying to reverseString with null as the interator" << endl;
			return false;
		}
		else {
//			cout << myList.toString() << endl;
//			cout << "Empty string was correctly returned from trying to reverseString with a null iterator, list not affected" << endl;
			return true;
		}
	}
}

bool replace() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(3);
	myList.push_front(1);
//	cout << "push_front 4,3,2,3,1 in that order" << endl;

	//DoubleLinkedList<int>::Iterator position = myList.find(myList.begin(), myList.end(), 3);

//	cout << "Replacing all 3's with 8's for entire list" << endl;
	myList.replace(myList.begin(), myList.end(), 3, 8);
	result = myList.toString();

	if (result.substr(0, 9).compare("1 8 2 8 4") == 0) {
		//test more stuff
//		cout << result << " 3's were replace with 8's" << endl;

//		cout << "Get iterators for nodes with data 1 and 2" << endl;
//		cout << "Change the 8 in bewteen them to a 9" << endl;
		DoubleLinkedList<int>::Iterator position1 = myList.find(myList.begin(), myList.end(), 1);
		DoubleLinkedList<int>::Iterator position2 = myList.find(myList.begin(), myList.end(), 2);
		myList.replace(position1, position2, 8, 9);
		result = myList.toString();
		if (result.substr(0, 9).compare("1 9 2 8 4") == 0) {
//			cout << result << " 1st 8 replaced with 9, 2nd 8 untouched" << endl;
			return true;
		}
		else {
//			cout << result << " Problems with replacing first 8 with 9 and leaving remaining 8 alone" << endl;
			return false;
		}
	}
	else {
//cout << result << "not all 3's were replaced with 8's" << endl;
		return false;
	}


}

bool replaceDoesntExist() {
	DoubleLinkedList<int> myList;
	string result;
	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(2);
	myList.push_front(1);
//	cout << "push_front 4,3,2,1 in that order" << endl;
//
//	cout << "Try to replace 5 with 9, 5 doesn't exist (but this should not crash)" << endl;
	myList.replace(myList.begin(), myList.end(), 5, 9);
	result = myList.toString();
	if (result.substr(0, 7).compare("1 2 3 4") == 0) {
//		cout << result << " list didn't change" << endl;
		return true;
	}
	else {
//		cout << result << " remove results incorrect, shouldn't have changed" << endl;
		return false;
	}
}
int main() {

	bool passed;
	cout << "UNIT TEST - findExists: ";
	passed = findExists();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findBeginning: ";
	passed = findBeginning();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findEnd: ";
	passed = findEnd();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findSecond: ";
	passed = findSecond();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - findDoesntExist: ";
	passed = findDoesntExist();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertBefore: ";
	passed = insertBefore();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertBeforeList: ";
	passed = insertBeforeList();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertBeforeDoesntExist: ";
	passed = insertBeforeDoesntExist();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertAfter: ";
	passed = insertAfter();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertAfterEndOfList: ";
	passed = insertAfterEndOfList();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - insertAfterDoesntExist: ";
	passed = insertAfterDoesntExist();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - remove: ";
	passed = remove();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - removeDoesntExist: ";
	passed = removeDoesntExist();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - removeEnd: ";
	passed = removeEnd();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - reverseStringPartial: ";
	passed = reverseStringPartial();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - reverseStringEntireList: ";
	passed = reverseStringEntireList();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - reverseStringDoesntExist: ";
	passed = reverseStringDoesntExist();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - replace: ";
	passed = replace();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";
	cout << "UNIT TEST - replaceDoesntExist: ";
	passed = replaceDoesntExist();
	passed ? cout << "You PASSED this unit test\n" : cout << "You DID NOT PASS this unit test\n\n";


	return 0;

}