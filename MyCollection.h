#pragma once
#include "AllLibraries.h"
#include "Queue.h"
#include "Sorter.h"
#include "Stack.h"
#include "String.h"
#include "Vector.h"
#include "MyCollection.h"
template<class T>

class MyCollection 
{
protected:
	int count;
public:
	virtual int GetCount() { return count; };
	virtual void Add(T value) {};
	virtual void Remove() {};
	virtual void Print() { cout << "Print MyCollection\n"; };
	//virtual T Search() { return T; };
	virtual void Replace(T value, int num) {};
	virtual void Sort() {};
};
