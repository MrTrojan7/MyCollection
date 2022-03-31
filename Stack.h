#pragma once
#include "AllLibraries.h"
class Stack
{
	static const unsigned long int SIZE = 1000;

	vector<int> stack;
	unsigned long int index = 0;
public:
	void Clear();
	bool IsEmpty() const;
	bool IsFull() const;
	int GetCount() const;
	void Push(int number);
	void Pop();
	int PrintTop() const;


};

