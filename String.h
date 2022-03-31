#pragma once
#include "AllLibraries.h"
#include "Sorter.h"
class String
{
private:
char* text = nullptr;
unsigned int length = 0;
unsigned int capacity = 80;
void CheckIndexLength(int index);
void SetString(const char* text, unsigned int capacity);
void ReallocNCopy();
void ReallocNCopy(int sz);
unsigned int GetSizeOfNum(unsigned int num);
unsigned int GetSizeOfDouble(double d);
unsigned int TruncRightNulls(unsigned num);
String ToString(double d);
bool ContainsTo(String const& right);
int SearchElements(const char* text, int index = 0);

public:
	String();
	String(const char* text);
	explicit String(unsigned int capacity);
	String(const String& original);
	String(const char* text, unsigned int capacity);
	~String();
	const char* const GetString() const;
	int GetLength() const;
	int GetCapacity() const;
	void Clear();
	void ShrinkToFit();
	void ShowInfo() const;
	void Print() const;
	void PrintLn() const;
	char GetCharAt(unsigned int index);
	void GetLine();
	int CompareTo(char* text);
	int CompareTo(String const& original);
	//////////////////
	void ConcatChar(const char* text);
	void ConcatNum(int num);
	void ConcatString(String const& s);
	void ConcatDouble(double d);
	//////////////////
	int IndexOf(char ch);
	int IndexOf(String const& right);
	int LastIndexOf(char ch);
	int LastIndexOf(String const& right);
	bool Equals(String const& right);
	bool Contains(String const& right);
	bool StartWith(String const& right);
	bool EndsWith(String const& right);
	void Remove(int start);
	void Remove(int start, int count);
	void Replace(char R, char Z);
	void Replace(int index, char Z);
	void Replace(String& substr, String& rep);
	//String* Split(char separator, int& pieces);
	String ToLower();
	String ToUpper();
	void TrimStart();
	void TrimEnd();
	void Trim();
	void Reverse();
	void SortAZ();
	void SortZA();
	void Shuffle();
	void RandomFill();
	//void Insert(char ch, unsigned int index);
	///////// 
	//overloading
	/////////
	void operator = (const String& original);
	bool operator ==(const String& original);
	bool operator > (const String& original);
	bool operator < (const String& original);
	bool operator >= (const String& original);
	bool operator <= (const String& original);
	bool operator != (const String& original);
	String operator ()(const char* text, unsigned int capacity);
	char operator [](unsigned int index);
	String operator + (const String& original);
	String operator += (const String& original);
	String operator += (const char* text);
	String operator + (const char* text);
	//String operator + (const char ch);
	friend ostream& operator << (ostream& out, const String& original);
	friend istream& operator >> (istream& in, const String& original);
	//operator char* ();
	//operator int ();
	//operator double ();

};

