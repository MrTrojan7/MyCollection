#include "DoublyLinkedList.h"

bool DoublyLinkedList::IsValidIndex(const int index) const
{
    return index >= 0 && index < count;
}

void DoublyLinkedList::Reverse(int* arr)
{
	for (unsigned int i = 0; i < count / 2; i++)
	{
		swap(arr[i], arr[count - i - 1]);
		//cout << arr[i] << "\n";
	}
}

void DoublyLinkedList::ToList(int* arr)
{
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp->data = arr[i];
		temp = temp->next;
	}
}

void DoublyLinkedList::Shuffle(int* arr)
{
	random_shuffle(&arr[0], &arr[count - 1]);
}

void DoublyLinkedList::SetAtHead(int value, int index)
{
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

void DoublyLinkedList::SetAtTail(int value, int index)
{
	Node* temp = tail;
	int i = count - 1;
	while (i >= 0)
	{
		if (i == index)
		{
			temp->data = value;
			return;
		}
		temp = temp->prev;
		--i;
	}
}

int DoublyLinkedList::SearchAtHead(int index)
{
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

int DoublyLinkedList::SearchAtTail(int index)
{
	Node* temp = tail;
	int i = count - 1;
	while (i >= 0)
	{
		if (i == index)
			return temp->data;
		temp = temp->prev;
		--i;
	}
	return -1;
}

void DoublyLinkedList::AddToHead(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	if (IsEmpty())
	{
		tail = temp;
	}
	else
	{
		head->prev = temp;
	}
	head = temp;
	count++;
}

void DoublyLinkedList::AddToTail(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->prev = tail;
	if (IsEmpty())
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	tail = temp;
	count++;
}

void DoublyLinkedList::Insert(int data, int position)
{
	if (position <= 0)
	{
		AddToHead(data);
		return;
	}
	if (position >= count)
	{
		AddToTail(data);
		return;
	}

	Node* elem = GetNode(position);
	Node* temp = new Node();
	temp->data = data;
	temp->next = elem;
	temp->prev = elem->prev;
	temp->prev->next = temp;
	temp->next->prev = temp;
	count++;
}

void DoublyLinkedList::DeleteFromHead()
{
	if (IsEmpty())
	{
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	if (head == nullptr)
	{
		tail = nullptr;
	}
	else
	{
		head->prev = nullptr;
	}
	count--;
}

void DoublyLinkedList::DeleteFromTail()
{
	if (IsEmpty())
	{
		return;
	}
	Node* temp = tail;
	tail = tail->prev;
	delete temp;
	if (tail == nullptr)
	{
		head = nullptr;
	}
	else
	{
		tail->next = nullptr;
	}
	count--;
}

void DoublyLinkedList::DeleteByIndex(int position)
{
	if (position == 0)
	{
		DeleteFromHead();
		return;
	}
	if (position == count - 1)
	{
		DeleteFromTail();
		return;
	}
	Node* sacrifice = GetNode(position);
	sacrifice->prev->next = sacrifice->next;
	sacrifice->next->prev = sacrifice->prev;
	delete sacrifice;
	count--;
}

void DoublyLinkedList::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}

void DoublyLinkedList::Print() const
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

int DoublyLinkedList::GetCount() const
{
	return count;
}

int DoublyLinkedList::IndexOf(int data) const
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

int DoublyLinkedList::LastIndexOf(int data) const
{
	if (IsEmpty())
		return -1;
	Node* temp = tail;
	int i = 0;
	while (i < count)
	{
		if (data == temp->data)
		{
			//cout << i << " cycles\n return: " << (count - i - 1) << "\n";
			return count - i - 1;
		}
		i++;
		temp = temp->prev;
	}
	return -1;
}

bool DoublyLinkedList::IsEmpty() const
{
	return count == 0;
}

void DoublyLinkedList::Reverse()
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

int* DoublyLinkedList::ToArray()
{
	if (IsEmpty())
		return nullptr;
	int* arr = new int[count];
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		arr[i] = temp->data;
		temp = temp->next;
	}
	return arr;
}

void DoublyLinkedList::SetAt(int value, int index)
{
	if (IsEmpty() || !IsValidIndex(index))
		return;
	index <= (count / 2) ? SetAtHead(value, index) : SetAtTail(value, index);
}

bool DoublyLinkedList::Contains(int value)
{
	if (IndexOf(value) >= 0)
		return true;
	return false;
}

void DoublyLinkedList::SortAsc()
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

void DoublyLinkedList::SortDesc()
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

void DoublyLinkedList::Shuffle()
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

bool DoublyLinkedList::Equals(const DoublyLinkedList& list)
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

DoublyLinkedList DoublyLinkedList::Clone()
{
	DoublyLinkedList copy;
	Node* temp = head;
	while (temp != nullptr)
	{
		copy.AddToTail(temp->data);
		temp = temp->next;
	}
	return copy;
}

void DoublyLinkedList::MergeWith(const DoublyLinkedList& list)
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

bool DoublyLinkedList::operator>(const DoublyLinkedList& list) const
{
	return GetCount() > list.GetCount();
}

bool DoublyLinkedList::operator<(const DoublyLinkedList& list) const
{
	return GetCount() < list.GetCount();
}

bool DoublyLinkedList::operator>=(const DoublyLinkedList& list) const
{
	return GetCount() >= list.GetCount();
}

bool DoublyLinkedList::operator<=(const DoublyLinkedList& list) const
{
	return GetCount() <= list.GetCount();
}

bool DoublyLinkedList::operator==(const DoublyLinkedList& list) const
{
	return GetCount() == list.GetCount();
}

bool DoublyLinkedList::operator!=(const DoublyLinkedList& list) const
{
	return GetCount() != list.GetCount();
}

void DoublyLinkedList::operator=(const DoublyLinkedList& list)
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

int DoublyLinkedList::operator[](int index)
{
	if (!IsValidIndex(index))
		return -1;
	int result;
	index <= (count / 2) ? result = SearchAtHead(index) : result = SearchAtTail(index);
	return result;
}

DoublyLinkedList::operator int* ()
{
	return ToArray();
}

DoublyLinkedList DoublyLinkedList::operator+(const DoublyLinkedList& list)
{
	DoublyLinkedList res;
	res.MergeWith(*this);
	res.MergeWith(list);
	return res;
}

DoublyLinkedList DoublyLinkedList::operator+=(const DoublyLinkedList& list)
{
	MergeWith(list);
	Print();
	return *this;
}
