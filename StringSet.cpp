// StringSet.cpp
#include "StringSet.h"
#include <iostream>	// FIX LATER
#include<string>
#include<array>
using std::string; using std::cout; using std::endl; using std::array; 

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
	for (int i = 0; i < setSize; i++) //edit
	{
		cout << stringSetPtr[i] << endl;
	}
}

bool StringSet::insert(string stringInsert) 
{
	if (find(stringInsert) != -1){	// if match found
		return false;
	}
	else if (find(stringInsert) == -1)
	{
		if (setSize == maxArraySize)
		{
			temp = stringSetPtr;	// assign stringSetPtr to temp
			stringSetPtr = new string[factor * maxArraySize];	// double max size & assign new array of maxArraySize to stringSetPtr
			for (int i = 0; i < setSize; i++)
				stringSetPtr[i] = temp[i];
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
}

bool StringSet::remove(string stringInsert) {
	if (setSize == 0) { // if empty
	return false;
	}
	else if (find(stringInsert) == -1){
		return false;
	}
	else{
		if (stringSetPtr[setSize-1] != stringSetPtr[find(stringInsert)]) // setSize-1 is the last element
		{
			stringSetPtr[find(stringInsert)] = stringSetPtr[setSize-1];
			setSize--;
			return true;
		}
		else
		{
			setSize--;
			return false;
		}
	};
}

int StringSet::find(string stringInsert) const 
{
	for (int i = 0; i < setSize; i++) 
	{
		if (stringSetPtr[i] == stringInsert)	// COMPARE string at index i to inserted string
			return i;
	}
	return -1;	// if not found
}

int StringSet::size() const {	// CHECK -- remove this
	return setSize;
	cout << setSize;
}

StringSet StringSet::unions(const StringSet& arr) const {
	StringSet setUnion;
	setUnion.setSize = setSize + arr.size();
	setUnion.stringSetPtr = new string[setSize + arr.size()];
	int k = 0;
	for (int i = 0; i < arr.size();i++) {
		setUnion.stringSetPtr[i] = arr.stringSetPtr[i];
		k++;
	}
	for (k; k < arr.size() + setSize; k++){
		setUnion.stringSetPtr[k] = stringSetPtr[k-arr.size()];
	}
	for (int i = 0; i < arr.size()-1; i++) {
		if (setUnion.stringSetPtr[i].find(arr.stringSetPtr[i]) != -1)
		{
			//cout << "match "<<setUnion.stringSetPtr[i] << endl;
			setUnion.stringSetPtr[i] = setUnion.stringSetPtr[arr.size() + setSize - 1];
			setUnion.stringSetPtr[arr.size() + setSize - 1] = setUnion.stringSetPtr[arr.size() + setSize - 2];
			setUnion.setSize = setUnion.setSize - 1;
		}
	}
	for (int i = arr.size()-1; i < setSize + arr.size() ; i++) {
		if (setUnion.stringSetPtr[i].find(arr.stringSetPtr[i]) != -1)
		{
			//cout << "match " << setUnion.stringSetPtr[i] << endl;
			setUnion.stringSetPtr[i] = setUnion.stringSetPtr[setSize - 1];
			setUnion.stringSetPtr[setSize - 1] = setUnion.stringSetPtr[setSize - 2];
		}
	}
	for (int i = 0; i < setSize + arr.size(); i++)
	{
		cout<<"set "<<setUnion.stringSetPtr[i]<<endl;
	}
	return setUnion;
}

StringSet StringSet::intersection(const StringSet& arr) const {
	StringSet setIntersect;
	setIntersect.stringSetPtr = new string[setSize + arr.size()];
	setIntersect = arr;
	for (int i = arr.size() + 1; i < setSize + arr.size() - 1; i++) {
		setIntersect.insert(stringSetPtr[i]);
	}
	return setIntersect;
}

StringSet StringSet::difference(const StringSet& arr) const {
	StringSet setDifference;
	setDifference.stringSetPtr = new string[setSize + arr.size()];
	setDifference = arr;
	for (int i = arr.size() + 1; i < setSize + arr.size() - 1; i++) {
		setDifference.insert(stringSetPtr[i]);
	}
	return setDifference;
}

int StringSet::getMaxArraySize() const {	// remove this later
	return maxArraySize;
}

int StringSet::getSetSize() const {	// remove this later
	return setSize;
}

string* StringSet::getStringSetPtr() {
	return stringSetPtr;
}

void StringSet::copyArr(const StringSet& arr) 
{
	maxArraySize = arr.maxArraySize;	// assign stringSetPtr to temp
	setSize = arr.setSize;
	stringSetPtr = new string[setSize];
	for (int i = 0; i < setSize; i++) {
		stringSetPtr[i] = arr.stringSetPtr[i];
	}
}

int StringSet::findUnionCall(const StringSet& unionSet, const StringSet& arr) const {
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr.stringSetPtr[i] == unionSet.stringSetPtr[i])	// COMPARE string at index i to inserted string
				return i;
		}
		return -1;	// if not found
	}
}
int StringSet::findUnionParam(const StringSet& unionSet, const StringSet& arr) const {
	{
		for (int i = arr.size() - 1; i < setSize + arr.size(); i++)
		{
			if (stringSetPtr[i] == unionSet.stringSetPtr[i])	// COMPARE string at index i to inserted string
				return i;
		}
		return -1;	// if not found
	}
	return -1;
}
