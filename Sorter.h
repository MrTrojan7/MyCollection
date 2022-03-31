#pragma once
#include "AllLibraries.h"

template <class T>
class Sorter
{
public:
    static void BubleSort(T* arr, unsigned int const size);
    static void InsertSort(T* arr, unsigned int const size);
    static void SelectSort(T* arr, unsigned int const size);
    static void qsortRecursive(T* arr, unsigned int const size);
    static void Swap(T& ref1, T& ref2);
    void PrintArray(T* arr, unsigned int const size);
};

template<class T>
inline void Sorter<T>::BubleSort(T* arr, unsigned int const size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) // ��� ���� ��������� ����� i-���
        {
            if (arr[j - 1] > arr[j]) // ���� ������� ������� ������ �����������
            {
                Swap(arr[j - 1], arr[j]); // ������ �� �������
            }
        }
    }
}

template<class T>
inline void Sorter<T>::InsertSort(T* arr, unsigned int const size)
{
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // ���� j>0 � ������� j-1 > j, x-������ int
            Swap(arr[j - 1], arr[j]);     // ������ ������� �������� j � j-1
}

template<class T>
inline void Sorter<T>::SelectSort(T* arr, unsigned int const size)
{
    int min = 0;
    T temp = 0;
    for (int i = 0; i < size; i++)
    {
        min = i; // �������� ����� ������� ������, ��� ������ � ����������� ���������
        // � ����� ������ �������� ����� ������ � ����������� ���������
        for (int j = i + 1; j < size; j++)
            min = (arr[j] < arr[min]) ? j : min;
        // c������ ������������ ����� ��������, ������� ��� ������� � �������
        if (i != min)
        {
            Swap(arr[i], arr[min]);
        }
    }
}

template<class T>
inline void Sorter<T>::qsortRecursive(T* arr, unsigned int const size)
{
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;
    //����������� ������� �������
    T mid = arr[size / 2];

    //����� ������
    do {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while (arr[i] < mid) {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (arr[j] > mid) {
            j--;
        }

        //������ �������� �������
        if (i <= j) {
            Swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);


    //����������� ������, ���� ��������, ��� �����������
    if (j > 0) {
        //"����� �����"
        qsortRecursive(arr, j + 1);
    }
    if (i < size) {
        //"������ �����"
        qsortRecursive(&arr[i], size - i);
    }
}

template<class T>
inline void Sorter<T>::Swap(T& ref1, T& ref2)
{
    T buffer = ref1;
    ref1 = ref2;
    ref2 = buffer;
}

template<class T>
inline void Sorter<T>::PrintArray(T* arr, unsigned int const size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
        if ((i + 1) % 5 == 0)
        {
            cout << "\n";
        }
    }
    cout << "\n";
}
