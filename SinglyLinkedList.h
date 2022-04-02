#pragma once
#include "AllLibraries.h"
#include "Sorter.h"
#include "MyCollection.h"
class SinglyLinkedList : public MyCollection<int>
{
public:
	struct Node
	{
		int data = 0;
		Node* next = nullptr;
	};

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int count = 0;
	bool IsValidIndex(const int index) const;
	void Reverse(int* arr);
	void ToList(int* arr);
	void Shuffle(int* arr);
public:
	void Add(int data) ;
	void Remove();
	int Search(int data);
	void Replace(int value, int index);
	void Sort();


	void AddToHead(int data);
	void AddToTail(int data);
	void InsertInto(int data, int position);
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
	bool Equals(const SinglyLinkedList& list);
	SinglyLinkedList Clone();
	void MergeWith(const SinglyLinkedList& list);
	bool operator > (const SinglyLinkedList& list) const;
	bool operator < (const SinglyLinkedList& list) const;
	bool operator >= (const SinglyLinkedList& list) const;
	bool operator <= (const SinglyLinkedList& list) const;
	bool operator == (const SinglyLinkedList& list) const;
	bool operator != (const SinglyLinkedList& list) const;
	void operator = (const SinglyLinkedList& list);
	int operator [] (int index);
	operator int* ();
	SinglyLinkedList operator +(const SinglyLinkedList& list);
	SinglyLinkedList operator +=(const SinglyLinkedList& list);
	//SinglyLinkedList (const SinglyLinkedList& list);

};

