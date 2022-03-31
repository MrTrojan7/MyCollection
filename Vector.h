#pragma once
#include "AllLibraries.h"
#include "Sorter.h"

template <class T>

class Vector
{
private:
	T* _arr;
	unsigned int _size;
	unsigned int _capacity;
	void SetCapacity(unsigned int const capacity);
	void EnsureCapacity(unsigned int const size);
	void ReallocationCapacity();
	void ReallocationArray(const bool flag, unsigned int const index, const T& value);
	void CheckIndex(unsigned int const index);
public:
	bool IsFoundElem(T& elem);
	unsigned int GetSize() const;
	unsigned int GetCapacity() const;
	Vector();
	Vector(unsigned int const capacity = 10);
	Vector(unsigned int const size, const T& value);
	Vector(unsigned int const size, const T* arr);
	Vector(const Vector<T>& original);
	void operator = (Vector<T>& original);
	bool operator == (Vector<T>& original);
	T& operator [] (unsigned int const index);
	friend ostream& operator<<<T> (ostream& out, const Vector<T>& original);
	friend istream& operator>><T> (istream& in, const Vector<T>& original);

	////////////////
	bool IsEmpty() const;
	void PushBack(const T& value);
	void PushFront(const T& value);
	void Insert(const T& value, unsigned int const index);
	void RemoveAt(unsigned int const index);
	void Remove(const T& value);
	void PopFront();
	void PopBack();
	void Clear();
	void TrimToSize();
	void SortAsc();
	void SortDesc();
	void RandomShuffle();
	void Reverse();
	void RandomFill();
	void Swap(unsigned int index_1, unsigned int index_2);
	bool Equal(Vector<T>& vector) const;
	T GetElementAt(unsigned int const index);
	const int const IndexOf(const T& value) const;
	const int const LastIndexOf(const T& value) const;
	void Clone(Vector<T>& vector);
	~Vector();
	void Print();
};

template<class T>
inline unsigned int Vector<T>::GetSize() const // GetSize
{
	return _size;
}

template<class T>
inline unsigned int Vector<T>::GetCapacity() const // GetCapacity
{
	return _capacity;
}

template<class T>
inline void Vector<T>::SetCapacity(unsigned int capacity) // SetCapacity
{
	if (capacity <= 10)
		this->_capacity = 10;
	else if (capacity > 10)
		this->_capacity = capacity;
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
	this->_arr = new T[_capacity];
}

///////// C-TORS

template<class T>
inline Vector<T>::Vector() : Vector<T>(10) {}

template<class T>
inline Vector<T>::Vector(unsigned int const capacity) //C-tor with param (capacity)
{
	SetCapacity(capacity);
	this->_size = 0;
}

template<class T>
inline Vector<T>::Vector(unsigned int const size, const T& value)
{
	SetCapacity(size);
	this->_size = size;
	for (unsigned int i = 0; i < GetSize(); i++)
		this->_arr[i] = value;
}

template<class T>
inline Vector<T>::Vector(unsigned int const size, const T* arr)
{
	SetCapacity(size);
	this->_size = size;
	for (unsigned int i = 0; i < GetSize(); i++)
		this->_arr[i] = arr[i];
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& original) // copy c-tor
{
	SetCapacity(original.GetCapacity());
	_size = original.GetSize();
	this->_arr = new int[_size];
	for (unsigned int i = 0; i < _size; i++)
		this->_arr[i] = original._arr[i];
}

//////////////////////
// Overloads
//////////////////////

template<class T>
inline void Vector<T>::operator = (Vector<T>& original) // operator =
{
	this->Clear();
	SetCapacity(original.GetCapacity());
	this->_size = original.GetSize();
	this->_arr = new int[_size];
	for (unsigned int i = 0; i < original.GetSize(); i++)
		this->_arr[i] = original._arr[i];
}

template<class T>
inline bool Vector<T>::operator == (Vector<T>& original) // operator ==
{
	return Equal(original);
}

template<class T>
ostream& operator<<(ostream& out, const Vector<T>& original)
{
	for (unsigned int i = 0; i < original.GetSize(); i++)
		out << original._arr[i] << endl;
	return out;
}

template<class T>
istream& operator>>(istream& in, const Vector<T>& original)
{
	for (unsigned int i = 0; i < original.GetSize(); i++)
		in >> original._arr[i];
	return in;
}

template<class T>
inline T& Vector<T>::operator[](unsigned int const index)
{
	CheckIndex(index);
	return _arr[index];
}

/////////// Methods

template<class T>
inline void Vector<T>::EnsureCapacity(unsigned int const size) // EnsureCapacity
{
	if (size < _capacity)
	{
		return;
	}
	else if (size >= _capacity)
	{
		this->_capacity = (size * 1.5 + 1);
		ReallocationCapacity();
	}
}

template<class T>
inline bool Vector<T>::IsEmpty() const // IsEmpty
{
	return _size == 0;
}

template<class T>
inline void Vector<T>::PushBack(const T& value) // PushBack
{
	EnsureCapacity(GetSize() + 1);
	_arr[_size++] = value;
}

template<class T>
inline void Vector<T>::PushFront(const T& value) // PushFront
{
	int index = 0;
	Insert(value, index);
}

template<class T>
inline void Vector<T>::Insert(const T& value, unsigned int const index) // Insert
{
	if(!IsEmpty())
		CheckIndex(index);
	EnsureCapacity(++_size);
	ReallocationArray(1, index, value);
}

template<class T>
inline void Vector<T>::CheckIndex(unsigned int const index) // Check Index
{
	if (index >= _capacity || index >= _size)
	{
		throw "error! bad index!";
	}
}

template<class T>
inline void Vector<T>::RemoveAt(unsigned int const index) // Remove At Index
{
	if (IsEmpty())
		return;
	CheckIndex(index);
	--_size;
	ReallocationArray(0, index, _arr[index]); // _arr[index] - crutch in this function...
}

template<class T>
inline void Vector<T>::PopBack() // PopBack
{
	RemoveAt(GetSize() - 1);
}

template<class T>
inline void Vector<T>::Remove(const T& value) // Remove by value
{
	if (IsEmpty())
		return;
	for (unsigned int i = GetSize(); i >= 0; i--)
	{
		if (_arr[i] == value)
			RemoveAt(i);
	}
}

template<class T>
inline void Vector<T>::PopFront() // PopFront
{
	if (IsEmpty())
		return;
	RemoveAt(0);
}

template<class T>
inline void Vector<T>::Clear() // Clear
{
	if (!IsEmpty())
		_size = 0;
}

template<class T>
inline void Vector<T>::TrimToSize() // TrimToSize
{
	this->_capacity = _size;
	ReallocationCapacity();
}

template<class T>
inline void Vector<T>::ReallocationCapacity() // Reallocation Capacity (Private Method)
{
	T* temp = new T[GetCapacity()];
	for (unsigned int i = 0; i < GetSize(); i++)
		temp[i] = _arr[i];
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
	_arr = temp;
}

template<class T>
inline void Vector<T>::ReallocationArray(const bool flag, unsigned int const index, const T& value) // Reallocation Array (Private Method)
{
	T* temp = new T[GetCapacity()];
	bool remove_flag = false;
	bool insert_flag = false;
	for (unsigned int i = 0; i < GetSize(); i++)
	{
		if (i == index)
		{
			flag == true ? insert_flag = true : remove_flag = true;
			if (insert_flag)
				temp[i] = value;
		}
		temp[i + insert_flag] = _arr[i + remove_flag];
	}
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
	_arr = temp;
}

template<class T>
inline const int const Vector<T>::IndexOf(const T& value) const // indexOf
{
	for (unsigned int i = 0; i < GetSize(); i++)
	{
		if (_arr[i] == value)
			return i;
	}
	return -1;
}

template<class T>
inline const int const Vector<T>::LastIndexOf(const T& value) const //LastIndexOf
{
	for (unsigned int i = GetSize() - 1; i >= 0; i--)
	{
		if (_arr[i] == value)
			return i;
	}
	return -1;
}

template<class T>
inline void Vector<T>::SortAsc() // SortAsc
{
	if (IsEmpty())
		return;
	Sorter<T> temp;
	temp.qsortRecursive(_arr, _size);
}

template<class T>
inline void Vector<T>::SortDesc() // SortDesc
{
	Sorter<T> temp;
	temp.qsortRecursive(_arr, _size);
	Reverse();
}

template<class T>
inline void Vector<T>::RandomShuffle() // RandomShuffle
{
	//random_shuffle(&_arr[0], &_arr[_size]);
	if (IsEmpty())
		return;
	unsigned int count = GetSize() - 1; // all ingenious is simple))
	Vector<unsigned int> temp(count);
	srand(time(0));
	while (count > 0)
	{
		unsigned int r = rand() % (GetSize() - 1);
		if (temp.IsFoundElem(r))
			continue;
		temp.PushFront(r);
		--count;
	}
	for (unsigned int i = 0; i < (GetSize() - 1); i++)
		Swap(i, temp[i]);
}

template<class T>
inline void Vector<T>::Reverse() // Reverse
{
	for (unsigned int i = 0; i < (GetSize() / 2 - 1); i++)
		Swap(i, (_size - i - 1));
}

template<class T>
inline void Vector<T>::Swap(unsigned int index_1, unsigned int index_2) // Swap
{
	CheckIndex(index_1);
	CheckIndex(index_2);
	T buffer = _arr[index_1];
	_arr[index_1] = _arr[index_2];
	_arr[index_2] = buffer;
}

template<class T>
inline void Vector<T>::RandomFill() // RandomFill
{
	srand(time(0));
	for (unsigned int i = 0; i < GetSize(); i++)
		_arr[i] = rand();
}

template<class T>
inline bool Vector<T>::Equal(Vector<T> & original) const // Equal
{
	if (IsEmpty() && original.IsEmpty())
		return true;
	else if (_size != original._size)
		return false;
	else if (_size == original._size)
	{
		for (unsigned int i = 0; i < GetSize(); i++)
		{
			if (_arr[i] != original._arr[i])
				return false;
		}
	}
	return true;
}

template<class T>
inline T Vector<T>::GetElementAt(unsigned int const index) //GetElementAt
{
	CheckIndex(index);
	T copy = _arr[index];
	return copy;
}

template<class T>
inline void Vector<T>::Clone(Vector<T> &vector)
{
	if (Equal(vector))
		return;
	EnsureCapacity(vector.GetSize());
	this->_size = vector.GetSize();
	for (unsigned int i = 0; i < GetSize(); i++)
		_arr[i] = vector._arr[i];
}

template<class T>
inline bool Vector<T>::IsFoundElem(T& elem)
{
	for (unsigned int i = 0; i < GetSize(); i++)
	{
		if (_arr[i] == elem)
			return true;
	}
	return false;
}




template<class T>
inline Vector<T>::~Vector() // DEST
{
	if (_arr != nullptr)
	{
		delete[] _arr;
		_arr = nullptr;
	}
}

template<class T>
inline void Vector<T>::Print() // Print
{
	if (IsEmpty())
	{
		cout << "Vector is empty!\n";
		return;
	}
	for (unsigned int i = 0; i < GetSize(); i++)
	{
		cout << _arr[i] << ", ";
		if ((i + 1) % 5 == 0)
			cout << "\n";
	}
	cout << "\n";
}

