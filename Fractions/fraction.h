#pragma once
#include"Header.h"
class Fraction;

bool operator==(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator> (const Fraction& left, const Fraction& right);
bool operator< (const Fraction& left, const Fraction& right);

Fraction& operator+(const Fraction& left, const Fraction& right);
Fraction& operator-(const Fraction& left, const Fraction& right);
Fraction& operator*(const Fraction& left, const Fraction& right);
Fraction& operator/(const Fraction& left, const Fraction& right);

class Fraction {
	int integer;// celoe;
	int numerator;// chislitel;
	int denominator;// znamenatel;
public:

	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;

	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	
	int minKrChislo(int denominator_left, int denominator_right);
	////////////////////////////////////////////////////
	int gcd(int denominator_left, int denominator_right);

	
	void print();
	Fraction& operator= (const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction& operator()(int numerator, int denominator);
	Fraction(int integer = 0, int numerator = 1, int denominator = 0);
	Fraction(const Fraction& other);
	~Fraction();
};

