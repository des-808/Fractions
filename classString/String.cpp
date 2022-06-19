#include "Strings.h"


///////////////////////////////////////////////////////////////////
////////////class definition   (определение класса)  //////////////
///////////////////////////////////////////////////////////////////
char String::get_size()const { return  length; }
const char* String::get_str()const { return str; }
char* String::get_str() { return str; }
void String::set_size(int integer) { this->length = integer; }

String::String(int length) : length(length), str(new char[length] {})
{
	cout << "Default Construktor\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{

	for (int i = 0; i < length; i++) { this->str[i] = str[i]; }
	cout << "Construktor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	for (int i = 0; i < length; i++) {
		this->str[i] = other.str[i];
	}cout << "CopyConstruktor:\t" << this << endl;
}
String::String(String&& other) 
{
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor\t" << this << endl;
}
String::~String() {//деструктор класса
	delete[] this->str;
	cout << "destructor " << this << endl;
}
String& String::operator=(const String& other) {
	if (this == &other)return *this;
	delete[] this->str;
	this->length = other.length;
	this->str = new char[length] {};
	for (int i = 0; i < length; i++) { this->str[i] = other.str[i]; }
	cout << "CopyAssigment:\t" << this << endl;
	return *this;
}
String& String::operator+=(String other) {//
	return *this = *this + other;
}
char String::operator[](int i)const {
	return str[i];
}
char& String::operator[](int i) {
	return str[i];
}
void String::print()const {
	cout << "----------------------------" << endl;
	cout << "print() " << "  Length: " << length << "\tStr: " << str << endl;
	cout << "----------------------------" << endl;
}
void String::to_upper() {
	int i = 0;
	for (; i < length; i++) {
		this->str[i] = toupper(this->str[i]);

	}
}
void String::to_lower() {
	int i = 0;
	for (; i < length; i++) {
		this->str[i] = tolower(this->str[i]);
	}
}
void String::revers() {
	int len;
	char t;
	char* start, * end;
	len = strlen(str);
	start = this->str;
	end = &this->str[len - 1];
	while (start < end) {
		t = *start;
		*start = *end;
		*end = t;
		start++;
		end--;
	}
}
bool String::is_palindrome() {
	int len;
	char t;
	char* start, * end;
	len = strlen(str);
	start = this->str;
	end = &this->str[len - 1];
	for (int i = 0; i < length / 2; i++) {
		if (!(*start == *end)) { return false; }
		start++;
		end--;
	}
	return true;
}


String operator+(const String& left, const String& right) {
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++) {
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++) {
		//cat.get_str()[i + left.get_size()-1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	}
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj) {
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& other) {
	char* buffer = new char[USHRT_MAX] {};//USHRT_MAX
	SetConsoleCP(1251);
	//is.getline(buffer, USHRT_MAX-1);
	is >> buffer;
	SetConsoleCP(866);
	other.set_size(strlen(buffer));
	other = buffer;
	delete[] buffer;
	return is;
}
std::istream& getline(std::istream& is, String& obj) {
	SetConsoleCP(1251);
	is.getline(obj.get_str(), obj.get_size());
	SetConsoleCP(866);
	return is;
}
///////////////////////////////////////////////////////////////////
//////// class definition end  (конец определения класса) /////////
///////////////////////////////////////////////////////////////////