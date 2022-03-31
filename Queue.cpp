#include "Queue.h"

SwitchingPriorityQueue::SwitchingPriorityQueue(unsigned int max_count)
{
	this->max_count = max_count;
	data = new int[max_count];
	priorities = new int[max_count];
	real_count = 0;
}

SwitchingPriorityQueue::~SwitchingPriorityQueue()
{
	if (data != nullptr) delete[] data;
	if (priorities != nullptr) delete[] priorities;
}

void SwitchingPriorityQueue::Clear()
{
	real_count = 0;
}

bool SwitchingPriorityQueue::IsEmpty() const
{
	return real_count == 0;
}

bool SwitchingPriorityQueue::IsFull() const
{
	return real_count == max_count;
}

int SwitchingPriorityQueue::GetCount() const
{
	return real_count;
}

void SwitchingPriorityQueue::Enqueue(int value, int priority)
{
	if (!IsFull())
	{
		data[real_count] = value;
		priorities[real_count] = priority;
		++real_count;

		for (int i = 0; i < real_count; i++)
		{
			for (int j = real_count - 1; j > 0; j--)
			{
				if (priorities[j - 1] > priorities[j])
				{
					swap(priorities[j], priorities[j - 1]);
					swap(data[j], data[j - 1]);
				}
			}
		}
	}
	else
	{
		throw "Queue is full!";
	}
}

int SwitchingPriorityQueue::Dequeue()
{
	if (!IsEmpty())
	{
		int max_priority = priorities[0];
		int max_priority_position = 0;

		for (int i = 1; i < real_count; i++)
		{
			if (max_priority < priorities[i])
			{
				max_priority = priorities[i];
				max_priority_position = i;
			}
		}

		int result = data[max_priority_position];

		for (int i = max_priority_position; i < real_count - 1; i++)
		{
			data[i] = data[i + 1];
			priorities[i] = priorities[i + 1];
		}

		--real_count;
		return result;
	}
	else
	{
		throw "Queue is empty!";
	}
}

void SwitchingPriorityQueue::Print() const
{
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < real_count; i++)
		cout << i + 1 << ") " << data[i] << "\n";
	cout << "-----------------------------------------------------\n";
}
