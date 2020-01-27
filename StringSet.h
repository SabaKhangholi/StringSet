// StringSet.h

#pragma once
#include<string>
using std::string;
class StringSet
{
public:
	// Constructor that creates an array of strings of size 2 in dynamic memory,
	// sets maximum size to 2, and current size to 0
	StringSet();	

	// Copy constructor that creates a deep copy of its parameter
	StringSet(const StringSet&);

	// Destructor that frees dynamic memory associated with the objects string
	~StringSet();

	// Overloaded assignment operator that creates a deep copy of its parameter, assigns it to a calling object
	// deallocates any no longer required any dynamic memory associated with the calling object
	StringSet& operator= (const StringSet & arr	);

	// Inserts a string into the array, if already in there, returns false, if not the array is already full, doubles size and inserts
	// PRE: 
	// POST: 
	// PARAM: 
	bool insert(string);

	// Removes a string
	// PRE: 
	// POST: 
	// PARAM: 
	bool remove(string);

	// Finds a string
	// PRE: 
	// POST: 
	// PARAM: 
	int find(string) const;

	// Returns set size
	// PRE: 
	// POST: 
	// PARAM: 
	int size() const;

	// Returns union of the calling object and another string set
	// PRE: 
	// POST: 
	// PARAM: 
	StringSet unions(const StringSet &) const;

	// Returns intersection of the calling object and another string set
	// PRE: 
	// POST: 
	// PARAM: 
	StringSet intersection(const StringSet&) const;

	// Returns set difference of the calling object and another string set
	// PRE: 
	// POST: 
	// PARAM: 
	StringSet difference(const StringSet&) const;

	int getMaxArraySize() const;	// delete later

	int getSetSize() const;	// delete later

	string* getStringSetPtr();

	void printSet(/*StringSet* arr*/);

private:

	string* stringSetPtr;
	int setSize;
	int unionSetSize;
	int maxArraySize;
	int factor = 2;	// used to double the array
	string* temp; // temporary array
	void copyArr(const StringSet& );
	int findUnionCall(const StringSet&, const StringSet&) const;
	int findUnionParam(const StringSet& unionSet, const StringSet& arr) const;
};
