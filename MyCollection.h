#pragma once
#include "MyCollection.h"
template<class T>

class MyCollection 
{
protected:
	int count;
public:
	virtual int GetCount() const = 0;
	virtual void Add(T value) = 0;
	virtual void Remove() = 0;
	virtual void Print() const = 0;
	virtual T Search(T data) = 0;
	virtual void Replace(T value, int num) = 0;
	virtual void Sort() = 0;
};

