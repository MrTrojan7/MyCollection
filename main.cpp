#include "AllLibraries.h"
#include "MyCollection.h"
#include "Queue.h"
#include "Sorter.h"
#include "Stack.h"
#include "String.h"
#include "Vector.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main()
{
	SinglyLinkedList a;
	a.AddToHead(1);
	a.AddToHead(2);
	a.AddToHead(3);
	a.AddToHead(4);
	a.AddToHead(5);
	a.Print();
	MyCollection <SinglyLinkedList> test1;
	test1.Add(a);
	test1.Print();
	return 0;
}