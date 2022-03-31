#pragma once
#include "AllLibraries.h"
class SwitchingPriorityQueue
{
	int* data;
	int* priorities;
	int max_count;
	int real_count;

public:
	SwitchingPriorityQueue (unsigned int max_count);
	~SwitchingPriorityQueue();
	void Clear();
	bool IsEmpty() const;
	bool IsFull() const;
	int GetCount() const;
	void Enqueue(int value, int priority);
	int Dequeue();
	void Print() const;
};

