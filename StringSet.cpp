// StringSet.cpp
// Author: Saba Khangholi
// Date Created: Jan 16, 2019
// Date Last Modified: Jan 27, 2019

// Brief File Description:
// This is the implementation file for the StringSet class. A number 
// of functions are defined here, which, when called, manipulate 
// the StringSet object in various ways. The data structure used 
// is a dynamic array.

#include<string>
#include "StringSet.h"

using std::string;

// StringSet Constructor Definition
StringSet::StringSet()
{
	setSize = 0;
	maxArraySize = 2;
	stringSetPtr = new string[maxArraySize]; // initialize new array in dynamic memory
}

// StringSet Copy Constructor Definition
StringSet::StringSet(const StringSet& arr)
{
	copyArr(arr);	// call to helper method
}

// StringSet Destructor Definition
StringSet::~StringSet()
{
	delete[] stringSetPtr;
}

// StringSet Overloaded Assignment Operator Definition
StringSet& StringSet::operator= (const StringSet& arr)	//Overloaded assignment operator
{
	if (this != &arr) {
		delete[] stringSetPtr;	// deallocate memory for old array
			copyArr(arr);	// call to deep copy helper method
	}
	return *this; // return new StringSet object
}

// StringSet insert Function Definition
bool StringSet::insert(string stringInsert) 
{
	if (find(stringInsert) != -1){	// if match found
		return false;
	}
	else if (find(stringInsert) == -1)	// if match not found
	{
		if (setSize == maxArraySize)	// if array is full
		{
			temp = stringSetPtr;	// assign stringSetPtr to a temporary array temp
			stringSetPtr = new string[factor * maxArraySize];	// double array size 
			for (int i = 0; i < setSize; i++)	// assign new array of maxArraySize to stringSetPtr
				stringSetPtr[i] = temp[i];
			stringSetPtr[setSize++] = stringInsert;	// insert the string at the incremented index
			maxArraySize = maxArraySize * factor; // double max size
			delete[] temp;	// deallocate memory of temporary array
			return true;
		}
		else // if not full
		{
			stringSetPtr[setSize++] = stringInsert; //insert at next available spot and increment index
			return true;
		}
	}
}

// StringSet remove Function Definition
bool StringSet::remove(string stringInsert) {
	if (setSize == 0) {	// if  array is empty
	return false;
	}
	else if (find(stringInsert) == -1){	// if string not found
		return false;
	}
	else{	// if string found
		if (stringSetPtr[setSize-1] != stringSetPtr[find(stringInsert)]) // setSize-1 is not the last element
		{
			stringSetPtr[find(stringInsert)] = stringSetPtr[setSize-1];	// replace with last element
			setSize--;	
			return true;
		}
		else{	// if it is the last element
			setSize--;	
			return false;
		}
	};
}

// StringSet find Function Definition
int StringSet::find(string stringInsert) const 
{
	for (int i = 0; i < setSize; i++) 
	{
		if (stringSetPtr[i] == stringInsert)	// COMPARE string at index i to inserted string
			return i;
	}
	return -1;	// if not found
}

// StringSet size Function Definition
int StringSet::size() const {	
	return setSize;	// actual array size
}

// StringSet unions Function Definition
StringSet StringSet::unions(const StringSet& arr) const {
	StringSet setUnion;
	// define size of union before duplicate removal
	setUnion.setSize = setSize + arr.size();	
	// create a new dynamic array
	setUnion.stringSetPtr = new string[setSize + arr.size()];
	int k = 0;	// increment to insert second array into union
	// insert elements of calling object into setUnion
	for (int i = 0; i < arr.size();i++) {
		setUnion.stringSetPtr[i] = arr.stringSetPtr[i];
		k++;
	}
	// insert elements of parameter object into setUnion
	for (k; k < arr.size() + setSize; k++){
		setUnion.stringSetPtr[k] = stringSetPtr[k-arr.size()];
	}
	for (int i = 0; i < arr.size(); i++) {	// calling object index
		for (int j = 0; j < arr.size(); j++) {	// parameter array index
			if (arr.stringSetPtr[i].find(stringSetPtr[j]) != -1){	// if duplicate found
				// remove the duplicate from the set -- insert last element into spot 
				// and decrement
				setUnion.stringSetPtr[j+i] = setUnion.stringSetPtr[setUnion.setSize - 1];
				setUnion.setSize--;
			}
		}
	}
	return setUnion;
}

// StringSet intersection Function Definition
StringSet StringSet::intersection(const StringSet& arr) const {
	StringSet setIntersect;
	// define size of intersection before duplicate removal
	setIntersect.setSize = setSize + arr.size();
	// create a new dynamic array
	setIntersect.stringSetPtr = new string[setSize + arr.size()];
	int k = 0;	// increment to insert second array into intersection
	// insert elements of calling object into setIntersect
	for (int i = 0; i < arr.size(); i++) {
		setIntersect.stringSetPtr[i] = arr.stringSetPtr[i];
		k++;
	}
	// insert elements of parameter object into setIntersect
	for (k; k < arr.size() + setSize; k++) {
		setIntersect.stringSetPtr[k] = stringSetPtr[k - arr.size()];
	}
	// remove the elements not present in both from the set 
	// -- insert last element into spot and decrement size
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (arr.stringSetPtr[i].find(stringSetPtr[j]) == -1)
			{
				setIntersect.stringSetPtr[j + i] = setIntersect.stringSetPtr[setIntersect.setSize-1];
			}
		}
	}
	return setIntersect;
}

// StringSet difference Function Definition
StringSet StringSet::difference(const StringSet& arr) const {
	StringSet setDifference;
	// define size of set difference before duplicate removal
	setDifference.setSize = setSize + arr.size();
	// create a new dynamic array
	setDifference.stringSetPtr = new string[setSize + arr.size()];
	int k = 0;	// increment to insert second array into set difference
	// insert elements of calling object into set difference
	for (int i = 0; i < arr.size(); i++) {
		setDifference.stringSetPtr[i] = arr.stringSetPtr[i];
		k++;
	}
	// insert elements of parameter object into setDifference
	for (k; k < arr.size() + setSize; k++) {
		setDifference.stringSetPtr[k] = stringSetPtr[k - arr.size()];
	}
	// remove the elements present in the calling object but not 
	// in the parameter -- insert last element into spot 
	// and decrement size
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (arr.stringSetPtr[i].find(stringSetPtr[j]) == -1)
			{
				setDifference.stringSetPtr[j + i] = setDifference.stringSetPtr[setDifference.setSize - 1];
			}
		}
	}
	return setDifference;
}

// StringSet copy Helper Function Definition
void StringSet::copyArr(const StringSet& arr) 
{
	maxArraySize = arr.maxArraySize;	// copy the maximum array size
	setSize = arr.setSize;				// copy the actual array size
	// create new dynamic array with new characteristics
	stringSetPtr = new string[setSize]; 
	for (int i = 0; i < setSize; i++) {
		// initialize copy array with parameter array elements
		stringSetPtr[i] = arr.stringSetPtr[i];	
	}
}
