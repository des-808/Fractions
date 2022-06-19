#pragma once
#include"Header.h"
#define ENTER 13
class String;

String operator+(const String& left, const String& right);
///////////////////////////////////////////////////////////////////
/////////// class deklaration   (Обьявление класса)  //////////////
///////////////////////////////////////////////////////////////////
class String {
	int length;
	char* str;

public:
	char get_size()const;
	const char* get_str()const;
	char* get_str();
	void set_size(int integer);

	explicit String(int length = 80);
	String(const char* str);
	String(const String& other);
	~String();
	String& operator=(const String& other);
	String& operator+=(String other);
	char operator[](int i)const;
	char& operator[](int i);
	void print()const;
	void to_upper();
	void to_lower();
	void revers();
	bool is_palindrome();
};
///////////////////////////////////////////////////////////////////
///////class deklaration end   (Конец Обьявления класса)  /////////
///////////////////////////////////////////////////////////////////

