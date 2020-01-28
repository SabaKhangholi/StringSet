// StringSet.h
// Author: Saba Khangholi
// Date Created: Jan 16, 2019
// Date Last Modified: Jan 27, 2019

// Brief File Description:
// This is the header file for the StringSet class. A number of functions are
// declared here, which, when called, manipulate the StringSet object. 
// The data structure used is a dynamic array.

#pragma once
#include<string>
using std::string;
class StringSet
{
public:
	// Constructor that creates an array of strings of size 2 in dynamic memory,
	// sets maximum size to 2, and current size to 0.
	StringSet();

	// Copy constructor that creates a deep copy of its parameter.
	StringSet(const StringSet&);

	// Destructor that frees dynamic memory associated with the objects string
	~StringSet();

	// Overloaded assignment operator that creates a deep copy of its parameter, 
	// assigns it to a calling object.
	// It deallocates any no longer required any dynamic memory associated with 
	// the calling object.
	StringSet& operator= (const StringSet& arr);

	// FUNCTION: insert ===============================================
	// PRE: The string to be inserted into the array must be a parameter.
	// POST: If the string is already there, returns false. 
	//       If not, it inserts. If the array is full, it doubles the 
	//       size and inserts and returns true.
	// PARAM: string
	bool insert(string);

	// Removes a string.
	// PRE: The string to be removed must be a parameter.
	// POST: Replaces the element in the array with the last element of 
	//       the array if possible and decrements the array size and 
	//       returns true if found.
	// PARAM: string
	bool remove(string);

	// Finds a string matching the string paramter.
	// PRE: The string to be found must be a parameter.
	// POST: Searches for needed element in the array
	//       and if found, returns index. If not, returns
	//       -1.
	// PARAM: string
	int find(string) const;

	// Returns set size of the calling array object.
	// PRE: The calling object must be an array.
	// POST: Returns the integer value representing
	//       the size of the array.
	// PARAM: none
	int size() const;

	// Returns union of the calling object and another string set.
	// PRE: Calling object and parameter array will be used.
	// POST: Returns an array which consists of the union of 
	//       the calling object and the array passed as a parameter.
	// PARAM: StringSet
	StringSet unions(const StringSet&) const;

	// Returns intersection of the calling object and another string set.
	// PRE: Calling object and parameter array will be used.
	// POST: Returns an array which consists of the intersection of 
	//       the calling object and the array passed as a parameter.
	// PARAM: StringSet
	StringSet intersection(const StringSet&) const;

	// Returns set difference of the calling object and another string set.
	// PRE: Calling object and parameter array will be used.
	// POST: Returns an array which consists of the set difference of 
	//       the calling object and the array passed as a parameter.
	// PARAM: StringSet
	StringSet difference(const StringSet&) const;

private:

	string* stringSetPtr;			
	int setSize;					
	int unionSetSize;				
	int maxArraySize;				
									
	int factor = 2;					// used to double the array
	string* temp;					// temporary array
	void copyArr(const StringSet&); // helper method for deep copy	
};
