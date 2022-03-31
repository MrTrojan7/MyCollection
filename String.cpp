#include "String.h"

void String::CheckIndexLength(int index)
{
	if (index < 0 || index >= strlen(this->text))
		throw "Invalid index!";
}

String::String() : String("", 80) {}

String::String(const char* text) : String(text, 80) {}

String::String(unsigned int capacity) : String("", capacity) {}

String::String(const String& original) : String(original.text, original.capacity) {}

String::String(const char* text, unsigned int capacity)
{
	SetString(text, capacity);
}

String::~String()
{
	if (text != nullptr)
	{
		delete[] text;
		text = nullptr;
	}
}

const char* const String::GetString() const
{
	return text;
}

void String::SetString(const char* text, unsigned int capacity)
{
	length = strlen(text);
	if (capacity <= length)
		capacity = (length + 1) * 1.5;
	this->capacity = capacity;
	if (this->text != nullptr)
	{
		delete[] this->text;
		this->text = nullptr;
	}
	this->text = new char[capacity];
	strcpy_s(this->text, length + 1, text);
}

int String::GetLength() const
{
	return length;
}

int String::GetCapacity() const
{
	return capacity;
}

void String::Clear()
{
	text[0] = 0;
	length = 0;
}

void String::ShrinkToFit()
{
	if (length + 1 <= capacity)
		return;
	capacity = length + 1;
	char* temp = new char[capacity];
	strcpy_s(temp, capacity, text);
	delete[] text;
	text = temp;
}

void String::ShowInfo() const
{
	cout << "Text: " << GetString() << endl;
	cout << "Length: " << GetLength() << endl;
	cout << "Capacity: " << GetCapacity() << endl;
}

void String::Print() const
{
	for (unsigned int i = 0; text[i] != '\0'; i++)
		cout << text[i];
}

void String::PrintLn() const
{
	Print();
	cout << "\n";
}

char String::GetCharAt(unsigned int index)
{
	CheckIndexLength(index);
	return text[index];
}

void String::GetLine()
{
	int size = 4096;
	char* temp = new char[size];
	cout << "Enter string:\n";
	cin.getline(temp, size);
	ConcatChar(temp);
	if (temp != nullptr)
	{
		delete[] temp;
		temp = nullptr;
	}
}

int String::CompareTo(char* text)
{
	if (strlen(this->text) != strlen(text))
		return -1;
	unsigned int count = 0;
	for (unsigned int i = 0; text[i] != '\0'; i++)
	{
		if (this->text[i] == text[i])
			++count;
	}
	return count;
}

int String::CompareTo(String const& original)
{
	return CompareTo(original.text);
}

void String::ConcatChar(const char* text)
{
	unsigned len = strlen(text) + strlen(this->text);
	if (capacity <= len)
		ReallocNCopy(len + 10);
	this->length = len;
	strcat_s(this->text, capacity - 1, text);
}

void String::ConcatNum(int num)
{
	char str[100];
	_itoa_s(num, str, 10);
	int sz = strlen(str) + strlen(text);
	if (sz >= capacity - 1)
		ReallocNCopy(sz + 10);
	this->length = sz;
	ConcatChar(str);
}

void String::ConcatString(String const& s)
{
	ConcatChar(s.text);
}

void String::ConcatDouble(double d)
{
	String d_str = ToString(d);
	ConcatString(d_str);
}

int String::IndexOf(char ch)
{
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		if (text[i] == ch)
			return i;
	}
	return -1;
}

int String::IndexOf(String const& right)
{
	if (!Contains(right))
		return -1;
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		if (text[i] == right.text[0])
		{
			int res = 0;
			for (unsigned int j = 0; j < strlen(right.text); j++)
			{
				if (text[i + j] == right.text[j])
					++res;
				if (res == strlen(right.text))
				{
					//cout << "index first-in-> " << i << "\n";
					return i;
				}
			}
		}

	}
	return -1;
}

int String::LastIndexOf(String const& right)
{
	if (!Contains(right))
		return -1;
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		if (SearchElements(right.text, i) < strlen(right.text))
		{
			//cout << "index last-in-> " << i << "\n";
			return i;
		}
	}
	return -1;
}

int String::LastIndexOf(char ch)
{
	for (int i = strlen(text) - 1; i >= 0; i--)
	{
		if (text[i] == ch)
			return i;
	}
	return -1;
}

bool String::Equals(String const& right)
{
	return CompareTo(right.text) == strlen(text);
}

bool String::Contains(String const& right)
{
	if (Equals(right))
	{
		//cout << "Contains is ==\n";
		return true;
	}
		
	if (strlen(text) < strlen(right.text))
	{
		//cout << "strlen this* < strlen right!\n";
		return false;
	}
	else
	{
		if (SearchElements(right.text) == strlen(right.text))
		{
			//cout << "Contains true!!\n";
			return true;
		}
		//cout << "this* contains is not have right text!\n";
		return false;
	}
	//cout << "Default false!\n";
	return false;
}

bool String::StartWith(String const& right)
{
	if (!Contains(right))
	{
		//cout << "StartWith: string !=\n";
		return false;
	}
	else 
	{
		int res = 0;
		for (unsigned int i = 0; i < strlen(right.text); i++)
		{
			if (text[i] == right.text[i])
				++res;
		}
		if (res == strlen(right.text))
		{
			//cout << "StartWith TRUE!!\n";
			return true;
		}
	}
	//cout << "StartWith FALSE!!\n";
	return false;
}

bool String::EndsWith(String const& right)
{
	if (!Contains(right))
	{
		//cout << "EndsWith: string !=\n";
		return false;
	}
		
	if (SearchElements(right.text, (strlen(text) - strlen(right.text))) == strlen(right.text))
	{
		//cout << "EndsWith TRUE!!\n";
		return true;
	}
	else
	{
		//cout << "EndsWith FALSE!!\n";
		return false;
	}
}

void String::Remove(int start)
{
	CheckIndexLength(start);
	this->text[start] = '\0';
}

void String::Remove(int start, int count)
{
	int len = strlen(text);
	CheckIndexLength(start);
	if (start + count > len)
	{
		Remove(start);
		return;
	}


	for (int i = 0; i < count; i++)
	{
		//_str[start + i] = '\0';
		this->text[start + i] = ' ';
	}

	len = len - start;
	int i = start;
	for (; i < start + len; i++)
	{
		this->text[i] = this->text[i + count];
	}
	this->text[i] = '\0';
}

void String::Replace(char R, char Z)
{
	while(IndexOf(R) >= 0)
		Replace(IndexOf(R), Z);
}

void String::Replace(int index, char Z)
{
	CheckIndexLength(index);
	this->text[index] = Z;
}

void String::Replace(String& substr, String& rep)
{
	if (!Contains(substr))
		return;
	int separator = IndexOf(substr);
	char* tmp = new char[strlen(text) - separator];
	strcpy_s(tmp, strlen(text) - separator + 1, &text[separator + strlen(substr.text)]);
	ReallocNCopy((strlen(tmp) + strlen(rep.text) + strlen(&text[strlen(tmp)])));
	text[separator] = '\0';
	strcat_s(text, capacity - 1, rep.text);
	strcat_s(text, capacity - 1, tmp);
	tmp[0] = '\0';
}

String String::ToLower()
{
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z') 
			text[i] += 'z' - 'Z';
		if (text[i] >= 'À' && text[i] <= 'ß')
			text[i] += 'ÿ' - 'ß';
	}
	return String();
}

String String::ToUpper()
{
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] >= 'a' && text[i] <= 'z')
			text[i] -= 'z' - 'Z';
		if (text[i] >= 'à' && text[i] <= 'ÿ')
			text[i] -= 'ÿ' - 'ß';
	}
	return String();
}

void String::TrimStart()
{
	int index = 0;
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		if (text[i] != ' ')
			break;
		++index;
	}
	strcpy_s(text, strlen(text), &text[index]);
}

void String::TrimEnd()
{
	int index = strlen(text);
	cout << index << "\n";
	for (int i = strlen(text) - 1; i >= 0; i--)
	{
		if (text[i] != ' ')
			break;
		--index;
	}
	text[index] = '\0';
	cout << strlen(text) << "\n";
	//strcpy_s(text, strlen(text), text);
}

void String::Trim()
{
	TrimStart();
	TrimEnd();
}

void String::Reverse()
{
	for (unsigned int i = 0; i < strlen(text) / 2; i++)
		swap(text[i], text[strlen(text) - i - 1]);
}

void String::SortAZ()
{
	Sorter<char> temp;
	temp.InsertSort(text, strlen(text));
}

void String::SortZA()
{
	SortAZ();
	Reverse();
}

void String::Shuffle()
{
	random_shuffle(&text[0], &text[strlen(text)]);
}

void String::RandomFill()
{
	for (unsigned int i = 0; i < strlen(text); i++)
		text[i] = rand() % (32 - 256) + 256;
}

void String::operator=(const String& original)
{
	if (strlen(text) <= strlen(original.text))
		ReallocNCopy(strlen(original.text) + strlen(text));
	strcpy_s(text, strlen(original.text) + 1, original.text);
}

bool String::operator==(const String& original)
{
	return Equals(original);
}

bool String::operator>(const String& original)
{
	return strlen(text) > strlen(original.text);
}

bool String::operator<(const String& original)
{
	return strlen(text) < strlen(original.text);
}

bool String::operator>=(const String& original)
{
	return strlen(text) >= strlen(original.text);
}

bool String::operator<=(const String& original)
{
	return strlen(text) <= strlen(original.text);
}

bool String::operator!=(const String& original)
{
	return strlen(text) != strlen(original.text);
}

String String::operator()(const char* text, unsigned int capacity)
{
	this->String::String(text, capacity);
	return String();
}

char String::operator[](unsigned int index)
{
	CheckIndexLength(index);
	return text[index];
}

String String::operator+(const String& original)
{
	ConcatString(original);
	return String();
}

String String::operator+=(const String& original)
{
	ConcatString(original);
	return String();
}

String String::operator+=(const char* text)
{
	ConcatChar(text);
	return String();
}

String String::operator+(const char* text)
{
	ConcatChar(text);
	return String();
}


//void String::Insert(char ch, unsigned int index)
//{
//	bool flag = false;
//	int res = strlen(text);
//	char* tmp = new char[res];
//	for (unsigned int i = 0; i < strlen(text); i++)
//	{
//		if (index == i)
//		{
//			flag = true;
//			tmp[i] = ch;
//		}
//		tmp[i + flag] = text[i];
//	}
//	tmp[res + 1] = '\0';
//	if (text != nullptr)
//	{
//		delete[] text;
//		text = nullptr;
//	}
//	text = tmp;
//}

//String* String::Split(char separator, int& pieces)
//{
//	// to be continued
//	int count = 0;
//	for (unsigned int i = 0; i < strlen(this->text); i++)
//	{
//		if (this->text[i] == separator)
//			++count;
//	}
//	pieces = count;
//	String* arr = new String[count];
//	count = 0;
//	int index = 0;
//	for (unsigned int i = 0; i < strlen(this->text); i++)
//	{
//		if (this->text[i] != separator)
//		{
//			arr[count].Insert(text[i], index);
//			++index;
//		}
//		if (this->text[i] == separator)
//		{
//			++count;
//			index = 0;
//		}
//	}
//	for (int i = 0; i < count; i++)
//	{
//		arr[i].PrintLn();
//	}
//
//	return arr;
//}








void String::ReallocNCopy()
{
	capacity = capacity * 1.5;
	char* tmp = new char[capacity];
	strcpy_s(tmp, capacity - 1, text);
	delete[] text;
	text = tmp;
}

void String::ReallocNCopy(int sz)
{
	capacity = sz;
	char* tmp = new char[capacity];
	strcpy_s(tmp, capacity - 1, text);
	delete[] text;
	text = tmp;
}

String String::ToString(double d)
{
	String s_num;
	if (d < 0)
		s_num.ConcatChar("-");
	int left = (int)d;
	int tmp = left;
	if (tmp < 0)
		tmp = -tmp;
	unsigned int sz = GetSizeOfNum(tmp);

	int pw = pow(10, sz - 1);
	if (sz == 0)
		s_num.ConcatNum(0);
	for (size_t i = 0; i < sz; i++)
	{
		s_num.ConcatNum(tmp / pw);
		tmp %= pw;
		pw /= 10;
	}
	s_num.ConcatChar(".");
	double right = abs(d - left);
	sz = GetSizeOfDouble(right);
	pw = pow(10, sz);
	right *= pw;
	right = TruncRightNulls(right);
	s_num.ConcatNum(right);
	return s_num;
}

bool String::ContainsTo(String const& right)
{

	return false;
}

int String::SearchElements(const char* text, int index)
{
	int result = 0;
	if (index == (strlen(this->text) - strlen(text) + 1))
		return result;
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		if(this->text[i + index] != text[i])
			return SearchElements(text, ++index);
		if (this->text[i + index] == text[i])
			++result;
		if (result == strlen(text))
			return result;
	}
	return result;
}

unsigned int String::GetSizeOfNum(unsigned int num)
{
	unsigned int sz = 0;
	while (num)
	{
		num /= 10;
		++sz;
	}
	return sz;
}

unsigned int String::GetSizeOfDouble(double d)
{
	unsigned int size = 0;
	double mirror = 1.0 - d;
	int const precision = 2;
	int concurency = 0;
	while (true)
	{
		++size;
		d *= 10;
		mirror *= 10;
		int int_d = (int)d;
		int int_m = (int)mirror;
		if (int_d == 0 && int_m == 9)
			concurency++;
		if (int_d - int_m == 0 || concurency == precision) 
			break;
		d -= int_d;
		mirror -= int_m;
	}
	return size;
}

unsigned int String::TruncRightNulls(unsigned num)
{
	if (num == 0)
		return num;
	while (true)
	{
		if (num % 10 == 0)
			num /= 10;
		else
			break;
	}
	return num;
}

ostream& operator<<(ostream& out, const String& original)
{
	int len = strlen(original.text);
	for (unsigned int i = 0; i < len; i++)
		out << original.text[i];
	return out;
}

istream& operator>>(istream& in, const String& original)
{
	in >> original.text;
	return in;
}
