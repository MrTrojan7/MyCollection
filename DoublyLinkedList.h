#pragma once
#include "AllLibraries.h"
#include "Sorter.h"
#include "MyCollection.h"
class DoublyLinkedList : public MyCollection<int>
{

public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;
	bool IsValidIndex(const int index) const;
	void Reverse(int* arr);
	void ToList(int* arr);
	void Shuffle(int* arr);
	void SetAtHead(int value, int index);
	void SetAtTail(int value, int index);
	int SearchAtHead(int index);
	int SearchAtTail(int index);
	Node* GetNode(int position)
	{
		if (position < 0 || position >= count) {
			return nullptr;
		}
		if (position == 0)
		{
			return head;
		}
		if (position == count - 1)
		{
			return tail;
		}

		Node* temp;
		int i = position;
		if (position <= count / 2)
		{
			temp = head->next;
			while (--i != 0)
			{
				temp = temp->next;
			}
		}
		else
		{
			temp = tail->prev;
			while (++i != count - 1)
			{
				temp = temp->prev;
			}
		}
		return temp;
	}
	
public:
	void Add(int value);
	void Remove();
	int Search(int data);
	void Replace(int value, int num);
	void Sort();

	void AddToHead(int data);
	void AddToTail(int data);
	void Insert(int data, int position);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteByIndex(int position);
	void Clear();
	void Print() const;
	int GetCount() const;
	int IndexOf(int data) const;
	int LastIndexOf(int data) const;
	bool IsEmpty() const;
	void Reverse();
	int* ToArray();
	void SetAt(int value, int index);
	bool Contains(int value);
	void SortAsc();
	void SortDesc();
	void Shuffle();
	bool Equals(const DoublyLinkedList& list);
	DoublyLinkedList Clone();
	void MergeWith(const DoublyLinkedList& list);
	bool operator > (const DoublyLinkedList& list) const;
	bool operator < (const DoublyLinkedList& list) const;
	bool operator >= (const DoublyLinkedList& list) const;
	bool operator <= (const DoublyLinkedList& list) const;
	bool operator == (const DoublyLinkedList& list) const;
	bool operator != (const DoublyLinkedList& list) const;
	void operator = (const DoublyLinkedList& list);
	int operator [] (int index);
	operator int* ();
	DoublyLinkedList operator +(const DoublyLinkedList& list);
	DoublyLinkedList operator +=(const DoublyLinkedList& list);
	//DoublyLinkedList (const DoublyLinkedList& list);
};

