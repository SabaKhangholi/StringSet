// main.cpp

#include "StringSet.h"
#include <iostream>	// FIX LATER
#include<string>
using std::string; // FIX LATER
using std::iostream;
using std::cout;
using std::endl; // FIX LATER

int main()
{

	// TEST: string set
	StringSet(testInsert);
	cout << "Max array size: " << testInsert.getMaxArraySize() << endl;
	cout << "Current array size: " << testInsert.getSetSize() << endl;
	// END TEST

	// TEST: Copy constructor
	//testInsert.insert("hi"); 
	testInsert.insert("n");
	testInsert.insert("n");
	testInsert.insert("n");
	cout << "new array size: "<<testInsert.getSetSize() << endl;
	cout << "new max array size: " << testInsert.getMaxArraySize() << endl;
	//cout << string.insert("hi");
	//cout << string1;
	
	// END TEST

	return 0;
}
