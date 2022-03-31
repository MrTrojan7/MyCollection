#include "Stack.h"

void Stack::Clear()
{
	index = 0;
}

bool Stack::IsEmpty() const
{
	return index == 0;
}

bool Stack::IsFull() const
{
	return index == SIZE;
}

int Stack::GetCount() const
{
	return index;
}

void Stack::Push(int number)
{
	if (!IsFull())
	{
		stack.push_back(number);
		++index;
	}
	else 
	{
		throw "Stack overflow!";
	}
}

void Stack::Pop()
{
	if (!IsEmpty())
	{
		stack.pop_back();
		--index;
	}
	else
	{
		throw "Stack is empty!";
	}
}

int Stack::PrintTop() const
{
	return stack[index - 1];
}
