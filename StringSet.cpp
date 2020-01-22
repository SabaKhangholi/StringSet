// StringSet.cpp

#include "StringSet.h"
#include <iostream>	// FIX LATER
#include<string>
using std::string; using std::cout; using std::endl; // ok?

int factor = 2;	// used to double the array
string* temp; // temporary array
StringSet testSet;	// TEST for now
StringSet::StringSet()  // Constructor
{
	setSize = 0;
	maxArraySize = 2;
	stringSetPtr = new string[maxArraySize]; // why did i get a stack overflow err here? when making StringSet the data type??
}

StringSet::StringSet(const StringSet& arr) // Copy constructor
{
	copyArr(arr);
}

StringSet::~StringSet()	// Destructor
{
	delete[] stringSetPtr;
}

StringSet& StringSet::operator= (const StringSet& arr)	//Overloaded assignment operator
{
	if (this != &arr) {
		delete[] stringSetPtr;
		copyArr(arr);	// FIX later
	}
	return *this;
}

void StringSet::printSet()
{
	cout << "Array: " << endl;
	for (int i = 0; i < setSize; i++)
	{
		cout << stringSetPtr[i] << endl;
	}
}

bool StringSet::insert(string stringInsert) {

	if (find(stringInsert) != -1)	// if match found in the set // assume it works for now
	{
		cout << "match not found" << endl;

		if (setSize == maxArraySize)
		{
			temp = stringSetPtr;	// assign stringSetPtr to temp
			stringSetPtr = new string[factor * maxArraySize];	// double max size & assign new array of maxArraySize to stringSetPtr
			for (int i = 0; i < setSize; i++)
			{
				stringSetPtr[i] = temp[i];
			}
			//setSize++;
			stringSetPtr[setSize++] = stringInsert;
			maxArraySize = maxArraySize * factor;
			delete[] temp;
			return true;
		}
		else
		{
			stringSetPtr[setSize++] = stringInsert; //insert at next available spot and increment
			return true;
		}
	}
	else
		cout << "false" << endl;
		return false;
}

bool StringSet::remove(string stringInsert) {
	if (testSet.find(stringInsert) == -1)
			return false;
	else
	{

	};
}

int StringSet::find(string stringInsert) const {

	for (int i = 0; i < setSize-1; i++) 
	{
		if (stringSetPtr[i] == stringInsert) {	// COMPARE index value to inserted string
			cout << i << endl;
			//cout << "hi" << endl;
			return i;
		}
		//else continue;
	}
	//cout << "-1" << endl;
	return -1;	// if not found
}

int StringSet::size(string) const {	// CHECK
	return setSize;
}

StringSet StringSet::unions(const StringSet&) const {
	StringSet j;
	return j;
}

StringSet StringSet::intersection(const StringSet&) const {
	StringSet j;
	return j;
}

StringSet StringSet::difference(const StringSet&) const {
	StringSet j;
	return j;
}

int StringSet::getMaxArraySize() {	// delete this later
	return maxArraySize;
}

int StringSet::getSetSize() {	// delete this later
	return setSize;
}

void StringSet::copyArr(const StringSet& arr)
{
	temp = stringSetPtr;	// assign stringSetPtr to temp
	stringSetPtr = new string[maxArraySize];	// assign new array of maxArraySize to stringSetPtr
	// copy array to new guy
	for (int i = 0; i < maxArraySize; i++) {
		stringSetPtr[i] = arr.stringSetPtr[i];
	}
	// TEST:
	cout << "Copy constructor called" << endl;
	// END TEST
}
