#include "SinglyLinkedList.h"
bool SinglyLinkedList::IsValidIndex(const int index) const
{
	return index >= 0 && index < count;
}

void SinglyLinkedList::Reverse(int* arr)
{
	for (unsigned int i = 0; i < count / 2; i++)
	{
		swap(arr[i], arr[count - i - 1]);
		//cout << arr[i] << "\n";
	}
}

void SinglyLinkedList::ToList(int* arr)
{
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp->data = arr[i];
		temp = temp->next;
	}
}

void SinglyLinkedList::Shuffle(int* arr)
{
	random_shuffle(&arr[0], &arr[count - 1]);
}

void SinglyLinkedList::Add(int data)
{
	AddToHead(data);
}

void SinglyLinkedList::Remove()
{
	DeleteFromHead();
}

int SinglyLinkedList::Search(int data)
{
	return IndexOf(data);
}

void SinglyLinkedList::Replace(int value, int index)
{
	SetAt(value, index);
}

void SinglyLinkedList::Sort()
{
	SortAsc();
}

void SinglyLinkedList::AddToHead(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	newElem->next = head;
	if (head == nullptr)
	{
		tail = newElem;
	}
	head = newElem;
	count++;
}

void SinglyLinkedList::AddToTail(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	if (tail == nullptr)
	{
		head = newElem;
	}
	else
	{
		tail->next = newElem;
	}
	tail = newElem;
	count++;
}

void SinglyLinkedList::InsertInto(int data, int position)
{
	if (position >= count)
	{
		AddToTail(data);
		return;
	}
	else if (position <= 0)
	{
		AddToHead(data);
		return;
	}

	Node* newElem = new Node();
	newElem->data = data;
	int i = 1;
	Node* beforeNew = head;
	while (i++ != position)
	{
		beforeNew = beforeNew->next;
	}
	newElem->next = beforeNew->next;
	beforeNew->next = newElem;

	count++;
}

void SinglyLinkedList::DeleteFromHead()
{
	if (count == 0)
		return;
	Node* temp = head;
	head = head->next;
	delete temp;
	count--;
	if (head == nullptr)
		tail = nullptr;
}

void SinglyLinkedList::DeleteFromTail()
{
	if (count == 0)
		return;
	DeleteByIndex(count - 1);
}

void SinglyLinkedList::DeleteByIndex(int position)
{
	if (position <= 0)
	{
		DeleteFromHead();
		return;
	}

	if (position >= count)
	{
		position = count - 1;
	}

	int i = 1;
	Node* beforeDel = head;
	while (i++ != position)
	{
		beforeDel = beforeDel->next;
	}
	Node* sacrifice = beforeDel->next;
	beforeDel->next = sacrifice->next;
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
		tail = beforeDel;
	}
}

void SinglyLinkedList::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}

void SinglyLinkedList::Print() const
{
	if (IsEmpty())
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int SinglyLinkedList::GetCount() const
{
	return count;
}

int SinglyLinkedList::IndexOf(int data) const
{
	if (IsEmpty())
		return -1;
	Node* temp = head;
	int i = 0;
	while (i < count)
	{
		if (data == temp->data)
		{
			return i;
		}
		i++;
		temp = temp->next;
	}
	return -1;
}

int SinglyLinkedList::LastIndexOf(int data) const
{
	if (count == 0)
		return -1;
	Node* temp = head;
	int i = 0;
	int res = 0;
	while (temp != nullptr)
	{
		if (data == temp->data)
		{
			res = i;
		}
		++i;
		temp = temp->next;
	}
	if(res == 0)
		return -1;
	return res;
}

bool SinglyLinkedList::IsEmpty() const
{
	return count == 0;
}

void SinglyLinkedList::Reverse()
{
	if (IsEmpty())
		return;
	int* arr = ToArray();
	Reverse(arr);
	ToList(arr);
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

int* SinglyLinkedList::ToArray()
{
	if (IsEmpty())
		return nullptr;
	int* arr = new int[count];
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		arr[i] = temp->data;
		//cout << arr[i] << "\n";
		temp = temp->next;
	}
	return arr;
}

void SinglyLinkedList::SetAt(int value, int index)
{
	if (IsEmpty() || !IsValidIndex(index))
		return;
	Node* temp = head;
	int i = 0;
	while (i < count)
	{
		if (i == index)
		{
			temp->data = value;
			return;
		}
		temp = temp->next;
		++i;
	}
}

bool SinglyLinkedList::Contains(int value)
{
	if (IsEmpty())
		return false;
	Node* temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			//cout << "list contains a value\n";
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void SinglyLinkedList::SortAsc()
{
	int* arr = ToArray();
	Sorter<int>::qsortRecursive(arr, count);
	ToList(arr);
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

void SinglyLinkedList::SortDesc()
{
	int* arr = ToArray();
	Sorter<int>::qsortRecursive(arr, count);
	Reverse(arr);
	ToList(arr);
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

void SinglyLinkedList::Shuffle()
{
	int* arr = ToArray();
	Shuffle(arr);
	ToList(arr);
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

bool SinglyLinkedList::Equals(const SinglyLinkedList& list)
{
	if (IsEmpty() && list.IsEmpty())
		return true;
	if (GetCount() != list.GetCount())
		return false;
	Node* left = head;
	Node* right = list.head;
	while (left != nullptr && right != nullptr)
	{
		if (left->data != right->data)
			return false;
		left = left->next;
		right = right->next;
	}
	return true;
}

SinglyLinkedList SinglyLinkedList::Clone()
{
	SinglyLinkedList copy;
	Node* temp = head;
	while (temp != nullptr)
	{
		copy.AddToTail(temp->data);
		temp = temp->next;
	}
	return copy;
}

void SinglyLinkedList::MergeWith(const SinglyLinkedList& list)
{
	if (list.IsEmpty())
		return;
	Node* copy = list.head;
	while (copy != nullptr)
	{
		AddToTail(copy->data);
		copy = copy->next;
	}
}

bool SinglyLinkedList::operator>(const SinglyLinkedList& list) const
{
	return GetCount() > list.GetCount();
}

bool SinglyLinkedList::operator<(const SinglyLinkedList& list) const
{
	return GetCount() < list.GetCount();
}

bool SinglyLinkedList::operator>=(const SinglyLinkedList& list) const
{
	return GetCount() >= list.GetCount();
}

bool SinglyLinkedList::operator<=(const SinglyLinkedList& list) const
{
	return GetCount() <= list.GetCount();
}

bool SinglyLinkedList::operator==(const SinglyLinkedList& list) const
{
	return GetCount() == list.GetCount();
}

bool SinglyLinkedList::operator!=(const SinglyLinkedList& list) const
{
	return GetCount() != list.GetCount();
}

void SinglyLinkedList::operator=(const SinglyLinkedList& list)
{
	if (Equals(list))
		return;
	Clear();
	Node* temp = list.head;
	while (temp != nullptr)
	{
		AddToTail(temp->data);
		temp = temp->next;
	}
}

int SinglyLinkedList::operator[](int index)
{
	if(!IsValidIndex(index))
		return -1;
	Node* temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		if (i == index)
			return temp->data;
		temp = temp->next;
		++i;
	}
	return -1;
}

SinglyLinkedList::operator int* ()
{
	return ToArray();
}

SinglyLinkedList SinglyLinkedList::operator+(const SinglyLinkedList& list)
{
	SinglyLinkedList res;
	res.MergeWith(*this);
	res.MergeWith(list);
	return res;
}

SinglyLinkedList SinglyLinkedList::operator+=(const SinglyLinkedList& list)
{
	MergeWith(list);
	Print();
	return *this;
}

//SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& list)
//{
//	cout << "copy c-tor\n";
//	operator =(list);
//}
